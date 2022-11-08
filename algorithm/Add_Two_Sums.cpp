// Solution for Leetcode Problem 1: Add Two Sums
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result;
    unordered_map<int, int> m;
    //O(n) time complexity
    for (int i = 0; i < nums.size(); i++){
        int answer = target - nums[i];
        if (m.find(nums[i]) != m.end()){
            result.push_back(m[nums[i]]);
            result.push_back(i);
            break;
        }
        else m[answer] = i;
    }
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}