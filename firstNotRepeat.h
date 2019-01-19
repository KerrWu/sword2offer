//
//  firstNotRepeat.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/17.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef firstNotRepeat_h
#define firstNotRepeat_h



/*
 目标：输入一个字符串，输出第一个只出现一次的字符
 */

/*
 思路：暴力方法为O(n^2)
 
 用hash表，先构建一个26个元素的hash表，每个元素对应-1，表示未出现过，
 遍历这个字符串，对第i个字符，如果其对应元素为-1，则说明没出现过，将该字符位置存入hash表
 如果对应元素不为-1，则表示出现过，则将其元素变为-2
 
 遍历完成后，得到的hash表中， 元素为-1表示没出现过该字符，为-2表示该字符重复
 元素为其余数值表示该元素首次出现的位置，输出其中最小值对应的index即可
 */

/*
 思路2:遍历两次，第一次统计出现的次数，第二次扫描时第一个出现1的就是目标元素
 */
char firstNotRepeat(const std::string& s)
{
    //char为1个字节，8位，256种可能，因此根据ascii表，可以创建一个长度为256的数组作为hash表，key位ascii码
    
    int tempHash[256];
    
    for (int i=0;i<256;++i)
        tempHash[i] = 0;
    
    for (auto& elem:s)
        tempHash[int(elem)] += 1;
    
    for (auto elem:s)
    {
        if (tempHash[int(elem)]==1 )
            return elem;
    }
    
    return '\0';
    
}
#endif /* firstNotRepeat_h */
