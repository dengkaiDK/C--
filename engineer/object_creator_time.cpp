#include<iostream>
#include<sys/time.h>

using namespace std;

class Val{
public:
    Val(double v = 1.0){
        for(int i=0; i < 1000; i++){
            val[i] = v;
        }
    }
    void Init(double v = 1.0){
        for(int i=0; i < 1000; i++){
            val[i] = v;
        }
    }
private:
    double val[1000];
};

class Object{
    public:
    Object(double v = 1.0):val(v){
        // 1708
    }

    // Object(double v = 1.0){
    //     val.Init(v); // 3429
    // }
    private:
    Val val;
};

//结论：使用成员初始化列表，比在普通函数中初始化成员变量要快一倍
int main(){
    clock_t start = clock();
    for(int i=0; i < 1000000; i++){
        Object obj(1.0);
    }
    clock_t elapsed = clock() - start;
    cout << "time elapsed: " << elapsed << endl;
    return 0;
}