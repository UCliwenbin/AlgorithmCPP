//
//  LeetCodeSolution6.hpp
//  CToC++
//
//  Created by mac on 2021/3/4.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef LeetCodeSolution6_hpp
#define LeetCodeSolution6_hpp

#include <iostream>
#include <vector>
using namespace std;

/**
 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

 P   A   H   N
 A P L S I I G
 Y   I   R
 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

 请你实现这个将字符串进行指定行数变换的函数：

 string convert(string s, int numRows);

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/zigzag-conversion
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:
    //问题：给定一个按照z字形输出的字符串s，并且这个z字形的行数为numRows，将这个z字形的s按照行来进行打印
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> rowTable(numRows,"");
        bool directFlag = false; //true表示从上往下，else从下往上
        size_t currentRow = 0;
        for (char &c : s) {
            rowTable[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows-1) {
                directFlag = !directFlag;
            }
            currentRow += directFlag ? 1 : -1;
        }
        string res = "";
        for (int i = 0; i < rowTable.size(); i++) {
            res += rowTable[i];
        }
        return res;
    }
};

#endif /* LeetCodeSolution6_hpp */
