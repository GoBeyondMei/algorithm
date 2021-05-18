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
        res.push_back(path); // �ռ��Ӽ�
        if (startIndex >= nums.size()) { // ��ֹ�������Բ���
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
//public://����B������û��д�麯��  B����̳�A���麯��(�̳е��ǵ���Ȩ)
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

//�����г��ִ�������һ�������
//1������
//2��Ħ��ͶƱ��
int majorityElement(vector<int> &nums) {
    int cur = 0; //������¼��ǰ����
    int vote = 0; //Ʊ��
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

//�������������1
//��������һ���������ĳ������ķ���������ֵ
int findMaxConsecutiveOnes(vector<int> &nums) {  //1 1 0 1 1 1
    int res = 0;
    int left, right;
    left = right = 0;
    while (right < nums.size()) {
        if (nums[right] != 1) { //�����˳���ܷŷ�  ��right��λ�ò�Ϊ1��ʱ��  right��Ҫ++
            right++;
            left = right;
        } else {
            right++;
        }
        res = max(res, right - left);
    }
    return res;
}

//�������1�ĸ���  �����Խ�k��0תΪ1
int longestOnes(vector<int> &nums, int k) { //1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0
    //��򵥵��ǻ�������
    int res = 0;
    int left, zero;
    left = zero = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zero++;
        while (zero > k) {
            if (nums[left] == 0) { //��0�ĸ�������kʱ  �����ҵ���һ��leftΪ0�ĵط�
                zero--;
            }
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}

//ɾ���ַ����е����������ظ���  abbaca
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

//�沨�����ʽ��ֵ 2,1,+,3,*=9
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

//�������ڵ����ֵ
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    deque<int> st;  //����Ҫ��deque
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
//my_memcpyʵ���ص��ڴ�ת��
char *my_memcpy(char *dest, const char *src) {
    //��鴫���������Ч��
    if (NULL == dest || NULL == src)
        return NULL;
    char *ret = dest;
    int count = strlen(dest) + 1;
    /**
    _Dest��_Source���ڴ��ַ������������ϣ�
    1. _Dest��_Sourceû�з����ص���
    2. _Dest��_Source��ַ�ص�����_Dest�ĵ�ַ����_Source�ĵ�ַ��
    3. _Dest��_Source��ַ�ص���_Dest�ĵ�ַС��_Source�ĵ�ַ��
    ��һ������͵����������ֱ�Ӵӵ�λ�ֽڿ�ʼ���ƣ����ɣ�
    �ڶ������������Ӹ�λ�ֽڿ�ʼ���ƣ����ܱ�֤������ȷ��
    */
    if (dest > src && dest <= src + count - 1) { //�ڶ������
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

//����ģʽ
//����ģʽ
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

//����
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
    vector<long> dp(n + 1);   //dp[i] ��ʾiλ���ϵ���������
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

//�����Ӵ�
int countSubstrings(string s) { //aba
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false)); //dp[i][j]��ʾ��i��j����Ӵ�
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

//��Ļ����Ӵ�
string longestPalindrome(string s) { //babad
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false)); //dp[i][j]��ʾ��i��j����Ӵ�
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
                res = max(res, j - i + 1); //����cabac  j��������c��λ��  dp[i] = dp[j] ��Ҫ�� dp[i+1][j-1]�Ƿ��ǻ����Ӵ�
                start = i; //��¼��������λ��
            }
        }
    }
    return s.substr(start, res);
}

//�����������(��һ������)
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

//�������ų���С����
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

