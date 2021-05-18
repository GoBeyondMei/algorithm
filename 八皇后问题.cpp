#include <iostream>
#include <vector>
#include <string>
//八皇后问题(采用回溯算法)
using namespace std;

void put_queen(int x, int y, vector<vector<int>> &attack) {
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    attack[x][y] = 1;
    for (int i = 1; i < attack.size(); i++) {
        for (int j = 0; j < 8; j++) { //遍历8个方向
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];
            if (nx >= 0 && ny < attack.size() && ny >= 0 && ny < attack.size()) {
                attack[nx][ny] = 1;
            }
        }
    }
}

void backtrack(int k, int n, //k表示当前行
               vector<string> &queue, //存放皇后的位置
               vector<vector<int>> &attack, //皇后攻击的位置
               vector<vector<string>> &solve) { //存放结果集
    if (k == n) {
        solve.push_back(queue);
        return;
    }
    //遍历0-(n-1)列，试探皇后的位置
    for (int i = 0; i < n; i++) {
        if (attack[k][i] == 0) {
            vector<vector<int>> tmp = attack;
            queue[k][i] = 'Q';
            put_queen(k, i, attack); //确定皇后在某个位置之后  需要把attack中其它皇后的攻击范围置为1

            backtrack(k + 1, n, queue, attack, solve);
            attack = tmp; //回退之前的结果
            queue[k][i] = '.';
        }
        cout << solve.size() << endl;
    }
}

vector<vector<string>> solveNQueues(int n) {
    vector<vector<string>> solve; //存储最后结果
    vector<vector<int>> attack; //标记皇后攻击位置
    vector<string> queen; //标记皇后位置

    //初始化attack和queen
    for (int i = 0; i < n; i++) {
        attack.push_back((vector<int>()));
        for (int j = 0; j < n; j++) {
            attack[i].push_back(0);
        }
        queen.push_back("");
        queen[i].append(n, '.');
    }
    backtrack(0, n, queen, attack, solve);

    return solve;
}

int main() {
    vector<vector<string>> result;
    result = solveNQueues(4);
    cout << "八皇后共有" << result.size() << "种解法" << endl;
    //for (auto item : result) {
    //    for (auto it : item) {
    //        cout << it << endl;
    //    }
    //    cout << endl;
    //}

    return 0;
}