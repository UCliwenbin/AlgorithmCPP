//
//  RecursionSolution.cpp
//  CToC++
//
//  Created by mac on 2020/4/6.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "RecursionSolution.hpp"
#include <algorithm>
#include <vector>

using namespace std;

int Solution::calMaxLength(TreeNode * node, int &maxCount) {
        int left = 0;
        if (node->left != NULL) {
            left = calMaxLength(node->left, maxCount);
            if (node->left->val == node->val) {
                left++;
            } else {
                left = 0;
            }
        }
        int right = 0;
        if (node->right != NULL) {
            right = calMaxLength(node->right, maxCount);
            if (node->val == node->right->val) {
                right++;
            } else {
                right = 0;
            }
        }
        
        int currentMaxPath = 0;
        if (node->left != NULL && node->right != NULL && node->left->val == node->right->val) {
            currentMaxPath = left + right;
        } else {
            currentMaxPath = max(left, right);
        }
        //更新记录值
        if (currentMaxPath > maxCount) {
            maxCount = currentMaxPath;
        }
        return max(left, right);
    }


int Solution::longestUnivaluePath(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int maxCount = 0;
    calMaxLength(root, maxCount);
    return maxCount;
}

int Solution::minDiffInBST(TreeNode *root) {
    int pre = -1,res = 100000;
    dfs(root, pre, res);
    return res;
}

void Solution::dfs(TreeNode *root, int &pre, int &res) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, pre, res);
    if (pre != -1) {
        res = min(res, (root->val - pre));
    }
    pre = root->val;
    dfs(root->right, pre, res);
}

void inorderTraversal(TreeNode *root, vector<int> &vec) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left,vec);
    vec.push_back(root->val);
    inorderTraversal(root->right,vec);
}

int Solution::rangeSumBST(TreeNode* root, int L, int R) {
    //1.遍历树,得到排序数组
    //2.找出范围内的值
    vector<int> sortValues;
    inorderTraversal(root, sortValues);
    int sum = 0;
    for (auto value : sortValues) {
        if (value >= L && value <= R) {
            sum+=value;
        }
    }
    return sum;
}


