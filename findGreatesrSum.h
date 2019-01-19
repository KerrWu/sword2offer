//
//  findGreatesrSum.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/16.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef findGreatesrSum_h
#define findGreatesrSum_h


#include <algorithm>

/*
 目标：给出一个数组，输出其最大子数组的和
 */

/*
 思路1：以一个sum变量从第一个元素开始累加，如果加上某个数后sum比这个数小，说明从这个数为起点比从之前的数为起点更大
 则令sum归零，重新从这个数开始累加
 每次遇到一个负数的时候，要比较当前值和最大值，保留其中的大者，再进行负数的累加工作
 O(n)
 
 测试用例：
 1. 输入数组为空
 2. 输入length<=0
 3. 输入的数组元素全为负数/正数
 4. 输入数组只有一个元素
 */

int findGreatestSum1(int a[], int length)
{
    if (a == nullptr)
    {
        std::cerr<<"a is a nullptr";
        exit(1);
    }
    
    if (length<=0)
    {
        std::cerr<<"length is not positive";
        exit(1);
        
    }
    
    int sum = 0;
    int max = INT_MIN;
    
    for(int i=0;i<length;++i)
    {
        if (sum+a[i]<a[i])
            sum = a[i];
        else
            sum += a[i];
        max = std::max(sum,max);
    }
    
 
    return max;
    
}

/*
 思路2: 利用动态规划解决，求长度为n的数组的最大子数组和，
 就是求长度为n-1的最大子数组和以及与该和与当前元素的和的大者
 以如下递归式实现动态规划
 f(i) = f(i-1) + a[i] -- if f(i-1)>0
 f(i) = a[i] -- if f(i-1)<=0
 */

int findGreatestSum2(int a[], int length)
{
    if (a == nullptr)
    {
        std::cerr<<"a is a nullptr";
        exit(1);
    }
    
    if (length<=0)
    {
        std::cerr<<"length is not positive";
        exit(1);
        
    }
    
    int sum=0;
    int max = INT_MIN;
    
    for (int i=0;i<length;++i)
    {
        if (sum>0)
            sum += a[i];
        else
            sum = a[i];
        
        max = std::max(sum,max);
    }
    
    return max;
        
    
}

#endif /* findGreatesrSum_h */
