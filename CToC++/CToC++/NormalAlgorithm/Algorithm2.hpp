//
//  Algorithm2.hpp
//  CToC++
//
//  Created by mac on 2020/6/17.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef Algorithm2_hpp
#define Algorithm2_hpp

#include <stdio.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Algorithm2 {
public:
    /**
     给定一个带随机指针的列表,对其进行复制
     */
    Node* copyRandomList(Node* head);
    /**
     上面的那个空间复杂度为O(N),本解法把时间复杂度降到O(1)
     */
    Node* copyRandomList2(Node *head);
};

#endif /* Algorithm2_hpp */
