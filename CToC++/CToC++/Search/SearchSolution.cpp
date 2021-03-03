//
//  SearchSolution.cpp
//  CToC++
//
//  Created by mac on 2020/4/10.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "SearchSolution.hpp"


int Solution::binarySearch(vector<int> arr, int begin, int end, int k) {
    int middleIndex = (begin+end)/2;
    if (k == arr[middleIndex]) {
        return middleIndex;
    }
    
    else if (arr[middleIndex] > k) {
        return binarySearch(arr, begin,middleIndex-1, k);
    }
    
    if (arr[middleIndex] < k) {
        return binarySearch(arr, begin+1, end, k);
    }
    return -1;
    
}


int Solution::search(vector<int> &arr, int target) {
    //先不考虑边界情况
    int left = 0;
    int right = (int)arr.size()-1;
    while (left <= right) {
        int mid = (left+right)/2;
        //左侧有序
        if (arr[mid] == target) {
            return mid;
        }
        //左侧有序(对于左边，必须要使用“=”号，因为（left+right）/2实际上取的是左边的下标，如：//[3,1]  target=1
        if (arr[mid] >= arr[left]) {
            if (arr[mid] > target && target >= arr[left]) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        else {
            //右侧有序
            if (arr[mid] < target && arr[right] >= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
    }
    return -1;
}

//int Solution::searchInsert(vector<int> &nums, int target) {
//    
//}
