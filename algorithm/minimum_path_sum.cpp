#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    map<pair<int, int>, int> path;
    int m,n;
    vector<vector<int>> G;
    int minPathSum(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        G = grid;
        return minPath(0, 0);
    }

    int minPath(int i, int j){
        if (i == m - 1 && j == n - 1) {
            return G[i][j];
        }
        if (path.find(make_pair(i, j))!= path.end())
            return path[make_pair(i, j)];
        
        int sum = INT_MAX;
        if (i < m - 1){
            auto right_sum = G[i][j] + minPath(i+1, j);
            sum = min(sum , right_sum);
        }

        if (j < n - 1){
            auto down_sum = G[i][j] + minPath(i, j+1);
            sum = min(sum, down_sum);
        }

        path[make_pair(i, j)] = sum;
        return path[make_pair(i, j)];
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}