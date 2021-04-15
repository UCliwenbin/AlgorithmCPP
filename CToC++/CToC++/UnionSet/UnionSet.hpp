//
//  UnionSet.hpp
//  CToC++
//
//  Created by mac on 2020/7/14.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef UnionSet_hpp
#define UnionSet_hpp

#include <iostream>
#include <vector>
using namespace std;

class UnionSet {
private:
    vector<int> parent;  //用来存放所有非联通子集
    vector<int> rank;  //用来记录当前集合的大小
    
public:
    UnionSet(int maxSize):parent(vector<int>(maxSize)),rank(vector<int>(maxSize,0)) {
        //初始化每一个节点都为自身
        for (int i = 0; i < maxSize; i++) {
            parent[i] = i;
        }
    }
    //找到集合的代表元素
    int find(int x);
    //合并
    void to_union(int x1,int x2);
    //是否在同一集合
    bool is_same(int e1,int e2);
};

#endif /* UnionSet_hpp */
