#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
struct display
{
    void operator()(const T&x) const
    {
        cout << x << " ";
    }
};

int main(int argc, char* argv[])
{
    int iarr[] = { 4, 5, 1, 3, 2 };
    vector<int> iv(iarr, iarr + sizeof(iarr) / sizeof(int));

    /*** make_heap: 把指定范围内的元素生成一个堆。 ***/
    //  原型： void make_heap(_RanIt _First, _RanIt _Last)
    make_heap(iv.begin(), iv.end());
    cout << "make_heap: ";
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;

    /*** pop_heap: 并不真正把最大元素从堆中弹出，而是重新排序堆。 ***/
    //  原型： void pop_heap(_RanIt _First, _RanIt _Last)
    pop_heap(iv.begin(), iv.end());
    iv.pop_back(); // 进行真正的删除
    cout << "pop_heap: ";
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;

    /*** push_heap: 假设first到last-1是一个有效堆，要被加入到堆的元素存放在位置last-1，重新生成堆。 ***/
    //  原型： void push_heap(_RanIt _First, _RanIt _Last)
    iv.push_back(6); // 先把6加入到堆中
    push_heap(iv.begin(), iv.end());
    cout << "push_heap: ";
    for_each(iv.begin(), iv.end(), display<int>());
    cout << endl;

    return 0;
}