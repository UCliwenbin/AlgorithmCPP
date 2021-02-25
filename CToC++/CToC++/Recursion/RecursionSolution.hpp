//
//  RecursionSolution.hpp
//  CToC++
//
//  Created by mac on 2020/4/6.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef RecursionSolution_hpp
#define RecursionSolution_hpp

#include <iostream>

class TreeNode {
    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
};

class Solution {
    
public:
    
    int calMaxLength(TreeNode * node, int &maxCount);
    int longestUnivaluePath(TreeNode* root);
    //二叉搜索树结点最小距离
    int minDiffInBST(TreeNode* root);
    //后续遍历
    void dfs(TreeNode *root ,int &pre,int &res);
    /**
            给定一颗平衡二叉树,以及L和R,求二叉树中大于L,小于R的和
     */
    int rangeSumBST(TreeNode* root, int L, int R);
};



#endif /* RecursionSolution_hpp */
