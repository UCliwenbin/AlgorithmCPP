//
//  UnionSetExample.hpp
//  CToC++
//
//  Created by mac on 2021/4/15.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef UnionSetExample_hpp
#define UnionSetExample_hpp

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char>> &grid) {
        count = 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }
    
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);  //路径压缩
        }
        return parent[i];
    }
    
    void unite(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                rank[rootY] += rank[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
            //联通分量-1
            count--;
        }
    }
    //判断是否联通
    bool connected(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        return rootX == rootY;
    }
    
    int getCount() {
        return count;
    }
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class UnionSetExample {
public:
    /**
     给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

     岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

     此外，你可以假设该网格的四条边均被水包围。



     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/number-of-islands
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
        使用并查集进行解决
     */
    int numIslands(vector<vector<char>>& grid) {
        int nr = (int)grid.size();
        if (!nr) return 0;
        int nc = (int)grid[0].size();
        UnionFind uf(grid);
        int num_island = 0;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i - 1 >= 0 && grid[i-1][j] == '1') uf.unite(i*nc+j, (i-1)*nc+j);
                    if (i + 1 < nr && grid[i+1][j] == '1') uf.unite(i*nc+j, (i+1)*nc+j);
                    if (j + 1 < nc && grid[i][j+1] == '1') uf.unite(i*nc+j, i*nc+(j+1));
                    if (j - 1 >= 0 && grid[i][j-1] == '1') uf.unite(i*nc+j, i*nc+(j-1));
                }
            }
        }
        return uf.getCount();
    }
};

#endif /* UnionSetExample_hpp */
