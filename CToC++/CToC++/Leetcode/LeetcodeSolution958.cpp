//
//  LeetcodeSolution958.cpp
//  CToC++
//
//  Created by mac on 2020/7/3.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LeetcodeSolution958.hpp"
#include <queue>
using namespace std;
/**
 思路:
 1.首先要搞明白什么是完全二叉树
 2.利用一个队列结构,层序遍历一颗树
    2.1. 如果发现某一个节点有右子树,而没有左子树,那么立马能够确定,这一定不是一颗完全二叉树
    2.2. 如果遍历的时候,发现某一个节点没有右子树(而不论有没有左子树),那么这个节点之后的所有节点,都是叶子节点(即左右节点都为空)
 */
bool Solution::isCompleteTree(TreeNode* root) {
    if (!root) {
        return false;
    }
    queue<TreeNode *> queue;
    queue.push(root);
    bool startLeaf = false;
    while (!queue.empty()) {
        TreeNode *frontNode = queue.front();
        queue.pop();
        if (frontNode->right && !frontNode->left) {
            return false;
        }
        if (frontNode->left) {
            if (startLeaf) return false;
            queue.push(frontNode->left);
        }
        if (frontNode->right) {
            if (startLeaf) return false;
            queue.push(frontNode->right);
        } else {
            startLeaf = true;
        }
    }
    return true;
}
