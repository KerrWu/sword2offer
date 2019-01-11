//
//  BST.h
//  offer
//
//  Created by dudu294396112@qq.com on 2019/1/10.
//  Copyright © 2019年 wz_0818@163.com. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include "BinaryTree.h"
#include <stack>

/*
 目标：输入一颗BST，将其转换为从小到大的有序双向链表输出
 要求是不能创建新链表，只能调整输入的BST的指针
 */
/*
 思路：BST的中序遍历是有序的，直接在中序遍历过程中建立链表
 
 保存中序遍历的上一个节点，在遍历到当前节点时，建立两者关系
 */

void bst2list(BinaryTreeNode* head)
{
    if (head ==nullptr)
        return;
    
    std::stack<BinaryTreeNode*> tempStack;
    
    BinaryTreeNode* listHead = new BinaryTreeNode();
    BinaryTreeNode* temp = listHead;
    
    while( !tempStack.empty() || head)
    {
        while(head)
        {
            tempStack.push(head);
            head = head->left;
        }
        
        if (tempStack.empty())
            break;
        head = tempStack.top();
        temp->right = head;
        head->left = temp;
        tempStack.pop();
        temp = head;
        head = head->right;
        
    }
    
}


#endif /* BST_h */
