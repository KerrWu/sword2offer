//
//  numberOf1.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/16.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef numberOf1_h
#define numberOf1_h

#include <string>

/*
 目标：输入一个整数n，求1-n中1出现的次数，如输入11，则出现1的数字有1，10，11，共4个1
 */
/*
 思路：将数字转换为单个字符，再看每个字符是否为1
 对每个数字都要判断其每一位数字
 n有O(logn)位，故时间复杂度为O(nlogn)
 */

int numberof1_1(int n)
{
    
    if (n==0)
        return 0;
    
    int sum = 0;
    
    for (int i=1; i<=n; ++i)
    {
        std::string si = std::to_string(i);
        
        for(auto& elem:si)
            if (elem=='1')
                ++sum;
    }
    
    return sum;
}


/*
输入一个数字n，判断其二进制表示中1的个数
 
 将n与1求&，若为1，则该位为1，再将1左移，判断下一位，直到1左移32位后为0，停止
 复杂度为O(32)=O(1)
 */

int numberOf1(int n)
{
    int flag=1;
    int count=0;
    
    while(flag)
    {
        if (n & flag)
            ++count;
        flag = flag<<1;
    }
    
    return count;
    
    
}


/*
 解法2:n-1与n进行位与运算，即可将n的最后一个非零位置0，n有多少个非零位，就可进行多少次该操作
 因此不断对n进行该操作，直到n变为0，即为n的非零位个数
 */

int numberOf1_2(int n)
{
    int count=0;
    
    while (n)
    {
        n = n & (n-1);
        ++count;
    }
    return count;
}

#endif /* numberOf1_h */
