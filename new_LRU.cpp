#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int size) : capacity(size) {}

    int get(int key) {
        const auto it = mp.find(key);
        if (it == mp.cend()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = mp.find(key);
        if (it != mp.end()) {  //keyÒÑ¾­´æÔÚ
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        if (cache.size() == capacity) {
            const auto &node = cache.back();
            mp.erase(node.first);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        mp[key] = cache.begin();
    }
};


int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;


    return 0;
}