// 对于对象空间性能的考察点，在于对临时对象的认识
#include<iostream>
#include<cstring>

using namespace std;

class Matrix{
    public:
    Matrix(double v = 0.0){
        for(int i=0; i < 10; i++){
            for(int j=0; j < 10; j++){
                val[i][j] = v;
            }
        }
        cout << "Matrix()" << endl;
    }
    Matrix(const Matrix &m){
        memcpy(this, &m, sizeof(Matrix));
        cout << "copy constructor" << endl;
    }

    Matrix& operator=(const Matrix &m){
        if(this == &m){
            return *this;
        }
        memcpy(this, &m, sizeof(Matrix));
        cout << "operator=" << endl;
        return *this;
    }

    friend const Matrix operator +(const Matrix&, const Matrix&);

    private:
    double val[10][10];
};

const Matrix operator+(const Matrix &arg1, const Matrix &arg2){
    Matrix *res = new Matrix();
    cout<<"operator+"<<endl;
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            res->val[i][j] = arg1.val[i][j] + arg2.val[i][j];
        }
    }
    return *res;
}

// const Matrix operator +(const Matrix &arg1, const Matrix &arg2){
//     Matrix res; // 使用临时对象，而不是new
//     cout<<"operator+"<<endl;
//     for(int i=0; i < 10; i++){
//         for(int j=0; j < 10; j++){
//             res.val[i][j] = arg1.val[i][j] + arg2.val[i][j];
//         }
//     } // 在栈空间上创建临时对象，会极大的消耗栈内存，因此，不要在栈空间上创建临时对象
//     return res;
// }

int main(){
    Matrix m1(1.0);
    Matrix m2(2.0);
    Matrix m3;
    m3 = m1 + m2;
    return 0;
}