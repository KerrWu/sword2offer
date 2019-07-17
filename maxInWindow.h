//
//  maxInWindow.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/22.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef maxInWindow_h
#define maxInWindow_h

/*
 给定一个数组和滑动窗口的大小，返回每个滑动窗口的最大元素
 */

/*
 输入：数组n，滑床大小k
 输出：元素的集合，用vector
 
 如果用暴力方法，对每个滑动窗口进行比较，则复杂度为O((n-(k-1))*k) = O(kn-k^2+k) = O(k*n)
 
 设置一个变量存放当前起始位置begin， 一个存放当前最大元素max，一个存放max的位置p，每次比较时向前进一个新元素i时进以下操作：
 1.begin-1：
 2.如果i小于当前最大值：
    若p>=begin:则最大元素不变，begin
    若p<begin:则最大元素发生改变，则还是要进行比较
 3.如果i大于当前最大值：
    更新max和p
 
 该算法复杂度为最坏时为每次p出窗时，i都更小，此时复杂度为O((n/k)*(k)) = O(n)
 
 如果先排序后进行滑窗口则为O(nlogn)
 */




#endif /* maxInWindow_h */
