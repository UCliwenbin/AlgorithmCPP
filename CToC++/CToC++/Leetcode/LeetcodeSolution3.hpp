//
//  LeetcodeSolution3.hpp
//  CToC++
//
//  Created by mac on 2020/7/31.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution3_hpp
#define LeetcodeSolution3_hpp

/**
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 示例 1:

 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 示例 2:

 输入: "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //暴力解法,里面含有很多重复的比较
//    int lengthOfLongestSubstring(string s) {
//        int max = 0;
//        for (int i = 0; i < s.length(); i++) {
//            int count = 1;
//            for (int j = i+1; j < s.length(); j++) {
//                //比较下一个数和前一个是否相等,如果相等,直接退出循环
//                bool equalFlag = false;
//                for (int k = j-1; k >=i; k--) {
//                    if (s[j] == s[k]) {
//                        equalFlag = true;
//                        break;
//                    }
//                }
//                if (equalFlag) {
//                    break;
//                }
//                count++;
//            }
//            if (count > max) {
//                max = count;
//            }
//        }
//        return  max;
//    }
    //遍历一次确定最长不重复字串解法
    int lengthOfLongestSubstring(string s) {
        /**关键点：
         1、使用HashTable来存储值和下标
         2、left、right指针卡出最长子串的长度
         */
        unordered_map<char, int> hashTable;
        size_t prev = 0;
        size_t maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (hashTable.count(c) && hashTable[c] >= prev) {
                prev = hashTable[c]+1;
            }
            hashTable[c] = i;
            maxLength = max(maxLength, i-prev+1);
        }
        return (int)maxLength;
    }
};

#endif /* LeetcodeSolution3_hpp */
