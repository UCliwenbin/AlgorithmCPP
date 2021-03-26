//
//  SwordAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2021/3/16.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef SwordAlgorithm_hpp
#define SwordAlgorithm_hpp

#include <iostream>
#include <vector>
#include "TreeNode.hpp"
using namespace std;

class SwordAlgorithm {
public:
    /*重建二叉树**/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    //剑指 Offer 10- II. 青蛙跳台阶问题
    int numWays(int n);
    /**剑指 Offer 13. 机器人的运动范围
     https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
     */
    int movingCount(int m, int n, int k);
    /**
     https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
     剑指 Offer 14- I. 剪绳子
        使用回溯算法计算超时
     */
    int cuttingRope(int n);
};

#endif /* SwordAlgorithm_hpp */
