//
//  LeetcodeSolution113.hpp
//  CToC++
//
//  Created by mac on 2020/7/17.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution113_hpp
#define LeetcodeSolution113_hpp

/**
 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

 说明: 叶子节点是指没有子节点的节点。

 示例:
 给定如下二叉树，以及目标和 sum = 22，

               5
              / \
             4   8
            /   / \
           11  13  4
          /  \    / \
         7    2  5   1
 返回:

 [
    [5,4,11,2],
    [5,8,4,5]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/path-sum-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
public:
    vector<vector<int>> ans;
    void dfs(TreeNode *root,int sum,vector<int> &path) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        }
        dfs(root->left, sum-root->val, path);
        dfs(root->right, sum-root->val, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> t;
        dfs(root, sum, t);
        return ans;
    }
};

#endif /* LeetcodeSolution113_hpp */
