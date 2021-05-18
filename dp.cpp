#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>
#include <array>

using namespace std;

int movingCount(int m, int n, int k) {
    int dx[] = {1, 0, -1, 0}; //��������
    int dy[] = {0, 1, 0, -1};


}

int climbStairs(int n) {
    int dp[n + 1]; //dp[i]��ʾ����i��ķ���
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int uniquePaths(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[m][n] = {{0}}; //dp[i][j] ��ʾ����(i,j)λ�õ�·����
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int dp[m][n]; //dp[i][j]��ʾ����(i,j)λ�õ��ϵ�·���ܺ���С
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) { //�������һ�и�����·���ܺ�
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + grid[0][i]; //��һ�еĸ���λ���ϵ�·���ܺ�
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
        }
    }
    return dp[m - 1][n - 1];
}

int get_min(int i, int j, vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int dx[3] = {1, 1, 1}; //��������  ����(i,j)λ���ܼ����·����  ֻ����������
    int dy[3] = {-1, 0, 1};
    int pos1, pos2, pos3;
    pos1 = pos2 = pos3 = matrix[i][j];
    for (int i = 0; i < 3; i++) {

    }
    if (i - 1 >= 0)
        pos1 = matrix[i][j] + matrix[i + dx[0]][i + dy[0]];
    if (i + 1 < m)
        pos2 = matrix[i][j] + matrix[i + dx[1]][i + dy[1]];
    if (j + 1 < n)
        pos3 = matrix[i][j] + matrix[i + dx[2]][i + dy[2]];
    return min(pos1, min(pos2, pos3));
}

int minFallingPathSum1(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int mx = INT_MAX;
    int dp[m][n]; //dp[i][j] ��ʾ(i, j)λ���ϵ���С�½�·����
    for (int i = 0; i < n; i++) { //���һ�е��½�·����Ϊ�䱾��
        dp[m - 1][i] = matrix[m - 1][i];
    }
    for (int i = m - 2; i >= 0; i--) { //�������Ϻü���һЩ
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = get_min(i, j, matrix);
            mx = min(dp[i][j], mx);
        }
    }
    return mx;
}

int minFallingPathSum(vector<vector<int>> &matrix) {
    // ��dp[i][j]Ϊ��i, jλ�õ���С·����
    int len = matrix.size();
    int dp[len + 1][len + 2];
    // �׿Ǵ���
    for (int i = 0; i < len + 1; i++) {
        dp[i][0] = INT_MAX;
        dp[i][len + 1] = INT_MAX;
    }
    for (int j = 0; j < len + 2; j++) {
        dp[0][j] = 0;
    }

    int ans = INT_MAX;
    for (int i = 1; i < len + 1; i++) {
        for (int j = 1; j < len + 1; j++) {
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
        }
    }
    for (int i = 1; i < len + 1; i++) {
        ans = min(ans, dp[len][i]);
    }
    return ans;
}

int main() {
    vector<int> v{3, 2, 5, 3, 1, 8};
    vector<vector<int>> obj{{2, 1, 3},
                            {6, 5, 4},
                            {7, 8, 9}};
    cout << minFallingPathSum(obj);

    return 0;
}