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
#include <stack>
#include <algorithm>
#include <ostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left = nullptr;
    BinaryTreeNode* right = nullptr;
};

/*
 中序遍历非递归实现
 */
void inTravel(BinaryTreeNode* root)
{
    if (root == nullptr)
        return;
    
    std::stack<BinaryTreeNode*> tempStack;
    
    BinaryTreeNode* p = root;
    
    while(!tempStack.empty() || p)
    {
        while(p)
        {
            tempStack.push(p);
            p = p->left;
        }
        
        if (!tempStack.empty())
        {
            p = tempStack.top();
            std::cout<< p->value <<std::endl;
            tempStack.pop();
            p = p->right;
        }
    }
}

/*
 前序遍历非递归实现
 */
void preTravel(BinaryTreeNode* root)
{
    if (root == nullptr)
        return;
    
    std::stack<BinaryTreeNode*> tempStack;
    
    BinaryTreeNode* p = root;
    
    while(!tempStack.empty() || p)
    {
        while(p)
        {
            std::cout<<p->value<<std::endl;
            tempStack.push(p->right);
            p = p->left;
        }
        
        if (!tempStack.empty())
        {
            p = tempStack.top();
            tempStack.pop();
        }
    }
}


/*
 目标：给出前序遍历序列和中序遍历序列，还原二叉树  --  不含重复数字
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

    
    node->left = construct((pre+1),  mid, i);
    node->right = construct( (pre+i+1), (mid+i+1), length-i-1);
    
    return node;
    
}

//
//
///*
// 输入：前中两个序列，length
// 输出：根节点指针
//
// 前序顺序是：根-左子树前序-右子树前序
// 中序顺序是：左子树中序-根-右子树中序
//
// 通过递归实现树的构建，每个节点左子树=constrcut(左前，左中，newLength)
// */
//BinaryTreeNode* construct2(int* pre, int* mid, int length)
//{
//    if (pre==nullptr || mid==nullptr || length<1)
//        return;
//
//    int leftLength = 0;
//    int rightLength = 0;
//
//    BinaryTreeNode* root = new BinaryTreeNode();
//    root->value=pre[0];
//
//    while(mid[leftLength]!=pre[0])
//        ++leftLength;
//
//    rightLength = length-leftLength-1;
//
//
//    root->left = construct2(pre+1, mid, leftLength);
//    root->right = construct2(pre+leftLength, mid+leftLength, rightLength);
//
//    return root;
//
//
//}






/*
 目标：给出一个二叉树其中一个节点，返回其中序遍历意义下的下一个节点
 分析：对于中序遍历
    如果该节点有左右子树，则其下一个节点是其右子树的最左端节点
    如果只有左子树，则其下一个节点是其父节点
    如果只有右子树，则其下一个节点是其右子树的最左端节点
    如果左右子树都没有，则其下一个节点是其父节点
 */


/*
 目标：输入两颗二叉树A，B，判断B是否是A的子树
 */

/*
 思路：遍历A，找到A中与B的root相等的子节点，再依次判断每一个节点
 用递归实现
 辅助函数f1：
 输入节点a，b
 先判断停止条件：
 如果其中一个为空，另一个不为空，返回False
 两个都为空，返回True
 否则：
     如果都不为空且两者value不相等，返回False
     如果两者value相等，则return f1(a->left, b->left) && f1(a->right,b->right)
     即两个左右子树都相等才返回True
 
 主函数中，先遍历A，直到找到和B的root相等的节点，送入辅助函数中判断
 */

bool isSubAux(BinaryTreeNode* a, BinaryTreeNode* b)
{
    if (! (a&&b))
    {
        if (a==nullptr && b==nullptr)
            return true;
        else
            return false;
    }
    
    else
    {
        if (a->value != b->value)
            return false;
        else
            return isSubAux(a->left, b->left) && isSubAux(a->right, b->right);
    }
        
}

bool isSubTree(BinaryTreeNode* a, BinaryTreeNode* b)
{
    if (a==nullptr && b==nullptr)
    {
        std::cerr<<"a b are all empty tree!";
        exit(1);
    }
    
    bool result = false;
    
    if (a!=nullptr && b!=nullptr)
    {
        if (a->value == b->value)
            result = isSubAux(a, b);
        if (result)
            return true;
        else
        {
            if (!result)
                result = isSubTree(a->left, b);
            if (!result)
                result = isSubTree(a->right, b);
        }

    }
    
    return result;
    
}

/*
 目标：将一个二叉树通过输出流以前序遍历序列输出，遇到的空节点输出#,节点间以逗号作为间隔
 */
void serialize(BinaryTreeNode* root, std::ostream& stream)
{
    if (root == nullptr)
    {
        stream<<'#'<<std::endl;
        return ;
    }
    
    stream<<root->value<<std::endl;
    serialize(root->left, stream);
    serialize(root->right, stream);
}

/*
 目标：通过一个输入流给出的序列，反序列化出一个二叉树，将这个序列视为前序序列，空节点用特殊符号#作为输入
 返回这个二叉树的root
 
 由于从流中输入的可能为数字或者字符#，因此需要写一个辅助函数判断当前输入的是数字还是字符，数字则返回true
 */

/*
 辅助函数，如果输入是数字则存入number，返回true，
 否则，如果是#则返回false，否则输出错误信息；
 */
bool readStream(std::istream& stream, int &number)
{
    char inputChar;
    stream>>inputChar;
    int asiccNumber = inputChar;
    
    if (asiccNumber>=48 && asiccNumber<=57)
    {
        number = asiccNumber-48;
        return true;
    }
    
    else if (asiccNumber == 35)
        return false;
    else
    {
        
        std::cout<<inputChar<<std::endl;
        std::cerr<<"input must be int or #, not "<<inputChar<<'\n';
        return false;

    }
}

void deserialize(BinaryTreeNode** root, std::istream& stream)
{
    
    int number;
    if(readStream(stream, number))
    {
        *root = new BinaryTreeNode();
        (*root)->value = number;
        deserialize(&((*root)->left), stream);
        deserialize(&((*root)->right), stream);
    }
    return;
}


/*
 目标：输入一棵树t，输出其深度
 */

/*
 思路：
 分四种情况：
 如果没有子节点，则返回
 如果有左子树无右子树，深度为左子树深度+1
 如果有右子树无左子树，深度为右子树深度+1
 如果都有，则深度为更大的那个子树的深度+1
 
 递归
 */



int treeDepth(BinaryTreeNode* t)
{
    if (t == nullptr)
        return 0;
    
    if (t->left == nullptr && t->right == nullptr)
        return 0;    
    else if (t->right == nullptr)
        return treeDepth(t->left)+1;
    else if (t->left == nullptr)
        return treeDepth(t->right)+1;
    else
        return std::max(treeDepth(t->left),treeDepth(t->right)) + 1;
}


#endif /* BinaryTree_h */
