//
//  moreThanHalfNum.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/14.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef moreThanHalfNum_h
#define moreThanHalfNum_h


/*
 给出一个数组a，该数组中有一个数的个数超过数组长度的一半，找到该数字
 
 测试用例：
 输入数组为空
 输入数组的length为<=0;
 */

/*
 思路：超过一半，则该数比其他所有元素个数加起来还多
 因此维护两个变量：cur和num
 如果a[i+1] == a[i]
 则num+=1
 否则
    如果num>1:
    num-=1
    如果num==1:
    num = 1
    cur=a[i+1]
 
 相当于用最多元素的个数减去其余元素的个数，由于超过一半，因此cur留下的总会是那个超过一半的元素
 */

int moreThanHalfNum(int *a, int length)
{
    if (a == nullptr)
    {
        std::cerr<<"input must be an array, not a nullptr!";
        exit(1);
    }
    
    if (length <= 0)
    {
        std::cerr<<"length must bigger than 0!";
        exit(1);
    }
    
    
    if (length==1)
        return a[0];
    
    int cur=a[0];
    int num=1;
    
    for(int i=1; i<length; ++i)
    {
        if (cur==a[i])
            ++num;
        else
        {
            if (num>1)
                --num;
            else
            {
                cur = a[i];
                num=1;
            }
        }
    }
    
    return cur;
    
}




#endif /* moreThanHalfNum_h */
