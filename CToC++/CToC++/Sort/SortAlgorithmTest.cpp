//
//  SortAlgorithmTest.cpp
//  CToC++
//
//  Created by mac on 2020/4/20.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "SortAlgorithmTest.hpp"
#include <algorithm>

//合并
static int merge(vector<int> &arr,int left,int middle,int right,vector<int> &temp) {
    int p = left;
    int q = middle+1;
    int cur = 0;
    int res = 0;
    while (p <= middle && q <=right) {
        if (arr[p] < arr[q]) {
            temp[cur++] = arr[p++];
            res+= arr[p] * (right - q + 1);
        } else {
            temp[cur++] = arr[q++];
        }
    }
    
    while (p <= middle) {
        temp[cur++] = arr[p++];
    }
    
    while (q <= right) {
        temp[cur++] = arr[q++];
    }
    cur = 0;
    while (left <= right) {
        arr[left++] = temp[cur++];
    }
    return res;
}
//排序
static int sort(vector<int> &arr,int left,int right,vector<int> &temp) {
    if (left == right) {
        return 0;
    } else {
        int middle = left + ((right-left)>>1);
        return sort(arr,left,middle,temp) + sort(arr,middle+1,right,temp) + merge(arr,left,middle,right,temp);
    }
}

int SortAlgorithmTest::calculateMinSum(vector<int> &sortArray) {
    //创建临时数组
    vector<int> tempArray(sortArray.size());
    return sort(sortArray,0,(int)sortArray.size()-1,tempArray);
}

//[1,3,2,4,5]
void SortAlgorithmTest::sortArray(vector<int> &arr, int x) {
    int less = -1;
    int more = (int)arr.size();
    int cur = 0;
    while (cur != more) {
        if (arr[cur] < x) {
            swap(arr[++less], arr[cur++]);
        } else if (arr[cur] > x) {
            swap(arr[--more], arr[cur]);
        } else {
            cur++;
        }
    }
}
