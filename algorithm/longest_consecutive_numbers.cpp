#include<iostream>
#include<vector>
#include<map>


using namespace std;

class Solution {
public:
    map<int, int> parent;
    map<int, int> set_rank{};
    map<int, int> counter{};
    int longestConsecutive(vector<int>& nums) {
        for (auto i : nums){
            build(i);
        }
        int max = 0;

        for(auto i: parent){
            if (parent.find(i.first + 1) != parent.end()){
                merge(i.first, i.first + 1);
            }
        }

        for(auto i: parent){
            counter[find(i.first)]++;
        }

        for(auto i: counter){
            if (i.second > max){
                max = i.second;
            }
        }

        return max;
    }

    int find(int x){
        if(x == parent[x]) return x;
        // path compression
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void build(int x){
        if(parent.find(x) == parent.end()){
            parent[x] = x;
            set_rank[x] = 1;
        }
    }

    void merge(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        //union by rank and avoid repeated merge
        if(rootx != rooty){
            if(set_rank[rootx] < set_rank[rooty]){
                parent[rootx] = rooty;}
            else if (set_rank[rootx] > set_rank[rooty]){
                parent[rooty] = rootx;}
            else{
                parent[rootx] = rooty;
                set_rank[rooty] += 1;
            }
        }
    }

    

};


int main(void){
    Solution s;
    vector<int> nums{0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}