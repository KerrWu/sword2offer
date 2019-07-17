//
//  printOneToMax.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/27.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef printOneToMax_h
#define printOneToMax_h


#include <stdio.h>
#include <iostream>
/*
 目标：打印1到max
 比如输入为3
 则打印1-999
 */

/*
 不考虑大数情况
 */
void printOne2Max(int k)
{
    if (k<0)
        exit(1);
    
    if (k==0)
        std::cout<<0<<std::endl;
    
    
    int max=1;
    while(k>0)
        max *= 10;
    
    for (int i=1; i<max; ++i)
    {
        std::cout<<i<<std::endl;
    }
}


/*
 考虑大数情况
 用字符串表示数字
 即用一个字符串模拟1-max的加法
 1. 先确定位数,每一位初始化为'0'
 2. 用字符串完成加法，某一位尝试+1；若发生进位，则该为置0，flag变为1，下一位再尝试+1，若最高位发生进位，则stop，退出循环
 */

void printOne2Max2(int k)
{
    char a[k+1];
    for (int i=0; i<k; ++i)
        a[i] = '0';
    a[k] = '\0';
    
    
    int flag=1;
    bool stop=false;
    
    while(!stop)
    {

        for (int i=k-1; i>=0; --i)
        {
            int curNum = a[i] - '0' + flag;
            
            if (curNum>=10)
            {
                if (i==0)
                {
                    stop=true;
                    break;
                }
                else
                {
                    a[i] = '0';
                }
            }
            
            else
            {
                a[i] = '0' + curNum;
                std::cout<<a<<std::endl;
                break;
            }
            
        }
        
        
    }
    
}








/*
 字符数组所表示的大数+1函数，返回一个stop，若最高位进位，则返回true，否则返回false
 进行加法时，两个字符相减的结果就是ascii码的差，若发生进位则向前继续，当前位置0，若没发生则保存当前值并退出
 */
bool increment(char *number)
{
    bool stop = false;
    int flag = 0;
    int length = int(strlen(number));
    
    for (int i=length-1; i>=0; --i)
    {
        int curNum = number[i] - '0' + flag;
        
        if (i==length-1)
            ++curNum;
        
        if (curNum>=10)
        {
            if (i==0)
                stop=true;
            else
            {
                flag = 1;
                curNum -= 10;
                number[i] = '0' + curNum;
            }
        }
        else
        {
            flag = 0;
            number[i] = '0' + curNum;
            break;
        }
        
    }
    
    return stop;
}

/*
 打印一个字符数组
 */
void printNumber(char *number)
{
    std::string curNumber = "";
    
    while (*number == '0')
        ++number;
    
    while(*number != '\0')
    {
        curNumber += *number;
        ++number;
    }
    
    std::cout<<curNumber<<std::endl;
}

/*
 思路：
 未给出上限，故不能直接打印，应想到如何表示大数
 可以用字符串表示数字，并设置一个进位flag表示最高位是否进位，即是否停止
 每次incrment 1，如果!flag为true，则打印，如果为false，则说明停止
 */

void printOneToMax(int n)
{
    
    if (n<=0)
        return;
    
    //初始化部分，定义一块动态内存存放字符串，用于表示大数
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    
    while(!increment(number))
    {
        printNumber(number);
    }
    
    delete [] number;
}

#endif /* printOneToMax_h */
