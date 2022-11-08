#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        map<int, int> row{};
        map<int, int>column{};
        int even = 0;
        int odd = 0;
        // time complexity: O(m + n + indices.size())
        for(auto ind : indices)
        {
            row[ind[0]] += 1;
            column[ind[1]] += 1;
        }
        for (int i =0; i<m ; i++)
        {
            int item = row[i];
            if (item % 2 == 0)
                even += 1;
            else
                odd += 1;
        }
        int result = 0;
        for (int i=0; i < n; i++)
        {
            int item = column[i];
            if (item % 2 == 0)
                result += odd;
            else
                result += even;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> indices = {{0,1},{1,1}};
    cout << s.oddCells(2, 3, indices) << endl;
    return 0;
}