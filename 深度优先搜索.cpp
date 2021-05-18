#include <iostream>
#include <vector>
//�����������  һ���ϵݹ�ͻ���
using namespace std;

const int dx[4] = {0, 0, 1, -1}; //��������
const int dy[4] = {1, -1, 0, 0};
int sx, sy, tx, ty;
int a[10][10],  //�ϰ�����
        b[10][10]; //ģ���߹�������
int ans = 0;
int n, m, t;
void dfs(int x, int y) {
    if (x == tx && y == ty) {
        ans++;
        return;
    }
    b[x][y] = 1; //��ǰ�߹��ĵ�
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m || b[xx][yy] || a[xx][yy])
            continue;
        b[xx][yy] = 1;
        dfs(xx, yy);
        b[xx][yy] = 0; //����
    }

}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> tx >> ty; //�����յ�����
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y; //�ϰ�����
        a[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans << endl;

    return 0;
}