//
//  LeetcodeSolution9.hpp
//  CToC++
//
//  Created by mac on 2020/8/31.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution9_hpp
#define LeetcodeSolution9_hpp

//问题地址:https://leetcode-cn.com/problems/palindrome-number/

/**
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int a;
    bool isPalindrome(int x) {
        vector<string> array;
        //先将整数出栈,然后依次加入到array中
        while (abs(x) >= 10) {
            array.push_back(to_string(abs(x)%10));
            x /= 10;
        }
        array.push_back(to_string(abs(x)));
        if (x < 0) {
            array.push_back("-");
        }
        //从左右2边依次比对值是否相等,如果不相等直接返回false
        int i = 0;
        int j = (int)array.size()-1;
        while (i <= j) {
            if (array[i] != array[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome2(int x) {
        if (x < 0) {
            return false;
        }
        string str = to_string(x);
        int i = 0;
        int j = str.length()-1;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};



#endif /* LeetcodeSolution9_hpp */
