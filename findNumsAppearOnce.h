//
//  findNumsAppearOnce.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/19.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef findNumsAppearOnce_h
#define findNumsAppearOnce_h

/*
 目标：给出一个数组，其中除了两个元素以外，其余元素都出现两次，返回这两个元素
 */

/*
 思路：如果只有一个元素出现一次，那么只需用0对所有元素求亦或即可，因为元素异或0得自己，元素异或自己得0，先实现该函数
 */
int findNumAppearOne(int *a, int length)
{
    
    int temp = 0;
    
    while(length>0)
        temp ^= a[--length];
    
    return temp;
}

/*
 如果是两个元素出现一次，那么异或整个数组的结果是两个不同的数的异或结果，不为0
 找出其某一个不为0的位，按这个位是否为0将原数组分为两个不同数组，两个元素必定分别在这两个数组中
 再对两个子数组分别用上面定义的辅助函数即可分别找出两个数
 或者找到该位后，仍旧依次遍历数组，如果该数的该位为0，则异或a，否则异或b
 这样就不用创建辅助数组
 需要构建辅助函数1判断某个数的一个不为0的位，这里设置为返回第一个不为0的位
 辅助函数2判断某个数的某一位是否为1
 
 注意：判断一个数n最低位为0/1，只需用(n&1)即可
 */

unsigned int findFirstBit(int num)
{
    int indexBit = 0;
    
    while (((num&1)==0) && (indexBit<8*sizeof(int)))
    {
        num = num>>1;
        ++indexBit;
    }
    
    return indexBit;
}

bool isBit(int num, unsigned int indexBit)
{
    num = num>>indedBit;
    return (num&1);
    
}

void findNumsAppearOnce(int *a, int length, int& n1, int&n2)
{
    int xor1 = 0;
    for (int i=0;i<length;++i)
        xor1 ^= a[i];
    
    int indexBit = findFirstBit(xor1);
    
    int xor2=xor3=0;
    
    for (int i=0;i<length;++i)
    {
        if (isBit(a[i], indexBit))
            xor2 ^= a[i];
        
        else
            xor3 ^= a[i];
    }
    
    n1 = xor2;
    n2 = xor3;

}



#endif /* findNumsAppearOnce_h */
