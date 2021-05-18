/**
  * Author: Mei
  * Date: 2021-02-27 18:43
  * Description:  两个栈实现队列
  *
  */
#include <iostream>
#include <stack>
#include <cstring>
#include <stdio.h>

using namespace std;

class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int t = s2.top();
        s2.pop();
        return t;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        if (s1.empty() && s2.empty()) {
            return true;
        }
        return false;
    }

private:
    stack<int> s1; //插入元素的栈
    stack<int> s2; //取出元素的栈
};

int main() {
    char a[13] = {'h', 'e', 'l', 'l', 'o', '\0'};
    strcat(a, " ");
    char b[6] = {'w', 'o', 'r', 'l', 'd', '\0'};
    char c[13];
    strcat(a, b);
    strcpy(c, a);
    printf("a=%s, b=%s, c=%s\n", a, b, c);
    string d = "abc";

    return 0;
}