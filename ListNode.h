//
//  ListNode.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/20.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h


#include <iostream>
#include <stack>


struct ListNode
{
    int value;
    ListNode *next = nullptr;
};

/*
 目标：给列表尾部插入新节点
 
 输入：list的头指针，新节点的值
 输出：无
 
 思路：
 遍历list，直到其next为nullptr为空时，加入新节点
 
 注意，如果输入的头指针为空，说明list中无内容，则新节点就要作为新的头指针
 所以输入要是一个指向头指针的指针，而不是一个头指针
 */

void addToTail(ListNode **head, int newValue)
{
    
    if (*head == nullptr)
    {
        *head = new ListNode();
        (*head)->value = newValue;
    }
    
    else
    {
        ListNode* p2 = *head;
        while (p2->next != nullptr)
            p2 = p2->next;
        
        p2->next = new ListNode();
        (p2->next)->value = newValue;
    }
    
        
    
}


/*
 数组的下标查找操作只要O(1)复杂度，但删除操作要o(n)
 链表则刚好相反，查找某值要o(n)，但删除只要o(1)
 
 目标：删除链表中某个节点
 */

/*
 遍历链表，删除遇到的第一个value等于目标value的节点
 如果head节点即为目标节点，则另head为head->next
 否则，另目标节点的上一个节点连接到目标节点的下一个节点，并delete目标节点
 注意该方法实际复杂度为o(n)，因为需要遍历一次链表找到value对应节点
 */

void removeNode(ListNode **head, int value)
{
    if (*head == nullptr || head == nullptr)
        return;
    
    ListNode* toDelete = nullptr;
    
    if( (*head)->value == value)
        {
            toDelete = *head;
            (*head)= (*head)->next;
        }
    
    else
    {
        ListNode* temp = *head;
        while ( temp->next != nullptr)
        {
            if ( (temp->next)->value == value)
            {
                toDelete = temp->next;
                temp->next =(temp->next)->next;
                break;
            }
            
            else
                temp = temp->next;
        }
    }
    
    if (toDelete != nullptr)
        delete toDelete;
    return;
}

/*
 在直接给出要删除的节点时，不论是单向还是双向链表都可在o(1)内完成删除
 双向很简单，而单向只需另后一个节点的值覆盖给出节点，再删除后一个节点即可
 
 注意特殊情况，即当前节点为尾节点时，仍然需要遍历一次找到前一个节点
 链表中只存在一个节点时，要令head为空
 
 此时假设输入的待删除节点在链表中 
 */
void removeNode(ListNode **head, ListNode *toRemove)
{
    if ( (*head)->next==nullptr && toRemove==*head)
    {
        delete *head;
        *head = nullptr;
    }
    
    else if (toRemove->next == nullptr)
    {
        while ( (*head)->next != toRemove)
            ++(*head);
        
        (*head)->next = toRemove->next;
        delete toRemove;
    }
    
    else
    {
        toRemove->value = (toRemove->next)->value;
        toRemove->next = (toRemove->next)->next;
        delete toRemove->next;
    }
    
    return;
    
    
        
    
}




/*
 目标：反向打印链表中元素
 思路：栈
 */

void reversePrint(ListNode* head)
{
    if (head == nullptr)
        return;
    
    std::stack<int> printStack;
    
    while (head != nullptr)
    {
        printStack.push(head->value);
        head = head->next;
    }
    
    while (!printStack.empty())
    {
        std::cout<< printStack.top() <<std::endl;
        printStack.pop();
    }
    
    return;
}



/*
 目标：返回长度为n的链表中倒数第k个节点的值
 设尾节点为倒数第1个节点
 */
/*
 思路：
 该问题的关键在于如何判断n>k
 倒数第k个节点即正数n-k个节点
 可以：
 
 先让一个指针走k个位置
 如果：
    不到k个位置就到尾节点，则n<k，抛出异常
 否则
    再让另一个指针和该指针同时开始走
    第一个指针到末尾时，第二个指针到达n-k个节点，即倒数第k个节点
 */


