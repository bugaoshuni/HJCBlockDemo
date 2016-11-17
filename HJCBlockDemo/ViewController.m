//
//  ViewController.m
//  HJCBlockDemo
//
//  Created by hjc on 2016/11/16.
//  Copyright © 2016年 hehe. All rights reserved.
//

#import "ViewController.h"

typedef void(^captureObjBlk)(NSObject *);

typedef void(^captureObjBlk2)();

@interface ViewController () {
    NSInteger num;
    captureObjBlk captureBlk;
    captureObjBlk2 captureBlk2;
}
@property (nonatomic, strong) captureObjBlk2 captureBlk21;
@end

@implementation ViewController

#pragma mark - life cycle
- (void)viewDidLoad {
    [super viewDidLoad];
    num = 1;
    //每次换行就是一个 测试点。
//    [self definitionBlock];
    
    [self testBlock1];
    
//    //博文中的考题
//    [self captureObject];
//    captureBlk([[NSObject alloc] init]);
//    captureBlk([[NSObject alloc] init]);
//    captureBlk([[NSObject alloc] init]);
    
//    [self captureObject2];
//    captureBlk2();
    
//    [self clangCode1];
    
//    [self clangCode2];
}



#pragma mark - 一、block的简单定义和调用
- (void)definitionBlock {
    //1、block声明
    void (^blockName1)(int arg1, int arg2); //相同： void (^blockName)(int, int);
    //block定义
    blockName1 = ^void(int arg1, int arg2) {
        
    };//相同： blockName1 = ^(int arg1, int arg2) {};
    //声明和调用放一起
    void (^blockName)(int, int) = ^(int arg1, int arg2) {
        NSLog(@"arg1 + arg2 = %d", arg1 + arg2);
    };
    blockName(1,2);
    
    //2、没有参数
    void (^blockName2)() = ^() {
        NSLog(@"block2");
    };
    NSLog(@"blockName2 = %@", blockName2);
    blockName2();
    
    //3、block有返回值
    int (^blockName3)(int) = ^(int n) {
        return n * 2;
    };
    //4、block作为方法的参数
    [self testBlock2:blockName3];
}

- (void)testBlock2:(int(^)(int))myBlock {
    myBlock(10);
}


#pragma mark - 二、block调用外部的变量
- (void)testBlock1 {
    //1、block修改成员变量
    void (^block1)() = ^(){
        ++num;
        NSLog(@"调用成员变量： %ld", num);
    };
    
    block1();
    
    //2、调用局部变量，不用__block，值传递。
    NSInteger testNum2 = 10;
    void (^block2)() = ^() {
        //testNum = 1000; 这样是编译不通过的
        NSLog(@"修改局部变量： %ld", testNum2); //打印：10
    };
    testNum2 = 20;
    block2();
    NSLog(@"testNum最后的值： %ld", testNum2);//打印：30

    //3、修改局部变量，要用__block，指针传递。
    __block int testNum3 = 10;
    void (^block3)() = ^() {
        NSLog(@"读取局部变量： %d", testNum3); //打印：20
        testNum3 = 1000;
    };
    testNum3 = 20;
    block3();
    NSLog(@"block执行后的值： %d", testNum3); //打印：1000
}

#pragma mark - 三、用clang 对应的OC代码：
- (void)clangCode1 {
    void (^clangBlk)() = ^{
        printf("打印block函数");
    };
    NSLog(@"clangBlk = %@", clangBlk);
    clangBlk();
}

- (void)clangCode2 {
    int num = 1;
    void (^clangBlk2)() = ^{
        printf("clangBlk2 = %d", num);
    };
    NSLog(@"clangBlk2 = %@", clangBlk2);
    clangBlk2();
}

#pragma mark - 三、block 在博文中的考题
- (void)captureObject {
    NSMutableArray *mutArray = [[NSMutableArray alloc] init];
    captureBlk = ^(NSObject* obj) {
        [mutArray addObject:obj];
        NSLog(@"mutArray元素个数：%ld", [mutArray count]);
    };
    [mutArray addObject:[[NSObject alloc] init]];
}

- (void)captureObject2 {
    int captureNum2 = 1;
    captureBlk2 = ^() {
        NSLog(@"num = %d", captureNum2);
    };
    captureNum2 = 2;
}

@end
