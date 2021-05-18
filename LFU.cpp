#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
//LFU��Least Frequently Used���㷨�������ݵ���ʷ����Ƶ������̭���ݣ�
// �����˼���ǡ�������ݹ�ȥ�����ʶ�Σ���ô���������ʵ�Ƶ��Ҳ���ߡ���
using namespace std;

struct Node {
    int cnt; //ʹ��Ƶ��
    int time; //���һ��ʹ�õ�ʱ��
    int key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    // ������Ҫʵ��һ�� Node ��ıȽϺ���
    // �� cnt��ʹ��Ƶ�ʣ���Ϊ��һ�ؼ��֣�time�����һ��ʹ�õ�ʱ�䣩��Ϊ�ڶ��ؼ���
    // ������ C++ ���Ե�һ���ȽϺ���������
    bool operator<(const Node &rhs) const { //���A.B  Ӧ�ð�A�ŵ�ǰ�� B�ŵ�����
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
    // ����������ʱ���
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // �����ϣ����û�м� key������ -1
        if (it == key_table.end()) return -1;
        // �ӹ�ϣ���еõ��ɵĻ���
        Node cache = it->second;
        // ��ƽ���������ɾ���ɵĻ���
        S.erase(cache); //��ɾ��
        // ���ɻ������
        cache.cnt += 1;
        cache.time = ++time;
        // ���»������·����ϣ���ƽ���������
        S.insert(cache); //��������
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) { //û�и�Ԫ��
            // ������ﻺ����������
            if (key_table.size() == capacity) {
                // �ӹ�ϣ���ƽ���������ɾ���������ʹ�õĻ���
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // �����µĻ���
            Node cache = Node(1, ++time, key, value);
            // ���»�������ϣ���ƽ���������
            key_table.insert(make_pair(key, cache)); //��������
            S.insert(cache);
        } else { //�Ѿ�����
            // ����� get() ��������
            Node cache = it->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it->second = cache;
        }
    }
};

int main() {
    LFUCache *lFUCache = new LFUCache(2);
    lFUCache->put(1, 1);   // cache=[1,_], cnt(1)=1
    lFUCache->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lFUCache->get(1) << endl;      // ���� 1
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache->put(3, 3);   // ȥ���� 2 ����Ϊ cnt(2)=1 ��ʹ�ü�����С
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lFUCache->get(2) << endl;      // ���� -1��δ�ҵ���
    cout << lFUCache->get(3) << endl;      // ���� 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache->put(4, 4);   // ȥ���� 1 ��1 �� 3 �� cnt ��ͬ���� 1 ���δʹ��
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lFUCache->get(1) << endl;      // ���� -1��δ�ҵ���
    cout << lFUCache->get(3) << endl;      // ���� 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lFUCache->get(4) << endl;      // ���� 4
    // cache=[3,4], cnt(4)=2, cnt(3)=3

    return 0;
}