#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>
#include <array>
#include <numeric>
#include <stack>
#include <random>
#include <time.h>

using namespace std;

//�������Ĳ�����ʵ�٣�
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

//�ݹ��ǰ���С��������
void preTree(TreeNode *root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preTree(root->left);
        preTree(root->right);
    }
}

void midTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    midTree(root->left);
    cout << root->val << " ";
    midTree(root->right);
}

void suffTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    suffTree(root->left);
    cout << root->val << " ";
    suffTree(root->right);
}

//�ǵݹ��ǰ���С���
void PreTree(TreeNode *root) {
    stack<TreeNode *> st;
    if (root == nullptr) return;
    st.push(root);
    while (!st.empty()) {
        TreeNode *t = st.top();
        st.pop();
        cout << t->val << " ";
        if (t->right != nullptr) st.push(t->right);
        if (t->left != nullptr) st.push(t->left);
    }
}

void MidTree(TreeNode *root) {
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *cur = root;
    while (!st.empty() || cur != nullptr) {
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top(); //��ס�����е�Ԫ��
            st.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }
}

void SuffTree(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {  //����ǰ��ĸ�����
        TreeNode *t = st.top();
        st.pop();
        if (t != nullptr) res.push_back(t->val);
        else
            continue;
        if (t->left) st.push(t->left);
        if (t->right) st.push(t->right);
    }
    reverse(res.begin(), res.end());
    for (auto item : res) {
        cout << item << " ";
    }
}

//��α���
void levelTree(TreeNode *root) {
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()) {
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            TreeNode *t = qu.front();
            qu.pop();
            cout << t->val << " ";
            if (t->left) qu.push(t->left);
            if (t->right) qu.push(t->right);
        }
    }
}

//����ͼ
void rightTree(TreeNode *root) {
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()) {
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            TreeNode *t = qu.front();
            qu.pop();
            if (i == size - 1)
                cout << t->val << " ";
            if (t->right) qu.push(t->right);
        }
    }
}

//���ƽ��ֵ
void avg_level_Tree(TreeNode *root) {
    queue<TreeNode *> qu;
    qu.push(root);
    int sum;
    while (!qu.empty()) {
        int size = qu.size();
        sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode *t = qu.front();
            qu.pop();
            sum += t->val;
            if (t->left) qu.push(t->left);
            if (t->right) qu.push(t->right);
        }
        cout << sum / size << " ";
    }
}

//��ת������
void reverse_tree(TreeNode *root) {
    if (root == nullptr) return;
    swap(root->left, root->right);
    reverse_tree(root->left);
    reverse_tree(root->right);
}

//�ǵݹ��ж϶������ĶԳ�
bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    queue<TreeNode *> qu;
    qu.push(root->left);
    qu.push(root->right);
    while (!qu.empty()) {
        TreeNode *leftNode = qu.front();
        qu.pop();
        TreeNode *rightNode = qu.front();
        qu.pop();
        if (!leftNode && !rightNode) continue;
        if (leftNode == nullptr && rightNode != nullptr ||
            leftNode != nullptr && rightNode == nullptr ||
            leftNode->val != rightNode->val) {
            return false;
        }
        qu.push(leftNode->left);
        qu.push(rightNode->right);
        qu.push(leftNode->right);
        qu.push(rightNode->left);
    }
    return true;
}

//�ݹ���������
int deepTree(TreeNode *root) {
    if (root == nullptr) return 0;
    int deep_left = deepTree(root->left);
    int deep_right = deepTree(root->right);
    return deep_left > deep_right ? deep_left + 1 : deep_right + 1;
}

//�ǵݹ������
int maxDeep(TreeNode *root) {
    queue<TreeNode *> qu;
    qu.push(root);
    int count = 0;
    while (!qu.empty()) {
        count++;
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            TreeNode *t = qu.front();
            qu.pop();
            if (t->left) qu.push(t->left);
            if (t->right) qu.push(t->right);
        }
    }
    return count;
}

