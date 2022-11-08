#include<iostream>
#include<vector>
#include<limits.h>


using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid1, mid2;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        mid1 = len1/2 + 1;
        mid2 = len/2 - mid1 + 2;  // need to consider INT_MIN
        nums1.push_back(INT_MAX);
        nums1.insert(nums1.begin(), INT_MIN);
        nums2.push_back(INT_MAX);
        nums2.insert(nums2.begin(), INT_MIN);
        while (nums1[mid1 -1] > nums2[mid2] || nums2[mid2-1] > nums1[mid1]){
                if (nums1[mid1 -1] > nums2[mid2]){
                    mid1--;
                    mid2++;
                }
                else{
                    mid1++;
                    mid2--;
                }
            }
        
        if (len %2 == 0){
            // even
            return (min(nums1[mid1], nums2[mid2])+ max(nums1[mid1-1], nums2[mid2-1]))/2.0;
        }
        else{
            return double(min(nums1[mid1], nums2[mid2]));
        }
    }
};

int main(){
    vector<int> nums1 = {1, 3, 4, 5};
    vector<int> nums2 = {0, 2};
    Solution r;
    double result = r.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}