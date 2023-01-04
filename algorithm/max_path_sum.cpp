#include<iostream>
#include<limits>

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
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        gain_from_subtree(root);
        return maxsum;
    }

private:
    int maxsum;

    int gain_from_subtree(TreeNode* root){
        if (root == nullptr) return 0;
        int left_gain = max(gain_from_subtree(root->left), 0);
        int right_gain = max(gain_from_subtree(root->right), 0);
        maxsum = max(maxsum, left_gain + right_gain + root->val);
        return max(left_gain, right_gain) + root->val;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.maxPathSum(root) << endl;
    return 0;
}