//�����ַ�����ַ���
int translateNum(int num) { //12258
    string s = to_string(num);
    const int n = s.size();
    vector<int> d(n);  //dp[i]��ʾ0��iλ������ɵ��ַ�������
    d[0] = 1; //һ���ַ�Ϊ1
    for (int i = 1; i < n; ++i) {
        d[i] = d[i - 1];
        //1225  ��i��5��λ��ʱ ��25������ַ���ʱ ��Ϊ�������һ�������25Ϊdp[i-2] ������ֻѡ5 Ϊdp[i-1]
        //1228 ��i��8��λ��ʱ 28��������ַ�������Ϊdp[i-1]
        string sub = s.substr(i - 1, 2);
        if (s[i - 1] != '0' && stoi(sub) < 26) {
            d[i] += i - 2 >= 0 ? d[i - 2] : 1;
        }
    }
    return d[n - 1];
}

//���ַ���תΪ����
int strToInt(string str) {
    int len = str.length();
    bool opt = true; //��������
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

//ԲȦ��ʣ�µ��������
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

//��������λ��
int searchInsert(vector<int> &nums, int target) { //1,3,5,6  5
    int l, r;
    int len = nums.size();
    l = 0;
    r = len;
    if (nums[0] > target) return 0;
    else if (nums[len - 1] < target) return len;
    while (l <= r) {
        int mid = l + (r - l) / 2; //Ϊ�˴�������������
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
//���ֲ���
/**
 * һ���Ϊ��������ұ�[left,right]
 * ����ҿ�[left, right)
 *
 */
//��һ�� ����target��һ������ұ�����
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

//�ڶ��֣�����target��һ������ҿ�����
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

//�����������в���Ԫ�صĵ�һ�������һ��λ��
//�ҵ������λ��
int binarySearch1(vector<int> &nums, int target) { //�Ľ��Ķ��ֲ���
    int left = 0, right = nums.size(); //5,7,7,8,8,10
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] >= target) { //��midλ�ú�targetλ�����ʱ  ������Сright�ķ�Χ
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
        } else if (nums[mid] <= target) {//��midλ�ú�targetλ�����ʱ  ��������left�ķ�Χ ʹ���ҵ��������ȵ�λ��
            left = mid + 1;
        }
    }
    if (nums[left - 1] != target) return -1;
    return left - 1; //������ʱλ����Ҫ�ı�һ��
}

vector<int> searchRange(vector<int> &nums, int target) { //5,7,7,8,8,10
    if (nums.size() <= 0) return {-1, -1};
    vector<int> res;
    res.push_back(binarySearch1(nums, target)); //���ҵ�һ����ȵ�
    res.push_back(binarySearch2(nums, target)); //�������һ����ȵ�
    return res;
}

//x��ƽ����
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

//������С��������
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

//ˮ������
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

//��Ч����ȫƽ����
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

//���������ƽ��
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

