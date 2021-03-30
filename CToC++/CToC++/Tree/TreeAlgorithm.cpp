//
//  TreeAlgorithm.cpp
//  CToC++
//
//  Created by mac on 2020/5/10.
//  Copyright © 2020 lwb. All rights reserved.
//

#include "TreeAlgorithm.hpp"
#include <vector>
#include <stack>
#include <sstream>
#include "TestTool.hpp"
#include <unordered_map>

TreeNode * constructBinaryTree(vector<int> pre,int pre_star,int pre_end,vector<int> vin,int in_star,int in_end) {
    int rootVal = pre[pre_star];
    TreeNode *root = new TreeNode(rootVal);
    //在中序中找到rootVal的位置
    int r;
    for (r = in_star; r <= in_end; r++) {
        if (vin[r] == rootVal) {
            break;
        }
    }
    
    int leftLen = r - in_star;
    int rightLen = in_end - r;
    if (leftLen > 0) {
        //开始构建左子树
        root->left = constructBinaryTree(pre,pre_star+1,pre_star+leftLen,vin,in_star,r-1);
    }
    
    if (rightLen > 0) {
        //开始构建o右子树
        root->right = constructBinaryTree(pre, pre_star+leftLen+1, pre_end, vin,r+1,in_end);
    }
    return root;
}

TreeNode* TreeAlgorithm::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    return constructBinaryTree(pre, 0, (int)pre.size()-1, vin, 0, (int)vin.size()-1);
}

void innerCreateBinaryTree(TreeNode *parent, TreeNode * &root,vector<int> &arr,int index) {
    if (index >= arr.size()) {
        return;
    }
    root = new TreeNode(arr[index]);
    root->parent = parent;
    innerCreateBinaryTree(root,root->left, arr, 2 * index + 1);
    innerCreateBinaryTree(root,root->right, arr, 2 * index + 2);
}

TreeNode* TreeAlgorithm::createBinaryTree(vector<int> arr) {
    TreeNode *root = NULL;
    innerCreateBinaryTree(NULL,root, arr, 0);
    return root;
}

void TreeAlgorithm::traverseTreePreOrder(TreeNode *root) {
    if (root != NULL) {
        cout<<root->val<<' ';
        traverseTreePreOrder(root->left);
        traverseTreePreOrder(root->right);
    }
}

void TreeAlgorithm::traverseTreePreOrderUsingStack(TreeNode *root) {
    if (!root) {
        cout<<" "<<endl;
        return;
    }
    stack<TreeNode *> treeStack;
    TreeNode *current = root;
    treeStack.push(current);
    while (!treeStack.empty()) {
        TreeNode *topNode = treeStack.top();
        treeStack.pop();
        cout<<topNode->val<<ends;
        if (topNode->right) {
            treeStack.push(topNode->right);
        }
        if (topNode->left) {
            treeStack.push(topNode->left);
        }
    }
    
}

void TreeAlgorithm::traverseTreeInOrderUsingStack(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode *> treeStack;
    TreeNode *currentNode = root;
    while (!treeStack.empty() || currentNode) {
        if (currentNode) {
            treeStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            TreeNode *topNode = treeStack.top();
            treeStack.pop();
            cout<<topNode->val<<ends;
            currentNode = topNode->right;
        }
    }
}

void TreeAlgorithm::traverseTreeInOrder(TreeNode *root) {
    if (root == NULL)
        return;
    traverseTreeInOrder(root->left);
    cout<<root->val<<' ';
    traverseTreeInOrder(root->right);
}

void TreeAlgorithm::traverseTreeBackOrder(TreeNode *root) {
    if (root != NULL) {
        traverseTreeBackOrder(root->left);
        traverseTreeBackOrder(root->right);
        cout<<root->val<<' ';
     }
}

