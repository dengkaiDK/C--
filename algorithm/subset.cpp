#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> array;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int n = nums.size();
        array = nums;
        for(int i = 0; i < n; i++)
            ans = power(ans, i);
        
        return ans;
    }

    vector<vector<int>> power(vector<vector<int>> a, int i){
        vector<vector<int>> res;
        for(auto v: a){
            vector<int> append(v);
            append.push_back(array[i]);
            res.push_back(v);
            res.push_back(append);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto ans = s.subsets(nums);
    for (auto v : ans){
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}