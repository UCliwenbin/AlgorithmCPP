//
//  SearchSolution.hpp
//  CToC++
//
//  Created by mac on 2020/4/10.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef SearchSolution_hpp
#define SearchSolution_hpp

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
};

class Solution {
    
public:
    //二分查找
    /**
     arr:待查找的数组
     begin:开始的位置
     end:结束的位置
     k:待查找的值
     return:返回查找到值所在的位置
     */
    int binarySearch(vector<int> arr,int begin,int end,int k);
    /**
     整数数组 nums 按升序排列，数组中的值 互不相同 。

     在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

     给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的索引，否则返回 -1 。

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    int search(vector<int>& arr, int target);
    /**
     给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

     你可以假设数组中无重复元素。

     示例 1:

     输入: [1,3,5,6], 5
     输出: 2
     示例 2:

     输入: [1,3,5,6], 2
     输出: 1
     示例 3:

     输入: [1,3,5,6], 7
     输出: 4
     示例 4:

     输入: [1,3,5,6], 0
     输出: 0

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/search-insert-position
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    int searchInsert(vector<int>& nums, int target);
};

#endif /* SearchSolution_hpp */
