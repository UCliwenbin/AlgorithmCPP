//
//  TreeNode.hpp
//  CToC++
//
//  Created by mac on 2021/3/10.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL),parent(NULL) {}
};

#endif /* TreeNode_hpp */
