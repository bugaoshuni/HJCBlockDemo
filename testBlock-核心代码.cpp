
// __block_impl 是block的结构体
struct __block_impl {
    void *isa;      // isa指针，在Objective-C中，任何对象都有isa指针
    int Flags;      // 按 bit位表示一些 block 的附加信息。在 block copy 的实现时就会使用。
    int Reserved;   // 保留变量
    void *FuncPtr;  // 函数指针，指向block声明的方法。
};

// __main_block_func_0 是block要执行的函数
static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
    printf("打印block函数");
}

// __main_block_desc_0 是block的描述信息 的结构体
static struct __main_block_desc_0 {
    size_t reserved;    // 结构体信息保留字段
    size_t Block_size;  // 结构体大小
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};


// __main_block_impl_0 是该block的实现，也是 block 实现的入口
struct __main_block_impl_0 {
    struct __block_impl impl;   // impl 为block类型的变量，函数里对它的impl的isa、Flags、FuncPtr来进行了赋值。
    struct __main_block_desc_0* Desc;
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) {
        impl.isa = &_NSConcreteStackBlock;  // block 的三种类型：_NSConcreteStackBlock、_NSConcreteGlobalBlock、_NSConcreteMallocBlock
        impl.Flags = flags;
        impl.FuncPtr = fp;
        Desc = desc;
    }
};

int main()
{
    // 定义并初始化了block类型的变量。
    void (*blockName)() = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA));
    // 调用block。
    ((void (*)(__block_impl *))((__block_impl *)blockName)->FuncPtr)((__block_impl *)blockName);
    return 0;
}

