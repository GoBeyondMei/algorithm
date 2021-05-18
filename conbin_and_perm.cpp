#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>
#include <array>
/**
 * ��Ϻ���������
 *
 */
using namespace std;

void print(vector<vector<int>> &res) {
    for (auto item : res) {
        for (int it : item) {
            cout << it << " ";
        }
        cout << endl;
    }
}

void print(vector<string> s) {
    for (auto str : s) {
        cout << str << " ";
    }
}

//���ظ�Ԫ�ص�����
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        int sum = 0;
        backtrack(candidates, target, sum, 0);
        print(res);
        return res;
    }

    void backtrack(vector<int> &candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

//�����е�������ÿ�������ֻ��ʹ��һ�Σ�ÿ�����Ҳ��Ψһ��
class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end()); //��Ϊ������ͬһ��Ԫ��  ��Ҫ����
        vector<bool> used(candidates.size(), false); //�������������ÿ��λ���Ƿ�ʹ�ù�
        backtrack(candidates, target, 0, 0, used);
        print(res);
        return res;
    }

    void backtrack(vector<int> &candidates,
                   int target,
                   int sum,
                   int startIndex,
                   vector<bool> &used) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        //�����˲���Ҫ��ѭ��
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            //��ʹ�ù���Ԫ�ؽ�������
            if (i > 0 && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true; //��Ǹ�λ��ʹ�ù�
            backtrack(candidates, target, sum, i + 1, used);
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

class A {
public:
    A(int v) : val(v) {
        //cout << "constrator function: val=" << val << endl;
    }

    bool operator<(const A &a) const {
        return this->val < a.val;
        //return true;
    }

    void setVal() const {
        //val = 3;
    }

    //const��Ա�����ǲ�������÷�const����  ����ͻ��Ӹı������ֵ
    int getVal() const {
        setVal();
        return val;
    }

private:
    int val;
};

//�ҳ�����1-9��k�������Ϊn����� ���ֲ������ظ�
class Solution2 {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        backtrack(n, 0, 1, k);
        print(res);
        return res;
    }

    void backtrack(int n,
                   int sum,
                   int startIndex,
                   int k) {
        if (sum > n) {
            return;
        }
        if (path.size() == k) {
            if (sum == n)
                res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtrack(n, sum, i + 1, k);
            sum -= i;
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

//������������Ӧ����ĸ
class Solution3 {
public:
    vector<string> combinationSum(string digit) {
        if (digit.size() == 0) return res;
        backtrack(digit, 0);
        print(res);
        return res;
    }

    void backtrack(string digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.length(); i++) {
            s.push_back(letters[i]);
            backtrack(digits, index + 1);
            s.pop_back();
        }
    }

private:
    vector<string> res;
    string s;
    const string letterMap[10] = {
            "", "", "abd", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
};

class Var {
private:
    int *a;
public:
    Var(int _a) {
        //a = &_a;
        //cout << *a << endl;
    }

    ~Var() {
        int _a;
        a = &_a;
        cout << *a << endl;
    }
};

int sumSubarrayMins(vector<int>& arr) {
    vector<vector<int>> obj;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j <= i; j++) {

        }

    }
}

int main() {
    vector<int> v{2, 3, 1, 5};
    vector<vector<int>> obj;
    vector<int> path;
    //sumSubarrayMins(v, obj, path, 0);
    //for (auto item : obj) {
    //    for (int it : item) {
    //        cout << it << " ";
    //    }
    //    cout << endl;
    //}
    Solution1 solu;
    solu.combinationSum(v, 8);

    return 0;
}