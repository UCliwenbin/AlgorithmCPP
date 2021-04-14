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
#include "Algorithm2.hpp"
#include "MazeAlgorithm.hpp"
#include "SwordAlgorithm.hpp"
#include "DFSAlgorithm.hpp"
#import "WCCTrieTreeUtil.h"

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
//    int res = algorithm.myAtoi("   -42");
//    cout<<res<<endl;
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
    
//    MazeAlgorithm algorithm;
//    vector<vector<int>> maze = algorithm.createMaze();
//    vector<string> path = algorithm.searchMinPathDFS(maze, 0, 0, 4, 4);
//    for (int i = 0; i < path.size(); i++) {
//        cout<<path[i]<<",";
//    }
//    cout<<endl;
//    SwordAlgorithm algorithm;
//    int rest = algorithm.cuttingRope(10);
//    cout<<rest<<endl;
//    DFSSolution solution;
//    vector<int> coins = {411,412,413,414,415,416,417,418,419,420,421,422};
//    int ans = solution.coinChange(coins, 9864);
//    cout<<ans<<endl;
    
//    TreeAlgorithm treeAlg;
//    vector<int> treeA = {1,3,2,4};
//    vector<int> treeB = {3,4};
//    TreeNode *A = treeAlg.createBinaryTree(treeA);
//    TreeNode *B = treeAlg.createBinaryTree(treeB);
//    bool val = treeAlg.isSubStructure(A, B);
//    cout<<val<<endl;
    
    WCCTrieTreeUtil *util = [[WCCTrieTreeUtil alloc] init];
    [util insert:@"五分钟学算法"];
    [util insert:@"五分钟商学院"];
    [util insert:@"五分钟英语演讲"];
    [util insert:@"六分钟"];
    [util insert:@"五分钟干点啥"];
    [util insert:@"五天的时间干点啥"];
    [util deleteStr:@"五分钟干点啥"];
    NSArray *arr = [util printPre:@"五"];
    for (int i = 0; i < arr.count; i++) {
        NSLog(@"%@",arr[i]);
    }
}



int main(int argc, const char * argv[]) {
    testAlgorithm(executeAlgorithm);
    return 0;
}


