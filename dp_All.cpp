#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>
#include <array>
#include <stack>
#include <numeric>
/**
 * dp��̬�滮
 * ���ĳһ�����кܶ��ص������⣬ʹ�ö�̬�滮����Ч��
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

//쳲���������
int fib(int N) {
    if (N <= 1) return N;
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

//��¥��
int upstar(int n) {
    if (n <= 1)return n;
    vector<int> dp(n + 1, 0); //dp[i]��ʾi��¥�ݵķ�����
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

//ʹ������ֵ����¥��
int minCostStairs(vector<int> &cost) {
    vector<int> dp(cost.size(), 0);  //dp[i]��ʾ��i��¥�ݶ�Ӧ������ֵ
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++) {
        dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
    }
    return min(dp[cost.size() - 2], dp[cost.size() - 1]);
}

int mi(int x, int n) {
    if (n == 0) return 1;
    return x * mi(x, n - 1);
}

//��е������·��
int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

//�������
int dfs(int i, int j, int m, int n) {
    if (i > m || j > n) return 0;
    if (i == m && j == n) return 1;
    return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
}

//���ϰ��������
int uniquePaths(vector<vector<int>> obt) {
    int m = obt.size();
    int n = obt[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n && obt[0][i] == 0; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m && obt[0][i] == 0; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obt[i][j] == 1)
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

//Ӳ�ҵ�1��2��5��10  ���+����
class Solution {
private:
    vector<int> coin{1, 2, 5, 10};
    vector<vector<int>> result;
    vector<int> path;
    int curCoins = 0;
public:

    void dfs(int target, int index) { //һ�����ȫ��Ԫ�� ��Ҫ����ֵ
        if (target == curCoins) { //����������
            result.push_back(path);
        }
        if (target < curCoins) return;
        for (int i = index; i < coin.size(); i++) {
            path.push_back(coin[i]);
            curCoins += coin[i];
            dfs(target, index + 1);
            //����
            curCoins -= coin[i];
            path.pop_back();
        }
    }

    vector<vector<int>> coinsNums(int target) {
        dfs(target, 0);
        return result;
    }
};

//������� 3+3+4  3*3*4���
int getMaxMulti(int n) {
    if (n <= 1)
        return 0;
    vector<int> dp(n + 1);   //dp[i]��ʾ�ֲ�����i�õ������˻�
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i - 1; j++) {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[n];
}

//01��������
void bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4; //����������
    vector<vector<int>> dp(weight.size() + 1, vector<int>(value.size() + 1, 0));
    for (int j = bagWeight; j >= weight[0]; j--) {
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }

}

class Solution2 {
private:
    vector<vector<int>> res;
    //set<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        backtrack(nums, 0, used);
        print(res);
        return res;
    }

    void backtrack(vector<int> &nums, int startIndex, vector<bool> &used) {
        if (path.size() >= 2) {
            res.push_back(path);
        }
        //���map��ÿ���ݹ��������������
        // ����i=1ʱ push(3) �ݹ������push(3)ʱ�Ͳ��� ������3����������� ��1 3 3�к�������3����
        //��ͬ��������
        unordered_map<int, int> the_set;//��¼��һ�������Ѿ����Ե�ѡ��
        for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() || the_set.count(nums[i])) {
                //if (!path.empty() && nums[i] < path.back() || used[i] == true) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            the_set[nums[i]]++;//��¼���ѡ��
            backtrack(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};

//�����������
int getSubArray(vector<int> &nums) {
    if (nums.size() <= 0)
        return 0;
    vector<int> dp(nums.size(), 1); //dp[i]��ʾi֮ǰ�ĵ���󳤶�
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result) result = dp[i];
        }
    }
    for (int item : dp) {
        cout << item << " ";
    }
    return result;
}

//���������������
int getContinuousSubArray(vector<int> &nums) {
    if (nums.size() <= 1)
        return nums.size();
    vector<int> dp(nums.size(), 1); //dp[i]��ʾi֮ǰ�ĵ���󳤶�
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        if (dp[i] > result) result = dp[i];
    }
    //for (int item : dp) {
    //    cout << item << " ";
    //}
    return result;
}

int findNumberOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    unordered_map<int, int> um;
    um[1] = 1;
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                if (um.count(dp[i]) <= 0) {
                    um[dp[i]] = 1;
                } else {
                    um[dp[i]] += 1;
                }
            }
            if (dp[i] > result) result = dp[i];
        }
        if (result == 1) {
            um[1]++;
        }
    }
    for (int item : dp) {
        cout << item << " ";
    }
    return um[result];
}

//��ظ�������
int findLength(vector<int> &nums1, vector<int> &nums2) {
    //dp[i][j]��ʾ��i-1��β��A������j-1��β��B����ظ�������ĳ���
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
    int result = 0;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                if (i - 1 < 0 || j - 1 < 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1; //����ǰһ��λ�ñ���3 2��3 2
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] > result) result = dp[i][j];
        }
    }
    return result;
}

//�����������
int longestCommonSubsequence(string text1, string text2) { //text1 = "abcde", text2 = "ace"
    int len1 = text1.length();
    int len2 = text2.length();
    int dp[len1 + 1][len2 + 1] = {0};
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

//���ཻ����
int notInterLine(vector<int> &num1, vector<int> &num2) {
    vector<vector<int>> dp(num1.size() + 1, vector<int>(num2.size() + 1, 0));
    for (int i = 1; i <= num1.size(); i++) {
        for (int j = 1; j <= num2.size(); j++) {
            if (num1[i - 1] == num2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[num1.size()][num2.size()];
}

//��������������
int maxAscendingSum(vector<int> &nums) { //10,20,30,5,10,50
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int cnt = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i]) {
            dp[i] = nums[i] + dp[i - 1];
        } else {
            dp[i] = nums[i];
        }
        if (dp[i] > cnt) cnt = dp[i];
    }
    return cnt;
}

//��������
int maxSubArray(vector<int> &nums) { //-2,1,-3,4,-1,2,1,-5,4
    vector<int> dp(nums.size()); //dp[i]��ʾiλ�õ���������
    dp[0] = nums[0];
    int cnt = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i] + dp[i - 1], nums[i]);
        if (dp[i] > cnt) cnt = dp[i];
    }
    for (int item : dp) {
        cout << item << " ";
    }
    return cnt;
}

//�ж�������
bool isSubsequence(string s, string t) { //s = "abc"   t = "ahbgdc"
    int len1 = s.length();
    int len2 = t.length();
    if (len1 > len2) {
        return false;
    } else if (len1 == 0 && len2 != 0) {
        return true;
    } else if (len1 != 0 && len2 == 0) {
        return false;
    } else if (len1 == 0 && len2 == 0) {
        return true;
    }
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));  //dp[i][j]��ʾi��jλ��֮ǰ���������
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    if (dp[len1][len2] == len1) return true;
    return false;
}

//�ָ�Ⱥ��Ӽ�
bool sepaSubArray(vector<int> &nums) { //1��5��5,11
    vector<int> dp(nums.size(), 0);  //dp[i]��ʾiλ��֮ǰ����������
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;   //���ܺ�Ϊ����ʱ  �����ֳܷ�������ȵļ���
    int target = sum / 2;
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum += nums[i];
        if (sum < target) {
            dp[i] += nums[i];
        } else if (i + 1 == nums.size() && sum == target) {
            return true;
        }
    }
    return false;
}

//���ظ��ַ�����Ӵ�
int getSubString(string str) {  //pwwkew
    //��ϣ�������
    //int len = str.length();
    //int cnt = 0;
    //set<char> st;
    //for (int i = 0; i < len; i++) {
    //    st.clear();
    //    for (int j = i; j < len; j++) {
    //        if (st.count(str[j]) > 0) {
    //            break;
    //        }
    //        st.insert(str[j]);
    //        cnt = max(cnt, j - i + 1);
    //    }
    //}
    //return cnt;

    //�������ڵ�����    pwwkew
    int left, right;
    int len = str.length();
    left = right = 0;
    set<char> qu;
    int cnt = 0;
    while (right < len) {
        while (right < len && qu.count(str[right]) <= 0) {
            qu.insert(str[right]);
            right++;
        }
        cnt = max(cnt, right - left);
        while (left < right) {
            qu.erase(str[left]);
            left++;
            //left����Ҫһֱ�ƶ�  ���ƶ�����right��ȵ�λ�� left�Ͳ���Ҫ�ƶ���
            if (str[left - 1] == str[right]) {
                break;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v1{1, 5, 5, 11};
    vector<vector<int>> obj{{2, 1, 3},
                            {6, 5, 4},
                            {7, 8, 9}};
    cout << boolalpha;
    //cout << uniquePaths(3, 7);
    cout << getSubString("dvadbf") << endl;
    return 0;
}