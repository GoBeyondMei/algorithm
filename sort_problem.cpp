#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

//3��2��6,1��9��0
//ѡ������O(n*n)
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

//��������O(n*n) ����������O(n)
void insert_sort(vector<int> &v) {
    int j;
    for (int i = 1; i < v.size(); i++) {
        int temp = v[i]; //���м����
        j = i - 1;
        while (j >= 0 && v[j] > v[i]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
}

//ð������ O(n*logn)
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

//��������3, 2, 3, 1, 2, 4, 5, 5, 6
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

//������
//���ȶ��еĵײ�����ö�����
void heap_use() {  //ʹ�������Դ��Ķ�����
    vector<int> vect{4, 3, 6, 7, 9, 8, 0};
    vector<int>::iterator it = vect.begin();
    while (it != vect.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << *it << endl;
    cout << "����֮ǰ" << endl;
    for (auto v : vect) {
        cout << v << " ";
    }
    make_heap(vect.begin(), vect.end()); //Ĭ���Ǵ����
    cout << "\n����֮��" << endl;
    for (auto v : vect) {
        cout << v << " ";
    }
    sort_heap(vect.begin(), vect.end());
    cout << "\n����֮��" << endl;
    for (auto v : vect) {
        cout << v << " ";
    }

    sort(vect.begin(), vect.end());
}
/************************������*****************************/
//���������
void adjustHead(int *arr, int i, int size) { //���������������Ҫ��
    int temp = arr[i]; //��ǰ���ڵ�
    //k��ʼ��ָ��ǰ�ڵ����ڵ㲢���Ǵ����ҽڵ� ������Ҫ�ж��Ƿ�����ҽڵ��
    for (int k = 2 * i + 1; k < size; k += 2 * k) {
        //cout<<k<<" ";
        if (k + 1 < size && arr[k] < arr[k + 1]) { //��������ӽڵ�  �������ӽ��������ӽ��
            ++k; //kָ�����ҽ�������Ľ��
        }
        if (arr[k] > temp) {  //����ӽڵ���ڸ��ڵ�
            arr[i] = arr[k];
            i = k; //ָ����Ҫ����СԪ���滻��λ��
        } else {
            break;
        }
    }
    arr[i] = temp; //����Сֵ�����ֵ
}

void print(int *arr) {
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
}

void heap_sort(int *arr, int size) {
    //1�����������
    for (int i = size / 2 - 1; i >= 0; --i) { //��Ҫ����size/2-1��
        adjustHead(arr, i, size);
    }

    //2�����������
    for (int j = size - 1; j > 0; --j) {
        swap(arr[0], arr[j]); //�����ֵ�����һ��Ԫ�ؽ���
        adjustHead(arr, 0, j); //����֮��������� ���ҳ��ȵݼ�
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