//
//  CQueue.hpp
//  CToC++
//
//  Created by mac on 2021/3/17.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef CQueue_hpp
#define CQueue_hpp

#include <iostream>
#include <stack>

using namespace std;

class CQueue {
    stack<int> addStack;
    stack<int> deleteStack;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        addStack.push(value);
    }
    
    int deleteHead() {
        if (deleteStack.empty()) {
            while (!addStack.empty()) {
                deleteStack.push(addStack.top());
                addStack.pop();
            }
        }
        if (deleteStack.empty()) return -1;
        int first = deleteStack.top();
        deleteStack.pop();
        return first;
    }
};

#endif /* CQueue_hpp */
