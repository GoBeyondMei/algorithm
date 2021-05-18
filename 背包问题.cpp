#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

//背包
/**
 * i > 0时  dp[i][j]有两种情况：
 *              不装入第i件物品->dp[i-1][j];
 *              装入第i件物品->v[i] + dp[i-1][j-w[i]]
 *
 * @param v  是每件商品的价值
 * @param W  是每件商品的容量
 * @return
 */
void Knapsack(int n, int c, int *w, int *p) { //c是容量 n是物品个数
    int f[100][100];
    int i = 0, j = 0;
    for (i = 1; i <= n; i++) { //i是物品
        for (j = 1; j <= c; j++) { //w[j]表示j个物品的容量
            f[i][j] = f[i - 1][j]; //不选当前物品
            if (j >= w[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + p[i]);
            }
        }
    }
    //因为我是i++和j++，循环结束，多加了一次i和j，所以最后要减回来
    cout << "背包能装的最大价值是：" << f[i - 1][j - 1] << endl;
}

int main() {


    return 0;
}