//��С���(�Ӹ��ڵ㵽�����Ҷ�ӽڵ�ĳ���)
int minDeep(TreeNode *root) {
    if (root == nullptr) return 0;
    int deep_left = deepTree(root->left);
    int deep_right = deepTree(root->right);
    if (root->left == nullptr && root->right != nullptr) {
        return 1 + deep_right;
    }
    if (root->left != nullptr && root->right == nullptr) {
        return 1 + deep_left;
    }
    return deep_left < deep_right ? deep_left + 1 : deep_right + 1;
}

//�ڵ����
void countNode(TreeNode *root, int &count) {
    if (root == nullptr) return;
    count++;
    countNode(root->left, count);
    countNode(root->right, count);
}

//������
void makeMaxHeap(vector<int> &nums, int i, int size) {
    int temp = nums[i]; //���游�ڵ�
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && nums[k] < nums[k + 1]) { //�ҽڵ������ڵ�
            ++k;
        }
        if (temp < nums[k]) {
            nums[i] = nums[k];
            i = k;  //������һ����Ҫ������λ��
        } else {
            break;
        }
    }
    nums[i] = temp;
}

void makeMinHeap(vector<int> &nums, int i, int size) { //����С����
    int temp = nums[i]; //���游�ڵ�
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && nums[k] > nums[k + 1]) { //�ҽڵ�С����ڵ�
            ++k;
        }
        if (temp > nums[k]) {
            nums[i] = nums[k];
            i = k;  //������һ����Ҫ������λ��
        } else {
            break;
        }
    }
    nums[i] = temp;
}

//�������ĸ߶�(���������
int getDepth(TreeNode *node) {
    if (node == nullptr) return 0;
    int leftDepth = getDepth(node->left);
    if (leftDepth == -1) return -1;
    int rightDepth = getDepth(node->right);
    if (rightDepth == -1) return -1;

    int result;
    if (abs(leftDepth - rightDepth) > 1) {
        result = -1;
    } else {
        result = 1 + max(leftDepth, rightDepth);
    }
    return result;
}

//�������������·��
void getPath(TreeNode *node, vector<int> &path, vector<string> &result) {
    path.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
        string sPath;
        for (int i = 0; i < path.size() - 1; i++) {
            sPath += to_string(path[i]);
            sPath += "->"; //���һ���ڵ㲻��Ҫ->
        }
        sPath += to_string(path[path.size() - 1]);
        result.push_back(sPath);
        return;
    }
    if (node->left) {
        getPath(node->left, path, result);
        path.pop_back();
    }
    if (node->right) {
        getPath(node->right, path, result);
        path.pop_back();
    }
}

void traversal(TreeNode *node, vector<int> &path, vector<string> &result) {
    path.push_back(node->val);
    //�����ҽڵ�Ϊ��ʱ  ����һ��������·��
    if (node->left == nullptr && node->right == nullptr) {
        string m_path;
        for (int i = 0; i < path.size() - 1; i++) {
            m_path += to_string(path[i]);
            m_path += "->";
        }
        m_path += to_string(path[path.size() - 1]);
        result.push_back(m_path);
        return;
    }
    if (node->left) {
        traversal(node->left, path, result);
        path.pop_back(); //����
    }
    if (node->right) {
        traversal(node->right, path, result);
        path.pop_back(); //����
    }
}

//�ǵݹ�������·��
vector<string> binaryTreePaths(TreeNode *root) {
    stack<TreeNode *> treeSt;
    stack<string> pathSt; //��ű���·��
    vector<string> result; //����·������
    if (root == nullptr) return result;
    treeSt.push(root);
    pathSt.push(to_string(root->val));
    while (!treeSt.empty()) {
        TreeNode *cur = treeSt.top();
        treeSt.pop();
        string path = pathSt.top();
        pathSt.pop();
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
        }
        if (cur->right) {
            treeSt.push(cur->right);
            pathSt.push(path + "->" + to_string(cur->right->val));
        }
        if (cur->left) {
            treeSt.push(cur->left);
            pathSt.push(path + "->" + to_string(cur->left->val));
        }
    }
    return result;
}

