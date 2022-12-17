#include<iostream>
#include<vector>

using namespace std;

// Time Complexity: O(m+n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int replace = nums1.size() - 1;
        int i = m -1, j = n - 1;
        
        while (replace >= 0){
            if (i < 0){
                nums1[replace--] = nums2[j--];
                continue;
            }
            if (j < 0) break;

            if (nums1[i] < nums2[j]){
                nums1[replace--] = nums2[j--];
            }
            else {
                nums1[replace--] = nums1[i];
                nums1[i--] = 0;
            }
        }

    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    for(auto i: nums1)
        cout << i << " ";
    cout << endl;
    return 0;
}