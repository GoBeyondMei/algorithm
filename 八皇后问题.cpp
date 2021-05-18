#include <iostream>
#include <vector>
#include <string>
//�˻ʺ�����(���û����㷨)
using namespace std;

void put_queen(int x, int y, vector<vector<int>> &attack) {
    static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    attack[x][y] = 1;
    for (int i = 1; i < attack.size(); i++) {
        for (int j = 0; j < 8; j++) { //����8������
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];
            if (nx >= 0 && ny < attack.size() && ny >= 0 && ny < attack.size()) {
                attack[nx][ny] = 1;
            }
        }
    }
}

void backtrack(int k, int n, //k��ʾ��ǰ��
               vector<string> &queue, //��Żʺ��λ��
               vector<vector<int>> &attack, //�ʺ󹥻���λ��
               vector<vector<string>> &solve) { //��Ž����
    if (k == n) {
        solve.push_back(queue);
        return;
    }
    //����0-(n-1)�У���̽�ʺ��λ��
    for (int i = 0; i < n; i++) {
        if (attack[k][i] == 0) {
            vector<vector<int>> tmp = attack;
            queue[k][i] = 'Q';
            put_queen(k, i, attack); //ȷ���ʺ���ĳ��λ��֮��  ��Ҫ��attack�������ʺ�Ĺ�����Χ��Ϊ1

            backtrack(k + 1, n, queue, attack, solve);
            attack = tmp; //����֮ǰ�Ľ��
            queue[k][i] = '.';
        }
        cout << solve.size() << endl;
    }
}

vector<vector<string>> solveNQueues(int n) {
    vector<vector<string>> solve; //�洢�����
    vector<vector<int>> attack; //��ǻʺ󹥻�λ��
    vector<string> queen; //��ǻʺ�λ��

    //��ʼ��attack��queen
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
    cout << "�˻ʺ���" << result.size() << "�ֽⷨ" << endl;
    //for (auto item : result) {
    //    for (auto it : item) {
    //        cout << it << endl;
    //    }
    //    cout << endl;
    //}

    return 0;
}