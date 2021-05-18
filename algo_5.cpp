#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <memory>
#include <queue>
#include <deque>
#include <list>
#include <string.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <math.h>
#include <memory>

using namespace std;

vector<int> getMax_Min(int n) {
    vector<int> v;
    int i = 0;
    while (n) {
        v.push_back(n % 10);
        n = n / 10;
        i++;
    }
    while (i != 4) {
        v.push_back(0);
        i++;
    }
    sort(v.begin(), v.end());
    int max, min;
    max = v[3];
    min = v[0];
    for (int i = 1; i < 4; i++) {
        max = max * 10 + v[3 - i];
        min = min * 10 + v[i];
    }
    return vector<int>{max, min};
}

bool isHappy(int n) { // 19  12 + 92 = 82
    int sum = 0;
    int temp = n;
    if (n == 1) return true;
    while (n != 1) {
        sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n = n / 10;
        }
        n = sum;
        if (n == temp) return false;
        if (sum == 4)return false;
    }
    return true;
}

bool backspaceCompare(string s, string t) {
    int len1 = s.length();
    int len2 = t.length();
    stack<char> st;
    stack<char> st1;
    for (int i = 0; i < len1; i++) {
        if (s[i] == '#') {
            if (st.empty()) {
                continue;
            } else
                st.pop();
        } else {
            st.push(s[i]);
        }
    }
    for (int i = 0; i < len2; i++) {
        if (t[i] == '#') {
            if (st1.empty()) {
                continue;
            } else
                st1.pop();
        } else {
            st1.push(t[i]);
        }
    }
    if (st.size() != st1.size()) {
        return false;
    }
    while (!st.empty()) {
        if (st.top() != st1.top()) {
            return false;
        }
        st.pop();
        st1.pop();
    }
    return true;
}

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, int startIndex) {
        res.push_back(path); // 收集子集
        if (startIndex >= nums.size()) { // 终止条件可以不加
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }

    int sumSubarrayMins(vector<int> &arr) {
        backtrack(arr, 0);
        int sum = 0;

        for (auto item : res) {
            int mi = INT_MAX;
            cout << *min_element(item.begin(), item.end()) << endl;
            //cout << mi << endl;
        }
        return sum;
    }
};

class A {
public:
    A(int n) : data1(n) {}

    virtual void fun1() {
        cout << "A virtual fun1" << endl;
    }

    void fun2() {
        cout << "A gener fun2" << endl;
    }

    int getData() const {
        return data1;
    }

    void setData(int num) {
        data1 = num;
    }

private:
    int data1;
    int data2;
};

//class B : public A {
//public://不管B中有有没有写虚函数  B都会继承A的虚函数(继承的是调用权)
//    void fun1() {
//        cout << "B virtual fun1" << endl;
//    }
//
//    void fun2() {
//        cout << "V virtual fun2" << endl;
//    }
//
//private:
//    int data3;
//};
//
//class C : public B {
//public:
//    void fun2() {
//
//    }
//
//private:
//    int data4;
//};

int removeArrayItem(vector<int> &nums) { //1, 1, 1, 2, 2, 3
    int prev, next;
    prev = next = 0;
    int cnt = 0;
    for (int next = 0; next < nums.size(); next++) {
        if (cnt >= 3) {
            prev = next;
        }
        if (nums[prev] == nums[next]) {
            cnt++;
        }
    }

}

void display(A &a) {
    a.setData(20);
    cout << a.getData() << endl;
}

//数组中出现次数超过一半的数字
//1、排序法
//2、摩尔投票法
int majorityElement(vector<int> &nums) {
    int cur = 0; //用来记录当前的数
    int vote = 0; //票数
    for (int item : nums) {
        if (vote == 0) cur = item;
        if (cur == item) {
            vote++;
        } else {
            vote--;
        }
    }
    return cur;
}

//最大连续个数的1
//滑动窗口一般用来解决某个区间的符合条件的值
int findMaxConsecutiveOnes(vector<int> &nums) {  //1 1 0 1 1 1
    int res = 0;
    int left, right;
    left = right = 0;
    while (right < nums.size()) {
        if (nums[right] != 1) { //下面的顺序不能放反  当right的位置不为1的时候  right先要++
            right++;
            left = right;
        } else {
            right++;
        }
        res = max(res, right - left);
    }
    return res;
}

