//
//  TestTool.hpp
//  CToC++
//
//  Created by mac on 2020/4/22.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef TestTool_hpp
#define TestTool_hpp

#include <iostream>
#include <vector>
using namespace std;

typedef void(*ExecuteAlgorithm)();


/// 随机数据生成器
/// @param arr 生成的数据存放的容器
/// @param k 数据量
/// @param maxValue 数据中的最大值（0~maxValue）
void generateRandArray(vector<int> &arr,int k,int maxValue);

/// 计算算法的执行时间
/// @param method 要执行的算法
void testAlgorithm(ExecuteAlgorithm method);

/// 根据给定的字符划分一个字符串
/// @param s 原字符串
/// @param v 划分后的数组
/// @param c 分割字符串
void splitString(string& s, vector<string>& v,string& c);

/// 格式化打印一个矩阵
/// @param matrix 矩阵
void printFormateMatrix(vector<vector<int>> &matrix);

#endif /* TestTool_hpp */
