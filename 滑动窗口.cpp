/**
  * Author: Mei
  * Date: 2021-02-27 18:43
  * Description:  滑动窗口
  *
  */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void getMaxWin(vector<int> &arr, int N, vector<int> &res) { //N是滑动窗口的大小
    if (N < 1 || arr.size() < N || arr.size() < 0) {
        return;
    }
    //暴力破解
    int k = 0;
    int max;
    for (int i = 0; i <= arr.size() - N; i++) {
        max = arr[i];
        for (int j = i; j < N + i; j++) {
            if (max < arr[j]) {
                max = arr[j];
            }
        }
        res[k++] = max;
    }
}

void getMaxWin(int *arr, int len, int w, int *result) { //N是滑动窗口的大小
    if (w < 1 || arr == NULL || len < w) {
        return;
    }
    //用来保存成为最大窗口的元素
    int index = 0;
    //用链表从当双向队列。
    deque<int> temp;
    //刚才演示的时候，我i直接从i = w-1那里开始演示了。
    for (int i = 0; i < len; i++) {
        //如果队列不为空，并且存放在队尾的元素小于等于当前元素，那么
        //队列的这个元素就可以弹出了，因为他不可能会是窗口最大值。
        //【当前元素】指的是窗口向右移动的时候新加入的元素。
        while (!temp.empty() && arr[temp.back()] <= arr[i]) {
            temp.pop_back();//把队尾元素弹出
        }
        //把【当前元素】的下边加入到队尾
        temp.push_back(i);
        //如果队首的元素不在窗口范围内，则弹出
        if (temp.front() == i - w) { //不能漏掉  比如递减序列
            temp.pop_front();//
        }
        if (i >= w - 1) {
            //由于队首存放的是最大值，所以队首总是对应窗口的最大值元素
            result[index++] = arr[temp.front()];
        }
    }
}

int main() {
    //vector<int> v{4, 3, 1, 5, 4, 3, 7, 1};
    //vector<int> v1(5);
    //getMaxWin(v, 5, v1);
    //for (auto re : v1) {
    //    cout << re << " ";
    //}

    int *arr = new int[8]{4, 3, 1, 5, 4, 3, 7, 17};
    int w = 5;
    int *res = new int[8 - w + 1];
    getMaxWin(arr, 8, w, res);
    for (int i = 0; i < 4; i++) {
        cout << res[i] << " ";
    }

    return 0;
}