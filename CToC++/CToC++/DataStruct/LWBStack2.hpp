//
//  LWBStack2.hpp
//  CToC++
//
//  Created by mac on 2020/4/26.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LWBStack2_hpp
#define LWBStack2_hpp

#include <iostream>
#include <queue>
using namespace std;

//利用队列来实现栈
class LWBStack2 {
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
    //给定一个队列
    queue<int> useQueue;
};

#endif /* LWBStack2_hpp */
