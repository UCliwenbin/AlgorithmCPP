//
//  LWBQueue.cpp
//  CToC++
//
//  Created by mac on 2020/4/25.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LWBQueue.hpp"


void LWBQueue::push(int value) {
    if (size == len) {
        return;
    } else {
        size++;
        arr[end] = value;
        end = end == (len - 1) ? 0 : end+1;
    }
}

int LWBQueue::poll() {
    if (size == 0) {
        return -1;
    } else {
        size--;
        int temp = arr[start];
        start = start == len-1 ? 0 : start + 1;
        return temp;
    }
}
