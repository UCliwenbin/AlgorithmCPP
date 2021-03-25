//
//  DFSAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2021/3/10.
//  Copyright © 2021 lwb. All rights reserved.
//

#include "DFSAlgorithm.hpp"

void findAllLeaf(TreeNode *root,vector<int> &leafArray) {
    if (root == NULL) return;
    if (!root->left && !root->right) {
        leafArray.push_back(root->val);
    }
    findAllLeaf(root->left, leafArray);
    findAllLeaf(root->right,leafArray);
}

bool DFSSolution::leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leafArray1;
    vector<int> leafArray2;
    findAllLeaf(root1,leafArray1);
    findAllLeaf(root2,leafArray2);
    if (leafArray1.size() != leafArray2.size()) {
        return false;
    }
    for (int i = 0; i < leafArray1.size(); i++) {
        if (leafArray1[i] != leafArray2[i]) {
            return false;
        }
    }
    return true;
}

/**
 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
 每条从根节点到叶节点的路径都代表一个数字：

 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
 计算从根节点到叶节点生成的 所有数字之和 。

 叶节点 是指没有子节点的节点。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//使用回溯算法
void deepSearch(TreeNode *root,string &s,int &res) {
    if (!root) return;
    s.push_back(to_string(root->val)[0]);
    if (!root->left && !root->right) {
        res += stoi(s);
        return;
    }
    deepSearch(root->left, s, res);
    if (root->left != NULL) {
        s.pop_back();
    }
    deepSearch(root->right, s, res);
    if (root->right != NULL) {
        s.pop_back();
    }
}

int DFSSolution::sumNumbers(TreeNode* root) {
    string s = "";
    int res = 0;
    deepSearch(root,s,res);
    return res;
}

vector<vector<int>> ans;
void backTrack(vector<int> &num,vector<int> &path,int start) {
    ans.push_back(path);
    for (int i = start; i < num.size(); i++) {
        path.push_back(num[i]);
        backTrack(num, path, i+1);
        path.pop_back();
    }
}

vector<vector<int>> DFSSolution::subsets(vector<int>& nums) {
    vector<int> path;
    backTrack(nums, path, 0);
    return ans;
}
