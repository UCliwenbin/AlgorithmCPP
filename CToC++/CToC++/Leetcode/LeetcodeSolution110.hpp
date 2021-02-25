//
//  LeetcodeSolution110.hpp
//  CToC++
//
//  Created by mac on 2020/8/26.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution110_hpp
#define LeetcodeSolution110_hpp

#include <iostream>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    
//    //计算当前节点的树的高度
//    int height(TreeNode *node) {
//        if (node == NULL) {
//            return 0;
//        }
//        return max(height(node->left), height(node->right))+1;
//
//    }
//    bool isBalanced(TreeNode* root) {
//        if (root == NULL) {
//            return true;
//        }
//        return abs(height(root->left)-height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//    }
    
    int height(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) > -1;
    }
};

#endif /* LeetcodeSolution110_hpp */
