//
//  LinkListTool.hpp
//  CToC++
//
//  Created by mac on 2020/5/4.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LinkListTool_hpp
#define LinkListTool_hpp

#include <iostream>
using namespace std;

class LinkNode {
public:
    int val;
    LinkNode *next;
    LinkNode(int val,LinkNode *next):val(val),next(next){}
    LinkNode(int x) : val(x), next(NULL) {}
    
};

/// 给定一个数组,生成一个列表结构并返回表头
/// @param arr 数组
/// @return 列表的表头
LinkNode *generateNormalLinkList(vector<int> arr);

/// 给定一个链表的头,打印此链表
/// @param head 链表的头
void printLinkList(LinkNode *head);

/// 给定一个链表的头,逆序一个链表(三指针法）
/// @param head 链表的表头
LinkNode* reverseLinkList(LinkNode *head);

/// 问题1.判断一个链表有没有环(leetcode:141. 环形链表)
/// @param head 给定链表的头结点
bool hasCycle(LinkNode *head);

/// 问题2.判断一个链表是否有环，如果有环，则返回环的入口节点，否则，返回NULL
/// @param head 链表头节点
LinkNode *detectCycle(LinkNode *head);

//问题2.判断两个无环单链表是否相交(leetcode:160. 相交链表)
//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

LinkNode *getIntersectionNode(LinkNode *headA, LinkNode *headB);

/// 寻找列表中倒数第K个元素
/// @param head 头节点
/// @param k 倒数第k，假设，k的值不会超过列表的总长度
LinkNode * searchBackKElement(LinkNode *head, int k);


#endif /* LinkListTool_hpp */
