//
//  LeetCodeSolution590.hpp
//  CToC++
//
//  Created by mac on 2020/7/21.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetCodeSolution590_hpp
#define LeetCodeSolution590_hpp

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
     Leetcode问题地址:   https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
 */



/// 多叉树节点
class Node {
    
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    //一下为递归解法
    void deep(Node *root,vector<int> &res) {
        if (root == NULL) {
            return;
        }
        for (Node *child : root->children) {
            deep(child,res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> res;
        deep(root,res);
        return res;
    }
    //迭代的解法
    vector<int> postorder2(Node* root) {
      if (root == NULL) {
          return {};
      }
        stack<pair<Node *, bool>> op_stack;
        vector<int> res;
        op_stack.push(make_pair(root, false));
        while (!op_stack.empty()) {
            auto &node = op_stack.top();
            if (!node.second) {
                int child_size = (int)node.first->children.size();
                for (int i = child_size-1; i >= 0; i--) {
                    op_stack.push(make_pair(node.first->children[i], false));
                }
                node.second = true;
            } else {
                res.push_back(node.first->val);
                op_stack.pop();
            }
        }
        return res;
    }

};

#endif /* LeetCodeSolution590_hpp */
