#include <iostream>
#include <vector>
//深度优先搜索  一般结合递归和回溯
using namespace std;

const int dx[4] = {0, 0, 1, -1}; //方向数组
const int dy[4] = {1, -1, 0, 0};
int sx, sy, tx, ty;
int a[10][10],  //障碍坐标
        b[10][10]; //模拟走过的坐标
int ans = 0;
int n, m, t;
void dfs(int x, int y) {
    if (x == tx && y == ty) {
        ans++;
        return;
    }
    b[x][y] = 1; //当前走过的点
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m || b[xx][yy] || a[xx][yy])
            continue;
        b[xx][yy] = 1;
        dfs(xx, yy);
        b[xx][yy] = 0; //回溯
    }

}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> tx >> ty; //起点和终点坐标
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y; //障碍坐标
        a[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans << endl;

    return 0;
}