//��Ҷ��֮��
//1����ǰ�� 2��
void getLeftSum(TreeNode *root, int &result) {
    if (root == nullptr) return;
    if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
        result += root->left->val;
    }
    getLeftSum(root->left, result);
    getLeftSum(root->right, result);
}

//�ҵ����½ǵ�ֵ
int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> qu;
    qu.push(root);
    int res = 0;
    while (!qu.empty()) {
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            TreeNode *t = qu.front();
            qu.pop();
            if (i == 0) res = t->val;
            if (t->left) qu.push(t->left);
            if (t->right) qu.push(t->right);
        }
    }
    return res;
}

//·���ܺ�
void judgeSum(TreeNode *root, vector<int> &path, int sum, bool &res) {
    path.push_back(root->val);
    if (!root->left && !root->right) {
        int t = 0;
        for (int item : path) {
            t += item;
        }
        if (t == sum) res = true;
    }
    if (root->left) {
        judgeSum(root->left, path, sum, res);
        path.pop_back();
    }
    if (root->right) {
        judgeSum(root->right, path, sum, res);
        path.pop_back();
    }
}

//�����Ҫ�������Ŷ������Ͳ���Ҫ����ֵ �����ֻ����������һ������������·�����ݹ麯������Ҫ����ֵ��ʱ����
bool traversal(TreeNode *cur, int count) {
    if (!cur->left && !cur->right && count == 0) return true;
    if (!cur->left && !cur->right) return false;
    if (cur->left) {
        count -= cur->left->val;
        if (traversal(cur->left, count)) return true;
        count += cur->left->val; //����
    }
    if (cur->right) {
        count -= cur->right->val;
        if (traversal(cur->right, count)) return true;
        count += cur->right->val; //����
    }
    return false;
}

bool iter_traversal(TreeNode *cur, int count) {
    if (cur == nullptr)
        return false;
    stack<pair<TreeNode *, int>> st; //ջ�нڵ���Ҫ��¼�ڵ�ָ��ʹӸ��ڵ㵽�ýڵ���ܺ�
    st.push(make_pair(cur, cur->val));
    while (!st.empty()) {
        pair<TreeNode *, int> t = st.top();
        st.pop();
        if (!t.first->left && !t.first->right && t.second == count) {
            return true;
        }
        if (t.first->right) {
            st.push(make_pair(t.first->right, t.second + t.first->right->val));
        }
        if (t.first->left) {
            st.push(make_pair(t.first->left, t.second + t.first->left->val));
        }
    }
    return false;
}

void pathSum1(TreeNode *root, vector<int> &path, vector<vector<int>> &res, int targetSum) {
    if (!root->left && !root->right && targetSum == 0) {
        res.push_back(path);
        return;
    }
    if (!root->left && !root->right) return;
    if (root->left) {
        path.push_back(root->left->val);
        targetSum -= root->left->val;
        pathSum1(root->left, path, res, targetSum);
        //�����ǻ���
        targetSum += root->left->val;
        path.pop_back();
    }
    if (root->right) {
        path.push_back(root->right->val);
        targetSum -= root->right->val;
        pathSum1(root->right, path, res, targetSum);
        //�����ǻ���
        targetSum += root->right->val;
        path.pop_back();
    }
}

class Solution2 {
public:
    int cur = 0;
    bool flag = false;

    void dfs(TreeNode *root, int targetSum) {
        cur += root->val;
        cout << cur << endl;
        if (root == nullptr) {
            return;
        }
        if (!root->left && !root->right && cur == targetSum) {
            flag = true;
            return;
        }
        if (root->left) {
            dfs(root->left, targetSum);
            cur -= root->left->val;
        }
        if (root->right) {
            dfs(root->right, targetSum);
            cur -= root->right->val;
        }
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        dfs(root, targetSum);
        if (flag) return true;
        return false;
    }
};

