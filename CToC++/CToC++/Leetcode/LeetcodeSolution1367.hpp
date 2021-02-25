//
//  LeetcodeSolution1367.hpp
//  CToC++
//
//  Created by mac on 2020/7/16.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution1367_hpp
#define LeetcodeSolution1367_hpp

/**
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/linked-list-in-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root);
private:
    bool dfs(TreeNode *rt , ListNode *head);
};

#endif /* LeetcodeSolution1367_hpp */
