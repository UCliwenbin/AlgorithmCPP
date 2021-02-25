//
//  HuffmanTree.hpp
//  CToC++
//
//  Created by mac on 2020/4/15.
//  Copyright © 2020 lwb. All rights reserved.
//

#ifndef HuffmanTree_hpp
#define HuffmanTree_hpp

typedef struct{
    int weight;  //权重
    int parent,left,right;  //父节点,左孩子,右孩子在数组中的下标
    
}HTNode, *HuffmanTree;

#include <stdio.h>

#endif /* HuffmanTree_hpp */
