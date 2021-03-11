//
//  SlidingWindowAlgorithm.hpp
//  CToC++
//
//  Created by mac on 2021/3/3.
//  Copyright © 2021 lwb. All rights reserved.
//

#ifndef SlidingWindowAlgorithm_hpp
#define SlidingWindowAlgorithm_hpp

#include <iostream>
using namespace std;

class SlidingWindowAlgorithm {
    
public:
    /**
     给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

     注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
     
     示例 1：

     输入：s = "ADOBECODEBANC", t = "ABC"
     输出："BANC"
     示例 2：

     输入：s = "a", t = "a"
     输出："a"


     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/minimum-window-substring
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     */
    string minWindow(string s, string t);
};

#endif /* SlidingWindowAlgorithm_hpp */
