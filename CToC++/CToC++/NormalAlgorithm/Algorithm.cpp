//
//  Algorithm.cpp
//  CToC++
//
//  Created by mac on 2020/3/14.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "Algorithm.hpp"
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <deque>
#include <stack>
#include <map>

void printEdge(vector<vector<int>> matrix,size_t tR,size_t tC,size_t dR,size_t dC);
void printLine(vector<vector<int>> &matrix,int tR,int tC,int dR,int dC,bool direction);


void _rotateOneCycle(vector<vector<int>> &matrix, int tR,int tC,int dR,int dC) {
    //总共需要旋转的次数(随便行或者列减都行）
    int total = dR - tR;
    for (int i = 0; i < total; i++) {
        int temp = matrix[tR+i][tC];
        matrix[tR+i][tC] = matrix[dR][tC+i];
        matrix[dR][tC+i] = matrix[dR-i][dC];
        matrix[dR-i][dC] = matrix[tR][dC-i];
        matrix[tR][dC-i] = temp;
    }
}

void NormalAlgorithm::reverse90(vector<vector<int>> &matrix) {
    /**
     涉及到：矩阵按圈打印、矩阵的旋转等等操作，一般都是先确定左上角和右下角的位置，然后再一圈一圈的进行调整
     */
   
//    方法1：
//    auto N = matrix.size();
//    //旋转次数（圈数）
//    for (auto i = 0; i < N/2; i++) {
//        //这里的条件是这样，是因为第一次我们已经把顶点旋转过了
//        for (auto j = i; j < N-i-1; j++) {
//            int temp = matrix[i][j];
//            matrix[i][j] = matrix[N-1-j][i];
//            matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
//            matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
//            matrix[j][N-1-i] = temp;
//        }
//    }
    
    //方法2：
    /**
        将矩阵的每一圈进行旋转，这里定义4个变量：tr,tc,dr,dc，分别代表左上和右下的坐标点，那么：
            如果TR<DR，那么说明还有小圈，否则旋转完毕
     */
    int tR = 0,tC = 0;
    int dR = matrix.size()-1,dC = matrix[0].size()-1;
    while (tR < dR) {
        _rotateOneCycle(matrix, tR++, tC++, dR--, dC--);
    }
    
}

void NormalAlgorithm::reverse_antiClockWise(vector<vector<int> > &matrix) {
    auto n = matrix.size();
    for (auto i = 0; i < n/2; i++) {
        for (auto j = i; j < n-i-1; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][n-i-1];
            matrix[j][n-i-1] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[n-j-1][i];
            matrix[n-j-1][i] = temp;
        }
    }
}

/**
 输入：nums = [8,1,2,2,3]
 输出：[4,0,1,1,3]
 */
vector<int> NormalAlgorithm::smallerNumbersThanCurrent(vector<int> &nums) {
    auto size = nums.size();
    vector<int> result(size,0);
    vector<int> cnt(101,0);
    //更新前缀数组
    for (int i = 0; i<size; i++) {
        cnt[nums[i]] ++;
    }
    //将频次数组转换成统计个数的数组
    for (int i = 1; i < cnt.size(); i++) {
        cnt[i] += cnt[i-1];
    }
    
    for (int i = 0; i<size; i++) {
        result[i] = cnt[nums[i] - 1];
    }
    return result;
}



void NormalAlgorithm::rotateMatrix(vector<vector<int>> matrix) {
    auto count = matrix.size();
    size_t tR = 0,tC = 0;
    size_t dR = count-1,dC = count-1;
    while (tR <= dR && tC <= dC) {
        printEdge(matrix, tR++, tC++, dR--, dC--);
    }
    
}

void printEdge(vector<vector<int>> matrix,size_t tR,size_t tC,size_t dR,size_t dC) {
    size_t curR = tR;
    size_t curC = tC;
//       如果是行矩阵
    if (tR == dR) {
        while (curC <= dC) {
            cout<<matrix[tR][curC++]<<'\t';
        }
    } else if (tC == dC) {
//        如果是列矩阵
        while (curR <= dR) {
            cout<<matrix[curR++][tC]<<'\t';
        }
    } else {
//        一般情况按圈打印
        while (curC < dC) {
            cout<<matrix[tR][curC++]<<'\t';
        }
        while (curR < dR) {
            cout<<matrix[curR++][curC]<<'\t';
        }
        while (curC > tC) {
            cout<<matrix[curR][curC--]<<'\t';
        }
        while (curR > tR) {
            cout<<matrix[curR--][curC]<<'\t';
        }
    }
}

