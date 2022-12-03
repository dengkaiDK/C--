#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return (vector<int>){-1, -1};
        int s,e;
        int mid;
        mid = binary_search(nums, target);
        if(mid == -1) return (vector<int>){-1, -1};
        s = e = mid;
        int start = 0, end = nums.size() - 1;
        while (start < s){
            mid = start + (s - start)/2;
            if (nums[mid] == target){
                s = mid;
            }
            else{
                start = mid + 1;
            }
        }
        
        while (end > e){
            mid = (end + e + 1) / 2; // Up round
            if(nums[mid] == target){
                e = mid;
            }
            else{
                end = mid - 1;
            }
        }
        
        return  (vector<int>){s, e};
    }
    
    int binary_search(vector<int>& nums, int target){
        int start=0, end = nums.size() -1;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return -1;
    }
};


int main(){
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = s.searchRange(nums, 8);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}