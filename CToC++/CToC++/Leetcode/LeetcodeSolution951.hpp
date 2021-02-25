//
//  LeetcodeSolution951.hpp
//  CToC++
//
//  Created by mac on 2020/7/22.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution951_hpp
#define LeetcodeSolution951_hpp
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//问题地址: https://leetcode-cn.com/problems/flip-equivalent-binary-trees/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode *root, map<int,TreeNode *> &dic) {
        if (root == nullptr) {
            return;
        }
        int val = root->val;
        dic[val] = root;
        dfs(root->left,dic);
        dfs(root->right,dic);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        map<int,TreeNode *> dic;
        dfs(root2,dic);
        queue<TreeNode *> t_queue;
        t_queue.push(root1);
        while (!t_queue.empty()) {
            TreeNode *root1_node = t_queue.front();
            t_queue.pop();
            auto res = dic.find(root1_node->val);
            TreeNode *root2_node = NULL;
            if (res != dic.end()) {
                root2_node = res->second;
            } else {
                return false;
            }
            int root1_num = 0;
            int root2_num = 0;
            if (root1_node->left) {
                root1_num++;
            }
            if (root1_node->right) {
                root1_num++;
            }
            if (root2_node->left) {
                root2_num++;
            }
            if (root2_node->right) {
                root2_num++;
            }
            if (root1_num != root2_num) {
                return false;
            }
            //左右子树,要不全为空,要不全不为空,或者有一个为空
            //2个子节点全为空
            if (root1_num == 0) {
                continue;
            }
            //一个为空,一个不为空
            else if (root1_num == 1 ) {
                TreeNode *tempNode1 = root1_node->left ? root1_node->left : root1_node->right;
                TreeNode *tempNode2 = root2_node->left ? root2_node->left : root2_node->right;
                if (tempNode1->val == tempNode2->val) {
                    t_queue.push(tempNode1);
                } else {
                    return false;
                }
            }
            else {
            //比较左右节点是否一致,以及互换后是否一致?
                if ((root1_node->left->val == root2_node->left->val && root1_node->right->val == root2_node->right->val) ||(root1_node->left->val == root2_node->right->val && root1_node->right->val == root2_node->left->val) )
                {
                    if (root1_node->left) {
                        t_queue.push(root1_node->left);
                    }
                    if (root1_node->right) {
                        t_queue.push(root1_node->right);
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
    //解法2
    bool flipEquiv2(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 != nullptr || root2 != nullptr || root1->val != root2->val) {
            return false;
        }
        return (flipEquiv2(root1->left, root2->left) && flipEquiv2(root1->right, root2->right)) || (flipEquiv2(root1->left, root2->right) && flipEquiv2(root1->right, root2->left));
    }
};


#endif /* LeetcodeSolution951_hpp */
