//
//  main.cpp
//  offer
//
//  Created by dudu294396112@qq.com on 2018/12/18.
//  Copyright © 2018年 wz_0818@163.com. All rights reserved.
//

#include <iostream>
#include <ostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = 2;
    root->left = new BinaryTreeNode();
    root->left->value = 1;
    root->right = new BinaryTreeNode();
    root->right->value = 3;
    
    serialize(root, cout);
    
    
    BinaryTreeNode* root2 = nullptr;
    BinaryTreeNode** p2root2 = &root2;
    deserialize(p2root2, cin);
    
    serialize(root2, cout);
    

}
