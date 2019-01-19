//
//  longestSubString.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/17.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef longestSubString_h
#define longestSubString_h

#include <algorithm>
/*
 目标：给出一个只包含‘a’ - ‘z’的字符串
 输出其不包含重复字符的最长子串的长度
 */

/*
 思路：、
 从k=0开始
 f(k)表示以第k个字符s[k]结尾的字符串的最长不重复子串长度
 则如果s[k]还未出现过，则f(k) = f(k-1) + 1
 如果s[k]出现过，则定位到其上次出现的位置并求得距离d
    如果的d<=f(k-1)，则说明s[k]之前出现的地方在f(k-1)的最长不重复子串内部，此时f(k)应=d
    如果d>f(k-1)，说明s[k]之前出现在f(k-1)的最长不重复子串外部，则此时f(k)=f(k-1) + 1
 
 如何判断s[k]是否出现过？
 以一个容量为26的hash表统计每个字符最新一次出现的下标，未出现时记为-1
 */
int longestSubString(const std::string& s)
{
    int length = s.size();
    
    if (length==1)
        return 1;
    
    int temp[26];
    
    for (int i=0;i<26;++i)
        temp[i] = -1;
        
    int curLength = 0;
    int maxLength = 0;
    
    for (int i=0;i<length;++i)
    {
        int curCharIndex = s[i] - 'a';
        
        if ( temp[curCharIndex]<0 || i-temp[curCharIndex]>curLength)
        {
            ++curLength;
            maxLength = std::max(maxLength, curLength);
            temp[curCharIndex] = i;
        }
        
        else
        {
            curLength = i-temp[curCharIndex];
            temp[curCharIndex] = i;
        }
        
    }
    
    return maxLength;
}



#endif /* longestSubString_h */
