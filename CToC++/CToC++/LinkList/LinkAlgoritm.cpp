//
//  LinkListTool.cpp
//  CToC++
//
//  Created by mac on 2020/5/4.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LinkAlgorithm.hpp"
#include <vector>
#include <set>


LinkNode *generateNormalLinkList(vector<int> arr) {
    LinkNode *head = NULL;
    LinkNode *pre = NULL;
    //利用尾插发
    for (int val : arr) {
        LinkNode *temp = new LinkNode(val,NULL);
        if (head == NULL) {
            head = pre = temp;
        } else {
            pre->next = temp;
            pre = temp;
        }
    }
    
    return head;
}

void printLinkList(LinkNode *head) {
    LinkNode *cur = head;
    while (cur) {
        cout<<cur->val<<' ';
        cur = cur->next;
    }
    cout<<endl;
}

LinkNode* reverseLinkList(LinkNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    } else {
        LinkNode *pre = head;
        LinkNode *next = head->next;
        pre->next = NULL;
        while (next) {
            LinkNode *temp = next;
            next = next->next;
            temp->next = pre;
            pre = temp;
        }
        return pre;
    }
}

//方法1,利用set看看在遍历的过程中是否已经存储过某个值,存储过,说明有环(比较的是节点的地址)
bool hasCycle(LinkNode *head) {
    set<LinkNode *> itSet;
    LinkNode *current = head;
    while (current) {
        if (itSet.count(current) > 0) {
            return true;
        }
        itSet.insert(current);
        current = current->next;
    }
    return false;
}

//方法2:快慢指针
/**
 主要思路:快慢指针,如果有环,快指针一定会在某一时刻赶上慢指针
 */
bool hasCycle2(LinkNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    LinkNode *slow = head;
    LinkNode *fast = head;
    while (fast) {
        if (fast->next == NULL || fast->next->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

LinkNode *detectCycle(LinkNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    LinkNode *slow = head;
    LinkNode *fast = head;
    bool hasCycle = false;
    while (fast) {
        if (fast->next == NULL || fast->next->next == NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    if (hasCycle) {
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}

/**
 执行用时：
 68 ms
 , 在所有 C++ 提交中击败了
 37.91%
 的用户
 内存消耗：
 14.5 MB
 , 在所有 C++ 提交中击败了
 100.00%
 的用户
 */
LinkNode *getIntersectionNode(LinkNode *headA, LinkNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    int listA_len = 1;
    int listB_len = 1;
    LinkNode *currentA = headA;
    LinkNode *currentB = headB;
    while (currentA->next != NULL) {
        listA_len++;
        currentA = currentA->next;
    }
    
    while (currentB->next != NULL) {
        listB_len++;
        currentB = currentB->next;
    }
    if (currentA != currentB) {
        return NULL;
    }
    currentA = headA;
    currentB = headB;
    //调整链表到一个合适的位置
    int diffVal = abs(listA_len-listB_len);
    if (listA_len > listB_len) {
        while (diffVal > 0) {
            currentA = currentA->next;
            diffVal--;
        }
    }
    
    if (listA_len < listB_len) {
        while (diffVal > 0) {
           currentB = currentB->next;
           diffVal--;
        }
    }
    //调整完毕,开始移动指针
    while (currentA != currentB) {
        currentA = currentA->next;
        currentB = currentB->next;
    }
    return currentA;
}

/**
 使用快慢指针：快指针先走k步，然后慢指针开始走，直到快指针为null
 */
LinkNode * searchBackKElement(LinkNode *head, int k) {
    LinkNode *fast = head;
    LinkNode *slow = head;
    while (k-- > 0) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return NULL;
    if (l1 && !l2)  return l1;
    if (!l1 && l2) return l2;
    ListNode *mergeNode;
    if (l1->val < l2->val) {
        mergeNode = l1;
        l1 = l1->next;
    } else {
        mergeNode = l2;
        l2 = l2->next;
    }
    ListNode *p = mergeNode;
    while (l1 && l2) {
        ListNode *tempNode = nullptr;
        if (l1->val < l2->val) {
            tempNode = l1;
            l1 = l1->next;
        } else {
            tempNode = l2;
            l2 = l2->next;
        }
        p->next = tempNode;
        p = p->next;
    }
    if (l1) p->next= l1;
    if (l2) p->next = l2;
    return mergeNode;
}

