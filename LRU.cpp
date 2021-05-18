#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;

    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode *node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode *removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        } else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

//new
struct LinkedNode {
    LinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    LinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}

    int key;
    int value;
    LinkedNode *prev;
    LinkedNode *next;
};

class Cache {
public:
    Cache(int c) : capacity(c), head(nullptr), tail(nullptr), size(0) {
        head = new LinkedNode();
        tail = new LinkedNode();
        head->next = tail;
        tail->next = head;
    }

    //取值
    int get(int key) {
        if (cache.count(key) > 0) {
            LinkedNode *node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    //存放值
    void put(int key, int value) {
        if (cache.count(key) == 0) { //不存在
            LinkedNode *node = new LinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            size++;
            if (size > capacity) { //容量过大
                LinkedNode *t = removeTail(); //需要返回要删除的节点 才能从hash表中删除
                cache.erase(t->key);
                delete t;
                --size;
            }
        } else {
            LinkedNode *node = cache[key];
            node->value = value; //重新修改值
            moveToHead(node); //加到头部
        }
    }

    //添加到头部
    void addToHead(LinkedNode *node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    //移除节点
    void removeNode(LinkedNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    //删除尾部节点
    LinkedNode *removeTail() {
        LinkedNode *res = tail->prev;
        removeNode(res);
        return res;
    }

    //先移除节点添加到头部
    void moveToHead(LinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

private:
    int size;
    int capacity;
    LinkedNode *head;
    LinkedNode *tail;
    unordered_map<int, LinkedNode *> cache;
};

int main() {
    Cache *lRUCache = new Cache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // 返回 1
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // 返回 -1 (未找到)
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lRUCache->get(3) << endl;    // 返回 3
    cout << lRUCache->get(4) << endl;    // 返回 4

    return 0;
}