//
//  reorderOddEven.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/2/13.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef reorderOddEven_h
#define reorderOddEven_h



/*
 输入一个数组，将奇数放置在数组前，偶数放置在数组后
 */

/*
 用两个指针，p1指向奇数，p2指向偶数，保证p1始终在p2后面。p1不断向后，遇到一个奇数，就将p1和p2的元素交换，并将p1后移至下一个奇数，p2后至下一个偶数
 复杂度为o(n)
 */

void reorderOddEven(int* array, int length)
{
    if (array==nullptr)
        return;
    
    int* p1 = array;
    int* p2 = array;
    int* end = array+length;
    
    while(*p1 % 2 == 0 && p1 != end)
        ++p1;
    
    while(*p2 % 2 != 0 && p2 != end)
        ++p2;
    
    while(p1<p2)
        ++p1;
    
    int temp;

    
    while(p1 != end && p2 != end)
    {
        temp = *p2;
        *p2 = *p1;
        *p1 = temp;
        
        while(*p1 % 2 == 0 && p1 != end)
            ++p1;
        
        while(*p2 % 2 != 0 && p2 != end)
            ++p2;
        
        while(p1<p2)
            ++p1;
    }
    
    
}



#endif /* reorderOddEven_h */
