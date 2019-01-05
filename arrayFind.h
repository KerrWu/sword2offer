//
//  arrayFind.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/20.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef arrayFind_h
#define arrayFind_h

/*
 目标； 在二维数组中查找某个整数
 行为从左至右递增
 列为从上至下递增
 
 输入：二维数组，row, col, 目标整数
 输出：0-未找到， 1-找到
 */


/*
 思路1:
 
 从左上角开始，比较整数与头尾，若小于头，则该行以及该行以下都不用比较，直接返回
 若大于尾，则该行不用比较，直接进入下一行
 
 复杂度为o(n)
 */

//a为静态数组
int arrayFind(int **a, int row, int col, int obj)
{
    int i=0, j=0;
    for (; i<row; ++i)
    {
        //a[i][j] = *((int*)a + col*i + j)
        if (*((int*)a + col*i + j) > obj)
            return 0;
        
        //a[i][col-1] = *((int*)a + col*i + col-1)
        if (*((int*)a + col*i + col-1) < obj)
            continue;
        
        for (; j<col; ++j)
        {
            if (*((int*)a + col*i + j) == obj)
                return 1;
            
        }
        
        j=0;
    }
    
    return 0;
    
}

//a为动态数组
int arrayFind2(int **a, int row, int col, int obj)
{
    int i=0, j=0;
    for (; i<row; ++i)
    {
        if (a[i][j] > obj)
            return 0;
        
        if (a[i][col-1] < obj)
            continue;
        
        for (; j<col; ++j)
        {
            if (a[i][j] == obj)
                return 1;
            
        }
        
        j=0;
    }
    
    return 0;
    
}


/*
 思路2:
 
 从右上角开始：
 先比较右上角元素与obj是否相等
 相等则返回，若右上角元素更大，则最右一整列可以删除
 若右上角元素小，则最上一行可以删除
 再比较新的右上角元素
 这样每次比较都可以删除一行或者一列
 
 复杂度降低为o(n^(1/2))
 
 */

int arrayFind3(int **a, int row, int col, int obj)
{
    
    int i=0;
    int j=col-1;
    
    while(i<row-1 && j>0)
    {
        if (a[i][j] == obj)
            return 1;
        
        else if (a[i][j] > obj)
            --j;
        
        else
            ++i;
    }
    
    //说明j=0，则对比第一列剩下的
    if (i < row-1)
    {
        while (i<row-1)
        {
            if (a[i][0]==obj)
                return 1;
            ++i;
        }
    }
    
    //说明i=row-1， 则对比最后一行剩下的
    if (j>0)
    {
        while (j>0)
        {
            if (a[row-1][j]==obj)
                return 1;
            --j;
        }
    }
    
    
    return 0;
    
}


#endif /* arrayFind_h */
