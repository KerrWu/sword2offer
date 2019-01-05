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

/*
 目标：打印1到max
 比如输入为3
 则打印1-999
 */

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
