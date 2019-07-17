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

    
    ListNode* head = new ListNode();
    head->value = 0;
    
    head->next = new ListNode();
    head->next->value = 1;
    
    head->next->next = new ListNode();
    head->next->next->value = 2;
    
    head->next->next->next = new ListNode();
    head->next->next->next->value = 3;
    
    
    ListNode* newHead = reverseHead(head);
    
    ListNode* pNewHead = newHead;
    while(pNewHead)
    {
        cout<<pNewHead->value<<endl;
        pNewHead = pNewHead->next;
    }
    
    
    
}
