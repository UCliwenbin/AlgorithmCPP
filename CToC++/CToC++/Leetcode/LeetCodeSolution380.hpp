//
//  LeetCodeSolution380.hpp
//  CToC++
//
//  Created by mac on 2020/7/8.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef LeetCodeSolution380_hpp
#define LeetCodeSolution380_hpp
#include<iostream>
#include <map>
#include <ctime>

using namespace std;
/**
 设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

 insert(val)：当元素 val 不存在时，向集合中插入该项。
 remove(val)：元素 val 存在时，从集合中移除该项。
 getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
 示例 :

 // 初始化一个空的集合。
 RandomizedSet randomSet = new RandomizedSet();

 // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
 randomSet.insert(1);

 // 返回 false ，表示集合中不存在 2 。
 randomSet.remove(2);

 // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
 randomSet.insert(2);

 // getRandom 应随机返回 1 或 2 。
 randomSet.getRandom();

 // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
 randomSet.remove(1);

 // 2 已在集合中，所以返回 false 。
 randomSet.insert(2);

 // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
 randomSet.getRandom();

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class RandomizedSet {
private:
    int count;
    map<int,int> actualMap;
    map<int,int> cacheMap;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        this->count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = actualMap.find(val);
        if (it != actualMap.end()) {
            return false;
        }
        actualMap[val] = count;
        cacheMap[count] = val;
        count++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = actualMap.find(val);
        if (it == actualMap.end()) {
            return false;
        }
        /**
         存在:
         如果字典中只有一个值,那么直接删除,count归0
         否则,如果如果删除的值是最后一个,那么直接删除,count--;
         否则:那么中间的值和最后一个值进行交换,删除之前的旧值
         */
        int val_index = actualMap[val];
        if (actualMap.size() == 1 || val_index == count-1) {
            actualMap.erase(val);
            cacheMap.erase(val_index);
            count--;
            return true;
        }
        //和最后一个值进行交换
        int last_val = cacheMap[count-1];
        cacheMap[val_index] = last_val;
        actualMap[last_val] = val_index;
        //删除多余的2个map-key
        size_t eraseCount = actualMap.erase(val);
        size_t eraseCount2 = cacheMap.erase(count-1);
        if (eraseCount == 1 && eraseCount2 == 1) {
            count--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (actualMap.size() == 0) {
            return 0;
        }
        srand((int)time(0));
        int random_val = rand()%count;
        int actualVal = cacheMap[random_val];
        return actualVal;
    }
};


#endif /* LeetCodeSolution380_hpp */
