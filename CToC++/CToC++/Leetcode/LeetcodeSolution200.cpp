//
//  LeetcodeSolution200.cpp
//  CToC++
//
//  Created by mac on 2020/7/14.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LeetcodeSolution200.hpp"
#include <queue>


//深度优先遍历
void infect(vector<vector<char> > &grid,int i,int j,int row,int col) {
    if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != 1) {
        return;
    }
    grid[i][j] = 2;
    infect(grid, i+1, j, row, col);
    infect(grid, i, j+1, row, col);
    infect(grid, i-1, j, row, col);
    infect(grid, i, j-1, row, col);
}

int Solution::numIslands(vector<vector<char> > &grid) {
    size_t row = grid.size();
    size_t col = grid[0].size();
    int res = 0;
    if (row == 0 && col == 0) {
        return 0;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                //感染函数
                res++;
            }
        }
    }
    return res;
}

/**广度优先遍历
 思路:
    1. 先给定一个节点,如果这个节点符合条件,那么将其加入队列;
    2. 将队列头部节点出队,将其四周的节点入队
    3. 分别将已出队的节点设置marked标记为true;
 */
bool inArea(int x,int y,int maxX,int maxY) {
    return x >= 0 && x <maxY && y >= 0 && y < maxY;
}


int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) {
        return 0;
    }
    int row = (int)grid.size();
    int col = (int)grid[0].size();
    int res = 0;
    bool marked[row][col];
    int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!marked[i][j] && grid[i][j] == '1') {
                res++;
                queue<int> tempQueue;
                tempQueue.push(i*col+col);
                marked[i][j] = true;
                while (!tempQueue.empty()) {
                    int cur = tempQueue.front();
                    tempQueue.pop();
                    int curX = cur/col;
                    int curY = cur%col;
                    for (int k = 0; k < 4; k++) {
                        int newX = curX + directions[k][0];
                        int newY = curY + directions[k][1];
                        if (inArea(newX, newY, row, col) && grid[newX][newY] == '1' && !marked[newX][newY]) {
                            tempQueue.push(newX*col+newY);
                            marked[newX][newY] = true;
                        }
                    }
                }
            }
        }
    }
    return res;
    
}


//并查集解决方案
class UnionFind {
    
public:
    UnionFind(vector<vector<char>> &grid) {
        count = 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i*n+j);
                    ++count;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }
    //查找
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    //合并
    void unite(int x,int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) {
                rank[rootx] += 1;
            }
            --count;
        }
    }
    
    int getCount() const {
        return count;
    }
    
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};


int numIslands2(vector<vector<char>>& grid) {
    int nr = (int)grid.size();
    if (!nr) return 0;
    int nc = (int)grid[0].size();
    UnionFind uf(grid);
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                grid[r][c] = '0';
                if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
            }
        }
    }
    return uf.getCount();
}
