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
};

#endif /* Algorithm_hpp */
