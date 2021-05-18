/**
  * Author: Mei
  * Date: 2021-02-27 18:43
  * Description: 
  *
  */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) { //{[]}
        stack<char> sc;
        vector<int> v;
        for(int i = 0; i < s.length(); i++) {
            if(sc.empty()) {
                sc.push(s[i]);
            } else {
                if((s[i]==']'&&sc.top()=='[') || (s[i]=='}'&&sc.top()=='{')||(s[i]==')'&&sc.top()=='(')) {
                    sc.pop();
                } else {
                    sc.push(s[i]);
                }
            }
        }
        if(sc.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    if(s.isValid("{[()]}")) {
        cout << "success" << endl;
    } else {
        cout << "failure" << endl;
    }

    return 0;
}