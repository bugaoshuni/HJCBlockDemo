

struct __block_impl {
    void *isa;
    int Flags;
    int Reserved;
    void *FuncPtr;
};

struct __main_block_impl_0 {
    struct __block_impl impl;
    struct __main_block_desc_0* Desc;
    int num;    //1、多了一个变量 num，block访问的局部变量 赋值给了这个int变量。
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int _num, int flags=0) : num(_num) {
        impl.isa = &_NSConcreteStackBlock;
        impl.Flags = flags;
        impl.FuncPtr = fp;
        Desc = desc;
    }
};

static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
    int num = __cself->num; // 2、__main_block_impl_0的num变量 赋值给__main_block_func_0 里的变量。
    printf("num = %d", num);
}

static struct __main_block_desc_0 {
    size_t reserved;
    size_t Block_size;
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};

int main()
{
    int num = 1;
    void (*blockName)() = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, num));
    ((void (*)(__block_impl *))((__block_impl *)blockName)->FuncPtr)((__block_impl *)blockName);
    return 0;
}

