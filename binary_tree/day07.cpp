/**
  * Author: Mei
  * Date: 2021-03-13 14:23
  * Description: 合并二叉树
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

class Solution { //返回二叉树中节点等于val的子节点树
private:
    queue<Tree *> que;
public:
    Tree *searchBST(Tree *root, int val) {
        if (root == nullptr || root->data == val) {
            return root;
        }
        if (root->data > val) { //直接返回节点就行
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};

int main() {
    Tree *root = new Tree(4);
    Tree *ch1 = new Tree(2);
    Tree *ch2 = new Tree(1);
    Tree *ch3 = new Tree(3);
    Tree *ch4 = new Tree(7);
    root->left = ch1;
    root->right = ch4;
    ch1->left = ch2;
    ch1->right = ch3;

    Solution s;
    print_tree(s.searchBST(root, 2));


    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete root;
    return 0;
}