#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

//3，2，6,1，9，0
//选择排序O(n*n)
void select_sort(vector<int> &v) {
    int min;
    for (int i = 0; i < v.size(); i++) {
        min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min]) min = j;
        }
        if (min != i) {
            swap(v[min], v[i]);
        }
    }
}

//插入排序O(n*n) 基本有序是O(n)
void insert_sort(vector<int> &v) {
    int j;
    for (int i = 1; i < v.size(); i++) {
        int temp = v[i]; //用中间变量
        j = i - 1;
        while (j >= 0 && v[j] > v[i]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
}

//冒泡排序 O(n*logn)
void bubble_sort(vector<int> &v) {
    int len = v.size();
    int flag = true;
    while (flag == true && len >= 0) {
        flag = false;
        for (int i = 0; i < len - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                flag = true;
            }
        }
        len--;
    }
}

//快速排序3, 2, 3, 1, 2, 4, 5, 5, 6
void quick_sort(vector<int> &v, int t, int w) {
    int i = t, j = w;
    int temp;
    if (t >= w) return;
    temp = v[i];
    while (i < j) {
        while (i < j && temp <= v[j]) j--;
        if (i < j) {
            v[i] = v[j];
            i++;
        }
        while (i < j && temp >= v[i]) i++;
        if (i < j) {
            v[j] = v[i];
            j--;
        }
    }
    v[i] = temp;
    quick_sort(v, t, j - 1);
    quick_sort(v, j + 1, w);
}

//堆排序
//优先队列的底层就是用堆排序
void heap_use() {  //使用容器自带的堆排序
    vector<int> vect{4, 3, 6, 7, 9, 8, 0};
    vector<int>::iterator it = vect.begin();
    while (it != vect.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << *it << endl;
    cout << "排序之前" << endl;
    for (auto v : vect) {
        cout << v << " ";
    }
    make_heap(vect.begin(), vect.end()); //默认是大根堆
    cout << "\n调整之后" << endl;
    for (auto v : vect) {
        cout << v << " ";
    }
    sort_heap(vect.begin(), vect.end());
    cout << "\n排序之后" << endl;
    for (auto v : vect) {
        cout << v << " ";
    }

    sort(vect.begin(), vect.end());
}
/************************堆排序*****************************/
//调整大根堆
void adjustHead(int *arr, int i, int size) { //调整大根堆是最重要的
    int temp = arr[i]; //当前父节点
    //k开始是指向当前节点的左节点并且是大于右节点 所以需要判断是否大于右节点的
    for (int k = 2 * i + 1; k < size; k += 2 * k) {
        //cout<<k<<" ";
        if (k + 1 < size && arr[k] < arr[k + 1]) { //如果有右子节点  并且右子结点大于左子结点
            ++k; //k指向左右结点中最大的结点
        }
        if (arr[k] > temp) {  //如果子节点大于父节点
            arr[i] = arr[k];
            i = k; //指向需要与最小元素替换的位置
        } else {
            break;
        }
    }
    arr[i] = temp; //把最小值与最大值
}

void print(int *arr) {
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
}

void heap_sort(int *arr, int size) {
    //1、构建大根堆
    for (int i = size / 2 - 1; i >= 0; --i) { //需要调整size/2-1次
        adjustHead(arr, i, size);
    }

    //2、调整大根堆
    for (int j = size - 1; j > 0; --j) {
        swap(arr[0], arr[j]); //把最大值与最后一个元素交换
        adjustHead(arr, 0, j); //交换之后继续调整 并且长度递减
    }
    print(arr);
}

int main() {
    vector<int> v{3, 2, 1, 4, 6};
    int arr[9] = {4, 3, 4, 0, 7, 2, 5, 6, 9};
    quick_sort(v, 0, v.size() - 1);

    for (auto item : v) {
        cout << item << " ";
    }
    //heap_use();


    return 0;
}