#include<iostream>
#include<vector>
#include<map>

using namespace std;

// m = obstacleGrid.size()
// n = obstacleGrid[0].size()
// 1 <= m, n <= 100
// obstacleGrid[i][j] is 0 or 1.
class Solution {
public:
    int m, n;
    map<pair<int, int>, int> path;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->m = obstacleGrid.size();
        this->n = obstacleGrid[0].size();
        return uniquePath(0, 0, &obstacleGrid);
    }

    int uniquePath(int i, int j, vector<vector<int>>* grid){
        if ((*grid)[i][j]) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (path.find(make_pair(i, j)) != path.end())
            return path[make_pair(i, j)];
        
        int sum = 0;
        if (i < m - 1)
            sum += uniquePath(i+1, j, grid);
        
        if (j < n - 1)
            sum += uniquePath(i, j+1, grid);
        
        path[make_pair(i, j)] = sum;
        return path[make_pair(i, j)];
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << s.uniquePathsWithObstacles(grid) << endl;
    return 0;
}