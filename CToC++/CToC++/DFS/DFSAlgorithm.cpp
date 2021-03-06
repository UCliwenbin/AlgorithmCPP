//
//  DFSAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2021/3/10.
//  Copyright © 2021 lwb. All rights reserved.
//

#include "DFSAlgorithm.hpp"
#include <algorithm>
#include <unordered_map>

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

void dupBackTrack(vector<int> &num,vector<int> &path,int start) {
    ans.push_back(path);
    for (int i = start; i < num.size(); i++) {
        //剪枝
        if (i > start && num[i] == num[i-1]) {
            continue;
        }
        path.push_back(num[i]);
        dupBackTrack(num, path, i+1);
        path.pop_back();
    }
}

vector<vector<int>> DFSSolution::subsetsWithDup(vector<int>& nums) {
    vector<int> path;
    sort(nums.begin(), nums.end(), [](int a,int b)->bool{
        return a < b;
    });
    dupBackTrack(nums, path, 0);
    return ans;
}

//求和数组
int sum(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

void dfsFindComp(vector<int> &candidates,vector<int> &path,int target,int start) {
    int tempSum = sum(path);
    if (tempSum == target) {
        ans.push_back(path);
    } else if (tempSum < target) {
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfsFindComp(candidates, path, target,i);
            path.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    dfsFindComp(candidates, path, target,0);
    return ans;
}


/**
 暴力递归 && 备忘录解法:
    输入一个金额n，返回凑出这个金额需要的最少钱币数（钱币数无限）
    如果不能凑出，那么返回-1
 FIXME://使用备忘录解法是可以通过的
 */
static unordered_map<int, int> memo;
int recursionFun(vector<int> &coins,int n) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 0) return 0;
    if (n < 0) return -1;
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int subPath = recursionFun(coins, n - coins[i]);
        if (subPath == -1) continue;
        res = min(res, 1 + subPath);
    }
    memo[n] = (res == INT_MAX ? -1 : res);
    return memo[n];
}


//回溯的解法
static vector<int> needCoins;
static int rest = INT_MAX;
void dfsSol(vector<int> &coins,int amount,int start) {
    if (amount == 0) {
        int coins  = (int)needCoins.size();
        if (coins < rest) rest = coins;
    }
    for (int i = start; i < coins.size(); i++) {
        int curCoin = coins[i];
        if (amount < curCoin) continue;
        needCoins.push_back(curCoin);
        dfsSol(coins, amount-curCoin, i);
        needCoins.pop_back();
    }
}

int DFSSolution::coinChange(vector<int> &coins, int amount) {
    dfsSol(coins, amount, 0);
    return rest == INT_MAX ? -1 : rest;
}
