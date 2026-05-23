#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
    Test(int v) : val(v) { cout << "构造 Test(" << val << ")" << endl; }
    ~Test() { cout << "析构 Test(" << val << ")" << endl; }
    void show() { cout << "val = " << val << endl; }
private:
    int val;
};

void raw_pointer_disaster() {
    cout << "=== 裸指针问题 ===" << endl;
    Test* p = new Test(100);
    p->show();
    // 忘记 delete，内存泄漏
    cout << "函数结束，内存未释放！" << endl;
}

void unique_ptr_demo() {
    cout << "\n=== unique_ptr ===" << endl;
    unique_ptr<Test> p1 = make_unique<Test>(42);
    p1->show();
    unique_ptr<Test> p2 = move(p1);
    if (p1 == nullptr) cout << "p1 已经为空" << endl;
    p2->show();
    // 函数结束自动释放
}

void shared_ptr_demo() {
    cout << "\n=== shared_ptr ===" << endl;
    shared_ptr<Test> p1 = make_shared<Test>(10);
    cout << "引用计数: " << p1.use_count() << endl;
    {
        shared_ptr<Test> p2 = p1;
        cout << "引用计数: " << p1.use_count() << endl;
    }
    cout << "引用计数: " << p1.use_count() << endl;
}

struct B;
struct A {
    shared_ptr<B> b_ptr;
    ~A() { cout << "A 析构" << endl; }
};
struct B {
    weak_ptr<A> a_ptr;  // 弱引用
    ~B() { cout << "B 析构" << endl; }
};

void circular_reference_demo() {
    cout << "\n=== weak_ptr 解决循环引用 ===" << endl;
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    cout << "a 引用计数: " << a.use_count() << endl;
}

int main() {
    raw_pointer_disaster();
    unique_ptr_demo();
    shared_ptr_demo();
    circular_reference_demo();
    return 0;
}