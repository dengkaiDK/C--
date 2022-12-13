#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:

    static bool cmp(vector<int>& i, vector<int>& j){
        return i[0] < j[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans{};
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1], start = intervals[0][0];
        for(auto range: intervals){
            if (range[0] > end){
                ans.push_back({start, end});
                start = range[0];
                end = range[1];
            }
            else{
                end = max(end, range[1]);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};


int main(){
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = s.merge(intervals);
    for(auto range: ans){
        cout << range[0] << " " << range[1] << endl;
    }
    return 0;
}