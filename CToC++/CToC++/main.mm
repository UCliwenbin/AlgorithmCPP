//
//  main.m
//  CToC++
//
//  Created by mac on 2020/3/2.
//  Copyright © 2020 lwb. All rights reserved.
//


#import "TestTool.hpp"
#include <vector>
#include "TrieTreeDataStruct.hpp"
#include <map>
#include "LeetcodeSolution13.hpp"
#include "LinkList/LinkAlgorithm.hpp"
#include "NormalAlgorithm/Algorithm.hpp"
#include "LRUCache.hpp"



//执行算法
void executeAlgorithm() {
//    vector<int> arr = {1,2,3,4,5,6,7};
//    LinkNode *head = generateNormalLinkList(arr);
//    LinkNode *res = searchBackKElement(head, 5);
//    cout<<"res:"<<res->val<<endl;
    NormalAlgorithm algorithm;
//    vector<vector<int>> matrix = {{1,2,3,4},{4,5,5,6},{7,8,8,9},{10,11,12,13}};
//    cout<<"原矩阵为："<<endl;
//    printFormateMatrix(matrix);
//    algorithm.reverse90(matrix);
//    cout<<"旋转后的矩阵为："<<endl;
//    printFormateMatrix(matrix);
//    vector<int> testArr = {3,4,5,6,7,0,1,2};
//    int index = algorithm.BSearch(testArr, 2);
//    cout<<"找到下标index:"<<index<<endl;
    LRUCache *cache = new LRUCache(3);
    cache->put("lwb", "22");
    cache->put("wq", "23");
    cache->put("lb", "18");
    cache->get("lwb");
    cache->printCacheData();
    cache->put("wzj", "16");
    cache->printCacheData();
    cache->get("lwb");
    cache->printCacheData();
}



int main(int argc, const char * argv[]) {
    testAlgorithm(executeAlgorithm);
    return 0;
}


