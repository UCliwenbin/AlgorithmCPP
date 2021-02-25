//
//  SortAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2020/4/20.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef SortAlgorithm_hpp
#define SortAlgorithm_hpp


#include <iostream>
#include <vector>
using namespace std;

class SortAlgorithm {
    
public:
    //归并排序
    void MergeSort(vector<int> &sortArray);
    //快速排序
    void quickSort(vector<int> &sortArray);
    //桶排序（计数排序）
    void countingSort(vector<int> &sortArray);
};

#endif /* SortAlgorithm_hpp */
