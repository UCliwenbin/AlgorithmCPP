//
//  main.m
//  CToC++
//
//  Created by mac on 2020/3/2.
//  Copyright © 2020 lwb. All rights reserved.
//


#import "TestTool.hpp"
#include <string>
#include <vector>
#include "TrieTreeDataStruct.hpp"
#include <map>
#include "LeetcodeSolution13.hpp"
#include "LinkList/LinkAlgorithm.hpp"
#include "NormalAlgorithm/Algorithm.hpp"
#include "LRUCache.hpp"
#include "DPAlgorithm.hpp"
#include "SlidingWindowAlgorithm.hpp"
#import "Algorithm.hpp"
#include "DFSAlgorithm.hpp"
#include "TreeAlgorithm.hpp"


//执行算法
void executeAlgorithm() {
//    vector<int> arr = {1,2,3,4,5,6,7};
//    LinkNode *head = generateNormalLinkList(arr);
//    LinkNode *res = searchBackKElement(head, 5);
//    cout<<"res:"<<res->val<<endl;
//    DPAlgorithm algorithm;
//    string str = algorithm.longestPalindrome("ac");
//    cout<<str<<endl;
//    SlidingWindowAlgorithm algorithm;
//    string res = algorithm.minWindow("ADOBECODEBANC", "ABC");
//    cout<<res<<endl;
    
//    NormalAlgorithm algorithm;
//    string s = algorithm.removeDuplicates("abbaca");
//    cout<<s<<endl;
//    string s;
//    s.push_back(to_string(1)[0]);
//    s.push_back(to_string(2)[0]);
//    s.push_back(to_string(3)[0]);
//    s.pop_back();
//    cout<<stoi(s)<<endl;
//    TreeAlgorithm tree;
//    TreeNode *root = tree.createBinaryTree({1,2,3});
//    DFSSolution sol;
//    cout<<sol.sumNumbers(root)<<endl;;
    
//    NormalAlgorithm algorithm;
//    vector<int> test = {1,2,-2,-1};
//    vector<vector<int>> res = algorithm.threeSum(test);
//    for (int i = 0; i < res.size(); i++) {
//        vector<int> arr = res[i];
//        for (int j = 0; j < arr.size(); j++) {
//            cout<<arr[j]<<",";
//        }
//        cout<<endl;
//    }

}



int main(int argc, const char * argv[]) {
    testAlgorithm(executeAlgorithm);
    return 0;
}


