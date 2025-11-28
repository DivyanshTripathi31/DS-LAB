#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}//constructor
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);  
    }

private:
    int helper(TreeNode* node, bool isLeft) {
        if (node == nullptr) {
            return 0;
        }

        // Check if this node is a leaf (no children)
        if (node->left == nullptr && node->right == nullptr) {
            if (isLeft) {
                return node->val;     
            } else {
                return 0;            
            }
        }

        int leftSum  = helper(node->left,  true);   // going to left child
        int rightSum = helper(node->right, false);  // going to right child

        return leftSum + rightSum;
    }
};

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int ans = sol.sumOfLeftLeaves(root);

    cout << "Sum of left leaves = " << ans << endl;
    return 0;
}
