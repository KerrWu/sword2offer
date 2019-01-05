//
//  BinaryTree.h
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/21.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <assert.h>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;
};


/*
 给出前序遍历序列和中序遍历序列，还原二叉树  --  不含重复数字
 */


/*
 思路1:
 前序遍历的第一位是根节点，然后是左子树的前序遍历，最后是右子树的前序遍历
 中序遍历的中间是根节点，左边是左子树的中序遍历，右边是右子树的中序遍历
 
 可以用递归的思想
 输入：前序遍历数组，中序遍历数组，数组长度
 返回：根节点指针
 
 当前节点为前序第一位，其左子树为递归结果，递归输入为左子树前序和中序及长度
 右子树为另一个递归结果，递归输入为右子树前序和中序及长度
 */

BinaryTreeNode* construct(int* pre, int* mid, int length)
{
    if (pre == nullptr || mid == nullptr || length <= 0)
        return nullptr;
    
    BinaryTreeNode* node = new BinaryTreeNode();
    node->value = pre[0];
    
    int i=0;
    
    while (mid[i] != pre[0] && i<length)
        ++i;
    
    assert(i<length);
    
    /*
    int* leftPre = pre+1;
    int* leftMid = mid;
    
    int* rightPre = pre+i+2;
    int* rightMid = mid+i+2;
     */
    
    
    
    node->left = construct((pre+1),  mid, i);
    node->right = construct( (pre+i+1), (mid+i+1), length-i-1);
    
    return node;
    
}


/*
 目标：给出一个二叉树其中一个节点，返回其中序遍历意义下的下一个节点
 分析：对于中序遍历
    如果该节点有左右子树，则其下一个节点是其右子树的最左端节点
    如果只有左子树，则其下一个节点是其父节点
    如果只有右子树，则其下一个节点是其右子树的最左端节点
    如果左右子树都没有，则其下一个节点是其父节点
 */

#endif /* BinaryTree_h */