//最大连续1的个数  最多可以将k个0转为1
int longestOnes(vector<int> &nums, int k) { //1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0
    //最简单的是滑动窗口
    int res = 0;
    int left, zero;
    left = zero = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zero++;
        while (zero > k) {
            if (nums[left] == 0) { //当0的个数大于k时  必须找到第一个left为0的地方
                zero--;
            }
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

//删除字符串中的所有相邻重复项  abbaca
string removeRealRep(string str) {
    stack<char> st;
    for (int i = 0; i < str.length(); i++) {
        if (st.empty() || str[i] != st.top()) {
            st.push(str[i]);
        } else if (str[i] == st.top()) {
            st.pop();
        }
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

//逆波兰表达式求值 2,1,+,3,*=9
int eval(vector<string> &tokens) {
    stack<int> st;
    for (auto item : tokens) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (item == "+") {
                st.push(a + b);
            } else if (item == "-") {
                st.push(a - b);
            } else if (item == "*") {
                st.push(a * b);
            } else {
                st.push(a / b);
            }
        } else
            st.push(stoi(item));
    }
    return st.top();
}

//滑动窗口的最大值
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    deque<int> st;  //必须要用deque
    for (int i = 0; i < nums.size(); i++) {
        st.push_back(i);
        if (!st.empty() && i - st.front() >= k) {
            st.pop_front();
        }
        while (!st.empty() && nums[i] > nums[st.back()]) {
            st.pop_back();
        }
        if (i >= k - 1) {
            res.push_back(nums[st.front()]);
        }
    }
    return res;
}

//strcpy(), atoi()
//my_memcpy实现重叠内存转移
char *my_memcpy(char *dest, const char *src) {
    //检查传入参数的有效性
    if (NULL == dest || NULL == src)
        return NULL;
    char *ret = dest;
    int count = strlen(dest) + 1;
    /**
    _Dest和_Source的内存地址有三种排列组合：
    1. _Dest和_Source没有发生重叠；
    2. _Dest和_Source地址重叠，且_Dest的地址大于_Source的地址；
    3. _Dest和_Source地址重叠，_Dest的地址小于_Source的地址；
    第一种情况和第三种情况，直接从低位字节开始复制，即可；
    第二种情况，必须从高位字节开始复制，才能保证复制正确。
    */
    if (dest > src && dest <= src + count - 1) { //第二种情况
        dest = dest + count - 1;
        src = src + count - 1;
        while (count--) {
            *dest-- = *src--;
        }
    } else {
        while (count--) {
            *dest++ = *src++;
        }
    }
    return ret;
}

//单例模式
//饿汉模式
template<typename T>
class singleton {
private:
    singleton() {}

    singleton(const singleton &) {}

    singleton &operator=(const singleton &) {}

    static T *m_instance;
public:
    static T *GetInstance();
};

template<typename T>
T *singleton<T>::GetInstance() {
    return m_instance;
}

template<typename T>
T *singleton<T>::m_instance = new T();

//懒汉
template<typename T>
class singleton1 {
private:
    singleton1() {}

    singleton1(const singleton1 &) {}

    singleton1 &operator=(const singleton1 &) {}

    static T *m_instance;
public:
    static T *GetInstance();
};

//template<typename T, typename ...Args>
//T *singleton1<T>::GetInstance(Args &&...args) {
//    if (m_instance == NULL) {
//        pthread_mutex_lock(&mutex);
//        if (m_instance == NULL) {
//            T *temp = new T(std::forward<Args>(args)...);
//            m_instance = temp;
//        }
//        pthread_mutex_unlock(&mutex);
//    }
//    return m_instance;
//}

template<typename T>
T *singleton1<T>::m_instance = NULL;

long long subsequence(int n, vector<int> &array) {  //4 2 3 5
    // write code here
    vector<long> dp(n + 1);   //dp[i] 表示i位置上的最大子序和
    dp[0] = 0;
    dp[1] = array[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + array[i - 1]);
    }
    for (int item : dp) {
        cout << item << " ";
    }
    return dp[n];
}

