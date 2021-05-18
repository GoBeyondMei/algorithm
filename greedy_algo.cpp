#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>
#include <array>
#include <numeric>
#include <stack>
#include <random>
#include <time.h>

using namespace std;

//�ַ����� g��ÿ�����ӵ�θ��ֵ��s�Ǳ��ɵ����
int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = g.size() - 1;
    int j = s.size() - 1;
    int cnt = 0;
    while (i >= 0) {
        if (j >= 0 && s[j] >= g[i]) {
            cnt++;
            j--;
        }
        i--;
    }
    return cnt;
}

//��������
int getMaxSubArray(vector<int> &v) { //-2, 1, -3, 4, -1, 2, 1, -5, 4
    //int tmpSum = 0, res = v[0];
    //for (int num : v) {
    //    tmpSum = max(tmpSum + num, num);
    //    res = max(res, tmpSum);
    //}
    //return res;
    //int result = INT_MIN; �����ⷨ
    //int count = 0;
    //for (int i = 0; i < v.size(); i++) {
    //    count = 0;
    //    for (int j = i; j < v.size(); j++) {
    //        count += v[j];
    //        result = max(count, result);
    //    }
    //}
    //return result;
    //̰�ĵ�����
    //int result = INT_MIN;
    //int count = 0;
    //for (int item : v) {
    //    count += item;
    //    if (count > result) result = count; //��ȡ�ֲ���������Ž�
    //    if (count <= 0) count = 0; //��ǰ���С��0 ��ֱ�Ӵ���һԪ�ؿ�ʼ
    //}
    //return result;
    //dp����
    if (v.size() <= 0) return 0;
    vector<int> dp(v.size(), 0); //dp[i]��ʾ��ǰλ�õ����Ž���һ��Ҫѡ�е�ǰλ�ò��ܹ�������
    dp[0] = v[0];
    int result = dp[0]; //result��¼���Ž�
    for (int i = 1; i < v.size(); i++) {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
        if (dp[i] > result) result = dp[i];
    }

    return result;
}


int main() {
    vector<int> g{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> s{1, 2, 3};

    cout << getMaxSubArray(g) << endl;


    return 0;
}