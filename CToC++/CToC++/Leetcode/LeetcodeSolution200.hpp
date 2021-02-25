//
//  LeetcodeSolution200.hpp
//  CToC++
//
//  Created by mac on 2020/7/14.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetcodeSolution200_hpp
#define LeetcodeSolution200_hpp

/**
 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

 此外，你可以假设该网格的四条边均被水包围。

  

 示例 1:

 输入:
 [
 ['1','1','1','1','0'],
 ['1','1','0','1','0'],
 ['1','1','0','0','0'],
 ['0','0','0','0','0']
 ]
 输出: 1
 
 
 示例 2:

 输入:
 [
 ['1','1','0','0','0'],
 ['1','1','0','0','0'],
 ['0','0','1','0','0'],
 ['0','0','0','1','1']
 ]
 输出: 3
 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/number-of-islands
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int numIslands(vector<vector<char>>& grid);
};

#endif /* LeetcodeSolution200_hpp */