//回文子串
int countSubstrings(string s) { //aba
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false)); //dp[i][j]表示从i到j的最长子串
    int cnt = 0;
    for (int j = 0; j < s.length(); j++) {
        for (int i = 0; i <= j; i++) {
            if (i == j) {
                dp[i][j] = true;
                cnt++;
            } else if (j - i == 1 && s[i] == s[j]) {
                dp[i][j] = true;
                cnt++;
            } else if (j - i > 1 && s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

//最长的回文子串
string longestPalindrome(string s) { //babad
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false)); //dp[i][j]表示从i到j的最长子串
    int res = 0;
    int start;
    for (int j = 0; j < s.length(); j++) {
        for (int i = 0; i <= j; i++) {
            if (i == j) {
                dp[i][j] = true;
            } else if (j - i == 1 && s[i] == s[j]) {
                dp[i][j] = true;
            } else if (j - i > 1 && s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
            if (dp[i][j] && j - i + 1 > res) {
                res = max(res, j - i + 1); //比如cabac  j遍历后面c的位置  dp[i] = dp[j] 需要看 dp[i+1][j-1]是否是回文子串
                start = i; //记录回文起点的位置
            }
        }
    }
    return s.substr(start, res);
}

//最长回文子序列(不一定连续)
int longestSubSeq(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));  //dp[i][j]
    for (int i = 0; i < s.length(); i++) dp[i][i] = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.length() - 1];
}

//把数组排成最小的数
string minNumber(vector<int> &nums) {
    if (nums.size() == 1) return to_string(nums[0]);
    vector<string> temp;
    string res = "";
    for (int item : nums) {
        temp.push_back(to_string(item));
    }
    sort(temp.begin(), temp.end(), [](const string &s1, const string &s2) {
        return (s1 + s2) < (s2 + s1);
    });
    for (string item : temp) {
        res += item;
    }
    return res;
}

//把数字翻译成字符串
int translateNum(int num) { //12258
    string s = to_string(num);
    const int n = s.size();
    vector<int> d(n);  //dp[i]表示0到i位置所组成的字符串个数
    d[0] = 1; //一个字符为1
    for (int i = 1; i < n; ++i) {
        d[i] = d[i - 1];
        //1225  当i到5的位置时 当25能组成字符串时 分为两种情况一种是组成25为dp[i-2] 另外是只选5 为dp[i-1]
        //1228 当i到8的位置时 28不能组成字符串，则为dp[i-1]
        string sub = s.substr(i - 1, 2);
        if (s[i - 1] != '0' && stoi(sub) < 26) {
            d[i] += i - 2 >= 0 ? d[i - 2] : 1;
        }
    }
    return d[n - 1];
}

//把字符串转为整数
int strToInt(string str) {
    int len = str.length();
    bool opt = true; //代表正数
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ')
            continue;
        if (str[i] == '-') {
            opt = false;
            continue;
        } else if (str[i] == '+') {
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && i > 7) {
                return opt ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (str[i] - '0');
        } else
            break;
    }
    if (!opt) res = -res;
    return res;
}

//圆圈中剩下的最后数字
int lastRemaining(int n, int m) {
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_front(i);
    }
    int j = 0;
    while (dq.size() > 1) {
        if (j < m - 1) {
            int t = dq.back();
            dq.pop_back();
            dq.push_front(t);
            j++;
        } else {
            dq.pop_back();
            j = 0;
        }
    }
    return dq.front();
}

//搜索插入位置
int searchInsert(vector<int> &nums, int target) { //1,3,5,6  5
    int l, r;
    int len = nums.size();
    l = 0;
    r = len;
    if (nums[0] > target) return 0;
    else if (nums[len - 1] < target) return len;
    while (l <= r) {
        int mid = l + (r - l) / 2; //为了大数相加溢出问题
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
//二分查找
/**
 * 一般分为两种左闭右闭[left,right]
 * 左闭右开[left, right)
 *
 */
//第一种 定义target在一个左闭右闭区间
int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

//第二种，定义target在一个左闭右开区间
int search1(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

//在排序数组中查找元素的第一个和最后一个位置
//找到最左的位置
int binarySearch1(vector<int> &nums, int target) { //改进的二分查找
    int left = 0, right = nums.size(); //5,7,7,8,8,10
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] >= target) { //当mid位置和target位置相等时  继续缩小right的范围
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    if (nums[left] != target) return -1;
    return left;
}

int binarySearch2(vector<int> &nums, int target) {
    int left = 0, right = nums.size();
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid;
        } else if (nums[mid] <= target) {//当mid位置和target位置相等时  继续扩大left的范围 使其找到最后面相等的位置
            left = mid + 1;
        }
    }
    if (nums[left - 1] != target) return -1;
    return left - 1; //最后相等时位置需要改变一下
}

