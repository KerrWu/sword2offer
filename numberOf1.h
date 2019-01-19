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
 思路2:从数字规律出发
 */


#endif /* numberOf1_h */
