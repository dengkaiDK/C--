#include<iostream>
#include<stack>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        //DFS search 
        stack<TreeNode*> s;
        map<TreeNode*, bool> m;
        int sum = 0;
        int num = 0;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            if(!p->left && !p->right)
            {
                num = num * 10 + p->val;
                sum += num;
                s.pop();
                num /= 10;  
                m[p] = true;
            }
            else if (p->left && !m[p->left])
            {
                num = num * 10 + p->val;
                s.push(p->left);
            }
            else if (p->right && !m[p->right]){
                if(p->left && m[p->left])
                {
                    num /= 10;
                }
                num = num * 10 + p->val;
                s.push(p->right);
            }
            else{
                s.pop();
                num /= 10;
                m[p] = true;
            }
        }
        return sum;
    }
};

int main()
{
    Solution a;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << a.sumNumbers(root) << endl;
    return 0;
}