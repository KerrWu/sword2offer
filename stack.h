//
//  stack.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/2/10.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <vector>

using std::vector;
/*
 目标：用两个栈实现队列
 实现两个功能：
 appendTail
 deleteHead
 */

/*
 将两个栈a，b视为一个队列
 a正常入栈，当a中元素超过一定数目或b为空时，将a中元素依次入栈b中
 这样先进入a中的元素就会后进入b中
 
 当元素需要入队列时，正常进入a，表示进入队列尾部
 当元素需要出队列时，从b中出，表示从队首出队
 */

struct stackAsArray
{
    vector<int> a;
    vector<int> b;
    
    void appendTail(int elem);
    void deleteHead();
};

void stackAsArray::appendTail(int elem)
{
    a.push_back(elem);
    
}

void stackAsArray::deleteHead()
{
    if (b.empty())
    {
        if (a.empty())
        {
            std::cerr<<"array is empty";
            exit(1);
        }
        
        while(!a.empty())
        {
            b.push_back(a.back());
            a.pop_back();
        }
    }
    
    b.pop_back();
}






#endif /* stack_h */
