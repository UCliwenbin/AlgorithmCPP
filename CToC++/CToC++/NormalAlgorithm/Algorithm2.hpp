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
};

#endif /* Algorithm2_hpp */
