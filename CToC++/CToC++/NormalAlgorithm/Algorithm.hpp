//
//  Algorithm.hpp
//  CToC++
//
//  Created by mac on 2020/3/14.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NormalAlgorithm {
public:
    /**
     有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。
     */
    void reverse90(vector<vector<int>> &matrix);
    //逆时针旋转矩阵
    void reverse_antiClockWise(vector<vector<int>> &matrix);
    /**
     给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
     */
    vector<int> smallerNumbersThanCurrent(vector<int>& nums);
    /// 给定义个矩阵，按照转圈的形式打印
    /// @param matrix 给定的矩阵
    void rotateMatrix(vector<vector<int>> matrix);
    
    /// 给定一个矩阵，按照Z字形打印输出
    /// @param matrix 给定的矩阵
    void PrintZMatrix(vector<vector<int>> matrix);
    //建立一个大跟堆
    void buildMaxHeap(vector<int> &dataList);
    //给定一个数组，求出最小的K个数,k表示找出的个数
    vector<int> findMinK(vector<int> arr,int k);
    //给定一个数组，进行快速排序
    void quickSort(vector<int> &arr,int left,int right);
    //给定一个数组，求出最小的K个数,k表示找出的个数,第二种方法
    vector<int> findMinK2(vector<int> arr,int k);
    //给定一个行和列排好序矩阵以及一个数k,判断这个数k是否在矩阵中
    bool findKInMatrix(vector<vector<int>> matrix,int k);
    //递归计算阶乘
    int factorial(int n);
    /**
     盘子的个数
     a.柱子1
     b.柱子2
     c.柱子3
     */
    void hanNuo(int n,string a,string b,string c);
    //计算斐波那契数列
    int fabNumber(int n);
    //全排列一个数组
    void Permutation(vector<int> arr,int begin,int end,int &count);
    /**
     给定一个数组，找出前K小个数
     */
    vector<int> findMinKNumber(vector<int> &arr,int k);
    /**
     给定一个数组，找出前K大个数
     */
    vector<int> findMaxKNumber(vector<int> &arr,int k);
    /**
      给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度O(N)，且要求不能用非基于比较的排序。
     */
    int calMaxGap(vector<int> &arr);
    /**
     给定一个数组和一个窗口,大小为w
     窗口每次移动一步,计算返回移动到末尾窗口中最大值组成的数组
     */
    vector<int> getMaxWindow(vector<int> arr,int w);
    /**
     荷兰国旗划分问题
     给定一个数组和一个数
     将小于target的数放左边,大于target的数放右边
     */
    void quickPation(vector<int> &arr, int target);

    /// 给定一个没有重复元素的旋转数组（它对应的原数组是有序的），求给定元素在旋转数组内的下标（不存在的返回-1）。
    /// @param arr 数组
    /// @param target 目标值
    /// @return 下标
    int BSearch(vector<int> arr,int target);
    /**
     给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

     在 S 上反复执行重复项删除操作，直到无法继续删除。

     在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    string removeDuplicates(string S);
    /**
     给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
     整数除法仅保留整数部分。
     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/basic-calculator-ii
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    int calculate(string s);
    /**
     给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

     注意：答案中不可以包含重复的四元组。



     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/4sum
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    /**
     找出3个数的和为0
     */
    vector<vector<int>> threeSum(vector<int>& nums);
};

#endif /* Algorithm_hpp */
