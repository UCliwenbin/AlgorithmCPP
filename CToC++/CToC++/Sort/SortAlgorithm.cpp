//
//  SortAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2020/4/20.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "SortAlgorithm.hpp"

#pragma mark - 归并排序
/**
 函数说明:
 输入:
    原数组,左边的位置,中间的位置,右边的位置,临时数组
 功能:
    将left到right之间的数据,按照从小到大的顺序合并
 */
static void merge(vector<int> &arr,int left,int middle,int right,vector<int> &temp) {
    int p = left;
    int q = middle+1;
    int cur = 0;
    //按照次序,依次将左右2边的数据存放到temp数组中
    while (p <= middle && q <=right) {
        if (arr[p] < arr[q]) {
            temp[cur++] = arr[p++];
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
    //将临时数组中的数据再次灌到原来数组的位置
    cur = 0;
    while (left <= right) {
        arr[left++] = temp[cur++];
    }
}

/**
 函数说明:
 排序算法:
 输入:
    原数组,待排数据的low位,代排数据的high位,临时数组
 输出: 无
 功能:
    将给定大小的数组进行排序
 
 */
static void sort(vector<int> &arr,int left,int right,vector<int> &temp) {
    if (left == right) {
        return;
    } else {
        int middle = left + ((right-left)>>1);
        sort(arr,left,middle,temp);
        sort(arr,middle+1,right,temp);
        merge(arr,left,middle,right,temp);
    }
}



void SortAlgorithm::MergeSort(vector<int> &sortArray) {
    //创建临时数组
    vector<int> tempArray(sortArray.size());
    sort(sortArray,0,(int)sortArray.size()-1,tempArray);
}

#pragma mark - 快速排序
static vector<int> partition(vector<int> &arr,int left,int right) {
    vector<int> temp(2,0);
    int less = left - 1;
    int more = right;
    while (left < more) {
        if (arr[left] < arr[right]) {
            swap(arr[++less], arr[left++]);
        } else if (arr[left] > arr[right]) {
            swap(arr[left], arr[--more]);
        } else {
            left++;
        }
    }
    swap(arr[more], arr[right]);
    temp[0] = less+1;
    temp[1] = more;
    return temp;
}

static void quickSortDeal(vector<int> &arr,int L,int R) {
    if (L < R) {
        vector<int> res = partition(arr,L,R);
        quickSortDeal(arr, L, res[0]-1);
        quickSortDeal(arr, res[1]+1, R);
    }
}
void SortAlgorithm::quickSort(vector<int> &sortArray) {
    quickSortDeal(sortArray, 0, (int)sortArray.size()-1);
}

#pragma mark - 计数排序
void SortAlgorithm::countingSort(vector<int> &sortArray) {
    //数组中的范围为0~10
    vector<int> backet(11,0);
    //归入桶中
    for (int i = 0; i < sortArray.size(); i++) {
        backet[sortArray[i]]++;
    }
    //将桶中的数据进行打印
    for (int i = 0; i < backet.size(); i++) {
        if (backet[i] == 0) {
            continue;
        } else {
            for (int j = 0; j < backet[i]; j++) {
                cout<<i<<' ';
            }
        }
    }
    cout<<endl;
}

