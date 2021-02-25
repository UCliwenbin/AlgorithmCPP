//
//  LeetCodeSolution2.cpp
//  CToC++
//
//  Created by mac on 2020/7/6.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LeetCodeSolution2.hpp"

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
     if (!l1 && !l2) {
          return NULL;
      }
      if (!l1) {
          return l2;
      }
      if (!l2) {
          return l1;
      }
      int accum = 0;
      ListNode *restList = NULL,*current = NULL;
      while (l1 || l2) {
          if (!l1) {
              int sum = l2->val + accum;
              if (sum > 9) {
                  accum = 1;
              } else {
                  accum = 0;
              }
              ListNode *temp = new ListNode(sum%10);
              current->next = temp;
              current = temp;
              l2 = l2->next;
              continue;
          }
          if (!l2) {
              int sum = l1->val + accum;
              if (sum > 9) {
                  accum = 1;
              } else {
                  accum = 0;
              }
              ListNode *temp = new ListNode(sum%10);
              current->next = temp;
              current = temp;
              l1=l1->next;
              continue;
          }
          if (restList == NULL) {
              int sum = l1->val + l2->val;
              if (sum > 9) {
                  accum = 1;
              } else {
                  accum = 0;
              }
              restList = new ListNode(sum%10);
              current = restList;
          } else {
              int sum = l1->val + l2->val + accum;
              if (sum > 9) {
                  accum = 1;
              } else {
                  accum = 0;
              }
              ListNode *temp = new ListNode(sum % 10);
              current->next = temp;
              current = temp;
          }
          l1 = l1->next;
          l2 = l2->next;
      }
      if (!l1 && !l2 && accum == 1) {
          while (current->next) {
              current = current->next;
          }
          ListNode *lastNode = new ListNode(accum);
          current->next = lastNode;
      }
      
      return restList;
}