void TreeAlgorithm::traverseTreeBackOrderUsingStack(TreeNode *root) {
    if (!root) {
        return;
    }
    stack<TreeNode *> treeStack1;
    stack<TreeNode *> treeStack2;
    TreeNode *current = root;
    treeStack1.push(current);
    while (!treeStack1.empty()) {
        current = treeStack1.top();
        treeStack1.pop();
        treeStack2.push(current);
        if (current->left != NULL) {
            treeStack1.push(current->left);
        }
        if (current->right != NULL) {
            treeStack1.push(current->right);
        }
    }
    while (!treeStack2.empty()) {
        TreeNode *topNode = treeStack2.top();
        treeStack2.pop();
        cout<<topNode->val<<ends;
    }
}

//给定一个节带Parent的TreeNode节点,找出它的后继节点
TreeNode * TreeAlgorithm::findSuccessorNode(TreeNode *root,TreeNode *node) {
/**
 思路:
 所谓找出后继节点,其实是按照中序遍历的方式来找的,所以这里的思路有两种:
 法一:
 1.根据给定的node节点,利用parent指针,依次向上找,找到root节点
 2.利用root节点,进行一次中序遍历
 3.将遍历后的结果依次比对,找到对应节点的后继节点,并输出
 4.但这个如果全补是整数,且里面含有相同值的时候,算法是失效的
 时间复杂对位3*O(n)
 法二:
  通过分析找出规律:
 1.如果给定的节点右子树不为空,那么他的后继节点为右子树最左边的节点;
 2.如果右子树为空(说明其并非一个子树的根节点),那么他的后继节点应该是他所属子树的左子树的根节点
 */
    if (root == NULL) {
        return NULL;
    }
    if (node->right != NULL) {
        TreeNode *subTreeNode = node->right;
        while (subTreeNode->left != NULL) {
            subTreeNode = subTreeNode->left;
        }
        return subTreeNode;
    }
    TreeNode *parent = node->parent;
    TreeNode *current = node;
    while (parent != NULL && parent->left != current) {
        current = parent;
        parent = parent->parent;
    }
    return parent;
}


TreeNode* TreeAlgorithm::findPreSuccessorNode(TreeNode *root,TreeNode *node) {
    if (root == NULL) {
        return NULL;
    }
    if (node->left != NULL) {
        TreeNode *current = node->left;
        while (current->right != NULL) {
            current = current->right;
        }
        return current;
    }
    TreeNode *parent = node->parent;
    TreeNode *current = node;
    while (parent != NULL && parent->right != current) {
        current = parent;
        parent = parent->parent;
    }
    return parent;
}

TreeNode * constructTreeFromArray(vector<int> &array,int L,int R) {
    if (L == R) {
        TreeNode *node = new TreeNode(array[R]);
        return node;
    } else if (L > R) {
        return NULL;
    } else {
        int val = array[R];
        TreeNode *node = new TreeNode(val);
        int i = L;
        for (; i <R; i++) {
            if (array[i] > val) {
                break;
            }
        }
        node->left = constructTreeFromArray(array,L,i-1);
        node->right = constructTreeFromArray(array,i,R-1);
        return node;
    }
}

TreeNode *TreeAlgorithm::reconstructSearchBinary(vector<int> &array) {
    /**
     1.这个数组已经是一个搜索二叉树后续遍历的结果了
     2.根据规律,最后一个节点,必然是整颗树的根节点
     3.左孩子是小于根节点的节点
     4.右孩子是大于根节点的节点
     5.递归求解
     */
    if (array.size() == 0) {
        return NULL;
    } else {
        return constructTreeFromArray(array, 0, (int)array.size()-1);
    }
}
/**
  输入: root = [2,1,3], p = 1
   2
   / \
  1   3
  输出: 2
分析:因为是搜索二叉树,所以中序遍历以后,序列是升序的;
 左<中<右
 如果给定的p值>root,那么其后继一定是在右子树,或者没有后继
 如果给定的p值<root,那么:
 1.其后继如果不是在root上,
 2.那么一定在其左子树上
 */
