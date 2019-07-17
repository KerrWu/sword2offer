//
//  power.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/2/12.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef power_h
#define power_h


/*
 实现函数power，求base的exp次方
 不考虑大数问题
 */
/*
 实现简单，但是需要考虑不同情况
 1. exp为大于1的正数
 2. exp为0或负数，这两种都要讨论base为0时的情况
    exp=0时，需讨论0^0 为0还是1
    exp为负数时，需要求倒数，此时需要对底数是否为0进行讨论
 */


double power(double base, int exp)
{
    
    if (exp>=1)
    {
        double result=1.0;
        
        while(exp>0)
        {
            result *= base;
            --exp;
        }
        
        return result;
    }
    
    else if (exp==0)
    {
        if (base==0)
            return 0.0;
        else
            return 1.0;
    }
    
    else
    {
        if (base==0)
            return 0.0;
        
        else
        {
            exp = (-1)*exp;
            
            double result=1.0;
            
            while(exp>0)
            {
                result *= base;
                --exp;
            }
            
            result = 1.0/result;
            
            return result;
        }
    }
    
    
}

#endif /* power_h */
