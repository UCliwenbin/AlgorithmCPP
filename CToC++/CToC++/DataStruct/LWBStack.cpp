
//
//  LWBStack.cpp
//  CToC++
//
//  Created by mac on 2020/4/25.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LWBStack.hpp"
#include <climits>
#include <array>


void LWBStack::push(int value) {
    if (index == stackSize) {
        cout<<"栈已满,不能再推入数据"<<endl;
        return;
    } else {
        arr[index++] = value;
        if (minStack.empty()) {
            minStack.push(value);
        } else {
            int minValue = std::min(minStack.top(), value);
            minStack.push(minValue);
        }
    }
}

int LWBStack::pop() {
    if (index == 0) {
        cout<<"栈为空,不能推出数据"<<endl;
        return INT_MAX;
    } else {
        minStack.pop();
        return arr[--index];
    }
}

int LWBStack::peek() {
    if (index == 0) {
        cout<<"栈为空"<<endl;
        return INT_MAX;
    } else {
        return arr[index-1];
    }
}

bool LWBStack::isEmpty() {
    if (index == 0) {
        return true;
    } else {
        return false;
    }
}

int LWBStack::getMinValue() {
    if (isEmpty()) {
        return -1;
    }
    return minStack.top();
}
