/**
  * Author: Mei
  * Date: 2021-03-13 14:23
  * Description: 最大二叉树
  *
  */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tree {
    struct Tree *left;
    struct Tree *right;
    int data;

    Tree(int d) : data(d), left(nullptr), right(nullptr) {}
};

void print_tree(Tree *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        print_tree(root->left);
        print_tree(root->right);
    }
}

class Solution { //给定一个二叉树 返回所有从根节点到叶子节点的路径
private:
    queue<Tree *> que;
public:
    Tree *buildTree(vector<int> &nums) {
        return build(nums, 0, nums.size());
    }

    Tree *
    build(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return NULL;
        }
        int maxValue = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxValue]) {
                maxValue = i;
            }
        }
        Tree *t = new Tree(nums[maxValue]);
        t->left = build(nums, left, maxValue);
        t->right = build(nums, maxValue + 1, right);

        return t;
    }
};

int main() {
    Tree *root = new Tree(1);
    Tree *ch1 = new Tree(2);
    Tree *ch2 = new Tree(3);
    Tree *ch3 = new Tree(5);
    Tree *ch4 = new Tree(4);
    root->left = ch1;
    root->right = ch2;
    ch1->left = ch3;
    ch2->left = ch4;
    Solution s;
    int ret = 0;
    vector<int> v{9, 3, 15, 20, 7};
    print_tree(s.buildTree(v));


    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete root;
    return 0;
}