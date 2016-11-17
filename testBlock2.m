
#import <Foundation/Foundation.h>

int main()
{
    int num = 1;
    void (^blockName)() = ^{
        printf("num = %d", num);
    };
    blockName();
    return 0;
}

