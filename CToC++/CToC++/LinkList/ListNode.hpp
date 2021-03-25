//
//  ListNode.hpp
//  CToC++
//
//  Created by mac on 2021/3/16.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val,ListNode *next):val(val),next(next){}
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* ListNode_hpp */