vector<int> searchRange(vector<int> &nums, int target) { //5,7,7,8,8,10
    if (nums.size() <= 0) return {-1, -1};
    vector<int> res;
    res.push_back(binarySearch1(nums, target)); //查找第一个相等的
    res.push_back(binarySearch2(nums, target)); //查找最后一个相等的
    return res;
}

//x的平方根
int mySqrt(int x) {
    int l = 0, r = x, ans = -1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

//长度最小的子数组
int getSubArray(vector<int> &nums, int target) {
    int left, right;
    left = right = 0;
    int sum = 0;
    int res = INT_MAX;
    while (right < nums.size()) {
        sum += nums[right];
        while (sum >= target) {
            if (sum == target)
                res = min(res, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return res == INT_MAX ? 0 : res;
}

//水果成篮
int totalFruit(vector<int> &tree) {
    unordered_map<int, int> st;
    int res, left, right;
    res = left = right = 0;
    while (right < tree.size()) {
        st[tree[right]]++;
        while (st.size() > 2) {
            st[tree[left]]--;
            if (st[tree[left]] == 0) {
                st.erase(tree[left]);
            }
            left++;
        }
        res = max(res, right - left + 1);
        right++;
    }
    return res;
}

//有效的完全平方数
bool isPerfectSquare(int num) { //16
    int left, right;
    left = 0;
    right = num;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long ans = mid * mid;
        if (ans == num) {
            return true;
        } else if (ans > num) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

void moveZeroes(vector<int> &nums) {
    if (nums.size() <= 1) return;
    int left, right;
    left = 0;
    right = 1;
    while (right < nums.size()) {
        if (nums[left] != 0) {
            left++;
        }
        swap(nums[left], nums[right]);
        right++;
    }
}

//有序数组的平方
vector<int> sortedSquares(vector<int> &nums) { //-4,-1,0,3,10  0,1,9,16,100
    int left, right;
    left = 0;
    right = nums.size() - 1;
    vector<int> res(nums.size());
    int index = right;
    while (left <= right) {
        if (nums[left] * nums[left] < nums[right] * nums[right]) {
            res[index--] = nums[right] * nums[right];
            right--;
        } else {
            res[index--] = nums[left] * nums[left];
            left++;
        }
    }
    return res;
}

//买卖股票系列
//买卖股票的最佳时机
int maxProfit1(vector<int> &prices) { //7,1,5,3,6,4   5 贪心算法  最左的最小值 和最右的最大值
    int low = INT_MAX;
    int res = 0;
    for (int i = 0; i < prices.size(); i++) {
        low = min(low, prices[i]);
        res = max(res, prices[i] - low);
    }
    return res;
}

int maxProfit(vector<int> &prices) { //7,1,5,3,6,4   5
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2));
    // dp[i][1] 下标为 i 这天结束的时候，不持股，手上拥有的现金数
    // dp[i][0] 下标为 i 这天结束的时候，持股，手上拥有的现金数

    // 初始化：不持股显然为 0，持股就需要减去第 1 天（下标为 0）的股价
    dp[0][1] = 0;
    dp[0][0] = -prices[0];

    for (int i = 1; i < len; i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}

//背包问题
void test_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    //dp[i][j]表示在0-i物品中所获得的最大价值
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));

    //初始化
    for (int i = bagWeight; i >= weight[0]; i--) {
        dp[0][i] = dp[0][i - weight[0]] + value[0];
    }

    for (int i = 1; i < weight.size(); i++) { //物品 因为0物品已经初始化过
        for (int j = 0; j <= bagWeight; j++) { //背包容量
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    for (auto item : dp) {
        for (int it : item) {
            cout << it << " ";
        }
        cout << endl;
    }
}

//压缩数组
void test_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    //dp[i]表示在容量为i背包的最大价值
    vector<int> dp(bagWeight + 1, 0);

    for (int i = 0; i < weight.size(); i++) { //物品
        for (int j = bagWeight; j >= weight[i]; j--) { //背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    for (auto item : dp) {
        cout << item << " ";
    }
}

//分割等和子集
bool canPartition(vector<int> &nums) {  //1 5 11 5
    int sum = 0;
    vector<int> dp(20001, 0); //dp[i]表示背包的总容量为i，最大可以凑成子集和为dp[i]
    sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum / 2;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    if (dp[target] == target) return true;
    return false;
}

//最后一块石头的重量
int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;
    for (int item : stones) {
        pq.push(item);
    }
    while (pq.size() != 1 && !pq.empty()) {
        auto first = pq.top();
        pq.pop();
        auto second = pq.top();
        pq.pop();
        if (first > second) {
            pq.push(first - second);
        }
    }
    if (pq.size() == 1) {
        return pq.top();
    } else {
        return 0;
    }
}

int lastStoneWeightII(vector<int> &stones) {


}

//打家劫舍
int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), 0); //dp[i]表示i以内上所偷窃到的最高价值
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    int res = max(dp[0], dp[1]);
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}

