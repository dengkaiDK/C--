//Solution for Leetcode Problem 42: Trapping Rain Water
//Language: cpp

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> b(height.size(), 0);
        vector<int> c(height.size(), 0);
        int i=0;
        int j=height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        
        // Find the left_max for every element
        for(i=0; i<height.size(); i++){
            if (height[i] > left_max){
                left_max = height[i];
                b[i] = left_max;
            }
            else{
                b[i] = left_max;
            }
        }
        // Find the right_max for every element
        for(j=height.size() - 1; j>=0; j--){
            if (height[j] > right_max){
                right_max = height[j];
                c[j] = right_max;
            }
            else{
                c[j] = right_max;
            }
        }
        // Find the water trapped at every element
        for(i=0; i<height.size(); i++){
            water += min(b[i], c[i]) - height[i];
        }
        
        return water;
    }
};


int main(){
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}