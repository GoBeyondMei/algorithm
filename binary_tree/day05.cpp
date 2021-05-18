/**
  * Author: Mei
  * Date: 2021-03-13 14:23
  * Description: 中序和后序构建二叉树
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
    Tree *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    Tree *
    build(vector<int>::iterator ib, vector<int>::iterator ie, vector<int>::iterator pb, vector<int>::iterator pe) {
        if (ib == ie) return NULL;
        vector<int>::iterator pe1 = pe - 1;
        Tree *tree = new Tree(*pe1);
        auto pos = find(ib, ie, *pe1);//查找中间节点
        tree->left = build(ib, pos, pb, pb + (pos - ib));
        tree->right = build(pos + 1, ie, pb + (pos - ib), pe1);
        return tree;
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
    vector<int> v1{9, 15, 7, 20, 3};
    print_tree(s.buildTree(v, v1));


    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete root;
    return 0;
}