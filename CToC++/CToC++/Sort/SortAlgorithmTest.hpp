//
//  SortAlgorithmTest.hpp
//  CToC++
//
//  Created by mac on 2020/4/20.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef SortAlgorithmTest_hpp
#define SortAlgorithmTest_hpp

#include <iostream>
#include <vector>
using namespace std;

class SortAlgorithmTest {
    
    
public:
    //计算最小和
    int calculateMinSum(vector<int> &arr);
    //给定一个数组和一个数，把小于x的数放左边，把大于x的数放右边；
    void sortArray(vector<int> &arr,int x);
};

#endif /* SortAlgorithmTest_hpp */
