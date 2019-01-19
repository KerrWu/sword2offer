//
//  getMaxValue.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/16.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef getMaxValue_h
#define getMaxValue_h


#include <algorithm>
/*
 目标：一个m*n的棋盘，每个格子有一个礼物，每个礼物价值不同(价值大于0)
 从左上角出发，只能向右或者向下，直到右下角
 计算能拿到的最大价值总和
 */

/*
 思路：用动态规划
 设在(i,j)格子时得到的礼物的价值为f(i,j)，则想要到达(i,j)，有两种方式
 (i-1,j)或者(i,j-1)，即f(i,j) = max( f(i-1,j), (i,j-1) ) + gift(i,j)
 
 如果用递归的方式解决，显然会有大量的重复计算，故以循环的方式实现，以一个二维数组a存储中间结果
 数组中a[i][j]表示到达(i,j)时的最大价值总和
 
 测试用例：
 1. 输入数组为空
 2. m=1 || n=1， m=1 && n=1
 */

int getMaxValue(int** value, int rows, int cols)
{
    if (value == nullptr)
    {
        std::cerr<<"value is nullptr";
        exit(1);
    }
    
    int a[rows][cols];
    std::cout<<typeid(*value).name()<<std::endl;
    
    for (int i=0; i<rows; ++i)
    {
        for (int j=0; j<cols; ++j)
        {
            if (i<1 && j<1)
                a[i][j] = *((int*)value+i*cols+j);
            
            else if (i<1)
                a[i][j] = a[i][j-1] + *((int*)value+i*cols+j);
            else if (j<1)
                a[i][j] = a[i-1][j] + *((int*)value+i*cols+j);
            else
                a[i][j] = std::max(a[i-1][j], a[i][j-1]) + *((int*)value+i*cols+j);
        }
    }
    
    return a[rows-1][cols-1];
}


#endif /* getMaxValue_h */
