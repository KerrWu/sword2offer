//
//  maxDiff.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/22.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef maxDiff_h
#define maxDiff_h


/*
 目标：给出股票序列，求最大利润可能值
 */

/*
 如果比较所有数与其后面的数的价格差，则复杂度为O(n^2)
 
 可以维护一个当前买入价格最小值priceMin和利润最大值profitMax，从前开始遍历
 遇到一个数，先计算和priceMin的差，即当前profit
 如果大于profitMax,则更新profitMax
 否则：如果当前价格小于priceMin，则更新priceMin
 该思路复杂度为O(n),且空间复杂度为O(1)
 */

#endif /* maxDiff_h */
