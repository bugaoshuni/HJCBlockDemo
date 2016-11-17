
#import <Foundation/Foundation.h>

int main()
{
    __block int num = 1;
    void (^blockName)() = ^{
        num = 10;
        printf("num = %d", num);
    };
    blockName();
    return 0;
}

