#include<iostream>
#include<vector>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp); // 可以考虑按照右端点排序
        int number = 1;
        int i;
        int min_end = INT_MAX;

        for (i = 0; i < points.size(); i++)
        {
            if (points[i][0] <= min_end)
            {
                min_end = min(min_end, points[i][1]);
            }
            else{
                number++;
                min_end = points[i][1];
            }
        }
        return number;
    }
};


int main()
{
    Solution a;
    vector<vector<int>> points = {{0,9},{1,8},{7,8},{1,6},{9,16},{7,13},{7,10},{6,11},{6,9},{9,13}};
    cout << a.findMinArrowShots(points) << endl;
    return 0;
}