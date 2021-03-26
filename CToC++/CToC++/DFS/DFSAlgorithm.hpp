//
//  DFSAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2021/3/10.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef DFSAlgorithm_hpp
#define DFSAlgorithm_hpp

#include <iostream>
#include <vector>
#include "TreeNode.hpp"
using namespace std;

/**
 一文搞懂回溯算法：
 https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/
 */

class DFSSolution {
public:
    /**
     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/leaf-similar-trees
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    bool leafSimilar(TreeNode* root1, TreeNode* root2);
    int sumNumbers(TreeNode* root);
    /**
     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/subsets
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     //回溯学习网址
     https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/
     */
    vector<vector<int>> subsets(vector<int>& nums);
    /**
     给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

     说明：解集不能包含重复的子集。
     https://leetcode-cn.com/problems/subsets-ii/
     */
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    /**
     给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

     candidates 中的数字可以无限制重复被选取。

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/combination-sum
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    
};

#endif /* DFSAlgorithm_hpp */
