//
//  main.cpp
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/18.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#include <iostream>
#include <istream>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include "streamMedian.h"

using namespace std;

void printVector(const vector<int>& v)
{
    for(auto& elem:v)
        cout<<elem<<endl;
}

int main(int argc, const char * argv[]) {
    
    vector<int> myVector = {0,1,2,3,4,5,6,7};
    
    getStreamMedian get = getStreamMedian();
    
    int temp = 0;
    
    while (cin>>temp)
        get.insert(temp);
    
    cout<<get.getMedian()<<endl;
    
}
