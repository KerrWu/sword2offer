//
//  findRepeat.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/19.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef findRepeat_h
#define findRepeat_h
/*
 目标，输入一个长度为n的数组a，其中元素值为0 - n-1，返回数组中某个重复出现的数字
 */

/*
 思路1:将长度为n的数组排序，再遍历数组，与前一个相同则为重复
 复杂度主要为排序复杂度，长度为n的数组排序复杂度为o(nlogn)
 */

/*
 思路2：
 输入：指向数组的指针
 输出：重复的数字,若无重复数字，返回-1，若错误，返回-2
 
 构建一个长度同样为n的数组b，另其中所有元素为0
 遍历数组a，若出现某个数k，则b[k]+=1
 则遍历时若b[k]!=0,返回k
 
 该方法复杂度为o(n),但是需要构建一个空间复杂度为o(n)的hash table
 */

int findRepeat1(int a[], const int length)
{
    int *b = new int[length];
    
    int elem;
    
    for (int i=0; i<length; ++i)
    {
        elem = a[i];
        if (b[elem] != 0)
        {
            delete [] b;
            return elem;
            
        }
        
        else
            b[elem] += 1;
    }
    delete [] b;
    return -1;
        
}


/*
 思路3
 
 边排序边找重
 在原数组上操作
 遍历原数组，如到第k个元素时，元素值为m
 先比较m是否等于k，
 如果是
    则进入下一个数字
 如果不是
     则比较m与a[m],若两者相等，则找到重复，返回m
     否则交换a[k]与a[m]，即m在a[m]上，继续在a[k]上重复此步骤(因为这样一个数组，若无重复数字，则a[m]=m)
 若遍历完整个数组，则返回-1
 */


int findRepeat2(int a[], int length)
{
    int temp;
    
    if (a == nullptr)
        return -1;
    
    
    
    for (int i=0; i<length;)
    {
        if (a[i] == i)
        {
            ++i;
            continue;
        }
        
        else
        {
            if (a[i]>=length)
                return -2;
            
            if (a[i] == a[a[i]])
                return a[i];
            else
            {
                temp = a[i];
                a[i] = a[a[i]];
                a[a[i]] = temp;
            }
        }
        
        
    }
    return -1;
}


/*
 目标：长度为n+1的数组，其中元素为1 - n  （必有元素重复） 找出重复元素并返回
 要求：不修改原数组
 
 输入：数组，数组长度
 输出：正常时输出重复元素，异常则输出-1
 
 */

/*
 思路1：
 类似上面，构建一个辅助数组
 需要o(n)的空间复杂度
 */

int findRepeat3(int a[], int length)
{
    int *b = new int[length];
    
    for (int i=0; i<length; ++i)
    {
        
        if (b[a[i]] != 0)
        {
            delete [] b;
            return a[i];
        }
        
        
        else
            b[a[i]] += 1;
    }
    
    delete [] b;
    return -1;

}


/*
 构建hash table需要的空间复杂度为O(n),时间复杂度也为O(n)
 */
int findRepeatNumber(int* a, int length)
{
    if (a==nullptr)
    {
        std::cerr<<"a is a nullptr";
        exit(-1);
    }
    
    int* temp = new int[length];
    
    for (int i=0;i<length;++i)
        temp[i] = 0;
    
    for (int i=0;i<length; ++i)
    {
        if (temp[a[i]]==0)
            ++temp[a[i]];
        else
        {
            delete [] temp;
            return a[i];
        }
        
    }
    
    delete [] temp;
    return -1;
    
}


//边排序边找重
int findRepeatNumber2(int a[], int length)
{
    int temp;
    
    for (int i=0;i<length;)
    {
        if (a[i]==i)
            ++i;
        else
        {
            if (a[i] == a[a[i]])
                return a[i];
            else
            {
                temp = a[a[i]];
                a[a[i]] = a[i];
                a[i] = temp;
            }

        }
    }
    
    return -1;
}


#endif /* findRepeat_h */
