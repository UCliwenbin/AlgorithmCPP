//
//  Algorithm2.hpp
//  CToC++
//
//  Created by mac on 2020/6/17.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef Algorithm2_hpp
#define Algorithm2_hpp

#include <iostream>
#include <vector>
#include "ListNode.hpp"
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Algorithm2 {
public:
    /**
     给定一个带随机指针的列表,对其进行复制
     */
    Node* copyRandomList(Node* head);
    /**
     上面的那个空间复杂度为O(N),本解法把时间复杂度降到O(1)
     */
    Node* copyRandomList2(Node *head);
    /**
     给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

     不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    int removeDuplicates(vector<int>& nums);
    /**
     给定一个 没有重复 数字的序列，返回其所有可能的全排列。

     示例:

     输入: [1,2,3]
     输出:
     [
       [1,2,3],
       [1,3,2],
       [2,1,3],
       [2,3,1],
       [3,1,2],
       [3,2,1]
     ]

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/permutations
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    vector<vector<int>> permute(vector<int>& nums);
    /**
     在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    bool findNumber(vector<vector<int>> arr,int target);
    /**
     在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

     示例 1：

     输入：
     [2, 3, 1, 0, 2, 5, 3]
     输出：2 或 3

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    int findRepeatNumber(vector<int>& nums);
    //请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
    string replaceSpace(string s);
    /**
     输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

      

     示例 1：

     输入：head = [1,3,2]
     输出：[2,3,1]
     */
    vector<int> reversePrint(ListNode* head);
    
    /**螺旋矩阵
     给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    
    /**螺旋矩阵2
     给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
     */
    vector<vector<int>> generateMatrix(int n);
    //旋转数组的最小数字
    int minArray(vector<int>& numbers);
    
//    矩阵中的路径
    bool exist(vector<vector<char>>& board, string word);
    
    
    
};

#endif /* Algorithm2_hpp */
