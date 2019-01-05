//
//  main.cpp
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/18.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ListNode* head =  nullptr;
    ListNode** pToHead = &head;
    addToTail(pToHead, 1);
    addToTail(pToHead, 2);
    addToTail(pToHead, 3);
    addToTail(pToHead, 4);
    addToTail(pToHead, 5);
    addToTail(pToHead, 6);
    addToTail(pToHead, 7);
    addToTail(pToHead, 8);
    head->next->next->next->next->next = head->next->next;
    
    ListNode* entrance = findEntrance(head);
    
    if (entrance==nullptr)
        cout<<"not find"<<endl;
    else
        cout<<entrance->value<<endl;

}
