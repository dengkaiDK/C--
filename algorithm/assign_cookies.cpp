#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int maximum = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i, j;
        for (i =0, j=0; i<g.size() && j<s.size(); )
        {
            if (g[i] <= s[j])
            {
                maximum++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return maximum;
    }
};

int main(){
    Solution a;
    vector<int> g = {1,2,3};
    vector<int> s = {2,1};
    cout << a.findContentChildren(g, s) << endl;
    return 0;
}