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
        // ʹ��αͷ����αβ���ڵ�
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // ��� key ���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // ��� key �����ڣ�����һ���µĽڵ�
            DLinkedNode *node = new DLinkedNode(key, value);
            // ��ӽ���ϣ��
            cache[key] = node;
            // �����˫�������ͷ��
            addToHead(node);
            ++size;
            if (size > capacity) {
                // �������������ɾ��˫�������β���ڵ�
                DLinkedNode *removed = removeTail();
                // ɾ����ϣ���ж�Ӧ����
                cache.erase(removed->key);
                // ��ֹ�ڴ�й©
                delete removed;
                --size;
            }
        } else {
            // ��� key ���ڣ���ͨ����ϣ��λ�����޸� value�����Ƶ�ͷ��
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

    //ȡֵ
    int get(int key) {
        if (cache.count(key) > 0) {
            LinkedNode *node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    //���ֵ
    void put(int key, int value) {
        if (cache.count(key) == 0) { //������
            LinkedNode *node = new LinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            size++;
            if (size > capacity) { //��������
                LinkedNode *t = removeTail(); //��Ҫ����Ҫɾ���Ľڵ� ���ܴ�hash����ɾ��
                cache.erase(t->key);
                delete t;
                --size;
            }
        } else {
            LinkedNode *node = cache[key];
            node->value = value; //�����޸�ֵ
            moveToHead(node); //�ӵ�ͷ��
        }
    }

    //��ӵ�ͷ��
    void addToHead(LinkedNode *node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    //�Ƴ��ڵ�
    void removeNode(LinkedNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    //ɾ��β���ڵ�
    LinkedNode *removeTail() {
        LinkedNode *res = tail->prev;
        removeNode(res);
        return res;
    }

    //���Ƴ��ڵ���ӵ�ͷ��
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
    lRUCache->put(1, 1); // ������ {1=1}
    lRUCache->put(2, 2); // ������ {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // ���� 1
    lRUCache->put(3, 3); // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // ���� -1 (δ�ҵ�)
    lRUCache->put(4, 4); // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // ���� -1 (δ�ҵ�)
    cout << lRUCache->get(3) << endl;    // ���� 3
    cout << lRUCache->get(4) << endl;    // ���� 4

    return 0;
}