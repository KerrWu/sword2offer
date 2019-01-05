//
//  binary.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/26.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef binary_h
#define binary_h


#include <cstdlib>

/*
 目标：输入一个整数，返回其二进制中1的个数
 */

/*
 思路1:从最右边开始处理，记录最右边是否为1，记录完毕后右移1位
 但是由于对于负数右移是将1右移，故该函数无法处理负数
 */

int numberOf1(int n)
{
    
    int count=0;
    
    while(n != 0)
    {
        if ((n & 1) > 0)
            ++count;
        n = n >> 1;
    }
    
    return count;
}

/*
 思路2:
 从最右边开始与1做与运算，记录最低位是否为1
 接着将1左移一位，将结果再做与运算，可得次低位是否为1。。。。
 位移总次数为整型变量位数
 */
int numberOf1_2(int n)
{
    int count=0;
    unsigned int musk = 1;
    
    while(musk)
    {
        if (n & musk)
            ++count;
        musk = musk << 1;
        
    }
    
    return count;
}


/*
 思路3：
 一个数n，将其-1，如果最后一位为1，则最后一位变成0
 如果倒数第m位为1，则第m位变为0，且第m位至最后1位都变为1 （这些位原本都是0）
 如果将n与（n-1）做与运算,相当于将第m位置0，且保持m之前的位置都为0，则能做几次，说明n中有几个1，直到n=0时，
 */

int numberOf1_3(int n)
{
    int count = 0;
    
    while (n)
    {
        count +=1;
        n = n & (n-1);
    }
    
    return count;
}


#endif /* binary_h */