void NormalAlgorithm::PrintZMatrix(vector<vector<int> > matrix) {
    //最大行和最大列
    size_t maxR = matrix.size()-1;
    size_t maxC = matrix[0].size()-1;
    //t表示上边移动的点，d表示向下移动的点
    int tR = 0,tC = 0;
    int dR = 0,dC = 0;
    bool direction = false;
    do {
        printLine(matrix, tR, tC, dR, dC, direction);
        tR = tC == maxC ? tR+1 : tR;
        tC = tC == maxC ? tC : tC+1;
        dR = dR == maxR ? dR : dR+1;
        dC = dR == maxR ? dC+1 : dC;
        direction = !direction;
    } while (tR!=dR && tC!=dC);
    
    cout<<matrix[dR][dC]<<endl;
}

//负责打印一次连线
//direction: true表示由上往下打，false表示由下往上打
void printLine(vector<vector<int> > &matrix,int tR,int tC,int dR,int dC,bool direction) {
    if (direction) {
        while (tR <= dR) {
            cout<<matrix[tR++][tC--]<<'\t';
        }
        
    } else {
        while (dR >= tR) {
            cout<<matrix[dR--][dC++]<<'\t';
        }
    }
}

void NormalAlgorithm::buildMaxHeap(vector<int> &dataList) {
    //从最后一个非叶子节点开始调整堆
    int last_index = (int)dataList.size()-1;
    for (int i = (last_index-1)/2; i>=0; i--) {
        //这样的话就能求出最后一个子节点
        int k = i;
        auto biggerIndex = 2 * k + 1;
        //说明有右节点
        if (biggerIndex < last_index) {
            if (dataList[biggerIndex] < dataList[biggerIndex+1]) {
                biggerIndex++;
            }
        }
        if (dataList[k] < dataList[biggerIndex]) {
            swap(dataList[k], dataList[biggerIndex]);
        }
    }
    
}

vector<int> NormalAlgorithm::findMinK(vector<int> arr,int k) {
    /**实现：
     1、新建一个大小为k的数组
     2、将大小为k的数组建立成大根堆
     3、遍历k+1 ...n的数，
     4、如果k+1的数小于root节点，那么替换root节点为k+1节点
     5、调整大根堆
     */
    vector<int> heap;
    for (int i = 0; i < k; i++) {
        heap.push_back(arr[i]);
    }
    //调整堆
    buildMaxHeap(heap);
    for (int i = k; i < arr.size(); i++) {
        if (heap[0] > arr[i]) {
            heap[0] = arr[i];
            buildMaxHeap(heap);
        }
    }
    return heap;
}

void NormalAlgorithm::quickSort(vector<int> &arr,int left,int right) {
    int k = arr[left];
    int i = left;
    int j = right;
    if (i >= j) {
        return;
    }
    while (i < j) {
        while (i < j && arr[j] >= k) {
            j--;
        }
        if (i < j) {
            swap(arr[i++], arr[j]);
        }
        while (i < j && arr[i] <= k) {
            i++;
        }
        if (i < j) {
            swap(arr[i], arr[j--]);
        }
    }
    //i和j碰头后
    quickSort(arr, left, i-1);
    quickSort(arr, i+1, right);
}

int NormalAlgorithm::factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

void NormalAlgorithm::hanNuo(int n, string a, string b, string c) {
    if (n == 1) {
        printf("移动盘子从%s->%s\n",a.c_str(),c.c_str());
    } else {
        hanNuo(n-1, a, c, b);
        hanNuo(1, a, b, c);
        hanNuo(n-1, b, a, c);
    }
}

int NormalAlgorithm::fabNumber(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fabNumber(n-1) + fabNumber(n-2);
    }
}

void printArr(vector<int>arr);
bool judgeSwap(vector<int>arr,int cur, int i);

