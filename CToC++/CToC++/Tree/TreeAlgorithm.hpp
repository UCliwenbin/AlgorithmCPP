//
//  TreeAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2020/5/10.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef TreeAlgorithm_hpp
#define TreeAlgorithm_hpp

#include <iostream>
#include "TreeNode.hpp"
using namespace std;
//定义TreeNode
class TreeAlgorithm {
public:
    //给定树的前序和中序遍历结果,构建一颗树
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
    //给定一个整型数组,来构建一颗二叉树,例如:
    /**
     原数组:
     arr=[1,2,3,4,5,6,7]
     树结构:
             1
             /\
            2  3
            /\  /\
           4 5 6 7
     */
    TreeNode* createBinaryTree(vector<int> arr);
    //前序遍历一棵树
    void traverseTreePreOrder(TreeNode *root);
    //利用栈来前序遍历一棵树
    void traverseTreePreOrderUsingStack(TreeNode *root);
    //中序遍历一棵树
    void traverseTreeInOrder(TreeNode *root);
    //利用栈来实现树的中序遍历
    void traverseTreeInOrderUsingStack(TreeNode *root);
    //后序遍历一颗树
    void traverseTreeBackOrder(TreeNode *root);
    //利用栈来实现后续遍历一棵树
    void traverseTreeBackOrderUsingStack(TreeNode *root);
    //给定一个节带Parent的节点,找出它的后继节点
    TreeNode * findSuccessorNode(TreeNode *root,TreeNode *node);
    //给定一个节带Parent的节点,找出它的前驱节点
    TreeNode * findPreSuccessorNode(TreeNode *root,TreeNode *node);
    //给定一个搜索二叉树后续遍历的结果,重建这颗二叉树
    TreeNode * reconstructSearchBinary(vector<int> &array);
    /**给一颗搜索二叉树和一个节点,找出这个节点的后继节点
     注意:是搜索二叉树
    */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);
    /**
     给定一棵树,将其序列化为一个字符串
     字符串的格式为:1_2_4_8_#_#_9_#_#_5_#_#_3_6_#_#_7_#_#_
     #表示空
     */
    string serializeTree(TreeNode *root);
    /**
     给定一个字符串(按照上面的格式给出),然后将其转换成一棵树
     */
    TreeNode *createTreeForString(string s);
    /**
     给定一颗树,判定其是否为一颗平衡二叉树
     */
    bool isBalanceBinaryTree(TreeNode *root);
    //翻转一颗二叉树
    TreeNode* invertTree(TreeNode* root);
    /**给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums);
    /**
     给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

     两棵树重复是指它们具有相同的结构以及相同的结点值。
     */
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
    //2个节点的最近公共祖先
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    //判断一颗二叉树是否是二叉搜索树
    bool isValidBST(TreeNode* root);
    
};

#endif /* TreeAlgorithm_hpp */
