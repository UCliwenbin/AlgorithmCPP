//
//  LeetCodeSolution222.cpp
//  CToC++
//
//  Created by mac on 2020/7/6.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LeetCodeSolution222.hpp"


/// 计算当前节点的树的高度,根节点的树高为1
/// @param node 当前节点
/// @param level 树的高度
int mostLeftLevel(TreeNode *node, int level) {
    while (node) {
        level++;
        node = node->left;
    }
    //因为树从1开始,会多计算一个节点,这里-1
    return level-1;
}


/// 递归计算当前节点的个数
/// @param node 当前节点
/// @param level 当前节点所在的层数,默认层数为1
/// @param height 整颗树的高度
int bs(TreeNode *node,int level,int height) {
    //如果是最后一层,那么是叶节点,返回1
    if (level == height) {
        return 1;
    }
    //如果当前节点的右子树能够达到树的高度,那么其左子树一定是满二叉树,递归处理右子树;否则其右子树是满二叉树,递归处理左子树
    if (mostLeftLevel(node->right, level+1) == height) {
        return (1<<(height-level))+bs(node->right,level+1,height);
    } else {
        return (1<<(height-level-1))+bs(node->left, level+1, height);
    }
}

int Solution::countNodes(TreeNode *root) {
    if (!root) {
        return 0;
    }
    //根节点,其层数为1,获得树的总高度
    return bs(root, 1, mostLeftLevel(root, 1));
}
