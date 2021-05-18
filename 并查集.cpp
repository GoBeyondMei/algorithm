#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>

//并查集
using namespace std;

class UnionFind {
public:
    int find(int x) {
        int root = x;
        while (father[root] != -1) {
            root = father[root];
        }
        while (x != root) { //路径压缩
            int original_father = father[x];
            father[x] = root;
            x = original_father;
        }
        return root;
    }

    int find1(int x) { //没有采用路径压缩的  当跟很深时退化为链表
        int root = x;
        while (father[root] != -1) {
            root = father[root];
        }
        return root;
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            father[root_x] = root_y;
            num_of_sets--;
        }
    }

    void add(int x) {
        if (!father.count(x)) {
            father[x] = -1;
            num_of_sets++;
        }
    }

    int get_num_of_sets() {
        return num_of_sets;
    }

private:
    // 记录父节点
    unordered_map<int, int> father;
    // 记录集合数量
    int num_of_sets = 0;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        UnionFind uf;
        for (int i = 0; i < isConnected.size(); i++) {
            uf.add(i);
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.get_num_of_sets();
    }
};

int main() {
    vector<vector<int>> v{{1, 0, 0},
                          {0, 1, 0},
                          {0, 0, 1}};
    Solution solu;
    cout << solu.findCircleNum(v) << endl;


    return 0;
}