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
     举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。

     如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

     如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/leaf-similar-trees
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    bool leafSimilar(TreeNode* root1, TreeNode* root2);
    int sumNumbers(TreeNode* root);
};

#endif /* DFSAlgorithm_hpp */
