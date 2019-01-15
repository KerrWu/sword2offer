//
//  streamMedian.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/15.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef streamMedian_h
#define streamMedian_h


#include <vector>
#include <istream>
#include <algorithm>
#include <functional>

using std::istream;
using std::vector;
using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::greater;
using std::less;
/*
 目标：给定一个数据流，求该流中数字的中位数
 */

/*
 思路:
 如果数据是从大到小排列的，那么：
 如果有奇数个数字，则中间的数字即为中位数
 如果有偶数个数字，则中间两个数字的均值为中位数
 
 如果维护一个有序数组，则每输入一个数字，都需要对数组进行排序
 如果用vector维护，插入操作的复杂度为O(n)，获取中位数的操作只需O(1)
 如果是用链表实现该数组，插入复杂度也为O(n)，且在实现一个指向中位数节点的指针的条件下，能实现O(1)获取中位数
 
 实际上需要的只是中间元素或者中间两个元素在对应位置，其余元素是否有序并不关心
 或者说需要两个元素，左边的是左边数组的最大值，右边的是右边数组的最小值
 可以实现两个堆
 两个堆的数目不能相差超过1
 左边元素用最大堆，可以随时获取最大值
 右边用最小堆，可以随时获取最小值
 保证最大堆中的所有数字小于最小堆
 这样可以以O(logk)实现插入，且以O(1)实现查找中位数
 (也可以用平衡BST，如RBT实现的set，左边用greater，右边用less，同样可以实现O(logk)插入，O(1)查找中位数)
 
 每次新加入元素时，判断左右两个堆的size大小
 如果相等，则插入左边
    如果大于左边的最大值，
 如果不等，必为右边小，插入右边
 并更新堆结构
 
 在获取中位数时，先判断两边的堆的大小
 如果相等，则元素为偶数个，最大堆的最大值和最小堆的最小值取平均
 如果不等，肯定是左边多，中位数为左边的最大堆的最大值
 */

struct getStreamMedian
{
  
    vector<int> maxHeap;
    vector<int> minHeap;
    
    void insert(int num)
    {
        //如果两个堆为空，则新元素应插入堆中,先左后右
        if (maxHeap.size()==0)
        {
            maxHeap.push_back(num);
            return;
        }
        
        if (minHeap.size()==0)
        {
            minHeap.push_back(num);
            return;
            
        }
            
        
        
        //如果两边size相等，则新元素应插入左边，此时需要判断
        //如果该元素小于右边最小值，直接插入左边
        //如果该元素大于右边最小值，则最小值出堆加入左边，该数字进入右边
        //如此一来保证左边+1元素，右边元素个数不变
        if (maxHeap.size() == minHeap.size())
        {
            if ( num <= *( minHeap.begin() ) )
                {
                    maxHeap.push_back(num);
                    push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                }
            else
                {
                    maxHeap.push_back( *(minHeap.begin()) );
                    push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                    
                    pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                    minHeap.pop_back();
                    
                    minHeap.push_back( num );
                    push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                }
        }
        
        //如果两边元素不等，则一定是左边元素多，新元素应插入右边
        //如果新元素大于左边最大值，则直接插入右边
        //如果小雨左边最大值，则左边最大值出堆并加入右边，该数字进入左边
        //保证左边元素个数不变，右边+1
        else
        {
            if (num >= *(maxHeap.begin()))
            {
                minHeap.push_back(num);
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
            }
            else
            {
                minHeap.push_back( *(maxHeap.begin()) );
                push_heap(minHeap.begin(), minHeap.end(), greater<int>());
                
                pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
                maxHeap.pop_back();
                
                maxHeap.push_back( num );
                push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
            }
        }
        
        return;
    }
    
    float getMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return (*(maxHeap.begin())+*(minHeap.begin()))/2.0;
        
        else
            return *(maxHeap.begin());
    }
    
    
};
#endif /* streamMedian_h */
