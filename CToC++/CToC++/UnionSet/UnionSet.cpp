//
//  UnionSet.cpp
//  CToC++
//
//  Created by mac on 2020/7/14.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "UnionSet.hpp"


int UnionSet::find(int x) {
    //终极压缩
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void UnionSet::to_union(int x1, int x2) {
    int f1 = find(x1);
    int f2 = find(x2);
    if (rank[f1] > rank[f2]) {
        parent[f2] = f1;
    } else {
        parent[f1] = f2;
        if (rank[f1] == rank[f2]) {
            rank[f2]++;
        }
    }
}

bool UnionSet::is_same(int e1, int e2) {
    return find(e1) == find(e2);
}
