/**
 * Definition for a binary tree node.*/
// struct TreeNode
// {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right)
//         : val(x), left(left), right(right)
//     {}
// };

#include <vector>

class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> v;
        traverse(v, root);
        return v;
    }

    void traverse(std::vector<int>& vect, TreeNode* root)
    {
        if (root != nullptr)
        {
            if (root->left != nullptr) traverse(vect, root->left);
            vect.push_back(root->val);
            if (root->right != nullptr) traverse(vect, root->right);
        }
    }
};
