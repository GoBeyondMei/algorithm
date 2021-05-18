#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

//����
/**
 * i > 0ʱ  dp[i][j]�����������
 *              ��װ���i����Ʒ->dp[i-1][j];
 *              װ���i����Ʒ->v[i] + dp[i-1][j-w[i]]
 *
 * @param v  ��ÿ����Ʒ�ļ�ֵ
 * @param W  ��ÿ����Ʒ������
 * @return
 */
void Knapsack(int n, int c, int *w, int *p) { //c������ n����Ʒ����
    int f[100][100];
    int i = 0, j = 0;
    for (i = 1; i <= n; i++) { //i����Ʒ
        for (j = 1; j <= c; j++) { //w[j]��ʾj����Ʒ������
            f[i][j] = f[i - 1][j]; //��ѡ��ǰ��Ʒ
            if (j >= w[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + p[i]);
            }
        }
    }
    //��Ϊ����i++��j++��ѭ�������������һ��i��j���������Ҫ������
    cout << "������װ������ֵ�ǣ�" << f[i - 1][j - 1] << endl;
}

int main() {


    return 0;
}