//
//  main.cpp
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/18.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, const char * argv[]) {
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = 2;
    root->left = new BinaryTreeNode();
    root->left->value = 1;
    root->right = new BinaryTreeNode();
    root->right->value = 3;
    
    bst2list(root);
    
    while(root->left != nullptr)
        root = root->left;
    
    while(true)
    {
        cout<<root->value<<endl;
        
        if (root->right == nullptr)
            break;
        else
            root = root->right;
    }
    
    while (root->left != nullptr)
    {
        root = root->left;
        delete root->right;
    }
    

    return 0;

}