int rob1(vector<int> &nums) {


}

//删除有序数组的重复项
int removeDuplicates(vector<int> &nums) {//0, 0, 1, 1, 1, 1, 2, 3, 3
    if (nums.size() <= 2) return nums.size();
    queue<int> qu;
    int temp = nums[0];
    int i = 0;
    for (int item : nums) {
        if (item == temp) {
            i++;
        } else {
            i = 1;
            temp = item;
        }
        if (i < 3) {
            qu.push(item);
        }
    }
    int n = qu.size();
    int index = 0;
    while (!qu.empty()) {
        nums[index++] = qu.front();
        qu.pop();
    }
    return n;
}

//判断丑数
bool isUgly(int n) { //8
    int x = n;
    while (x > 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else if (x % 3 == 0) {
            x = x / 3;
        } else if (x % 5 == 0) {
            x = x / 5;
        } else {
            return false;
        }
    }
    if (x == 1) return true;
    else return false;
}

//求解第n个丑数
int nthUglyNumber(int n) {
//1、最小堆  2、动态规划  3、双指针
    vector<int> dp(n + 1); //dp[i]表示第i个丑数为dp[i]
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        int num1 = dp[p2] * 2, num2 = dp[p3] * 3, num3 = dp[p5] * 5;
        dp[i] = min(min(num1, num2), num3);
        if (dp[i] == num1) {
            p2++;
        }
        if (dp[i] == num2) {
            p3++;
        }
        if (dp[i] == num3) {
            p5++;
        }
    }
    return dp[n];
}

int nthUglyNumber2(int n, int a, int b, int c) {
//1、最小堆  2、动态规划  3、双指针
    int cnt = 0;
    int i = 1;
    while (1) {
        if (i % a == 0 || i % b == 0 || i % c == 0) {
            cnt++;
            if (cnt == n) {
                return i;
            }
        }
        i++;
    }
    return -1;
}

int nthUglyNumber1(int n) {
//1、最小堆
    vector<int> factors = {2, 3, 5};
    unordered_set<long> seen;
    priority_queue<long, vector<long>, greater<long>> heap;
    seen.insert(1L);
    heap.push(1L);
    int ugly = 0;
    for (int i = 0; i < n; i++) {
        long curr = heap.top();
        heap.pop();
        ugly = (int) curr;
        cout << curr << " ";
        for (int factor : factors) {
            long next = curr * factor;
            if (!seen.count(next)) {
                seen.insert(next);
                heap.push(next);
            }
        }
    }
    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    return ugly;
}

int singleNumber(vector<int> &nums) {
    int ret = 0;
    for (auto e: nums)
        ret ^= e;
    return ret;
}

//寻找峰值
int findPeakElement(vector<int> &nums) { //1,1,1,3,5,6,4
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

//寻找重复数
int findDuplicate(vector<int> &nums) {
    //普通的解法
    //for (int i = 0; i < nums.size(); i++) {
    //    while (nums[i] != i + 1) {
    //        if (nums[nums[i]-1] == nums[i]) {
    //            return nums[i];
    //        }
    //        swap(nums[i], nums[nums[i] - 1]);
    //    }
    //}
    //return -1;

    //快慢指针的解法 时间复杂的为O(n) 空间为O(1) 没有改动原数组
    int slow = 0;
    int fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast) { //判断是否有环
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    int pre1 = 0;
    int pre2 = slow;
    while (pre1 != pre2) {  //寻找相交的地方  pre1从0开始  pre2从slow(是与fast相遇的地方)开始
        pre1 = nums[pre1];
        pre2 = nums[pre2];
    }
    return pre1;
}

//计算右侧小于当前元素的值
vector<int> countSmaller(vector<int> &nums) {
    vector<int> res(nums.size());
    int cnt;
    for (int i = 0; i < nums.size(); i++) {
        cnt = 0;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                cnt++;
            }
        }
        res[i] = cnt;
    }
    return res;
}

