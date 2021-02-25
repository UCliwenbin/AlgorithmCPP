//
//  LWBStack2.cpp
//  CToC++
//
//  Created by mac on 2020/4/26.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LWBStack2.hpp"

void LWBStack2::push(int value) {
    useQueue.push(value);
}
int LWBStack2::pop() {
    if (useQueue.empty()) {
        return -1;
    } else {
        queue<int> temp;
        while (useQueue.size() > 1) {
            int value = useQueue.front();
            temp.push(value);
            useQueue.pop();
        }
        int actVal = useQueue.front();
        useQueue.pop();
        while (!temp.empty()) {
            int value = temp.front();
            useQueue.push(value);
            temp.pop();
        }
        return actVal;
    }
}

