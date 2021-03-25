//
//  LeetCodeSolution2.hpp
//  CToC++
//
//  Created by mac on 2020/7/6.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetCodeSolution2_hpp
#define LeetCodeSolution2_hpp

#include <stdio.h>
#include "ListNode.hpp"

/**
 给出两个 非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 示例：

 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-two-numbers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif /* LeetCodeSolution2_hpp */
