//
//  array.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/2/10.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef array_h
#define array_h


#include <vector>

using std::vector;

/*
 用两个队列实现一个栈
 
 思路：
 两个队列a，b
 实现appendTail，deleteTail
 
 入栈时，选择已经有元素的一个队列正常入栈
 出栈时，先将前n-1个元素入到另一个队列，再将第n个元素弹出，即可等效于后进先出
 */

struct arrayAsStack
{
    vector<int> a;
    vector<int> b;
    
    void appendTail(int elem);
    void deleteTail();
    
};

void arrayAsStack::appendTail(int elem)
{
    if (b.empty())
        a.push_back(elem);
    
    else if (a.empty())
        b.push_back(elem);
}


void arrayAsStack::deleteTail()
{
    if (a.empty() && b.empty())
    {
        std::cerr<<"stack is empty";
        exit(1);
    }
    
    if(a.empty())
    {
        while (b.size()>1)
        {
            a.push_back(b.front());
            b.erase(b.begin());
        }
        
        b.erase(b.begin());
        
    }
    
    else if (b.empty())
    {
        while (a.size()>1)
        {
            b.push_back(a.front());
            a.erase(a.begin());
        }
        
        a.erase(a.begin());
        
    }
}



#endif /* array_h */
