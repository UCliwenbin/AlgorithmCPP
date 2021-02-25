//
//  SearchSolution.hpp
//  CToC++
//
//  Created by mac on 2020/4/10.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef SearchSolution_hpp
#define SearchSolution_hpp

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
};

class Solution {
    
public:
    //二分查找
    /**
     arr:待查找的数组
     begin:开始的位置
     end:结束的位置
     k:待查找的值
     return:返回查找到值所在的位置
     */
    int binarySearch(vector<int> arr,int begin,int end,int k);
};

#endif /* SearchSolution_hpp */
