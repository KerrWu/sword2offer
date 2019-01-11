//
//  permutation.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/12.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef permutation_h
#define permutation_h

/*
 目标：输入一个字符数组，打印其全排列
 如输入abc，打印abc,acb,bac,bca,cab,cba
 */

/*
 思路：
 此题应该将其分解为小问题通过递归解决
 对每个字符串，看作首元素一个字符和之后的一个子串
 其中首元素可以为其中任意一个元素
 
 以一个指针pst指向数组的首元素
 另一个指针pbegin指向当前的输入排列组的子串首元素

 将字符串操作分为三步进行：
 将字符串分为两部分，第一部分是第一个字符；另外一部分是后面的字符串；每次循环将第一个字符与后面的每个字符进行交换；
 对后一部分字符串，视为当前字符串，进行前面同样的操作；
 子字符串操作完成后，需要恢复第一个位置的原本字符。
 例子：如“abcd”，a和b交换后，成为“bacd”;当后面的3个字符的子字符串操作完成后，需要对‘a’和‘c’进行交换，但是当前是“bacd”；所以需要再交换回来成为“abcd”，再进行交换及后面子字符串的操作。

 */

void permutation(char* pst, char* pbegin)
{
    //如果pbegin是\0，说明子串为空了，当前排列组完成，输出当前排列组
    if (*pbegin == '\0')
        std::cout<<pst<<std::endl;
    
    for(char* pcn=pbegin; *pcn != '\0'; ++pcn)
    {
        //交换首元素与pcn的值
        char temp = *pcn;
        *pcn = *pbegin;
        *pbegin = temp;
        
        permutation(pst, pbegin+1);
        
        //完成输出后需要恢复原排序
        *pbegin = *pcn;
        *pcn = temp;
    }
    
    return;
}


void permutation(char* ptr)
{
    if (ptr == nullptr)
        return;
    permutation(ptr, ptr);
}

#endif /* permutation_h */