void NormalAlgorithm::Permutation(vector<int> arr, int begin, int end,int &count) {
    if (begin == end) {
        printArr(arr);
        ++count;
    }
    for (int i = begin; i <= end; i++) {
        if (!judgeSwap(arr, begin, i)) {
            continue;
        }
        swap(arr[begin], arr[i]);
        Permutation(arr,begin+1,end,count);
        swap(arr[i], arr[begin]);
    }
}

void printArr(vector<int>arr) {
    for (auto value : arr) {
        cout<<value<<",";
    }
    cout<<endl;
}

//从cur~i的范围内,如果出现过和i的值相同的值,那么这个值已经被放到了开头过了,所以不需要再放一次(实际是去重操作)
bool judgeSwap(vector<int>arr,int cur, int i) {
    for (int j = cur; j < i; j++) {
        if (arr[j] == arr[i]) {
            return false;
        }
    }
    return true;
}

void insertionSort(vector<int> &arr,int begin,int end);
int getMedian(vector<int>arr,int begin,int end);
int medianOfMedians(vector<int> arr,int begin,int end);
vector<int> partition(vector<int> &arr,int begin,int end,int pivotValue);
int getMinKthByBFPRT(vector<int> arr,int k);
int select(vector<int> &arr,int begin,int end,int i);

vector<int> NormalAlgorithm::findMinK2(vector<int> arr, int k) {
    if (k < 1 || k > arr.size()) {
        return arr;
    }
    int minKth = getMinKthByBFPRT(arr, k);
    vector<int> res(k,0);
    int index = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < minKth) {
            res[index++] = arr[i];
        }
    }
    for (; index != res.size(); index++) {
        res[index] = minKth;
    }
    return res;
}

bool findKInMatrix(vector<vector<int>> &matrix,int k) {
    /**
     1.矩阵为空
     2.矩阵为一行
     3.矩阵为一列
     4.正常矩阵
     */
    size_t max_row = matrix.size();
    size_t max_col = matrix[0].size();
    if (max_row == 0) {
        return false;
    }
    int curRow = (int)max_row;
    int curCol = 0;
    while (curRow > -1 && curCol < max_col) {
        if (matrix[curRow][curCol] == k) {
            return true;
        } else if (k > matrix[curRow][curCol]) {
            curCol++;
        } else {
            curRow--;
        }
    }
    return false;
    
}

int getMinKthByBFPRT(vector<int> arr,int k) {
    vector<int> copyArr(arr);
    return select(copyArr, 0, (int)copyArr.size()-1, k-1);
}

int select(vector<int> &arr,int begin,int end,int i) {
    if (begin == end) {
        return arr[begin];
    }
    int pivot = medianOfMedians(arr, begin, end);
    vector<int> pivotRange = partition(arr,begin,end,pivot);
    if (i >= pivotRange[0] && i <= pivotRange[1]) {
        return arr[i];
    } else if (i < pivotRange[0]) {
        return select(arr,begin, pivotRange[0]-1, i);
    } else {
        return select(arr,pivotRange[1]+1, end, i);
    }
}

//求解中位数中的中位数
int medianOfMedians(vector<int> arr,int begin,int end) {
    int num = end - begin + 1;
    int offset = num % 5 == 0 ? 0 : 1;
    vector<int> mArr(num/5+offset,0);
    for (int i = 0; i < mArr.size(); i++) {
        int beginI = begin + i * 5;
        int endI = beginI + 4;
        mArr[i] = getMedian(arr, beginI,endI);
    }
    return select(arr,0 , (int)mArr.size()-1,(int)mArr.size()/2);
    
}

//划分过程
vector<int> partition(vector<int> &arr,int begin,int end,int pivotValue) {
    int small = begin - 1;
    int cur = begin;
    int big = end + 1;
    while (cur != big) {
        if (arr[cur] < pivotValue) {
            swap(arr[++small], arr[cur++]);
        } else if (arr[cur] > pivotValue) {
            swap(arr[cur], arr[--big]);
        } else {
            cur++;
        }
    }
    vector<int> range(2,0);
    range[0] = small + 1;
    range[1] = big - 1;
    return range;
}

//求解中位数
int getMedian(vector<int>arr,int begin,int end) {
    insertionSort(arr, begin, end);
    int sum = end + begin;
    int mid = (sum / 2) + (sum % 2);
    return arr[mid];
}

