//
//  TrieTreeDataStruct.cpp
//  CToC++
//
//  Created by mac on 2020/7/20.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "TrieTreeDataStruct.hpp"


TrieTree::TrieTree()
{
    root = new TrieNode();
}


TrieTree::~TrieTree()
{
    destory(root);
}

//利用后续遍历的方式进行释放
void TrieTree::destory(TrieNode* root)
{
    if(root == nullptr)
        return ;
    for(int i=0;i<MaxBranchNum;i++)
    {
        destory(root->nexts[i]);
    }
    delete root;
    root = nullptr;
}

void TrieTree::insert(string str)
{
    if(str == "")
        return ;
    char buf[str.size()];
    strcpy(buf, str.c_str());
    TrieNode* node = root;
    int index = 0;
    //纵向增加一条路径
    for(int i=0; i<strlen(buf); i++)
    {
        index = buf[i] - 'a';
        if(node->nexts[index] == nullptr)
        {
            node->nexts[index] = new TrieNode();
        }
        node = node->nexts[index];
        node->path++;//有一条路径划过这个节点
    }
    node->End++;
    node->word = str;
}


int TrieTree::search(string str)
{
    if(str == "")
        return 0;
    char buf[str.size()];
    strcpy(buf, str.c_str());
    TrieNode* node = root;
    int index = 0;
    for(int i=0;i<strlen(buf);i++)
    {
        index = buf[i] - 'a';
        if(node->nexts[index] == nullptr)
        {
            return 0;
        }
        node = node->nexts[index];
    }
    if(node != nullptr)
    {
        return node->End;
    }else
    {
        return 0;
    }
}

void TrieTree::Delete(string str)
{
    //不存在直接退出
    if(str == "" || search(str) == 0)
        return ;
    char buf[str.size()];
    strcpy(buf, str.c_str());
    TrieNode* node = root;
    TrieNode* tmp;
    int index = 0;
    for(int i = 0 ; i<str.size();i++)
    {
        index = buf[i] - 'a';
        tmp = node->nexts[index];
        if(--node->nexts[index]->path == 0)
        {
            delete node->nexts[index];
        }
        node = tmp;
    }
    node->End--;
}

int TrieTree::prefixNumbers(string str)
{
    if(str == "")
        return 0;
    char buf[str.size()];
    strcpy(buf, str.c_str());
    TrieNode* node = root;
    int index = 0;
    for(int i=0;i<strlen(buf);i++)
    {
        index = buf[i] - 'a';
        if(node->nexts[index] == nullptr)
        {
            return 0;
        }
        node = node->nexts[index];
    }
    return node->path;
}

void TrieTree::printPre(string str)
{
    if(str == "")
        return ;
    char buf[str.size()];
    strcpy(buf, str.c_str());
    TrieNode* node = root;
    int index = 0;
    for(int i=0;i<strlen(buf);i++)
    {
        index = buf[i] - 'a';
        if(node->nexts[index] == nullptr)
        {
            return ;
        }
        node = node->nexts[index];
    }
    Print(node);
}

void TrieTree::Print(TrieNode* node)
{
    if(node == nullptr)
        return ;
    if(node->word != "")
    {
        cout<<node->word<<" "<<node->path<<endl;
    }
    for(int i = 0;i<MaxBranchNum;i++)
    {
        Print(node->nexts[i]);
    }
}

void TrieTree::printAll()
{
    Print(root);
}


void al_test()
{
//    cout << "Hello world!" << endl;
    TrieTree trie;
//    string str = "li";
//    cout<<trie.search(str)<<endl;
//    trie.insert(str);
//    cout<<trie.search(str)<<endl;
//    trie.Delete(str);
//    cout<<trie.search(str)<<endl;
//    trie.insert(str);
//    cout<<trie.search(str)<<endl;
//
//    trie.insert(str);
//    cout<<trie.search(str)<<endl;
//
//    trie.Delete("li");
//    cout<<trie.search(str)<<endl;
//    trie.Delete("li");
//    cout<<trie.search(str)<<endl;
    trie.insert("lia");
    trie.insert("lic");
    trie.insert("liab");
    trie.insert("liad");
    trie.Delete("lia");
    cout<<trie.search("lia")<<endl;
    cout<<trie.prefixNumbers("lia")<<endl;
}




