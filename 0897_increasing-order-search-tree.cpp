// #include <iostream>
// #include <vector>

/**
 * Definition for a binary tree node. */
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

class Solution
{
    void inOrderTraversal(TreeNode* root, std::vector<int>& values)
    {
        if (root != nullptr)
        {
            inOrderTraversal(root->left, values);
            values.push_back(root->val);
            inOrderTraversal(root->right, values);
        }
    }

public:
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode* newTree = new TreeNode;
        std::vector<int> values;
        inOrderTraversal(root, values);
        auto head = newTree;
        for (auto num : values)
        {
            head->right = new TreeNode(num);
            head = head->right;
        }
        newTree = newTree->right;
        return newTree;
    }
};
