//
//  DPAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2020/5/25.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "DPAlgorithm.hpp"
#include <climits>
#include <algorithm>
#include <vector>

/**
 @name 暴力递归法
 @brief
   递归公式:
  cost(i,j) = grid[i][j] + min(cost(i+1,j),cost(i,j+1))
 以当前点为原点,依次向右和向下计算代价值
 */
int calculate(vector<vector<int>> &grid,int i,int j) {
    size_t bound_m = grid.size();  //行
    size_t bound_n = grid[0].size(); //列
    if (i == bound_m || j == bound_n) return INT_MAX;
    if (i == (bound_m -1) && j == (bound_n -1)) return grid[i][j];
    return grid[i][j] + min(calculate(grid, i+1, j), calculate(grid, i, j+1));
}

static vector<vector<int>> table;

int calculate2(vector<vector<int>> &grid,int i,int j) {
    size_t bound_m = grid.size();  //行
    size_t bound_n = grid[0].size(); //列
    if (i == bound_m || j == bound_n) return INT_MAX;
    
    if (i == (bound_m -1) && j == (bound_n -1)) return grid[i][j];
    
    if (table[i][j] != -1) return table[i][j];
    
    int sum = grid[i][j] + min(calculate2(grid, i+1, j), calculate2(grid, i, j+1));
    table[i][j] = sum;
    return sum;
}

int DPAlgorithm::minPathSum(vector<vector<int>> &grid) {
    //从0,0点开始出发
    //暴力递归
//    return calculate(grid, 0, 0);
//    记忆搜索算法
//    size_t m = grid.size();  //行
//    size_t n = grid[0].size(); //列
//    //申请一张m*n的表
//    table = vector<vector<int> >(m,vector<int> (n,-1));
//    return calculate2(grid, 0, 0);
    //二维dp算法
//    size_t m = grid.size();  //行
//    size_t n = grid[0].size(); //列
//    vector<vector<int>> dp(m,vector<int>(n,-1));
//    dp[0][0] = grid[0][0];
//    //更新第一行
//    for (int i = 1; i < n; i++) {
//        dp[0][i] = grid[0][i] + dp[0][i-1];
//    }
//    //更新第一列
//    for (int i = 1; i < m; i++) {
//        dp[i][0] = grid[i][0] + dp[i-1][0];
//    }
//    //根据递推公式,按行更新dp表
//    for (int i = 1; i < m; i++) {
//        for (int j = 1; j < n; j++) {
//            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
//        }
//    }
//    return dp[m-1][n-1];
    //一维dp算法
    size_t m = grid.size();  //行
    size_t n = grid[0].size(); //列
    vector<int> dp(n,-1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            if (i == 0 && j == 0) {
                //更新第一个元素
                dp[j] = grid[i][j];
            } else if (i == 0 && j > 0) {
                //更新第一行
                dp[j] = grid[i][j] + dp[j-1];
            } else if (j == 0 && i > 0) {
                //更新第一列
                dp[j] = grid[i][j] + dp[j];
            } else {
                //更新其他位置
                dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
            }
        }
    }
    return dp[n-1];
    
}

int process1(vector<int> &arr,int index,int aim) {
    //换钱成功了
    if (aim == 0) {
        return 1;
    }
    //计算到最后换钱都没有成功
    if (index == arr.size()) {
        return 0;
    }
    
    int res = 0;
    for (int i = 0; arr[index] * i <= aim; i++) {
         res += process1(arr, index+1, aim - arr[index]*i);
    }
    return res;
}

vector<vector<int>> dp;
//记忆搜索算法
int process2(vector<int> &arr,int index,int aim) {
    //换钱成功了
    if (aim == 0) {
        return 1;
    }
    //计算到最后换钱都没有成功
    if (index == arr.size()) {
        return 0;
    }
    
    int res = 0;
    for (int i = 0; arr[index] * i <= aim; i++) {
        if (dp[index+1][aim - arr[index]*i] != -1) {
            res += dp[index+1][aim - arr[index]*i];
        } else {
            res += process2(arr, index+1, aim - arr[index]*i);
        }
         
    }
    dp[index][aim] = res;
    return res;
}


int DPAlgorithm::coins(vector<int> &arr, int aim) {
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    dp = vector<vector<int>>(arr.size(),vector<int>(aim+1,-1));
    return process2(arr,0, aim);
}

/**
 判断是否是回文字符串
 */
bool isValide(string string) {
    int begin = 0;
    int end = (int)string.length()-1;
    while (begin < end) {
        if (string[begin] != string[end]) {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

string DPAlgorithm::longestPalindrome(string s) {
//    //方法1：暴力解法求最长回文子串
//    if (s.length() < 2) {
//        return s;
//    }
//
//    size_t maxLength = 0;
//    string res = s.substr(0,1);
//    for (int i = 0; i < s.length()-1; i++) {
//        for (int j = i+1; j < s.length(); j++) {
//            string subString = s.substr(i,j-i+1);
//            if (subString.length() > maxLength && isValide(subString)) {
//                maxLength = subString.length();
//                res = subString;
//            }
//        }
//    }
//    return res;
    
    /**法2：动态规划（leetcode可以测试通过）
     状态转移函数：
        字符串s的任意子串范围为：i---j 之间，而且要保证 j > i
     动态表格行和列分别表示子串的范围；
      如果首尾字符相同，那么只要子序列为回文，那么一定是回文
     那么转移方程就变成：
     dp[i][j] = （s[i] == s[j] && dp[i+1][j-1]）;
     
     1、初始化dp数组
     */
    if (s.length() < 2) {
        return s;
    }
    size_t len = s.length();
    size_t begin = 0;
    size_t length = 1;
    //dp数组
    bool dp[len][len];
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }
    for (int j = 1; j < len; j++) {
        for (int i = 0; i < j; i++) {
            if (s[i] != s[j]) {
                dp[i][j] = false;
            } else {
                if (j-i+1 < 3) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            //出现为真，那么进行收集
            if (dp[i][j] && (j-i+1) > length) {
                begin = i;
                length = j-i+1;
            }
        }
    }
    return s.substr(begin,length);
    
}
