#include<iostream>
#include<map>
#include<vector>
#include<limits>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> prime{};
    map<char, int> hash_value;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans{};
        prime_generator(101); // generate 26 prime numbers
        char a = 'a';
        int i = 0;
        //cout<<"prime size : (" << prime.size() <<")"<< endl;
        while(a <= 'z'){
            hash_value[a++] = prime[i++];
        }

        map<long long, vector<string>> anagram;
        for(auto s: strs){
            long long index = 1;
            for (auto c: s){
                if(index > LLONG_MAX / 100)
                    index /= 100;
                index *= hash_value[c];
                
            }
            if (anagram.find(index) == anagram.end())
                anagram[index] = vector<string> {s};
            else
                anagram[index].push_back(s);
        }

        for(auto it = anagram.begin(); it!=anagram.end(); it++)
            ans.push_back(it->second);
        return ans;

    }
    // generate all the prime number below n + 1
    void prime_generator(const int n){
        int p=2;
        bool value[n+1];
        fill_n(value, n+1, false);
        while(p*p < n){
            for(int i = p*p; i < n+1; i += p)
                value[i] = true;
            while (value[++p]) ;
        }
        for(int i=2; i< n+1; i++)
        {
            if(!value[i])
                prime.push_back(i);
        }
    }
};


int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for(auto v: ans){
        for(auto s: v)
            cout<<s<<" ";
        cout<<endl;
    }
    return 0;
}