//删除并获得点数
int deleteAndEarn(vector<int> &nums) { //2,2,3,3,3,4
    if (nums.size() == 0) {
        return 0;
    } else if (nums.size() == 1) {
        return nums[0];
    }
    int len = nums.size();
    int mx = nums[0];
    for (int i = 0; i < len; ++i) {
        mx = max(mx, nums[i]);
    }
    //构造一个新的数组all
    vector<int> all(mx + 1, 0);
    for (int item : nums) {
        all[item]++;
    }
    vector<int> dp(mx + 1);
    dp[1] = all[1] * 1;
    dp[2] = max(dp[1], all[2] * 2);
    //动态规划求解
    for (int i = 2; i <= mx; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * all[i]);
    }
    return dp[mx];
}

//位1的个数
int hammingWeight(uint32_t n) {
    int res = 0;
    //while (n) {
    //    if (n & 1 == 1) {
    //        res++;
    //    }
    //    n = n >> 1;
    //}
    //return res;
    while (n) {
        n = n & (n - 1);
        res++;
    }
    return res;
}

bool isPowerOfThree(int n) { //9
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid * mid == n) {
            return true;
        } else if (mid * mid > n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

//丢失的数字
int missingNumber(vector<int> &nums) {  //3,0,1  ->2
    cout << (3 ^ 1) << endl;
    vector<int> temp(nums.size() + 1, -1);
    for (int item : nums) {
        temp[item] = item;
    }

    for (int i = 0; i < temp.size(); i++) {
        if (i != temp[i]) {
            return i;
        }
    }
    return -1;
}

//数组中重复的数字
vector<int> findDuplicates(vector<int> &nums) { //4,3,2,7,8,2,3,1 ->2 3
    vector<int> res;
    //unordered_map<int, int> um;
    //for (int item : nums) {
    //    if (um.count(item) <= 0) {
    //        um.insert(make_pair(item, 1));
    //    } else {
    //        res.push_back(item);
    //    }
    //}
    //return res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[abs(nums[i])] < 0)
            res.push_back(abs(nums[i]));
        nums[abs(nums[i])] = -nums[abs(nums[i])];
    }
    return res;
}

//构建乘积数组
vector<int> constructArr(vector<int> &a) { //1,2,3,4,5 ->120,60,40,30,24
    vector<int> res;
    vector<int> temp(a.size());
    vector<int> temp1(a.size());
    int sum = 1;
    int t;
    for (int i = a.size() - 1; i >= 0; i--) {
        sum *= a[i];
        temp1[i] = sum;
    }
    sum = 1;
    for (int i = 0; i < a.size(); i++) {
        sum *= a[i];
        temp[i] = sum;
        if (i == 0) {
            t = temp1[i + 1];
        } else if (i == a.size() - 1) {
            t = temp[i - 1];
        } else {
            t = temp[i - 1] * temp1[i + 1];
        }
        res.push_back(t);
    }
    return res;
}

int print_once(vector<int> &nums) {
    unordered_map<int, int> um;
    for (int item : nums) {
        if (um.count(item) <= 0) {
            um[item] = 1;
        } else {
            um[item] += 1;
        }
    }
    for (int item : nums) {
        if (um[item] == 1) {
            return item;
        }
    }
    return -1;
}

struct LinkList {
    int data;
    shared_ptr<LinkList> next;

    LinkList() : data(0) {}

    LinkList(int n) : data(n) {}
};

void removeNode(shared_ptr<LinkList> &head, int n) {
    shared_ptr<LinkList> p = head;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    p = head;
    len = len - n - 1;
    while (len > 0) {
        p = p->next;
        --len;
    }
    p->next = p->next->next;
}

