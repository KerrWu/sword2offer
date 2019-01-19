//
//  inversePairs.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/19.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef inversePairs_h
#define inversePairs_h



/*
 目标：输入一个数组，输出其逆序对的总数
 */

/*
 逆序对即前面的数比后面的数大的一个数对
 可以视为
 从第二个数开始，求位于每个数前面的数中，大于该数的元素个数
 如果用暴力统计法的话，复杂度为O(1+2+3+...n) = O(n^2)
 */

/*
 使用merge sort的思想，在排序的过程中记录逆序对数目
 其中，由于merge sort需要一个O(n)的辅助数组，故这是一个以空间换时间的做法
 为了统计逆序对个数，需要对mergesort做一定改变，即从后往前对比两个子数组，
 原本的mergesort的辅助数组为前面的子数组
 现在：
 如果前面子数组剩余的最后一个值的比后面子数组剩余的最后一个值大，则count加上后面子数组的剩余元素个数
 此时辅助数组表示后面的子数组
 */

void merge(int *a, int low, int mid, int high, int& count)
{
    int length = high - mid;
    
    int temp[length];
    
    for (int t=0;t<length;++t)
        temp[t] = a[mid+t];
    
    // k is index for a-pre, i is index for temp, j is index for a-post
    int k = mid-1;
    int i = length-1;
    int j = high-1;
    
    while( k>=low && i>=0)
    {
        if (a[k] > temp[i])
        {
            a[j] = a[k];
            count += i;
            --k;
        }
        
        else
        {
            a[j] = temp[i];
            --i;
        }
        
        --j;
    }
    
    while (k>=low)
    {
        a[j] = a[k];
        --k;
        --j;
    }
    
    
    while(i>=0)
    {
        a[j] = temp[i];
        --i;
        --j;
        count += (mid-low);
    }
    
    return;
    
    
}

void mergeSort(int *a, int low, int high, int& count)
{
    
    if (high-low < 2)
        return;
    int mid = (low+high) / 2;
    
    mergeSort(a, low, mid, count);
    mergeSort(a, mid, high, count);
    
    merge(a, low, mid, high, count);
    return;
    
}


int inversePairs(int *a, int length)
{
    if (a == nullptr)
    {
        std::cerr<<"a is a nullptr";
        exit(1);
    }
    
    int count = 0;
    mergeSort(a, 0, length, count);
    
    return count;
    
}



#endif /* inversePairs_h */
