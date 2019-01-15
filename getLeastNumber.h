//
//  getLeastNumber.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/14.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef getLeastNumber_h
#define getLeastNumber_h

#include <set>
#include <vector>
#include <functional>

using std::vector;
using std::multiset;
using std::greater;

/*
 目标：输入一个数组指针a，数组长度length，数字k，以及一个存储k个最小元素的数组的指针b
 按升序返回数组中最小的k的数字
 
 测试用例
 1. 数组指针为空
 2. k>length
 3. k,length中任意一个<=0
 */

/*
 思路1：
 如果可以改变原数组
 先对数组排序，再将前k个元素按顺序复制到b中
 复杂度即排序复杂度O(nlogn)
 */

#include "sort.h"

void getLeastNumber1(int a[], int length, int b[], int k)
{
    mergeSort(a,0,length);
    
    for (int i=0; i<k; ++i)
    {
        b[i] = a[i];
    }
    
    return;
}



/*
 如果不能改变原数组：
 频繁查找并替换最大值的问题需想到用二叉树实现，RBT或者最大堆都可  
 思路2:维护一个长度为k的有序数组b，遍历一遍a，不断用a中元素替换b中元素的最大值，最终输出b
 此时复杂度为O(n*k)，
 如果维护的是一个二叉树，则可以使复杂度变为O(n*logk)

 比如维护一个最大堆，每次在k个元素中查找最大值只需要O(1)，而插入、删除一个元素需要O(logk)
 或者维护一个红黑树，查找、删除、插入都是O(logk)
 
 但是从头实现一个红黑树太麻烦，STL中的set和multiset都是基于红黑树实现的，可以直接用STL
 */

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIter;

/*
 data是传入的数组，不能改变，因此用传常量引用
 leastNumber是用于维护k个最小元素的容器，这里用multiset实现，在外部定义并传入引用
 该实现不需存储data中数据，只是每次读入一个，适合海量数据问题
 */
void getLeastNumber(const vector<int>& data, intSet& leastNumber, int k)
{
    
    leastNumber.clear();
    
    if (k<1 || data.size()<k)
        return;
    
    vector<int>::const_iterator iter = data.begin();
    
    for(; iter!=data.end(); ++iter)
    {
        //如果容器中元素不足k个，则直接插入
        if (leastNumber.size()<k)
            leastNumber.insert(*iter);
        //否则需要判断
        else
        {
            setIter iter2 = leastNumber.begin();
            if (*iter < *iter2)
            {
                leastNumber.erase(iter2);
                leastNumber.insert(*iter);
            }
        }
    }
}

#endif /* getLeastNumber_h */





