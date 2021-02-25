//
//  LeetCodeSolution13.hpp
//  CToC++
//
//  Created by mac on 2020/9/3.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetCodeSolution13_hpp
#define LeetCodeSolution13_hpp
#include <iostream>

/**
 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

 字符          数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

 I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/roman-to-integer
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    /**
     分析:
     1.大数在小数前面,直接相加
     2.小数在大数后面,需要进行判断
     */
    int romanToInt(string s) {
        //先准备字典
        map<char,int> dic;
        dic['I'] = 1;
        dic['V'] = 5;
        dic['X'] = 10;
        dic['L'] = 50;
        dic['C'] = 100;
        dic['D'] = 500;
        dic['M'] = 1000;
        int sum = 0;
        int i = 0;
        int j = 1;
        if (s.length() == 0) return 0;
        if (s.length() == 1) return dic[s[0]];
        while (j < s.length()) {
            if (dic[s[i]] >= dic[s[j]]) {
                sum+= dic[s[i]];
                i++;
                j++;
            } else {
                sum += (dic[s[j]] - dic[s[i]]);
                i += 2;
                j += 2;
            }
        }
        if (i == (s.length()-1)) {
            sum+= dic[s[i]];
        }
        return sum;
    }
};

#endif /* LeetCodeSolution13_hpp */
