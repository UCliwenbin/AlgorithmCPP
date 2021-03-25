//
//  Algorithm2.cpp
//  CToC++
//
//  Created by mac on 2020/6/17.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "Algorithm2.hpp"
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


Node * Algorithm2::copyRandomList(Node *head) {
    if (head == NULL) {
           return NULL;
       }
       map<Node*,Node*> map;
       Node *cur = head;
       while (cur) {
           Node *copyNode = new Node(cur->val);
           map[cur] = copyNode;
           cur = cur->next;
       }
       //map[A,A']
       cur = head;
       while (cur) {
           Node *copyNode = map[cur];
           copyNode->next = map[cur->next];
           if (cur->random) {
               copyNode->random = map[cur->random];
           } else {
               copyNode->random = NULL;
           }
       }
       return map[head];
}


Node* Algorithm2::copyRandomList2(Node *head) {
    /**
     解法思路:
     复制 && 插入
     
     1. head不为空的时候,原链表上,每遍历一个节点,复制一个节点出来
     2. 将复制出来的值依次插入到原列表中a->a'->b->b'->c->c'
     
     设置随机指针指向的位置
     1. 遍历原列表的每一个节点,确定出新节点随机指针的指向
     
     拆分链表,将原链表和复制链表分开
     */
    if (!head) {
        return NULL;
    }
    //插入
    Node *current = head;
    while (current) {
        Node *copyNode = new Node(current->val);
        copyNode->next = current->next;
        current->next = copyNode;
        current = current->next->next;
    }
    //设置随机节点
    current = head;
    while (current) {
        Node *copyNode = current->next;
        Node *randomNode = current->random;
        if (randomNode == NULL) {
            copyNode->random = NULL;
        } else {
            copyNode->random = randomNode->next;
        }
        current = current->next->next;
    }
    //将链表拆开
    current = head;
    Node *copyHead = NULL;
    Node *copyLast = NULL;
    while (current) {
        if (copyHead == NULL) {
            copyHead = current->next;
            copyLast = copyHead;
        } else {
            copyLast->next = current->next;
            copyLast = current->next;
        }
        current->next = copyLast->next;
        current = copyLast->next;
    }
    return copyHead;
}


int Algorithm2::removeDuplicates(vector<int> &nums) {
//1. 暴力删除法
//    for (int i = 0; i < nums.size(); i++) {
//        int currVal = nums[i];
//        auto begin = nums.begin()+i;
//        int length = 0;
//        for (int j = i+1; j < nums.size(); j++) {
//            if (currVal == nums[j]) {
//                length++;
//            }
//        }
//        if (length == 0) continue;
//        nums.erase(begin+1, begin+1+length);
//    }
//    return nums.size();
//    2. 题解的骚操作，快慢指针法
    int slow = 0,fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] == nums[slow]) {
            fast++;
        } else {
            slow++;
            nums[slow] = nums[fast];
            fast++;
        }
    }
    return slow;
    
}

//回溯
void backTrace(vector<int> &nums,vector<int> &trace,vector<vector<int>> &res) {
    if (trace.size() == nums.size()) {
        res.push_back(trace);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (find(trace.begin(),trace.end(),nums[i]) != trace.end()) {
            continue;
        }
        trace.push_back(nums[i]);
        backTrace(nums, trace, res);
        trace.pop_back();
    }
}

vector<vector<int>> Algorithm2::permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> track;
    backTrace(nums,track,res);
    return res;
}


bool Algorithm2::findNumber(vector<vector<int>> arr,int target) {
    
    if (arr.size() == 0 || arr[0].size() == 0) return false;
    int max_row = (int)arr.size()-1;  //行数
    int max_col = (int)arr[0].size()-1;
    //先找到左下角的坐标
    int row = max_row;
    int col = 0;
    while (row >= 0 && col <= max_col) {
        int curVal = arr[row][col];
        if (curVal == target) {
            return  true;
        } else if (curVal > target) {
            row--;
        } else {
            col++;
        }
    }
    return false;
}

int Algorithm2::findRepeatNumber(vector<int> &nums) {
    unordered_set<int> hashTable;
    for (int i = 0; i < nums.size(); i++) {
        if (hashTable.count(nums[i])) {
            return nums[i];
        } else {
            hashTable.insert(nums[i]);
        }
    }
    return 0;
}


string Algorithm2::replaceSpace(string s) {
    string replaceStr = "%20";
    string res;
    char replaced = ' ';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == replaced) {
            res.append(replaceStr);
        } else {
            res.push_back(s[i]);
        }
    }
    return res;
}

/**
 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 限制：

 0 <= 链表长度 <= 10000
 */


void collectListNode(ListNode *head,vector<int> &res) {
    if (head == NULL) return;
    collectListNode(head->next, res);
    res.push_back(head->val);
}

