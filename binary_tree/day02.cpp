/**
  * Author: Mei
  * Date: 2021-03-13 14:23
  * Description: 给定一个二叉树 返回所有从根节点到叶子节点的路径
  *
  */
#include <iostream>
#include <vector>

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

class Solution1 { //给定一个二叉树 返回所有从根节点到叶子节点的路径
private:
    vector<int> path;
    vector<string> result;
public:
    void binaryTreePaths(int *res, Tree *root) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                *res += root->left->data;
                binaryTreePaths(res, root->left);
            }
            if (root->right != nullptr) {
                binaryTreePaths(res, root->right);
            }
        }
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
    ch1->right = ch3;
    //ch2->left = ch4;
    Solution1 s;
    int res = 0;
    s.binaryTreePaths(&res, root);
    cout << res << endl;

    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete root;
    return 0;
}