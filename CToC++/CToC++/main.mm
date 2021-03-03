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
#include "DPAlgorithm.hpp"


//执行算法
void executeAlgorithm() {
//    vector<int> arr = {1,2,3,4,5,6,7};
//    LinkNode *head = generateNormalLinkList(arr);
//    LinkNode *res = searchBackKElement(head, 5);
//    cout<<"res:"<<res->val<<endl;
    DPAlgorithm algorithm;
    string str = algorithm.longestPalindrome("ac");
    cout<<str<<endl;
}



int main(int argc, const char * argv[]) {
    testAlgorithm(executeAlgorithm);
    return 0;
}


