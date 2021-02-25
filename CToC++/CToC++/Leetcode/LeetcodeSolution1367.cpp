//
//  LeetcodeSolution1367.cpp
//  CToC++
//
//  Created by mac on 2020/7/16.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LeetcodeSolution1367.hpp"

bool Solution::dfs(TreeNode *rt, ListNode *head) {
    if (head == NULL) {
        return true;
    }
    if (rt == NULL) {
        return false;
    }
    if (rt->val != head->val) {
        return false;
    }
    return dfs(rt->left, head->next) || dfs(rt->right, head->next);
}

bool Solution::isSubPath(ListNode *head, TreeNode *root) {
    if (root == NULL) {
        return false;
    }
    return dfs(root,head) || isSubPath(head,root->left) || isSubPath(head, root->right);
}
