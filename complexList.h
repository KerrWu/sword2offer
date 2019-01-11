//
//  complexList.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/10.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef complexList_h
#define complexList_h

#include <unordered_map>

/*
 复杂链表类
 每一个节点除了指向下一个节点，还指向链表中另外一个节点
 */

struct complexListNode
{
    int value;
    complexListNode* next = nullptr;
    complexListNode* sibling = nullptr;
};

void add2Tail(complexListNode** head, int value)
{
    if (*head == nullptr)
    {
        complexListNode* newHead = new complexListNode();
        newHead->value = value;
        *head = newHead;
        return;
    }
    else
    {
        complexListNode* newNode = new complexListNode();
        newNode->value = value;
        
        complexListNode* cur = *head;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        
        cur->next = newNode;
        return;
    }
    
    
}


/*
 目标：复制一个复杂List，返回其head
 */

/*
 思路：如果是普通链表的复制，只需遍历该链表，复制其value，再新建节点加入新链表中即可
 而如果复杂链表这样操作，有两种方式，一种是浅复制，即其中的sibling对象指向原链表中的sibling
 一种是深复制，sibling对象也要是全新的对象
 
 如果要深复制：
 思路1:
 先复制整个链表，不管sibling，全部复制完后，再对每个节点复制sibling
 即对原节点找到其sibling为多少个节点之后获之前的对象，，再在新链表中加入即可
 这样的复杂度为O(n^2)
 
 思路2:
 hash
 对原链表中中每个节点i，其对应的复制节点为ii，将其用<i,ii>这样的hash表存储
 设i对应的sibling为s
 
 这样先不管sibling，复制完整个链表后，对于ii，找到其i，就可找到s，有s就可找到ss，再将ii与ss连接即可
 相当于以空间换时间，时空复杂度都为O(n)
 
 输入：要复制的链表的头节点head
 输出：新链表的头节点newHead
 
 过程：
 1. 判断head是否为空，如果是，直接返回空，如果否，进入2
 2. 创建一个用于存储位置关系的hash table， key为新增节点，value为对应老节点
 3. 创建新头节点newHead，value等于head->value;并将<newHead,head>存入hash table
    在循环外创建头节点，不然在循环中写判断语句更耗时
 4. 创建临时指针temp1，值为head->next, 创建临时指针temp2，其值等于新链表头指针newHead
 5. while(temp1不为空)
        创建新节点cur，cur的值等于temp1当前值
        将<cur, temp1>存入hashtable
        连接上一个节点与新节点，temp2->next=cur
        temp1 = temp1->next
        temp2 = temp2->next
    该循环复杂度为O(n)
 6. 此时新链表除了sibling都创建完毕，开始添加sibling
    创建temp3，其值等于新链表头指针newHead
    while(temp3 != nullptr)
        得到其sibling值为hash table[temp3]->sibling->value
        创建一个新节点curSibling,其value为value
        将temp3->sibling = curSibling
        temp3=temp3->nextl
 7. 返回newHead
 */

complexListNode* clone1(complexListNode* head)
{
    
    if (head == nullptr)
        return nullptr;
    
    std::unordered_map<complexListNode*, complexListNode*> new2old;
    complexListNode* newHead = new complexListNode();
    newHead->value = head->value;
    new2old.insert(std::make_pair(newHead, head));
    
    complexListNode* temp1 = head->next;
    complexListNode* temp2 = newHead;
    complexListNode* temp3 = newHead;
    
    while(temp1 != nullptr)
    {
        complexListNode* curNode = new complexListNode();
        curNode->value = temp1->value;
        new2old.insert(std::make_pair(curNode, temp1));
        temp2->next = curNode;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    while(temp3 != nullptr)
    {
        if (new2old[temp3]->sibling == nullptr)
        {
            temp3 = temp3->next;
            continue;
        }
        
        
        complexListNode* curSib = new complexListNode();
        curSib->value = new2old[temp3]->sibling->value;
        temp3->sibling = curSib;
        temp3 = temp3->next;
    }
    
    return newHead;
    
    
    
}

/*
 clone问题有更优解，不需要额外空间
 思路：
 同样先复制正常链，但是将两个链表合二为一，即
 
 令i->next = ii, ii->next = i+1;
 i+1->next = (i+1)(i+1),
 (i+1)(i+1)->next = i+2......
 
 如此一来，每个节点的next都是其对应的新节点
 而每个新节点对应的sibling就是其上一个节点(即对应老节点)的sibling的next
 
 最后再用一个head取出奇数节点组成原链表，
 另一个newHead取出偶数节点组成新链表即可
 */

complexListNode* clone(complexListNode* head)
{
    if (head == nullptr)
        return nullptr;
    
    complexListNode* temp = head;
    
    while (temp != nullptr)
    {
        complexListNode* curNode = new complexListNode();
        curNode->value = temp->value;
        curNode->next = temp->next;
        temp->next = curNode;
        
        temp = temp->next->next;
    }
    
    complexListNode* temp2 = head;
    while (temp2 != nullptr)
    {
        if (temp2->sibling != nullptr)
        {
            temp2->next->sibling = temp2->sibling->next;
        }
        
        temp2 = temp2->next->next;
    }
    
    complexListNode* newHead = head->next;
    complexListNode* temp3 = head->next->next;
    
    while(temp3!=nullptr)
    {
        head->next = temp3;
        newHead->next = temp3->next;
        temp3 = temp3->next->next;
    }
    
    return newHead;
}

#endif /* complexList_h */
