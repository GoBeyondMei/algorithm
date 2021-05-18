/**
  * Author: Mei
  * Date: 2021-02-27 18:43
  * Description:  基本测试题
  *
  */
#include <iostream>
#include <stack>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

void add(int *p) {
    (*p)++; //*p是有返回值的  比如引用
    cout << *p;

    if (*p > 5) return;

    add(p);
}

//隐藏
class Base {
public:
    void fun(double, int) { cout << "Base::fun(double ,int )" << endl; }
};

class Derive : public Base {
public:
    void fun(int) { cout << "Derive::fun(int )" << endl; }
};

//重写(覆盖)
class Base1 {
public:
    virtual Base1 &fun(int i) { cout << "Base::fun(int) : " << i << endl; }
};

class Derived1 : public Base1 {
public:
    virtual Derived1 &fun(int i) { cout << "Derived::fun(int) : " << i << endl; }
};

class A1 {
public:
    virtual ~A1() {}
};

class B1 {
public:
    virtual ~B1() {}
};

class C1 : public A1, public B1 {
};

//无符号整型与整型比较  会将无符号转为int类型 再比较
void test() {
    for (int i = 10; i >= 0; i--) { //死循环
        cout << i << " ";
    }
    cout << (unsigned int) (-1) << endl;  //结果为4294967295

    //浮点类型判断
    float f = 0.21;
    if (abs(f - 0.2) < 0.00001) {
        cout << "equal" << endl;
    }
}

void fun(int *p1, int *p2, int *s) {
    s = (int *) malloc(sizeof(int));
    printf("fun: %p\n", s);
    *s = *p1 + *(p2++);
    cout << *s << endl;
}

class A {
protected:
    int a = 20;
};

class B : public A {
public:
    void displayB() {
        cout << a << endl;
    }
};

class C : public B {
public:
    void display() {
        cout << a << endl;
    }
};

class Hum {
public:
    Hum() { cout << "人类的构造函数..........................................<<endl" << endl; }

    int a = 20;

    void walk() { cout << "人类可以走路！！！" << endl; }
};

class Father : virtual public Hum {
public:
//    void walk(int){cout<<"父亲能够直立行走！！！"<<endl;}
    Father() { cout << "父亲的构造函数..." << endl; }
};

class Mother : virtual public Hum {
public:
    Mother() { cout << "母亲的构造函数...." << endl; }
};

class Son : public Mother, public Father {
public:
    Son() { cout << "儿子的构造函数..." << a << endl; }
};

int main() {
    C c;
    c.display();
    return 0;
}