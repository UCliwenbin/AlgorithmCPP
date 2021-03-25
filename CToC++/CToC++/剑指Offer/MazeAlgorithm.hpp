//
//  MazeAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2021/3/23.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef MazeAlgorithm_hpp
#define MazeAlgorithm_hpp

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

/**
 迷宫问题细细品
 
 链接：https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc
 来源：牛客网

 定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示：


 int maze[5][5] = {
 0, 1, 0, 0, 0,
 0, 1, 0, 1, 0,
 0, 0, 0, 0, 0,
 0, 1, 1, 1, 0,
 0, 0, 0, 1, 0,
 };


 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一空格是可以走的路。


 */
class MazeAlgorithm {
public:
    //生成一个迷宫
    vector<vector<int>> createMaze();
    //搜索迷宫最短路径
    /// 给一个迷宫，找出从起点到终点的最短路径（test2：找出迷宫中所有可行的路线）
    /// @param maze 迷宫
    /// @param sx 起点x
    /// @param sy 起点y
    /// @param ex 终点x
    /// @param ey 终点y
    vector<string> searchMinPathBFS(vector<vector<int>> maze, int sx,int sy,int ex,int ey);
    //使用DFS找出最短路径
    vector<string> searchMinPathDFS(vector<vector<int>> maze, int sx,int sy,int ex,int ey);
    //找出所有路线
    vector<vector<string>> searchAllPath(vector<vector<int>> maze, int sx,int sy,int ex,int ey);
    
};

#endif /* MazeAlgorithm_hpp */
