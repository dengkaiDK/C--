#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    map<vector<int>, vector<int>> set;
    map<vector<int>, int> size;
    int removeStones(vector<vector<int>>& stones) {
        int num = 0;
        for (auto loc: stones){
            build(loc);
        }
        map<int, vector<int>> row;
        map<int, vector<int>> column;
        for (auto loc: stones){
            if (row.find(loc[0])!=row.end() || column.find(loc[1])!=column.end()){
                if(row.find(loc[0])!=row.end() && column.find(loc[1]) == column.end()) 
                {
                    add(row[loc[0]], loc);
                    column[loc[1]] = loc;
                }
                else if (column.find(loc[1])!=column.end() && row.find(loc[0]) == row.end())
                {
                    add(column[loc[1]], loc);
                    row[loc[0]] = loc;
                }
                else{
                    add(row[loc[0]], loc);
                    add(column[loc[1]], loc);
                }
                   
            }else{
                row[loc[0]] = loc;
                column[loc[1]] = loc;
            }
        }
        map<vector<int>, bool> stand;
        for(auto loc: stones)
        {
            if (stand.find(find(loc)) == stand.end())
                stand.insert(make_pair(find(loc), true));
        }
        for(auto loc: stand){
            num += size[loc.first] - 1;
        }
        return num;
    }
    
    vector<int> find(vector<int> a){
        if (set[a] == a) return a;
        set[a] = find(set[a]);
        return set[a];
    }
    
    void build(vector<int> a){
        set[a] = a;
        size[a] = 1;
    }
    
    void add(vector<int> a, vector<int> b){
        if (find(a) == find(b)) return;
        else{
            if(size[find(a)] > size[find(b)]){
                size[find(a)] += size[find(b)];
                set[find(b)] = set[find(a)];
            }
            else{
                size[find(b)] += size[find(a)];
                set[find(a)] = set[find(b)];
            }
        }
    }
};

int main(void){
    Solution a;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << a.removeStones(stones) << endl;
    return 0;
}