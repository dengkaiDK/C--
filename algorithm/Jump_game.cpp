#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    map<int, bool> f;
    vector<int> n;
    bool canJump(vector<int>& nums) {
        n = nums;
        int i;
        // initialize
        if(nums.size() == 1) return true;
        f[nums.size() - 1] = true;
        // backward computation: can efficiently speed up the computation by memorization.
        for(i = nums.size() -2 ; i >=0; i--)
            Jump(i, i+1);
        
        return f[0];
    }

    // use next index and its result to accelerate the computation
    bool Jump(int index, int prev){
        if (index >= n.size() - 1) return true;
        if (f.find(index) != f.end()) return f[index];

        int i = n[index];
        int j = n[prev];

        // if the next index is reachable and current value is > 0, than current index is reachable
        f[index] = i==0 ? false : f[prev];
        // if not reachable, find index bigger than 1 + next_value to avoid duplicate computation, this is
        // another trick to accelerate computation. Find a reachable index, break the loop.
        while(i > j + 1 && !f[index]){
            f[index + i] = Jump(index + i, index + i + 1);
            f[index] |= f[index + i];
            i--;
        }
        return f[index];
    }
   
};


int main(){
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << s.canJump(nums) << endl;
    return 0;
}