#include<iostream>
#include<stack>
#include<set>


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
    bool isValidBST(TreeNode* root) {
        bool have_prev = false;
        int prev;
        stack<TreeNode*> node;
        set<TreeNode*> visit;
        if (root == nullptr) return true;

        node.push(root);
        visit.insert(root);
        while(!node.empty()){
            TreeNode* tmp = node.top();
            while(tmp->left && visit.find(tmp->left) == visit.end()){
                tmp = tmp->left;
                node.push(tmp);
            }

            if (!have_prev) {
                prev = tmp->val;
                have_prev = true;
            }
            else{
                if (tmp->val <= prev) return false;
                else prev = tmp->val;
            }

            node.pop();
            visit.insert(tmp);

            if(tmp->right){
                node.push(tmp->right);
            }

        }
        return true;
    }
};


int main(){
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << s.isValidBST(root) << endl;
    return 0;
}