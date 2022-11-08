#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    map<pair<int, int>, pair<int, int>> parent;
    map<pair<int, int>, bool> surrounded;
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // initialize parent and surrounded
        for(int i=0; i<m ;i++)
        {
            for(int j=0; j<n; j++){
                if (i ==0 || j ==0 || i==m-1 || j== n-1){
                    build(make_pair(i, j), false);
                }
                else{
                    build(make_pair(i, j), true);
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++){
                if (board[i][j] == 'O'){
                    if (i>0 && board[i-1][j] == 'O'){
                        merge(make_pair(i, j), make_pair(i-1, j));
                    }
                    if (i<m-1 && board[i+1][j] == 'O'){
                        merge(make_pair(i, j), make_pair(i+1, j));
                    }
                    if (j>0 && board[i][j-1] == 'O'){
                        merge(make_pair(i, j), make_pair(i, j-1));
                    }
                    if (j<n-1 && board[i][j+1] == 'O'){
                        merge(make_pair(i, j), make_pair(i, j+1));
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++){
                if (board[i][j] == 'O'){
                    if (surrounded[find(make_pair(i, j))]){
                        board[i][j] = 'X';
                    }
                }
            }  
        }
    }

    pair<int, int> find(pair<int, int> x, bool flag=true){
        if(x == parent[x]) 
        {
            if(!flag){
                surrounded[x] = false;
            }
            return x;
        }
        // path compression
        parent[x]= find(parent[x], flag);
        return parent[x];
    }

    void build(pair<int, int> x, bool mark=false){
        if(parent.find(x) == parent.end()){
            parent[x] = x;
            surrounded[x] = mark;
        }
    }

    void merge(pair<int, int> x, pair<int, int> y){
        pair<int, int> rootx = find(x, surrounded[x]);
        pair<int, int> rooty = find(y, surrounded[y]);
        //union by rank and avoid repeated merge
        if(rootx != rooty){
            parent[rooty] = rootx;
            if (!surrounded[rooty]){
                surrounded[rootx] = false;
            }
        }
    }
};

int main(void){
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    Solution s;
    s.solve(board);
    for(auto i: board){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}