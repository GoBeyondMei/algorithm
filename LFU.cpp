#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
//LFU（Least Frequently Used）算法根据数据的历史访问频率来淘汰数据，
// 其核心思想是“如果数据过去被访问多次，那么将来被访问的频率也更高”。
using namespace std;

struct Node {
    int cnt; //使用频率
    int time; //最近一次使用的时间
    int key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    // 我们需要实现一个 Node 类的比较函数
    // 将 cnt（使用频率）作为第一关键字，time（最近一次使用的时间）作为第二关键字
    // 下面是 C++ 语言的一个比较函数的例子
    bool operator<(const Node &rhs) const { //如果A.B  应该把A放到前面 B放到后面
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
    // 缓存容量，时间戳
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
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it->second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache); //先删除
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache); //重新排序
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) { //没有该元素
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache)); //重新排序
            S.insert(cache);
        } else { //已经存在
            // 这里和 get() 函数类似
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
    cout << lFUCache->get(1) << endl;      // 返回 1
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lFUCache->put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lFUCache->get(2) << endl;      // 返回 -1（未找到）
    cout << lFUCache->get(3) << endl;      // 返回 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lFUCache->put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lFUCache->get(1) << endl;      // 返回 -1（未找到）
    cout << lFUCache->get(3) << endl;      // 返回 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lFUCache->get(4) << endl;      // 返回 4
    // cache=[3,4], cnt(4)=2, cnt(3)=3

    return 0;
}