#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
//�������
using namespace std;

class Solution { //�����ظ�ʹ��
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(vector<int> &candidates, int target) {
        int sum = 0;
        backtrack(candidates, target, sum, 0);
        return res;
    }

    //2 3 5   8
    void backtrack(vector<int> candidates, int target, int sum, int startindex) {
        if (sum > target) return;
        if (sum == target) { //��һ�� ��������
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

class Solution1 { //�������ظ�ʹ��
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end()); //����
        vector<bool> used(candidates.size(), false);
        backtrack(candidates, target, 0, 0, used);
        return res;
    }

    //2 3 5   8
    void backtrack(vector<int> &candidates, int target, int sum, int startindex, vector<bool> &used) {
        if (sum > target) return;
        if (sum == target) { //��һ�� ��������
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtrack(candidates, target, sum, i + 1, used);
            path.pop_back();
            used[i] = false;
            sum -= candidates[i];
        }
    }
};

int main() {
    vector<int> v{10, 1, 2, 7, 6, 1, 5};
    Solution1 solu;
    for (auto item : solu.combine(v, 8)) {
        for (auto it : item) {
            cout << it << " ";
        }
        cout << endl;
    }


    return 0;
}