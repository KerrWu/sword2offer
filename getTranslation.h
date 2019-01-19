//
//  getTranslation.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/16.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef getTranslation_h
#define getTranslation_h


/*
 目标：给出一个数字，将其翻译为字母序列
 0-a, 1-b,....11-l,25-z
 返回其可能的不同翻译方法个数
 */
/*
 思路：
 显然对于一个数字有不同的翻译方法，如111可以翻译为aaa，al，la
 类似与一次走1步或者走2步的问题 -- 即fibonacci数列
 只是带有约束
 如果连续的2位数字大于25，则只能走分为两步走
 
 用递归求解
 f(n) = f(n-1) + f(n-2)
 会出现重复计算的问题
 如数字12345
 1-2345或12-345
 则345会在两者中出现，如果直接分治会造成重复计算
 
 解决：从左到右转换为从右向左，这样只需计算数字的积
 从最右开始，如果连续两个数字<=25，则sum*=2，向左进两位
 如果>25，则只有一种可能，sum*=1，向左进1位
*/

int getTranslation1(int n)
{
    std::string sn = std::to_string(n);
    int length = sn.size();
    
    if (length <= 1)
        return length;
    
    int sum=1;
    
    for(int i=length-1; i>=0;)
    {
        if (i==0)
        {
            sum+=1;
            break;
        }
        int curNum = (sn[i-1]-'0')*10 + (sn[i]-'0');
        if (curNum<=25)
        {
            sum*=2;
            i-=2;
        }
        else
            --i;
    }
    
    return sum;
}

#endif /* getTranslation_h */
