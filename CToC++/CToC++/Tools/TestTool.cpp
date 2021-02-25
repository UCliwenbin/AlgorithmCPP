//
//  TestTool.cpp
//  CToC++
//
//  Created by mac on 2020/4/22.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "TestTool.hpp"
#include <ctime>
#include <sys/timeb.h>
#include <memory>


//计算算法执行时间的程序
void testAlgorithm(ExecuteAlgorithm method) {
    struct timeb startTime , endTime;
    ftime(&startTime);
    method();
    ftime(&endTime);
    cout << "算法执行时间：" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "毫秒" << endl;
}

//随机生成K个数据的数组(0~1000)
void generateRandArray(vector<int> &arr,int k,int maxValue) {
    cout<<"数据样本为："<<endl;
    for (int i = 0; i < k; i++) {
        int value = rand()%maxValue;
        cout<<value<<' ';
        arr.push_back(value);
    }
    cout<<endl;
}

void splitString(string& s, vector<string>& v,string& c) {
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

void printFormateMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
}