//������Ʊϵ��
//������Ʊ�����ʱ��
int maxProfit1(vector<int> &prices) { //7,1,5,3,6,4   5 ̰���㷨  �������Сֵ �����ҵ����ֵ
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
    // dp[i][1] �±�Ϊ i ���������ʱ�򣬲��ֹɣ�����ӵ�е��ֽ���
    // dp[i][0] �±�Ϊ i ���������ʱ�򣬳ֹɣ�����ӵ�е��ֽ���

    // ��ʼ�������ֹ���ȻΪ 0���ֹɾ���Ҫ��ȥ�� 1 �죨�±�Ϊ 0���Ĺɼ�
    dp[0][1] = 0;
    dp[0][0] = -prices[0];

    for (int i = 1; i < len; i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}

//��������
void test_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    //dp[i][j]��ʾ��0-i��Ʒ������õ�����ֵ
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));

    //��ʼ��
    for (int i = bagWeight; i >= weight[0]; i--) {
        dp[0][i] = dp[0][i - weight[0]] + value[0];
    }

    for (int i = 1; i < weight.size(); i++) { //��Ʒ ��Ϊ0��Ʒ�Ѿ���ʼ����
        for (int j = 0; j <= bagWeight; j++) { //��������
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

//ѹ������
void test_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    //dp[i]��ʾ������Ϊi����������ֵ
    vector<int> dp(bagWeight + 1, 0);

    for (int i = 0; i < weight.size(); i++) { //��Ʒ
        for (int j = bagWeight; j >= weight[i]; j--) { //��������
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    for (auto item : dp) {
        cout << item << " ";
    }
}

//�ָ�Ⱥ��Ӽ�
bool canPartition(vector<int> &nums) {  //1 5 11 5
    int sum = 0;
    vector<int> dp(20001, 0); //dp[i]��ʾ������������Ϊi�������Դճ��Ӽ���Ϊdp[i]
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

//���һ��ʯͷ������
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

//��ҽ���
int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), 0); //dp[i]��ʾi��������͵�Ե�����߼�ֵ
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

//ɾ������������ظ���
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

//�жϳ���
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

//����n������
int nthUglyNumber(int n) {
//1����С��  2����̬�滮  3��˫ָ��
    vector<int> dp(n + 1); //dp[i]��ʾ��i������Ϊdp[i]
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
//1����С��  2����̬�滮  3��˫ָ��
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
//1����С��
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

//Ѱ�ҷ�ֵ
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

//Ѱ���ظ���
int findDuplicate(vector<int> &nums) {
    //��ͨ�Ľⷨ
    //for (int i = 0; i < nums.size(); i++) {
    //    while (nums[i] != i + 1) {
    //        if (nums[nums[i]-1] == nums[i]) {
    //            return nums[i];
    //        }
    //        swap(nums[i], nums[nums[i] - 1]);
    //    }
    //}
    //return -1;

    //����ָ��Ľⷨ ʱ�临�ӵ�ΪO(n) �ռ�ΪO(1) û�иĶ�ԭ����
    int slow = 0;
    int fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast) { //�ж��Ƿ��л�
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    int pre1 = 0;
    int pre2 = slow;
    while (pre1 != pre2) {  //Ѱ���ཻ�ĵط�  pre1��0��ʼ  pre2��slow(����fast�����ĵط�)��ʼ
        pre1 = nums[pre1];
        pre2 = nums[pre2];
    }
    return pre1;
}

//�����Ҳ�С�ڵ�ǰԪ�ص�ֵ
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

//ɾ������õ���
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
    //����һ���µ�����all
    vector<int> all(mx + 1, 0);
    for (int item : nums) {
        all[item]++;
    }
    vector<int> dp(mx + 1);
    dp[1] = all[1] * 1;
    dp[2] = max(dp[1], all[2] * 2);
    //��̬�滮���
    for (int i = 2; i <= mx; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * all[i]);
    }
    return dp[mx];
}

//λ1�ĸ���
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

//��ʧ������
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

//�������ظ�������
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

//�����˻�����
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

//�����˵��˶���Χ
int sum(int n) { //������λ֮��
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void backtracking(int m, int n,
                  int x, int y, //��ǰ��������λ��
                  int k, int &cnt, //cnt�Ǽ���
                  vector<vector<bool>> &used) { //��ǰԪ���Ƿ�ʹ�ù�
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

//��������
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

//������
int cuttingRope(int n) { //10 = 3 + 3 + 4, 3 �� 3 �� 4 = 36
    if (n == 2)
        return 1;
    long long flag = 1e9 + 7;
    vector<int> dp(n + 1, 0); //dp[i]��ʾ����Ϊi�����ӵ����˻�
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) { //ֻ��Ҫ����һ�뼴�� ���糤��Ϊ5 (1,4)(2,3)�Ϳ��Խ�����
            dp[i] = max(dp[i], j * (i - j)); //ʣ�µ�i-j�����Ӳ����Ľ��
            dp[i] = max(dp[i], j * dp[i - j]); // ʣ�µ�i-j�����Ӽ�����
        }
    }
    for (int item : dp) {
        cout << item << " ";
    }

    return dp[n];
}

int findTargetSumWays(vector<int> &nums, int target) {

}

//���������
int maximalSquare(vector<vector<char>> &matrix) {
    //dp[i][j]��ʾi,jλ�������߳�
    int row = matrix.size();
    int col = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    //��ʼ��
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