#include<iostream>
#include<memory>
//内存泄漏
// share ptr: 使用的是引用计数，当引用计数为0时，自动释放内存
// 
using namespace std;
//不建议将shared_ptr作为函数参数， 和返回函数，因为会增加引用计数

struct CLASS{
    CLASS(){

    };
};
//不建议使用
void TestFun(shared_ptr<int> p, CLASS* obj){
    cout << "TestFun" << endl;
}
//循环引用
struct B;

struct A{
    shared_ptr<B> b;
    A(){
        cout << "A()" << endl;
    }
    ~A(){
        cout << "~A()" << endl;
    }
};

struct B{
    shared_ptr<A> a;
    B(){
        cout << "B()" << endl;
    }
    ~B(){
        cout << "~B()" << endl;
    }
};
//解决循环引用需要将shared_ptr改为weak_ptr
// weak_ptr不会增加引用计数，也不共享指针，不操作资源

struct D;

struct C{
    weak_ptr<D> d;
    C(){
        cout << "C()" << endl;
    }
    ~C(){
        cout << "~C()" << endl;
    }
};

struct D{
    shared_ptr<C> c;
    D(){
        cout << "D()" << endl;
    }
    ~D(){
        cout << "~D()" << endl;
    }
};


int main(){
    shared_ptr<int> p1(new int(10));
    //shared_ptr<int> p2 = new int(1);
    //C++ 11不支持原生的指针赋值给shared_ptr
    shared_ptr<A> a(new A);
    shared_ptr<B> b(new B);
    a->b = b;
    b->a = a;

    shared_ptr<C> c(new C);
    shared_ptr<D> d(new D);
    c->d = d;
    d->c = c;

    return 0;
}