TreeNode* TreeAlgorithm::inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == NULL) {
        return NULL;
    }
    if (p->val >= root->val) {
        return inorderSuccessor(root->right, p);
    } else {
        TreeNode *left = inorderSuccessor(root->left, p);
        return left ? left : root;
    }
}

void traversalTree(TreeNode *root,string &s) {
    if (!root) {
        s += "#_";
        return;
    }
    stringstream ss;
    ss<<root->val<<"_";
    s += ss.str();
    traversalTree(root->left, s);
    traversalTree(root->right, s);
}

string TreeAlgorithm::serializeTree(TreeNode *root) {
    if (root == NULL) {
        return "#!";
    }
    string rest = "";
    traversalTree(root, rest);
    return rest;
}

void preTraversalCreateTree(TreeNode * &root,vector<string> &arr) {
    static int index = 0;
    if (arr[index] == "#") {
        index++;
        return;
    }
    if (root == NULL) {
        string val = arr[index++];
        root = new TreeNode(stoi(val));
        preTraversalCreateTree(root->left, arr);
        preTraversalCreateTree(root->right,arr);
        
    }
}

TreeNode * TreeAlgorithm::createTreeForString(string s) {
    vector<string> arr;
    string splitStr = "_";
    splitString(s,arr,splitStr);
    TreeNode *root = NULL;
    preTraversalCreateTree(root, arr);
    return root;
}

typedef struct ReturnVal {
    bool isBalance;
    int height;
    ReturnVal(bool isB,int h) {
        isBalance = isB;
        height = h;
    }
} *ReturnValue;

ReturnValue process(TreeNode *root) {
    if (root == NULL) {
        return new ReturnVal(true,0);
    }
    ReturnValue leftVal = process(root->left);
    if (!leftVal->isBalance) {
        return new ReturnVal(false,0);
    }
    ReturnValue rightVal = process(root->right);
    if (!rightVal->isBalance) {
        return new ReturnVal(false,0);
    }
    if (abs(leftVal->height - rightVal->height) > 1) {
        return new ReturnVal(false,0);
    }
    int length = max(leftVal->height, rightVal->height);
    return new ReturnVal(true,length+1);
    
}

bool TreeAlgorithm::isBalanceBinaryTree(TreeNode *root) {
    return process(root)->isBalance;
}


TreeNode *TreeAlgorithm::invertTree(TreeNode *root) {
    /**
     使用前序遍历
     */
//    if (root == NULL) {
//        return NULL;
//    }
//    TreeNode *temp = root->left;
//    root->left = root->right;
//    root->right = temp;
//    invertTree(root->left);
//    invertTree(root->right);
//    return root;
    //使用后续遍历
    if (root == NULL) {
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    if (root->left || root->right) {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}


/// 构造一个最大值的二叉树
/// @param nums 数组
/// @param L 数组左边索引
/// @param R 数组右边索引
TreeNode *constructMaxBinaryTree(vector<int> &nums,int L,int R) {
    if (L == R) {
        return new TreeNode(nums[L]);
    }
    if (L > R) {
        return NULL;
    }
//    找出最大值的下标
    int maxIndex = L;
    int cur = L+1;
    while (cur <= R) {
        if (nums[cur] > nums[maxIndex]) {
            maxIndex = cur;
        }
        cur++;
    }
    TreeNode *root = new TreeNode(nums[maxIndex]);
    root->left = constructMaxBinaryTree(nums, L, maxIndex-1);
    root->right = constructMaxBinaryTree(nums, maxIndex+1, R);
    return root;
}

TreeNode* TreeAlgorithm::constructMaximumBinaryTree(vector<int>& nums) {
    
    return constructMaxBinaryTree(nums, 0, (int)nums.size()-1);
}

string traveTree(TreeNode *root,unordered_map<string, int> &map,vector<TreeNode *> &res) {
    if (root == NULL) {
        return "#";
    }
    string left = traveTree(root->left, map, res);
    string right = traveTree(root->right, map, res);
    //子树的形状
    string subTree = left+","+right+","+to_string(root->val);
    if (map[subTree] == 1) {
        res.push_back(root);
    }
    map[subTree]++;
    return subTree;
}

vector<TreeNode*> TreeAlgorithm::findDuplicateSubtrees(TreeNode* root) {
    //知道自己长啥样
//    知道别人长啥样
    unordered_map<string, int> map;
    vector<TreeNode *> res;
    traveTree(root, map, res);
    return res;
}


//解法1：纯递归解法
bool searchCommonAncestor(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *res) {
    if (root == NULL) {
        return false;
    }
    bool left = searchCommonAncestor(root->left,p,q,res);
    bool right = searchCommonAncestor(root->right,p,q,res);
    if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))) {
        res = root;
    }
    return left || right || root->val == p->val || root->val == q->val;
}

