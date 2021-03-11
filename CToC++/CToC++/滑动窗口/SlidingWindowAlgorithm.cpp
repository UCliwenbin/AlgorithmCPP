//
//  SlidingWindowAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2021/3/3.
//  Copyright © 2021 lwb. All rights reserved.
//

#include "SlidingWindowAlgorithm.hpp"
#include <unordered_map>


string SlidingWindowAlgorithm::minWindow(string s, string t) {
    /**
     求S中包含t，使用滑动窗口+双指针（left、right）
     为什么使用hash表？是为了快速确定要找的字符是否已经存在这个窗口中
     核心思路：
        0、移动right指针，直到窗口包含所有元素
        1、如果窗口中的元素包含了t中的所有元素，那么比较是否是最小的字串
        2、比较完毕后，更新left指针
     */
    size_t start = 0;
    size_t minLength = INT_MAX;
    size_t left = 0, right = 0;
    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    int mach = 0;
    for (char &c : t) needs[c]++;
    
    while (right < s.size()) {
        char c = s[right];
        if (needs.count(c)) {
            window[c]++;
            //表示窗口中对应的字符已经可以匹配t中的对应字符了
            if (window[c] == needs[c]) {
                mach++;
            }
        }
        right++;
        //窗口中的字母包含了t字符串，那么不停的移动left指针，知道不符合位置
        while (mach == needs.size()) {
            if (right - left < minLength) {
                start = left;
                minLength = right - left;
            }
            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                //存在移动left以后仍然是匹配的
                if (window[c2] < needs[c2]) {
                    mach--;
                }
            }
            left++;
        }
        
    }
    return minLength == INT_MAX ? "" : s.substr(start,minLength);
    
}
