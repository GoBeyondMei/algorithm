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

class Solution { //给定一个二叉树 返回所有从根节点到叶子节点的路径
private:
    vector<int> path;
    vector<string> result;
public:
    vector<string> binaryTreePaths(Tree *root) {
        if (root == nullptr) return {};
        tractback(root);
        return result;
    }
    void tractBack(Tree *root) {
        path.push_back(root->data);
        if (root->left == nullptr && root->right == nullptr) {
            string str;
            for (int i = 0; i < path.size() - 1; i++) {
                str += to_string(path[i]);
                str += "->";
            }
            str += to_string(path[path.size() - 1]);
            result.push_back(str);
            return;
        }
        if (root->left) { //采用回溯法  当一个元素左右为空并且处理过 取出(回溯到上一个元素)该元素
            tractback(root->left);
            path.pop_back();
        }
        if (root->right) {
            tractback(root->right);
            path.pop_back();
        }
    }

    void print_path() {
        int flag = 1;
        for (auto s : result) {
            if (flag == 1) {
                cout << s;
                flag = 0;
            } else {
                cout << "," << s;
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
    ch1->left = ch4;
    Solution s;
    s.binaryTreePaths(root);
    s.print_path();

    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete root;
    return 0;
}