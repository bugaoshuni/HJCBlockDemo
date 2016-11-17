
#import <Foundation/Foundation.h>

int main()
{
    void (^blockName)() = ^{
        printf("打印block函数");
    };
    blockName();
    return 0;
}

