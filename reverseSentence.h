//
//  reverseSentence.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/19.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef reverseSentence_h
#define reverseSentence_h



/*
 目标： 反转一个句子中单词的顺序，但是单词的字符不变
 即 "i have a pen." -> "pen. a have i"
 */

/*
 思路：
 先翻转整个字符串，再将每个单词转回来
 "i have a pen." -> ".nep a evah i" -> "pen. a have i"
 
 先实现一个辅助函数，给出头尾指针，翻转范围内字符串
 */

void reverse(char* head, char* tail)
{
    if (head == nullptr || tail == nullptr)
        return;
    
    while (head < tail)
    {
        char temp = *head;
        *head = *tail;
        *tail = temp;
        ++head;
        --tail;
    }
    
}

void reverSentence(char* a)
{
    if (a == nullptr)
        return;
    
    char* head = a;
    char* tail = a;
    
    while (*tail != '\0')
        ++tail;
    
    --tail;
    
    reverse(head, tail);
    
    
    head = tail = a;
    while (*head != '\0')
    {
        if (*head == ' ')
        {
            ++head;
            ++tail;
        }
        
        else if (*tail == ' ' || *tail == '\0')
        {
            reverse(head, --tail);
            head = ++tail;
        }
        else
            ++tail;
            
    }
        
}




#endif /* reverseSentence_h */