void linked_test() {
    shared_ptr<LinkList> head = make_shared<LinkList>();
    shared_ptr<LinkList> p1 = make_shared<LinkList>(1);
    shared_ptr<LinkList> p2 = make_shared<LinkList>(2);
    shared_ptr<LinkList> p3 = make_shared<LinkList>(3);
    shared_ptr<LinkList> p4 = make_shared<LinkList>(4);
    shared_ptr<LinkList> p5 = make_shared<LinkList>(5);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = NULL;
    removeNode(head, 1);
    head = head->next;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

//机器人的运动范围
int sum(int n) { //计算数位之和
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void backtracking(int m, int n,
                  int x, int y, //当前遍历到的位置
                  int k, int &cnt, //cnt是计数
                  vector<vector<bool>> &used) { //当前元素是否使用过
    if (x == m || y == n || used[x][y])
        return;
    if (sum(x) + sum(y) > k)
        return;
    used[x][y] = true;
    cnt++;
    backtracking(m, n, x + 1, y, k, cnt, used);
    backtracking(m, n, x, y + 1, k, cnt, used);
}

int movingCount(int m, int n, int k) {
    //for (int i = 0; i <= m; i++) {
    //    for (int j = 0; j <= n; j++) {
    //        cout << i << "," << j << " ";
    //    }
    //    cout << endl;
    //}
    int cnt = 0;
    vector<vector<bool>> used(m, vector<bool>(n, false));
    backtracking(m, n, 0, 0, k, cnt, used);
    return cnt;
}

//单词搜索
class Solution2 {
private:
    vector<pair<int, int>> dirt = {{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1}};
    int rows;
    int cols;
public:
    bool backtracking(int x, int y,
                      int begin,
                      vector<vector<char>> &board, string word, vector<vector<bool>> &used) {
        if (begin == word.length() - 1) {
            return board[x][y] == word[begin];
        }
        if (board[x][y] == word[begin]) {
            used[x][y] = true;
            for (auto item : dirt) {
                int newX = x + item.first;
                int newY = y + item.second;
                if (inArea(newX, newY) && !used[newX][newY]) {
                    if (backtracking(newX, newY, begin + 1, board, word, used)) {
                        return true;
                    }
                }
            }
            used[x][y] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        rows = board.size();
        cols = board[0].size();
        if (rows == 0) {
            return false;
        }
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtracking(i, j, 0, board, word, used)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool inArea(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

};

//剪绳子
int cuttingRope(int n) { //10 = 3 + 3 + 4, 3 × 3 × 4 = 36
    if (n == 2)
        return 1;
    long long flag = 1e9 + 7;
    vector<int> dp(n + 1, 0); //dp[i]表示长度为i的绳子的最大乘积
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) { //只需要遍历一半即可 比如长度为5 (1,4)(2,3)就可以结束了
            dp[i] = max(dp[i], j * (i - j)); //剩下的i-j段绳子不剪的结果
            dp[i] = max(dp[i], j * dp[i - j]); // 剩下的i-j段绳子继续剪
        }
    }
    for (int item : dp) {
        cout << item << " ";
    }

    return dp[n];
}

int findTargetSumWays(vector<int> &nums, int target) {

}

//最大正方形
int maximalSquare(vector<vector<char>> &matrix) {
    //dp[i][j]表示i,j位置上最大边长
    int row = matrix.size();
    int col = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    //初始化
    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
            res = max(res, dp[i][0]);
        }
    }
    for (int i = 0; i < col; i++) {
        if (matrix[0][i] == '1') {
            dp[0][i] = 1;
            res = max(res, dp[0][i]);
        }
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res * res;
}

int main() {
    cout << boolalpha;
    vector<int> nums{2, 3, 1, 2, 3};
    vector<vector<char>> nums1{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
    vector<string> strs{"2", "1", "+", "13", "*"};
    cout << cuttingRope(10) << endl;
    deque<int> qu;
    qu.push

    //for (int item : constructArr(nums)) {
    //    cout << item << " ";
    //}

    //priority_queue<int, vector<int>, greater<int>> pq{greater<int>(), vector<int>{5, 7, 3, 1, 8, 9, 0}};
    //while (!pq.empty()) {
    //    cout << pq.top() << " ";
    //    pq.pop();
    //}

    return 0;
}