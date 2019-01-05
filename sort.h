//
//  sort.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/25.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <cassert>
/*
 输入一个数组，及其待排序首位元素及末尾元素，对区间内元素从小到大进行排序
 */

/*
 思路1:
 快速排序
 步骤：
 设定一个首指针和尾指针，
 先令首指针对应元素为pivot元素
 从尾指针开始向前与pivot比较，若小于pivot，则首指针元素变为该元素（pivot仍然为原来的不变）
 再从首指针开始向前与pivot比较，若大于pivot，则尾指针元素变为该元素
 重复直到两指针相遇则停止
 停止时将pivot插入到重合位置
 完成一次排序，
 此时左边都是比pivot小的元素，右边都是比pivot大的元素
 然后再对左右两个子数组做同样操作
 */
int findPivot(int a[], int low, int high)
{
    int head = low;
    int tail = high;
    int base = a[head];
    
    while (head < tail)
    {
        while (a[tail]>=base && head<tail)
            --tail;
        
        if (a[tail]<base)
            a[head] = a[tail];
        
        else
        {
            a[tail] = base;
            return tail;
        }
        
        
        while(a[head]<=base && head<tail)
            ++head;
        
        if (a[head]>base)
            a[tail] = a[head];
        else
        {
            a[head] = base;
            return tail;
        }
    }
    
    return -1;

}

void quickSort(int a[], int low, int high)
{
    if (a==nullptr)
    {
        std::cerr<<"input array is nullptr \n";
        exit(1);
    }
    
    if (low>=high)
        return;
    
    int pivot = findPivot(a, low, high);
    
    assert(pivot>=0);
    quickSort(a, low, pivot-1);
    quickSort(a, pivot+1, high);
   
}

#endif /* sort_h */
