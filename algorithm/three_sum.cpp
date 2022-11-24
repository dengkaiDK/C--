#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int i=0;
        set<tuple<int, int, int>> tripletset;
        set<set<int>> S;
        set<int> compare;
        
        for(i = 0; i < nums.size(); i++){
            auto x = nums[i];
            tripletset = twoSum(nums, -x, i);
            
            if(tripletset.size() > 0){
                for(auto it = tripletset.begin(); it!=tripletset.end(); it++){
                    compare = {get<0>(*it), get<1>(*it), get<2>(*it)};
                    if(S.find(compare) == S.end()){
                        S.insert(compare);
                        result.push_back(vector<int> {get<0>(*it), get<1>(*it), get<2>(*it)});
                    }
                }
            }
        }
        
        return result;
    }
    
    set<tuple<int, int, int>> twoSum(vector<int>& nums, int result, int i){
        set<tuple<int, int, int>> ret{};
        int j=0;
        map<int, bool> h;
        for(j =0; j < nums.size(); j++){
            if(j == i)
                continue;
            if(h.find(result - nums[j]) == h.end()){
                h[nums[j]] = true;
            }
            else{
                ret.insert(make_tuple(-result, result - nums[j], nums[j]));
                h[nums[j]] = true;
            }
        }
        return ret;
    }
};


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map<int, int> m;
    sort(nums.begin(), nums.end());    
    
    int n = nums.size();
    
    if (n < 3) return {}; 
    if (nums[0] > 0) return {}; 
    
    for (int i = 0; i < n; i++)
        m[nums[i]] = i;
    
    for (int i = 0; i < n - 2; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) return ans;
        
        for (int j = i + 1; j < n - 1; j++) {
            
            if (j != i + 1 && nums[j] == nums[j - 1]) continue; 
            
            int key = -(nums[i] + nums[j]);
            if (m.find(key) != m.end() && m[key] > j) 
                ans.push_back({nums[i], nums[j], key});
        }
    }
    return ans;
    }
    
};


int main(){
    Solution s;
    Solution2 s1;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto result = s.threeSum(nums);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "Solution 2" << endl;
    result = s1.threeSum(nums);
    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}