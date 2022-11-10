#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 根据入参计算出最长无重复子数组的元素个数
     * @param arr int整型vector 任意输入的一组一维数组
     * @return int整型
     */
    int getMaxLength(vector<int>& arr) {
        // write code here
        int n = arr.size();
        int i=0, j=0;
        set<int> s;
        int maxLen = 0;
        
        while(j < n){
            if (s.find(arr[j]) == s.end()){
                s.insert(arr[j]);
                j++;
                maxLen = max(maxLen, j - i);
            }
            else{
                maxLen = max(maxLen, j - i);
                s.erase(arr[i]);
                i++;
            }
        }
        return maxLen;
    }
};


int main(){
    Solution a;
    vector<int> arr = {2};
    cout << a.getMaxLength(arr) << endl;
    return 0;
}