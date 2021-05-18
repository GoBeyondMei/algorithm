/**
  * Author: Mei
  * Date: 2021-02-27 18:43
  * Description: 
  *
  */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isMirror(TreeNode *u, TreeNode *v) {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);
        while(!queue.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
int main() {




    return 0;
}