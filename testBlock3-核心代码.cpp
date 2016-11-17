

struct __block_impl {
    void *isa;
    int Flags;
    int Reserved;
    void *FuncPtr;
};

// 一、用于封装 __block 修饰的外部变量
struct __Block_byref_num_0 {
    void *__isa;    // 对象指针
    __Block_byref_num_0 *__forwarding;  // 指向 拷贝到堆上的 指针
    int __flags;    // 标志位变量
    int __size;     // 结构体大小
    int num;        // 外部变量
};

struct __main_block_impl_0 {
    struct __block_impl impl;
    struct __main_block_desc_0* Desc;
    __Block_byref_num_0 *num; // 二、__block int num  变成了 __Block_byref_num_0指针变量。也就是 __block的变量通过指针传递给block
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, __Block_byref_num_0 *_num, int flags=0) : num(_num->__forwarding) {
        impl.isa = &_NSConcreteStackBlock;
        impl.Flags = flags;
        impl.FuncPtr = fp;
        Desc = desc;
    }
};

static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
    __Block_byref_num_0 *num = __cself->num; // bound by ref
    
    (num->__forwarding->num) = 10;  //三、这里修改的是__forwarding 指向的内存的值
    printf("num = %d", (num->__forwarding->num));
}

//四、对__Block_byref_num_0结构体进行内存管理。新加了copy和dispose函数。
static void __main_block_copy_0(struct __main_block_impl_0*dst, struct __main_block_impl_0*src) {
    // _Block_object_assign 函数：当 block 从栈拷贝到堆时，调用此函数。
    _Block_object_assign((void*)&dst->num, (void*)src->num, 8/*BLOCK_FIELD_IS_BYREF*/);
}

// 当 block 从堆内存释放时，调用此函数:__main_block_dispose_0
static void __main_block_dispose_0(struct __main_block_impl_0*src) {_Block_object_dispose((void*)src->num, 8/*BLOCK_FIELD_IS_BYREF*/);}

static struct __main_block_desc_0 {
    size_t reserved;
    size_t Block_size;
    void (*copy)(struct __main_block_impl_0*, struct __main_block_impl_0*);
    void (*dispose)(struct __main_block_impl_0*);
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0), __main_block_copy_0, __main_block_dispose_0};

int main()
{
    __attribute__((__blocks__(byref))) __Block_byref_num_0 num = {(void*)0,(__Block_byref_num_0 *)&num, 0, sizeof(__Block_byref_num_0), 1};
    void (*blockName)() = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, (__Block_byref_num_0 *)&num, 570425344));
    ((void (*)(__block_impl *))((__block_impl *)blockName)->FuncPtr)((__block_impl *)blockName);
    return 0;
}

