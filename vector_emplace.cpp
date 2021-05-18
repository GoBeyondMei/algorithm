#include <vector>
#include <iostream>

using namespace std;

/**
 * vector中insert和emplace的效率比较
 *
 *
 *
 */
class testDemo {
public:
    testDemo(int num) : num(num) {
        std::cout << "调用构造函数" << endl;
    }

    testDemo(const testDemo &other) : num(other.num) {
        std::cout << "调用拷贝构造函数" << endl;
    }

    testDemo(testDemo &&other) : num(other.num) {
        std::cout << "调用移动构造函数" << endl;
    }

    testDemo &operator=(const testDemo &other);

    ~testDemo() {
        //cout << "析构函数" << endl;
    }

private:
    int num;
};

testDemo &testDemo::operator=(const testDemo &other) {
    this->num = other.num;
    return *this;
}

/***************/
class C3 {
public:
    C3() {}

    C3(int ii, string ss) : i(ii), s(ss) { cout << " constructor " << endl; }

    C3(const C3 &c) : i(c.i + 100), s(c.s + "hhhhhhhhhhh") { cout << " copy constructor " << endl; }

    int i;
    string s;
};

int main() {
    //cout << "emplace_back:" << endl;
    //std::vector<testDemo> demo1;
    //demo1.emplace_back(2);
    //cout << "push_back:" << endl;
    //std::vector<testDemo> demo2;
    //demo2.push_back(testDemo(1));

    vector<C3> vC;
    //vC.reserve(5);
    vC.push_back(C3(1, "ss"));
    cout << vC[0].i << endl;
    cout << endl;
    vC.emplace_back(3, "kk");
    cout << vC[1].i << " " << vC[0].i << endl;
    vC.empty();
    vC.size();
    /**
     * 运行结果
     *   constructor
         copy constructor
        101

         constructor
         copy constructor
        3 201
        第二个copy constructor是容器扩容时打印的 会调用拷贝构造函数使结果加100
        如果初始直接指定容器大小就不会打印了
     */
    return 0;
}