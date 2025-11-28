#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// --------- Solution class ---------
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);   // values must be from 1 to n
    }

private:
    // Build all unique BSTs using values in [start, end]
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;

        // Empty subtree: very important base case
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        // Try each value as root
        for (int rootVal = start; rootVal <= end; ++rootVal) {
            // All possible left subtrees using values < rootVal
            vector<TreeNode*> leftTrees  = buildTrees(start, rootVal - 1);
            // All possible right subtrees using values > rootVal
            vector<TreeNode*> rightTrees = buildTrees(rootVal + 1, end);

            // Combine each left choice with each right choice
            for (TreeNode* leftRoot : leftTrees) {
                for (TreeNode* rightRoot : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
};

// --------- Helper to print a tree (preorder) ---------
void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}


int main() {
    int n = 3;
    Solution sol;
    vector<TreeNode*> trees = sol.generateTrees(n);

    cout << "Number of unique BSTs for n = " << n << " is: "
         << trees.size() << "\n\n";

    cout << "Trees in preorder (value and 'null' for empty child):\n";
    int idx = 1;
    for (TreeNode* root : trees) {
        cout << "Tree " << idx++ << ": ";
        printPreorder(root);
        cout << "\n";
    }

    return 0;
}
