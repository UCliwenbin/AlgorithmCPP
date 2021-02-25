//
//  LWBCache.cpp
//  CToC++
//
//  Created by mac on 2021/2/25.
//  Copyright © 2021 lwb. All rights reserved.
//

#include "LRUCache.hpp"


void DoubleList::print() {
    CacheNode *p = tail->parent;
    while (p != head) {
        cout<<"(key:"<<p->key<<"    value:"<<p->val<<")"<<endl;
        p = p->parent;
    }
}

void DoubleList::addLast(CacheNode *node) {
    //尾插法
    node->parent = tail->parent;
    tail->parent->child = node;
    node->child = tail;
    tail->parent = node;
    count++;
}

void DoubleList::remove(CacheNode *node) {
    //删除节点
    CacheNode *pre = node->parent;
    CacheNode *next = node->child;
    pre->child = next;
    next->parent = pre;
    count--;
}

CacheNode* DoubleList::removeFirst() {
    if (head->child == tail) {
        return NULL;
    }
    CacheNode *delNode = head->child;
    remove(delNode);
    return delNode;
}

DoubleList::DoubleList(){
    head = new CacheNode("","");
    tail = new CacheNode("","");
    head->child = tail;
    tail->parent = head;
    count = 0;
}

string LRUCache::get(string key) {
    if (map->count(key) == 0) {
        return "没有此元素";
    }
    _makeRecently(key);
    return map->at(key)->val;
}

void LRUCache::put(string key, string val) {
    if (map->count(key) > 0) {
        _deleteKey(key);
        _addRecently(key, val);
    } else {
        _addRecently(key, val);
        while (cacheList->size() > capacity) {
            _removeLeastRecently();
        }
    }
}

void LRUCache::printCacheData() {
    cout<<"打印："<<endl;
    cacheList->print();
}
#pragma mark -私有方法
void LRUCache::_makeRecently(string key) {
    CacheNode *node = map->at(key);
    //先移除
    cacheList->remove(node);
    //再插入
    cacheList->addLast(node);
}

void LRUCache::_addRecently(string key,string value) {
    CacheNode *node = new CacheNode(key,value);
    cacheList->addLast(node);
    map->insert({key,node});
}
void LRUCache::_deleteKey(string key) {
    CacheNode *node = map->at(key);
    map->erase(key);
    cacheList->remove(node);
}
void LRUCache::_removeLeastRecently() {
    CacheNode *node = cacheList->removeFirst();
    map->erase(node->key);
}
