//
//  MyTree.hpp
//  CToC++
//
//  Created by mac on 2020/3/19.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef MyTree_hpp
#define MyTree_hpp

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode():value(0),left(NULL),right(NULL){}
};


class MyTree {
    
public:
    
    /// 给定一个数组，将其转为树结构
    /// @param values 给定的数组
    TreeNode * createTree(vector<int> values);
};

#endif /* MyTree_hpp */
