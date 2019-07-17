//
//  singleton.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/18.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//



#ifndef singleton_h
#define singleton_h


/*
 定义一个singleton类
 方法是将其构造函数定义为private，这样就无法从外部创建实例
 再定义一个内部方法，在不存在实例的时候返回一个实例
 */

#include <iostream>
#include <mutex>



/*
 方式1:
 在内部定义一个private的singleton的静态实例，令其为空，
 再定义一个public的create方法，如果静态实例为空，则创建一个实例，返回之
 否则返回空
 
 但该方式不是多线程安全的
 如果多个线程同时访问s，此时s都为nullptr，则会创建多个实例
 */
struct singleton1
{
    int attr;
private:
    singleton1(): attr(1) {}
    static singleton1* s;
    
public:
    static singleton1* create()
    {
        if (s==nullptr)
        {
            s = new singleton1();  //注意这里要用动态内存创建，而不能创建一个局部变量
            return s;
        }
        
        else
        {
            std::cerr<<"instance already exist.\n";
            exit(1);
            //return nullptr;
        }
        
    }
};
singleton1* singleton1::s = nullptr;




/*
 方式2:
 在方式1的基础上加入互斥锁实现线程安全
 */

struct singleton2
{
    int attr;
    
private:
    singleton2():attr(2) {}
    static singleton2* s;
    static std::mutex sMutex;
    
public:
    static singleton2* create()
    {
        if (s==nullptr)
        {
            sMutex.lock();
            s = new singleton2();
            sMutex.unlock();
            return s;
        }
        else
        {
            std::cerr<<"instance already exist.\n";
            exit(1);
        }
        
    }
};
singleton2* singleton2::s = nullptr;
std::mutex singleton2::sMutex;


//上面的实现问题在于lock的时候可能不同线程的程序都已经进入if语句块中，相当于没用多线程，故进入if后还要再判断一次，如下所示


struct mySingle
{
    static int exist;
    static std::mutex myMutex;
    
    
private:
    mySingle(){}
    
public:
    static mySingle* create()
    {
        if (mySingle::exist==0)
        {
            mySingle::myMutex.lock();
            if (mySingle::exist==0)
            {
                mySingle::exist=1;
                myMutex.unlock();
                return new mySingle();
            }
            else
            {
                std::cerr<<"instance already exist\n";
                exit(0);
            }
        }
        else
        {
            std::cerr<<"instance already exist\n";
            exit(0);
        }
    }
};
int mySingle::exist=0;
std::mutex mySingle::myMutex;






















#endif
