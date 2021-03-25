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
    
};

#endif /* DFSAlgorithm_hpp */
