//
//  MazeAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2021/3/23.
//  Copyright © 2021 lwb. All rights reserved.
//

#include "MazeAlgorithm.hpp"


vector<vector<int>> MazeAlgorithm::createMaze(void) {
    vector<vector<int>> maze ={
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };
    return maze;
}


struct Node {
    int x;
    int y;
};
vector<string> MazeAlgorithm::searchMinPathBFS(vector<vector<int>> maze, int sx,int sy,int ex,int ey) {
    queue<Node> queue;
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};//四个方向
    //用来标记是否已经被访问过
    vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
    vector<vector<Node>> pre(maze.size(),vector<Node>(maze[0].size()));
    Node node;
    node.x = sx;
    node.y = sy;
    queue.push(node);
    visited[node.x][node.y] = true;
    bool isEnd = false;
    while (!queue.empty()) {
        Node node = queue.front();
        queue.pop();
        
        for (int i = 0; i < 4; i++) {
            Node temp;
            temp.x = node.x + dir[i][0];
            temp.y = node.y + dir[i][1];
            if (temp.x >= 0 && temp.x<=ex &&
                temp.y >= 0 && temp.y <= ey &&
                maze[temp.x][temp.y] == 0 && !visited[temp.x][temp.y])
            {
                if (temp.x == ex && temp.y == ey) {
                    pre[temp.x][temp.y] = node;
                    isEnd = true;
                    break;
                } else {
                    visited[temp.x][temp.y] = true;
                    pre[temp.x][temp.y] = node;
                    queue.push(temp);
                }
            }
        }
        if (isEnd) break;
    }
    //打印出来
    stack<Node> stack;
    Node tempNode;
    tempNode.x = ex;
    tempNode.y = ey;
    stack.push(tempNode);
    while (tempNode.x != sx || tempNode.y != sy) {
        tempNode = pre[tempNode.x][tempNode.y];
        stack.push(tempNode);
    }
    //找出最后的点
    vector<string> resVec;
    while (!stack.empty()) {
        Node temp = stack.top();
        stack.pop();
        char str[80];
        sprintf(str,"(%d,%d)",temp.x,temp.y);
        string s = str;
        resVec.push_back(s);
    }
    return resVec;
}

static int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};//四个方向
static int counter = 0;
static stack<Node> path,temp;

void dfs(vector<vector<int>> &maze, vector<vector<bool>> &visited,int sx,int sy,int ex,int ey) {
    //到达目的地
    if (sx == ex && sy == ey) {
        cout << "******************路径"<< ++counter <<  "******************" << endl;
        while (!path.empty()) {
            Node node = path.top();
            path.pop();
            temp.push(node);
        }
        
        while (!temp.empty()) {
            Node p1 = temp.top();
            temp.pop();
            path.push(p1);//将路径放回path里面，因为后面还要回溯!!!
            cout << "(" << p1.x << "," << p1.y << ")" << endl;
        }
        return;
    } else {
        if(sx < 0 || sx > ex || sy < 0 || sy > ey) return;
        for (int i = 0; i < 4; i++) {
            Node temp;
            temp.x = sx + dir[i][0];
            temp.y = sy + dir[i][1];
            if (temp.x >= 0 && temp.x<=ex &&
                temp.y >= 0 && temp.y <= ey &&
                maze[temp.x][temp.y] == 0 && !visited[temp.x][temp.y]) {
                visited[temp.x][temp.y] = true;
                path.push(temp);
                //深度优先遍历
                dfs(maze, visited, temp.x, temp.y, ex, ey);
                visited[temp.x][temp.y] = false;
                path.pop();
            }
        }

    }
}

//可以找出所有可达路径
vector<vector<string>> searchAllPath(vector<vector<int>> maze, int sx,int sy,int ex,int ey) {
    vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
    dfs(maze, visited, sx, sy, ex, ey);
    vector<vector<string>> res;
    return res;
}

//vector<string> MazeAlgorithm::searchMinPathDFS(vector<vector<int>> maze, int sx,int sy,int ex,int ey) {
//    //
//    return ;
//}
