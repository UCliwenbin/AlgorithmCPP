//
//  TrieTreeDataStruct.hpp
//  CToC++
//
//  Created by mac on 2020/7/20.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef TrieTreeDataStruct_hpp
#define TrieTreeDataStruct_hpp

#include <iostream>
#include <string>
using namespace std;

/**
 博客讲解: https://blog.csdn.net/weixin_35479108/article/details/90289855
 知乎一篇不错的文章: https://www.zhihu.com/search?type=content&q=%E5%89%8D%E7%BC%80%E6%A0%91
 */

const int MaxBranchNum = 26;//可以扩展

class TrieNode{
public:
    string word;
    int path;  //该字符被划过多少次，用以统计以该字符串作为前缀的字符串的个数
    int End; //以该字符结尾的字符串
    TrieNode* nexts[MaxBranchNum];

    TrieNode()
    {
        word = "";
        path = 0;  //划过
        End = 0;  //结尾
        memset(nexts,NULL,sizeof(TrieNode*) * MaxBranchNum);
    }

};

class TrieTree{
private:
    TrieNode *root;
public:
    TrieTree();
    ~TrieTree();
    //插入字符串str
    void insert(string str);
    //查询字符串str是否出现过，并返回作为前缀几次
    int search(string str);
    //删除字符串str
    void Delete(string str);
    void destory(TrieNode* root);
    //打印树中的所有节点
    void printAll();
    //打印以str作为前缀的单词
    void printPre(string str);
    //按照字典顺序输出以root为根的所有单词
    void Print(TrieNode* root);
    //返回以str为前缀的单词的个数
    int prefixNumbers(string str);
};

void al_test();



#endif /* TrieTreeDataStruct_hpp */