//插入排序
void insertionSort(vector<int> &arr,int begin,int end) {
    for (int i = begin+1; i <= end; i++) {
        for (int j = i; j > begin; j--) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
            } else {
                break;
            }
        }
    }
}


vector<int> NormalAlgorithm::findMinKNumber(vector<int> &arr, int k) {
    /**
     1.构建一个拥有K个元素的大根堆
     2.将剩余的元素依次与根元素比较：
     2.1：如果比较元素大于根元素，那么直接跳过
     2.2：否则的话插入到堆中
     3.输出堆中的元素就是最小的K个元素
     */
    if (arr.size() < k) {
        return arr;
    }
    priority_queue<int> maxHeap;
    for (int i = 0; i < k; i++) {
        maxHeap.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++) {
        if (arr[k] > maxHeap.top()) {
            continue;
        } else {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    vector<int> rest;
    while (!maxHeap.empty()) {
        int val = maxHeap.top();
        rest.push_back(val);
        maxHeap.pop();
    }
    return rest;
}

int bucket(int num,int len,int min,int max) {
    return (int)((num - min)*len/(max-min));
}

int NormalAlgorithm::calMaxGap(vector<int> &arr) {
    if (arr.size() == 0 || arr.size() < 2) {
        return 0;
    }
    int min = INT_MIN;
    int max = INT_MAX;
    int len = (int)arr.size();
    for (int i = 0; i < arr.size(); i++) {
        min = std::min(min, arr[i]);
        max = std::max(max, arr[i]);
    }
    if (min == max) {
        return 0;
    }
    vector<bool> hasNum(len+1,false);
    vector<int> maxs(len+1,0);
    vector<int> mins(len+1,0);
    int bid = 0;
    for (int i = 0; i < len; i++) {
        bid = bucket(arr[i], len, min, max);
        mins[bid] = hasNum[bid] ? std::min(mins[bid], arr[i]) : arr[i];
        maxs[bid] = hasNum[bid] ? std::max(maxs[bid], arr[i]) : arr[i];
        hasNum[bid] = true;
    }
    int res = 0;
    //因为0号桶放的是最小值
    int lastMax = maxs[0];
    int i = 1;
    for (; i <= len; i++) {
        if (hasNum[i]) {
            res = std::max(res, mins[i] - lastMax);
            lastMax = maxs[i];
        }
    }
    return res;
}


vector<int> NormalAlgorithm::getMaxWindow(vector<int> arr,int w) {
    /**普通方法:
     1.设置begin和end变量,表示窗口的开始和结束
     2.begin和end每次移动一步,计算窗口中的最大值,并加入到res数组
     3.返回res结果数组
     时间复杂度:
     O(N*w)
     **/
    /**
     时间复杂度为O(N)的解法
     arr = [4,3,5,4,3,3,6,7];
     w = 3;
     */
    vector<int> res;
    if (arr.size() == 0 || w < 1 || arr.size() < w) {
        return res;
    }
    deque<int> deque;
    for (int i = 0; i < arr.size(); i++) {
        while (!deque.empty() && arr[deque.back()] <= arr[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
        if (deque.front() == (i - w)) {
            deque.pop_front();
        }
        if (i >= w-1) {
            res.push_back(arr[deque.front()]);
        }
    }
    return res;
}

void NormalAlgorithm::quickPation(vector<int> &arr, int target) {
    //边界判断
    if (arr.size() == 0) {
        return;
    }
    //开始划分
    int less = -1;  //只存放小于target的值,不存放等于的值
    int more = (int)arr.size();
    int cur = 0;
    while (cur < more) {
        if (arr[cur] < target) {
            swap(arr[++less], arr[cur++]);
        } else if (arr[cur] > target) {
            swap(arr[--more], arr[cur]);
        } else {
            cur++;
        }
    }
}


int NormalAlgorithm::BSearch(vector<int> arr, int target) {
    int left = 0;
    int right = (int)arr.size()-1;
    while (left <= right) {
        int middle = (left + right)/2;
        int m_val = arr[middle];
        if (m_val == target) return middle;
        //右边有序
        if (m_val < arr[right]) {
            if (target > m_val && target <= arr[right]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        else {
            if (target < m_val && target >= arr[left]) {
                right = middle - 1;
               
            } else {
                left = middle + 1;
            }
        }
    }
    
    return -1;
}

/**
 输入："abbaca"
 输出："ca"
 解释：
 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
string NormalAlgorithm::removeDuplicates(string S) {
    stack<char> st;
    for (char &c : S) {
        if (st.empty() || st.top() != c) {
            st.push(c);
        } else {
            st.pop();
        }
    }
    string res = "";
    //注意：这里用插入的方式时间会很慢，因为需要进行移位插入操作，如果字符串很大很多的话，时间浪费会很多，不如先收集起来，然后再翻转时间复杂度好
//    while (!st.empty()) {
//        res.insert(res.begin(), st.top());
//        st.pop();
//    }
    while(!st.empty()) {
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

/**
 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

 整数除法仅保留整数部分。

  

 示例 1：

 输入：s = "3+2*2"
 输出：7
 示例 2：

 输入：s = " 3/2 "
 输出：1
 示例 3：

 输入：s = " 3+5 / 2 "
 输出：5


 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/basic-calculator-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int NormalAlgorithm::calculate(string s) {
    char preSign = '+';
    vector<int> arr;
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        //如果是数字怎么处理；
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        //如果是符号或者到达末尾的时候触发计算
        if ((!isdigit(s[i]) && !isspace(s[i])) || (i == s.length()-1)) {
            switch (preSign) {
                case '+':
                {
                    arr.push_back(num);
                }
                    break;
                case '-':
                {
                    arr.push_back(-num);
                }
                    break;
                case '*':
                {
                    int val = arr.back() * num;
                    arr.pop_back();
                    arr.push_back(val);
                }
                    break;
                case '/':
                {
                    int val = arr.back() / num;
                    arr.pop_back();
                    arr.push_back(val);
                }
                    break;
                    
                default:
                    break;
            }
            num = 0;
            preSign = s[i];
        }
    }
    int res = 0;
    for (auto &value : arr) {
        res+= value;
    }
    return res;
}

/**
 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 注意：答案中不可以包含重复的四元组。

 示例 1：

 输入：nums = [1,0,-1,0,-2,2], target = 0
 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 
 示例 2：
 输入：nums = [], target = 0
 输出：[]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/4sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//vector<vector<int>> NormalAlgorithm::fourSum(vector<int>& nums, int target) {
//
//}

/**
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

 注意：答案中不可以包含重复的三元组。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/3sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
vector<vector<int>> NormalAlgorithm::threeSum(vector<int>& nums) {
    /**
     需要注意：
     1、结果中不包含重复3元组
     2、3个数的和为0
     */
    vector<vector<int>> res;
    if (nums.size() < 3) return {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        //确定第一个数
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int target = -nums[i];
        //放在这里是主要是因为可能存在负数特别大，而正数部分特别小的情况，会丢失用例
        size_t k = nums.size() - 1;
        //确定第二个数
        for (int j = i+1; j < k; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) {
                continue;
            }
            //确定第三个数
            while (j < k && (nums[j] + nums[k] > target)) {
                k--;
            }
            if (j == k) {
                break;
            }
            if (nums[j] + nums[k] == target) {
                vector<int> temp = {nums[i],nums[j],nums[k]};
                res.push_back(temp);
            }
        }
    }
    return res;
}

/**
 说明：s中可能存在空白、非数字字符等其他符号
 要求：
    1、有符号数
    2、如果不是有效的数字，那么返回0
    3、如果中间有非数字，那么只返回前半段的数字
 */
int NormalAlgorithm::myAtoi(string s) {
    char sign = ' ';
    long res = 0;
    if (s.length() == 0) return 0;
    int i = 0;
    while (i < s.length()) {
        char temp = s[i];
        //去掉无用的前导空格
        if (temp == ' ' && res == 0) {
            i++;
            continue;
        }
        if (sign == ' ' && (temp == '+' || temp == '-')) {
            sign = temp;
            i++;
        } else if ((temp-'0') >= 0 && (temp-'0')<= 9) {
            if (sign == ' ') {
                sign = '+';
            }
            res = (res * 10) + (temp - '0');
            i++;
        } else {
            break;
        }
    }
    
    res = (sign == '+' ? res : -res);
    if (res >= INT32_MAX || res <= INT32_MIN) {
        return 0;
    }
    return res;
    
}
