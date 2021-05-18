#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <algorithm>

//trie树
using namespace std;

class Trie {
private:
    bool isEnd;
    Trie *next[26] = {NULL};
public:
    Trie() {
        isEnd = false; //判断该节点是否是最后一个结束标识
        //memset(next, 0, sizeof(next));
    }

    ~Trie() {
    }

    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return false;
            }
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c : prefix) {
            node = node->next[c - 'a'];
            if (node == NULL) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("sea");
    trie.insert("sells");
    trie.insert("she");
    cout << trie.search("she") << endl;
    cout << trie.startsWith("sde") << endl;


    return 0;
}