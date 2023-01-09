#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //Complexity: O(n)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank, traversal = 0;
        int L = cost.size();
        int k, i;
        
        for(i = 0; traversal < L; ){
            if(gas[i] - cost[i] >= 0){
                tank = gas[i] - cost[i];
                k = (i + 1) % L;
                while(tank >= 0 && k != i){
                    tank += gas[k] - cost[k];
                    k = (k + 1) % L;
                }

                if(tank < 0){
                    if(k > i) traversal += k - i;
                    else traversal += L - (i - k);
                    i = k;
                }
                else return i;
            }
            else {
                i++;
                traversal++;
            }
        }

        return -1;
    }
};


int main(){
    Solution s;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}