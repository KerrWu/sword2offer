//
//  replaceSpace.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/20.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef replaceSpace_h
#define replaceSpace_h


/*
 目标： 输入一个字符串，将输入字符串中的空格都替换为%20
 
 输入： 原字符串s, 字符长度length
 输出： void，原地操作
 */

/*
 思路1:
 从头开始遍历， 遇到空格，将其后的字符串都移动2位地址，并将空格替换为%20
 
 复杂度 o(n^2)
 */

void replaceSpace(char s[], int length)
{
    int i=0,j=0;
    
    
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            for (j=length-1; j>i; --j)
                s[j+2] = s[j];
            
            length = length + 2;
            s[i] = '%';
            s[i+1] = '2';
            s[i+2] = '0';
            
            i = i+2;
        }
        
        ++i;
    }
    std::cout<<"end"<<std::endl;
}


/*
 思路2:
 先遍历一遍数组，记录空格的个数，设有k个
 再从尾部开始遍历，先将每个元素后移k*2个地址
 每遇见一个空格，将其替换为%20，k=k-1
 
 用两个指针，一个p1指向原字符串末尾，一个p2指向新字符串末尾
 不断将p1上的元素复制到p2
 若p1为空格，则复制%20
 
 若片p1 == p2，则停止复制
 
 这样复杂度为o(n)
 */

void replaceSpace2(char s[], int length)
{
    if (s == nullptr || length<=0)
        return ;
    
    int numberOfSpace=0;
    
    int i=0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
            ++numberOfSpace;
        ++i;
    }
    
    int newLength = length + 2 * numberOfSpace;
    
    int p1 = length;
    int p2 = newLength;
    int j=0;
    while (p1 != p2)
    {
        std::cout<<j++<<std::endl;
        if (s[p1] == ' ')
        {
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
            --p1;
        }
        else
            s[p2--] = s[p1--];

    }
    
}


#endif /* replaceSpace_h */
