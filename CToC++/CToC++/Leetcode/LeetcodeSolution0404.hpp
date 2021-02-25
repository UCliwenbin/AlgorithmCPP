//
//  LeetcodeSolution0404.hpp
//  CToC++
//
//  Created by mac on 2020/7/16.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution0404_hpp
#define LeetcodeSolution0404_hpp

#include <iostream>
using namespace std;

/**
 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


 示例 1:
 给定二叉树 [3,9,20,null,null,15,7]
     3
    / \
   9  20
     /  \
    15   7
 返回 true 。
 示例 2:
 给定二叉树 [1,2,2,3,3,null,null,4,4]
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 返回 false 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/check-balance-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int calTreeHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        } else {
            return 1+max(calTreeHeight(root->left), calTreeHeight(root->right));
        }
    }
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int leftHeight = calTreeHeight(root->left);
        int rightHeight = calTreeHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        if (isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};

#endif /* LeetcodeSolution0404_hpp */
