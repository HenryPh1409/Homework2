#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (levelOrder[i] != -1) {
            node->left = new TreeNode(levelOrder[i]);
            q.push(node->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != -1) {
            node->right = new TreeNode(levelOrder[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int diameterOfBinaryTree(TreeNode* root, int& diameter) {
    if (!root) return 0;
    int leftHeight = diameterOfBinaryTree(root->left, diameter);
    int rightHeight = diameterOfBinaryTree(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    vector<int> levelOrder = {1, 2, 3, 4, 5, -1, -1, -1, -1, 6, 7};
    TreeNode* root = buildTree(levelOrder);

    int diameter = 0;
    diameterOfBinaryTree(root, diameter);
    cout << diameter << endl;
    return 0;
}
