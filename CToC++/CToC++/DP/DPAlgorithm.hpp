//
//  DPAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2020/5/25.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef DPAlgorithm_hpp
#define DPAlgorithm_hpp

#include <iostream>
#include <vector>
using namespace std;

class DPAlgorithm {
    
public:
    /**
     给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
     */
    int minPathSum(vector<vector<int>> &grid);
    /**
     给定数组arr，arr中所有的值都为正数且不重复。每个值代表⼀种⾯值的货币，
     每种⾯值的货币可以使⽤任意张，再给定⼀个整数aim代表要找的钱数，求换钱
     有多少种⽅法。
     【举例】
     arr=[5,10,25,1]，aim=0。
     组成0元的⽅法有1种，就是所有⾯值的货币都不⽤。所以返回1。
     arr=[5,10,25,1]，aim=15。
     组成15元的⽅法有6种，分别为3张5元，1张10元+1张5元，1张10元+5张1元，
     10张1元+1张5元，2张5元+5张1元，15张1元。所以返回6。
     arr=[3,5]，aim=2。
     任何⽅法都⽆法组成2元。所以返回0。
     */
    int coins(vector<int> &arr, int aim);
    
};

#endif /* DPAlgorithm_hpp */
