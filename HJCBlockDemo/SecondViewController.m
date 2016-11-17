//
//  SecondViewController.m
//  HJCBlockDemo
//
//  Created by hjc on 2016/11/17.
//  Copyright © 2016年 hehe. All rights reserved.
//  这个页面是为了好截图放博客上

#import "SecondViewController.h"

@interface SecondViewController ()

@end

@implementation SecondViewController

typedef void(^captureObjBlk2)();
captureObjBlk2 captureBlk2;

- (void)viewDidLoad {
    [super viewDidLoad];
    [self captureObject2];
    captureBlk2();
}

- (void)captureObject2 {
    int captureNum2 = 1;
    captureBlk2 = ^() {
        NSLog(@"num = %d", captureNum2);    // num = 1
    };
    captureNum2 = 2;
}
 
@end
