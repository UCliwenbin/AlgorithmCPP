//
//  LWBQueue.hpp
//  CToC++
//
//  Created by mac on 2020/4/25.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LWBQueue_hpp
#define LWBQueue_hpp

#include <stdio.h>

class LWBQueue {
public:
    int peek();
    void push(int value);
    int poll();
    bool isEmpty();
private:
    int arr[10];
    int start = 0;
    int end = 0;
    int size = 0;
    int len = 10;
};

#endif /* LWBQueue_hpp */
