//
//  LWBStack.hpp
//  CToC++
//
//  Created by mac on 2020/4/25.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LWBStack_hpp
#define LWBStack_hpp

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class LWBStack {
public:
    //获取栈顶元素
    int peek();
    //向栈中推入一个值
    void push(int value);
    //向栈中推出一个值
    int pop();
    //是否为空
    bool isEmpty();
    //获取当前栈中的最小值
    int getMinValue();
private:
    int stackSize = 10;
    int arr[10];
    int index = 0;
    stack<int> minStack;
};

#endif /* LWBStack_hpp */
