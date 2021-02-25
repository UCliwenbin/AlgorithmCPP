//
//  LeetcodeSolution102.hpp
//  CToC++
//
//  Created by mac on 2020/7/19.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution102_hpp
#define LeetcodeSolution102_hpp

/**
 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

  

 示例：
 二叉树：[3,9,20,null,null,15,7],

    3
    / \
   9  20
     /  \
    15   7
 返回其层次遍历结果：

 [
   [3],
   [9,20],
   [15,7]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {{}};
        }
        vector<vector<int>> res;
        queue<TreeNode *> level_queue;
        level_queue.push(root);
        while (!level_queue.empty()) {
            auto queue_size = level_queue.size();
            vector<int> temp;
            for (int i = 0; i < queue_size; i++) {
                TreeNode *front = level_queue.front();
                level_queue.pop();
                temp.push_back(front->val);
                if (front->left) {
                    level_queue.push(front->left);
                }
                if (front->right) {
                    level_queue.push(front->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

#endif /* LeetcodeSolution102_hpp */
