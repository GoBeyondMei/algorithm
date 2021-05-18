/**
  * Author: Mei
  * Date: 2021-04-20 10:07
  * Description: 
  *
  */
#include<iostream>

using namespace std;

class B1 {
public:
    void func1() {}

    int _b;
};

class B2 {
public:
    virtual void func() {}

    int _b;
};

int main() {
    cout << "sizeof(B1) = " << sizeof(B1) << endl;
    cout << "sizeof(B2) = " << sizeof(B2) << endl;
    return 0;
}
