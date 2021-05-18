#include <vector>
#include <iostream>

using namespace std;

/**
 * vector��insert��emplace��Ч�ʱȽ�
 *
 *
 *
 */
class testDemo {
public:
    testDemo(int num) : num(num) {
        std::cout << "���ù��캯��" << endl;
    }

    testDemo(const testDemo &other) : num(other.num) {
        std::cout << "���ÿ������캯��" << endl;
    }

    testDemo(testDemo &&other) : num(other.num) {
        std::cout << "�����ƶ����캯��" << endl;
    }

    testDemo &operator=(const testDemo &other);

    ~testDemo() {
        //cout << "��������" << endl;
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
     * ���н��
     *   constructor
         copy constructor
        101

         constructor
         copy constructor
        3 201
        �ڶ���copy constructor����������ʱ��ӡ�� ����ÿ������캯��ʹ�����100
        �����ʼֱ��ָ��������С�Ͳ����ӡ��
     */
    return 0;
}