//解法2：找出从根到某一个节点的路径，然后找出2条路径最后一个相同的节点
static bool flag = false;
void getPath(TreeNode *root,TreeNode *node,vector<TreeNode *> &path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root);
    if (root == node) {
        flag = true;
        return;
    }
    getPath(root->left, node, path);
    getPath(root->right, node, path);
    if (flag) {
        return;
    }
    path.pop_back();
}


TreeNode* TreeAlgorithm::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *res = NULL;
    searchCommonAncestor(root, p,q,res);
    return res;
}

/**
 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

 假设一个二叉搜索树具有如下特征：

 节点的左子树只包含小于当前节点的数。
 节点的右子树只包含大于当前节点的数。
 所有左子树和右子树自身必须也是二叉搜索树。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/validate-binary-search-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

void inOrderTravel(TreeNode *root,vector<int> &arr) {
    if (root == NULL) return;
    inOrderTravel(root->left, arr);
    arr.push_back(root->val);
    inOrderTravel(root->right, arr);
}
bool TreeAlgorithm::isValidBST(TreeNode* root) {
//    if (root == NULL) return true;
//    //左子树是二叉，右子树也是二叉
//    bool lt = isValidBST(root->left);
//    bool rt = isValidBST(root->right);
//
//    bool leftOk = true;
//    bool rightOk = true;
//    if (root->left && root->val < root->left->val) {
//        leftOk = false;
//    }
//    if (root->right && root->val > root->right->val) {
//        rightOk = false;
//    }
//    return lt && rt && leftOk && rightOk;
    vector<int> resArray;
    inOrderTravel(root, resArray);
    if (resArray.size() < 2) {
        return true;
    }
    //判断是否是升序
    bool isAscending = true;
    for (int i = 1; i < resArray.size(); i++) {
        int temp = i - 1;
        if (resArray[temp] > resArray[i]) {
            isAscending = false;
            break;
        }
    }
    return isAscending;
}

/**
 序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

      _9_
     /   \
    3     2
   / \   / \
  4   1  #  6
 / \ / \   / \
 # # # #   # #
 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

 你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
bool TreeAlgorithm::isValidSerialization(string preorder) {
    
    int slots = 1;  //默认是1个槽位（放入根节点数字以后，slots++），这时slots = 2；
    size_t i = 0;
    size_t n = preorder.length();
    while (i < n) {
        //提前没有槽子放东西了，那就直接返回false
        if (slots == 0) {
            return false;
        }
        if (preorder[i] == ',') {
            i++;
        } else if (preorder[i] == '#') {
            slots--;
            i++;
        } else {
            //多位数要作为一个数，所以这里需要跳过一下
            while (i < n && preorder[i] != ',') {
                i++;
            }
            slots++;
        }
    }
    return slots == 0;
    
}


vector<int> TreeAlgorithm::inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode *> stack;
    while (root != NULL || !stack.empty()) {
        //如果有左边的节点，那就一直往左穿
        while (root != NULL) {
            stack.push(root);
            root = root->left;
        }
        TreeNode *node = stack.top();
        stack.pop();
        res.push_back(node->val);
        root = node->right;
    }
    return res;
}
