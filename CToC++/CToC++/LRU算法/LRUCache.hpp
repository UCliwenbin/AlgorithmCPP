//
//  LWBCache.hpp
//  CToC++
//
//  Created by mac on 2021/2/25.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef LWBCache_hpp
#define LWBCache_hpp

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

//参考文章：https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247486428&idx=1&sn=3611a14535669ba3372c73e24121247c&chksm=9bd7f5d4aca07cc28c02c3411d0633fc12c94c2555c08cbfaa2ccd50cc2d25160fb23bccce7f&scene=21#wechat_redirect

class CacheNode {
public:
    CacheNode(string key,string val):key(key),val(val){
        this->child = NULL;
        this->parent = NULL;
    }
    CacheNode *child;
    CacheNode *parent;
    string key;
    string val;
};

class DoubleList {
private:
    CacheNode *head,*tail;
    size_t count;
public:
    DoubleList();
    //末尾增加一个节点
    void addLast(CacheNode *node);
    //删除一个节点
    void remove(CacheNode *node);
    //删除首节点
    CacheNode *removeFirst();
    //返回列表的长度
    inline size_t size(){ return count;}
    void print();
};

/**
 缓存算法
 手撸LRU算法的实现
 */
class LRUCache {
    
public:
    LRUCache(int capacity):capacity(capacity){
        map = new unordered_map<string, CacheNode*>();
        cacheList = new DoubleList();
    }
    void put(string key,string val);
    string get(string key);
    //查看所有缓存的数据
    void printCacheData(void);
private:
    int capacity;
    unordered_map<string, CacheNode*> *map; //Hash表
    DoubleList *cacheList;  //双列表
    //将某个值设置为最近使用
    void _makeRecently(string key);
    void _addRecently(string key,string value);
    void _deleteKey(string key);
    void _removeLeastRecently();
};

#endif /* LWBCache_hpp */