vector<int> Algorithm2::reversePrint(ListNode* head) {
    vector<int> res;
    collectListNode(head, res);
    return res;
}

void collectCircleNumber(vector<vector<int>>& matrix,int tr,int tc,int dr,int dc,vector<int> &res);
/**
思路：
    1、 确定每一圈打印的模型以及打印方式
    2、缩小规模
 
 */
vector<int> Algorithm2::spiralOrder(vector<vector<int>>& matrix) {
    int tr = 0;
    int tc = 0;
    int dr = (int)matrix.size()-1;
    int dc = (int)matrix[0].size()-1;
    vector<int> res;
    while (tr <= dr && tc <= dc) {
        collectCircleNumber(matrix, tr++, tc++, dr--, dc--, res);
    }
    return res;
}

//用来收集一圈的数据
void collectCircleNumber(vector<vector<int>>& matrix,int tr,int tc,int dr,int dc,vector<int> &res) {
    //定义一个游标
    size_t row = tr;
    size_t col = tc;
    //行矩阵
    if (tr == dr) {
        while (col <= dc) {
            res.push_back(matrix[tr][col++]);
        }
    }
    //列矩阵
    else if (tc == dc) {
        while (row <= dr) {
            res.push_back(matrix[row++][tc]);
        }
    }
    else {
        //top circle
        while (col < dc) {
            res.push_back(matrix[row][col++]);
        }
        //right circle
        while (row < dr) {
            res.push_back(matrix[row++][col]);
        }
        // bottom circle
        while (col > tc) {
            res.push_back(matrix[row][col--]);
        }
        // left circle
        while (row > tr) {
            res.push_back(matrix[row--][col]);
        }
    }
}

int fillMatrix(vector<vector<int>> &matrix,int tr,int tc,int dr,int dc,vector<int> nums,int index) {
    //定义一个游标
    size_t row = tr;
    size_t col = tc;
    //行矩阵
    if (tr == dr) {
        while (col <= dc) {
            matrix[tr][col++] = nums[index++];
        }
    }
    //列矩阵
    else if (tc == dc) {
        while (row <= dr) {
            matrix[row++][tc] = nums[index++];
        }
    }
    else {
        //top circle
        while (col < dc) {
            matrix[row][col++] = nums[index++];
        }
        //right circle
        while (row < dr) {
            matrix[row++][col] =  nums[index++];
        }
        // bottom circle
        while (col > tc) {
            matrix[row][col--] = nums[index++];
        }
        // left circle
        while (row > tr) {
            matrix[row--][col] = nums[index++];
        }
    }
    return index;
}
/**
 输入：n = 3
 输出：[[1,2,3],[8,9,4],[7,6,5]]
 */
vector<vector<int>> Algorithm2::generateMatrix(int n) {
    vector<int> nums;
    int allN = n * n;
    for (int i = 0; i < allN; i++) {
        nums.push_back(i+1);
    }
    int tr = 0;
    int tc = 0;
    int dr = n - 1;
    int dc = n - 1;
    int index = 0;
    vector<vector<int>> res(n,vector<int>(n));
    //填充完一圈再填充下一圈
    while (tr <= dr && tc <= dc && index < allN) {
       index = fillMatrix(res, tr++, tc++, dr--, dc--, nums,index);
    }
    return res;
}

/**
 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

 示例 1：

 输入：[3,4,5,1,2]
 输出：1
 
 示例 2：

 输入：[2,2,2,0,1]
 输出：0

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
int Algorithm2::minArray(vector<int>& numbers) {
    //二分查找方式
    int left = 0;
    int right = (int)numbers.size()-1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] < numbers[right]) {
            right = middle;
        } else if(numbers[middle] > numbers[right]) {
            left = middle+1;
        } else {
            right--;
        }
    }
    
    return numbers[left];
}

/**
 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

 [["a","b","c","e"],
 ["s","f","c","s"],
 ["a","d","e","e"]]

 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//上、下、左、右
static int direct[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

static bool dfs(vector<vector<char>>& board,string word,int i,int j,int k) {
    if (i >= board.size() || i < 0 || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
    if (k == word.size()-1) return true;
    char temp = word[k];
    board[i][j] = '\0';
    for (int i = 0; i < 4; i++) {
        if(dfs(board, word, i+direct[i][0], j+direct[i][1], k+1)) return true;
    }
    board[i][j] = temp;
    return false;
}
bool Algorithm2::exist(vector<vector<char>>& board, string word) {
    //使用深度优先遍历
    //先选点
    int M = (int)board.size();
    int N = (int)board[0].size();
    int k = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (dfs(board, word, i, j,k)) return true;
        }
    }
    return false;
}
