//
//  LeetcodeSolution897.hpp
//  CToC++
//
//  Created by mac on 2020/7/22.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution897_hpp
#define LeetcodeSolution897_hpp

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 //1.中序遍历，并把结果存放在一个队列中
 //2.出队列构造二叉树，出队列的时候，左子树为空，右子树为队列中的值。
 //3.返回构造的对头
class Solution {
public:
    void inOrderTraversal(TreeNode *root,vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left,res);
        res.push_back(root->val);
        inOrderTraversal(root->right,res);
    }
    void reConstructBinaryTree(TreeNode * &root,vector<int> &num,int index) {
        if (index == num.size()) {
            return;
        }
        if (root == nullptr) {
            root = new TreeNode(num[index]);
            root->left = NULL;
            reConstructBinaryTree(root->right,num, index+1);
        }
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        vector<int> nums;
        inOrderTraversal(root, nums);
        TreeNode *resRoot = NULL;
        reConstructBinaryTree(resRoot, nums,0);
        return resRoot;
    }
};


#endif /* LeetcodeSolution897_hpp */
