//
//  LeetCodeSolution1.cpp
//  CToC++
//
//  Created by mac on 2020/6/30.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "LeetCodeSolution1.hpp"
#include <map>

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> rest;
    map<int,int> hashMap;
    //存储Hash表
    for (int i = 0; i < nums.size(); i++) {
        hashMap[nums[i]] = i;
    }
    //查找Hash表
    for (int i = 0; i < nums.size(); i++) {
        int rest_val = target - nums[i];
        auto it_find = hashMap.find(rest_val);
        //有值
        if (it_find != hashMap.end() && it_find->second != i) {
            rest.push_back(i);
            rest.push_back(it_find->second);
            break;
        }
    }
    return rest;
}

vector<int> Solution::twoSum2(vector<int>& nums, int target) {
    map<int,int> hashMap;
    //将查找Hash表和存储Hash表可以同时做,因为遍历到后者的时候,前者肯定已经被存放在Hash表中了
    for (int i = 0; i < nums.size(); i++) {
        auto it_find = hashMap.find(target - nums[i]);
        //有值
        if (it_find != hashMap.end()) {
            return {it_find->second,i};
        } else {
           hashMap[nums[i]] = i;
        }
    }
    return {};
}
