/**
  * Author: Mei
  * Date: 2021-03-13 14:23
  * Description: 给定一个二叉树 返回所有从根节点到叶子节点的路径
  *
  */
#include <iostream>
#include <vector>
#include <queue>

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
    void getLeftMax(int *val, Tree *root) {
        if (root != nullptr) {
            que.push(root);
            *val = root->data;
        }
        while (!que.empty()) {
            int size = que.size();
            int flag = 1;
            while (size) { //表示每层的元素
                Tree *temp = que.front();
                que.pop(); //出队列
                if (temp->left != nullptr) {
                    que.push(temp->left);
                    if (flag == 1) { //只获取每层的最左边元素
                        *val = temp->left->data;
                        flag = 0;
                    }
                }
                if (temp->right != nullptr) {
                    que.push(temp->right);
                }
                --size;
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
    ch1->left = ch3;
    ch2->left = ch4;
    Solution s;
    int ret = 0;
    s.getLeftMax(&ret, root);
    cout << ret << endl;

    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete root;
    return 0;
}