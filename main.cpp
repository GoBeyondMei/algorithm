#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int sum = 0;
        backtrack(candidates, target, sum, 0);
        return res;
    }
    //2, 5, 3
    void backtrack(vector<int> candidates, int target, int sum, int startindex) {
        if (sum > target) return;
        if (sum == target) {
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
private:
    vector<vector<int>> res;
    vector<int> path;
};
int main() {
    vector<int> v{2, 5, 3};
    Solution s;
    auto res = s.combinationSum(v, 8);
    for(auto rol : res) {
        for(auto col : rol) {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}