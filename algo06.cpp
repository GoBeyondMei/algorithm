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

int getIndex(vector<int> nums, int k) { //[1,3,5,6], 5
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (nums[mid] < k) {
            i = mid + 1;
        } else if (nums[mid] > k) {
            j = mid - 1;
        } else {
            return mid;
        }
    }
    return 0;
}

int removeItem(vector<int> &nums, int target) { //[0,1,2,2,3,0,4,2], val = 2,
    int len = nums.size();
    int slowIndex = 0, fastIndex = 0;
    while (fastIndex < len) {
        if (nums[fastIndex] != target) {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
        fastIndex++;
    }
    return slowIndex;
}

int getSubArray(vector<int> &v, int target) {
    //暴力解法
    //int sum, count;
    //int mi = INT_MAX;
    //for (int i = 0; i < v.size(); i++) {
    //    sum = 0;
    //    count = 0;
    //    for (int j = i; j < v.size(); j++) {
    //        sum += v[j];
    //        count++;
    //        if (sum > target) {
    //            break;
    //        } else if (sum == target) {
    //            mi = min(mi, count);
    //        }
    //    }
    //}
    //return mi == INT_MAX ? 0 : mi;

    //滑动窗口的做法
    int sum = 0, mi, i, subLength;
    mi = INT_MAX;
    i = subLength = 0;
    for (int j = 0; j < v.size(); j++) { //7, nums = [2,3,1,2,4,3]
        sum += v[j];
        while (sum >= target) {
            subLength = (j - i + 1);
            mi = mi < subLength ? mi : subLength;
            sum -= v[i++];
        }
    }
    return mi == INT_MAX ? 0 : mi;
}

int main() {
    vector<int> v{2, 3, 1, 2, 4, 3};
    cout << getSubArray(v, 7) << endl;

    return 0;
}