int findKToLast(ListNode* head, int k)
{
    
    if (head == nullptr)
    {
        std::cerr<<"head is a nullptr!";
        exit(1);
    }
    
    if (k<=0)
    {
        std::cerr<<"k must be positive";
        exit(1);
    }
    
    ListNode* p1 = head;
    ListNode* p2 = head;
    
    for (int i=1; i<=k; ++i)
    {
        if (p1 != nullptr)
            p1 = p1->next;
        else
        {
            std::cerr<<" k must less than n";
            exit(1);
        }
    }
    
    while (p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p2->value;
}

/*
 目标：判断链表中是否有环
 */
/*
 链表中如果有环
 一个指针一次2步，一个一次一步，则两者必会在某个时刻相等
 如果没有环，则2步的那个一定会先到尾节点
 */

bool findCycle(ListNode* head)
{
    if (head == nullptr)
    {
        std::cerr<<"head is a nullptr!\n";
        exit(1);
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    
    do
    {
        if (fast != nullptr)
            fast = fast->next;
        else
            return false;
        
        if (fast != nullptr)
            fast = fast->next;
        else
            return false;
        
        slow = slow->next;
        
    }
    while (fast != slow);
    
    
    return true;
    
}


/*
 目标：给定一个链表，判断其是否有环
 如果有，找到环的入口节点并返回
 如果无，返回nullptr
 */
/*
 思路：
 1.判断是否有环，无则返回
 2.若有，则得到环的长度k
 3.两个指针一个每次走2步，另一个每次走1步，两者相遇的点开始计数，再此到该点时停止，得到k
 4.再定义两个指针，一个先走k，另一个再走，两者相遇的那个节点就是环的入口
 */

ListNode* findEntrance(ListNode* head)
{
    if (head == nullptr)
    {
        std::cerr<<"head is a nullptr!\n";
        exit(1);
    }
    
    ListNode* fast = head;
    ListNode* slow = head;
    
    do
    {
        if (fast != nullptr)
            fast = fast->next;
        else
            return nullptr;
        
        if (fast != nullptr)
            fast = fast->next;
        else
            return nullptr;
        
        slow = slow->next;
        
    }
    while (fast != slow);
    
    int length = 0;
    
    do
    {
        fast = fast->next;
        ++length;
    }
    while(fast!=slow);
    
    ListNode* pre = head;
    ListNode* post = head;
    
    for (int i=1; i<=length; ++i)
    {
        pre = pre->next;
    }
    
    while (pre!=post)
    {
        pre = pre->next;
        post = post->next;
    }
    
    return post;
    
}

/*
 目标：反转输入列表。返回新列表的head节点
 */

/*
 思路
 在调整一个节点i时，需要有3个指针
 一个指向i pNode
 一个指向i前一个节点 pPre
 一个指向i后一个节点 pNext
 
 本来是ppre->pnode->pnext，
 
 while(pnode!=nullptr)
     首先pnext = pnode->next,
        如果pnext == nullptr,则已到尾节点，ReversedHead = pnode
     再令pnode->next = ppre,
     ppre=pnode
     pnode=pnext
 */
ListNode* reverseList(ListNode* head)
{
    if (head == nullptr)
    {
        std::cerr<<"head is a nullptr!\n";
        exit(1);
    }
    
    ListNode* pre = nullptr;
    ListNode* pnode = head;
    ListNode* reversedHead = nullptr;
    ListNode* pnext = nullptr;
    
    while (pnode != nullptr)
    {
        pnext = pnode->next;
        
        if (pnext == nullptr)
            reversedHead = pnode;
        
        pnode->next = pre;
        pre = pnode;
        pnode = pnext;
    }
   
    return reversedHead;
}

/*
 目标：输入两个链表m,n，找到两个链表的第一个公共节点并返回，若无则返回nullptr
 */

/*
 思路：
 暴力方法复杂度为O(m*n)
 两个单向链表如果有公共节点，那么一定是一个Y型结构
 如果可以从后往前遍历，则一旦出现两个不相等的节点，则该节点之前的那个节点就是第一个公共节点
 因此如果先遍历m，再遍历n，将其节点分别入栈，之后再轮流出栈就可完成比较
 复杂度为O(m+n)，但是需要空间复杂度为O(m+n)
 
 更简单的方法，先遍历两个链表得到长度差为k
 对长的那个链表先走k步，之后两个链表同时前进，如果两个节点相同，则为公共节点
 该思路不需额外空间复杂度
 */

ListNode* findFirstCommonNode(ListNode* m, ListNode* n)
{
    if (!m && !n)
        return nullptr;
    
    int lengthM = 0;
    int lengthN = 0;
    
    ListNode* mHead = m;
    ListNode* nHead = n;
    
    while (mHead->next != nullptr)
    {
        mHead = mHead->next;
        ++lengthM;
    }
    
    while (nHead->next != nullptr)
    {
        nHead = nHead->next;
        ++lengthN;
    }
    
    if (lengthM > lengthN)
    {
        int sub = lengthM - lengthN;
        
        while (sub>0)
        {
            m = m->next;
            --sub;
        }
        
        while (m != n)
        {
            m = m->next;
            n = n->next;
        }
        
        return m;
    }
    
    else
    {
        int sub = lengthN - lengthM;
        
        while (sub>0)
        {
            n = n->next;
            --sub;
        }
        
        while (m != n)
        {
            m = m->next;
            n = n->next;
        }
        
        return m;
    }
    
    
}




#endif /* ListNode_h */
