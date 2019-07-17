//
//  fibonacci.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/25.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef fibonacci_h
#define fibonacci_h


/*
 目标：返回fibonacci数列的第n项
 输入：n
 n=0时：返回0
 n=1时：返回1
 否则：返回f(n-1) + f(n-2)
 */

/*
 递归实现：重复计算，效率低
 */
int fibonacci1(int n)
{
    
    if (n<0)
    {
        std::cerr<<"n must be equal or larger than 0 !\n";
        exit(1);
    }
    
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
    {
        return fibonacci1(n-1) + fibonacci1(n-2);
    }
    
}


/*
 用一个数组存储结果，用循环实现，避免重复计算
 但是该方式需要维护一个长度为n的数组
 */

int fibonacci2(int n)
{
    if (n<0)
    {
        std::cerr<<"n must be equal or larger than 0 !\n";
        exit(1);
    }
    
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    
    else
    {
        int a[n];
        a[0] = 0;
        a[1] = 1;
        
        for (int i=2; i<n; ++i)
            a[i] = a[i-1]+a[i-2];
        
        return a[n-1] + a[n-2];
    }
    
    
}


/*
 其实我们需要的只是n-1和n-2.不用保存之前所有结果
 */
int fibonacci3(int n)
{
    if (n<0)
    {
        std::cerr<<"n must be equal or larger than 0 !\n";
        exit(1);
    }
    
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
    {
        int n_2 = 0;
        int n_1 = 1;
        int temp = 0;
        
        for (int i=2;i<n;++i)
        {
            temp = n_1;
            n_1 = n_2 + n_1;
            n_2 = temp;
        }
        return n_2 + n_1;
    }
    
}

/*
fibonacci数列的应用：
 上台阶问题：
 一次上1级或者2级
 一共有n级台阶
 几种上法
 */

/*
 当n>2时，若第一次上1级，则有f(n-1)中方法，若第一次上2级
 则有f(n-2)种方法
 也就是f(n) = f(n-1) + f(n-2)
 即fibonacci数列
 */

int stepJump(int n)
{
    if (n<0)
    {
        std::cerr<<"n must be equal or larger than 0 !\n";
        exit(1);
    }
    
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else if (n==2)
        return 2;
    else
    {
        int temp = 0;
        int n_1 = 1;
        int n_2 = 2;
        
        for (int i=3;i<n;++i)
        {
            temp = n_1;
            n_1 = n_1 + n_2;
            n_2 = temp;
        }
        
        return n_1 + n_2;
    }
}

#endif /* fibonacci_h */
