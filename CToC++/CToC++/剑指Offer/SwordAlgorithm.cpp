//
//  SwordAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2021/3/16.
//  Copyright © 2021 lwb. All rights reserved.
//

#include "SwordAlgorithm.hpp"
#include <unordered_map>

/**
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

  

 例如，给出

 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

    3
    / \
   9  20
     /  \
    15   7

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

TreeNode *createSubTree(vector<int>& preorder,int preL,int preR,vector<int>& inorder,int inL,int inR) {
    if (preL > preR || inL > inR) {
        return NULL;
    }
    int nodeVal = preorder[preL];  //当前根节点值
    int index = inL;
    //寻找在中序遍历中的下标
    while (index <= inR) {
        if (inorder[index] == nodeVal) {
            break;
        }
        index++;
    }
    //前序数组中计算左由子树的步长
    int preGap = index - inL;
    TreeNode *rootNode = new TreeNode(nodeVal);
    rootNode->left = createSubTree(preorder,preL+1 , preL+preGap, inorder, inL, index-1);
    rootNode->right = createSubTree(preorder, preL+1+preGap, preR, inorder, index+1, inR);
    return rootNode;
    
}
TreeNode* SwordAlgorithm::buildTree(vector<int>& preorder, vector<int>& inorder) {
    return createSubTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

/**
 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 示例 1：

 输入：n = 2
 输出：2
 示例 2：

 输入：n = 7
 输出：21

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int SwordAlgorithm::numWays(int n) {
    /**
        前面的2个if用来确定，剩余一阶台阶或者剩余2阶台阶
     算法时间复杂度超时
     */
//    if (n <= 1) {
//        return 1;
//    }
//    if (n == 2) {
//        return 2;
//    }
//    return numWays(n-1)+numWays(n-2);
//    f(n) = f(n-1) + f(n-2)
    if (n <= 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int pre = 1;
    int cur = 2;
    int iterator = n - 2;
    while (iterator > 0) {
        int temp = pre + cur;
        pre = cur;
        cur = temp;
        iterator--;
    }
    return cur;
}

/**
 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

int sum(int i,int j) {
    vector<int> ivec;
    vector<int> jvec;
    int res = 0;
    while (i > 9) {
        int tem = i % 10;
        res += tem;
        i /= 10;
    }
    res += i;
    
    while (j > 9) {
        int tem = j % 10;
        res += tem;
        j /= 10;
    }
    res += j;
    return res;
}

//定义移动方向
static int direct[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
static int counter = 0;
/// dfs算法
/// @param si 开始的i坐标
/// @param sj 开始的j坐标
/// @param ei 结束的i坐标
/// @param ej 结束的j坐标
/// @param k k值
void dfs(int si,int sj,int ei,int ej,int k,vector<vector<bool>> &visited) {
    if (si > ei || si < 0 || sj > ej || sj < 0 || sum(si, sj) > k || visited[si][sj]) return;
    counter++;
    visited[si][sj] = true;
    for (int i = 0; i < 4; i++) {
      dfs(si+direct[i][0],sj+direct[i][1],ei, ej, k, visited);
    }
}
    
int SwordAlgorithm::movingCount(int m, int n, int k) {
    
    /**
     从（0，0）开始走，有上下左右
     */
    vector<vector<bool>> visited(m,vector<bool>(n));
    dfs(0, 0, m-1, n-1, k, visited);
    return counter;
}

static int maxNum = 0;
vector<int> path;
//备忘录，记录当绳子长度对应的最大乘积的值
unordered_map<int, int> memo;
int calMutiply(vector<int> arr) {
    int res = 1;
    for (int i = 0; i < arr.size(); i++) {
        res *= arr[i];
    }
    return res;
}

unordered_map<int, int> ropMemo;
int dfsCal(int n) {
    if (ropMemo.find(n) != ropMemo.end()) {
        return ropMemo[n];
    }
    if (n == 0 || n == 1) return 1;
    int res = 0;
    for (int i = 1; i < n; i++) {
        //剩下的继续剪 || 剩下的不剪了
         res = max(res,max(dfsCal(n - i) * i, i * (n - i))) ;
    }
    ropMemo[n] = res;
    return res;
}

int SwordAlgorithm::cuttingRope(int n) {
    int ans = dfsCal(n);
    return ans;
}
