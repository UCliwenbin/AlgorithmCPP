//
//  Algorithm2.cpp
//  CToC++
//
//  Created by mac on 2020/6/17.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "Algorithm2.hpp"
#include <map>

Node * Algorithm2::copyRandomList(Node *head) {
    if (head == NULL) {
           return NULL;
       }
       map<Node*,Node*> map;
       Node *cur = head;
       while (cur) {
           Node *copyNode = new Node(cur->val);
           map[cur] = copyNode;
           cur = cur->next;
       }
       //map[A,A']
       cur = head;
       while (cur) {
           Node *copyNode = map[cur];
           copyNode->next = map[cur->next];
           if (cur->random) {
               copyNode->random = map[cur->random];
           } else {
               copyNode->random = NULL;
           }
       }
       return map[head];
}


Node* Algorithm2::copyRandomList2(Node *head) {
    /**
     解法思路:
     复制 && 插入
     
     1. head不为空的时候,原链表上,每遍历一个节点,复制一个节点出来
     2. 将复制出来的值依次插入到原列表中a->a'->b->b'->c->c'
     
     设置随机指针指向的位置
     1. 遍历原列表的每一个节点,确定出新节点随机指针的指向
     
     拆分链表,将原链表和复制链表分开
     */
    if (!head) {
        return NULL;
    }
    //插入
    Node *current = head;
    while (current) {
        Node *copyNode = new Node(current->val);
        copyNode->next = current->next;
        current->next = copyNode;
        current = current->next->next;
    }
    //设置随机节点
    current = head;
    while (current) {
        Node *copyNode = current->next;
        Node *randomNode = current->random;
        if (randomNode == NULL) {
            copyNode->random = NULL;
        } else {
            copyNode->random = randomNode->next;
        }
        current = current->next->next;
    }
    //将链表拆开
    current = head;
    Node *copyHead = NULL;
    Node *copyLast = NULL;
    while (current) {
        if (copyHead == NULL) {
            copyHead = current->next;
            copyLast = copyHead;
        } else {
            copyLast->next = current->next;
            copyLast = current->next;
        }
        current->next = copyLast->next;
        current = copyLast->next;
    }
    return copyHead;
}


int Algorithm2::removeDuplicates(vector<int> &nums) {
//1. 暴力删除法
//    for (int i = 0; i < nums.size(); i++) {
//        int currVal = nums[i];
//        auto begin = nums.begin()+i;
//        int length = 0;
//        for (int j = i+1; j < nums.size(); j++) {
//            if (currVal == nums[j]) {
//                length++;
//            }
//        }
//        if (length == 0) continue;
//        nums.erase(begin+1, begin+1+length);
//    }
//    return nums.size();
//    2. 题解的骚操作，快慢指针法
    int slow = 0,fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] == nums[slow]) {
            fast++;
        } else {
            slow++;
            nums[slow] = nums[fast];
            fast++;
        }
    }
    return slow;
    
}
