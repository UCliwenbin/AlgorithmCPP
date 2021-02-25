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