//���·��
class Solution3 {
public:
    int cur = 0;
    int cnt = 0;
    bool flag = false;
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return;
        cur += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && cur == targetSum) {
            res.push_back(path);
            return;
        }
        if (root->left) {
            dfs(root->left, targetSum);
            cur -= root->left->val;
            path.pop_back();
        }
        if (root->right) {
            dfs(root->right, targetSum);
            cur -= root->right->val;
            path.pop_back();
        }
    }

    void pre_print(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        dfs(root, targetSum);
        pre_print(root->left, targetSum);
        pre_print(root->right, targetSum);
    }

    int pathSum(TreeNode *root, int targetSum) {
        pre_print(root, targetSum);
        return cnt;
    }
};

//��Ҷ��֮��
int sumOfLeftLeaves(TreeNode *root) { //�ú������
    if (root == nullptr) return 0;
    int leftValue = sumOfLeftLeaves(root->left);
    int rightValue = sumOfLeftLeaves(root->right);
    int value = 0;
    if (root->left && !root->left->left && !root->right->right) {
        value = root->left->val;
    }
    return value + leftValue + rightValue;
}

//���½ǵ�ֵ
int maxLen = INT_MIN; //��¼������
int maxleftValue;  //����������ڵ����ֵ
void getLeftValue(TreeNode *root, int leftLen) { //��α�������򵥵�
    //����
    if (root->left == nullptr && root->right == nullptr) {
        if (leftLen > maxLen) {
            maxLen = leftLen;
            maxleftValue = root->val;
        }
        return;
    }
    if (root->left) {
        ++leftLen;
        getLeftValue(root->left, leftLen);
        leftLen--;
    }
    if (root->right) {
        ++leftLen;
        getLeftValue(root->right, leftLen);
        leftLen--;
    }
}

//Ŀ���
bool traversal(TreeNode *root, int sum, int target) {
    sum += root->val;
    if (sum == target) return true;
    if (!root) {
        return false;
    }
    if (root->left) {
        if (traversal(root->left, sum, target)) return true;
        sum -= root->left->val;
    }
    if (root->right) {
        if (traversal(root->right, sum, target)) return true;
        sum -= root->right->val;
    }
}

TreeNode *sortList(TreeNode *head) {
    TreeNode *p = head->left;
    //head->next = nullptr;
    //TreeNode *n_head = new TreeNode(0);
    //n_head->next = head;
    //while (p != NULL) {
    //    TreeNode *q = p->next;
    //    TreeNode *pre = n_head;
    //    while (pre->next != nullptr && p->val > pre->next->val) {
    //        pre = pre->next;
    //    }
    //    p->next = pre->next;
    //    pre->next = p;
    //    p = q;
    //}
    //p = n_head->next;
    //delete n_head;
    return p;
}

#define MAX(x, y)((x) > (y) ? (x) : (y))

int main() {
    TreeNode *root = new TreeNode(5);
    TreeNode *node_2 = new TreeNode(10);
    TreeNode *node_3 = new TreeNode(8);
    TreeNode *node_4 = new TreeNode(1);
    TreeNode *node_5 = new TreeNode(25);
    TreeNode *node_6 = new TreeNode(12);
    TreeNode *node_7 = new TreeNode(7);
    //root->left = node_2;
    //root->right = node_3;
    //node_2->left = nullptr;
    //node_2->right = node_5;
    //node_3->left = node_6;
    //node_3->right = node_7;
    //node_4->left = nullptr;
    //node_4->right = nullptr;
    //node_5->right = nullptr;
    //node_5->left = nullptr;
    //node_6->right = nullptr;
    //node_6->left = nullptr;
    //node_7->left = nullptr;
    //node_7->right = nullptr;
    root->left = node_2;
    node_2->left = node_3;
    node_3->left = node_4;
    node_4->left = node_5;
    node_5->left = nullptr;
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    bool res = false;
    cout << boolalpha;
    cout << MAX(4, 8) << endl;
    //cout <<  << endl;
    //path.push_back(root->val);
    //pathSum1(root, path, result, 10 - root->val);
    //for (auto item : pathSum(root, 10, sum)) {
    //    for (int it : item) {
    //        cout << it << " ";
    //    }
    //    cout << endl;
    //}
    //cout << sum << endl;

    delete root;
    delete node_2;
    delete node_3;
    delete node_4;
    delete node_5;
    delete node_6;
    delete node_7;
    return 0;
}