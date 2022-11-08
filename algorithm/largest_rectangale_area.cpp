#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int area = 0;
        for(int i=0; i<heights.size(); i++)
        {
            while(!s.empty() && heights[s.top()] > heights[i]){
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                area = max(area, h * w);
            }
            s.push(i);
        }
        return area;
    }
};

int main(void){
    Solution a;
    vector<int> heights = {4, 2,5, 6};
    cout << a.largestRectangleArea(heights) << endl;
    return 0;
}