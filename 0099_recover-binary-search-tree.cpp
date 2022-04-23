#include <bits/stdc++.h>
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

class Solution
{
    void swapNodes(TreeNode* node1, TreeNode* node2)
    {
        auto temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }

    void recoverTree(TreeNode* root, TreeNode* max, TreeNode* min)
    {
        if (root != nullptr)
        {
            if (root->val <= min->val)
            {
                swapNodes(root, min);
            }
            else if (root->val > max->val)
            {
                swapNodes(root, max);
            }
            recoverTree(root->left, root, min);
            recoverTree(root->right, max, root);
        }
    }

public:
    void recoverTree(TreeNode* root)
    {
        recoverTree(root, new TreeNode(INT_MAX), new TreeNode(INT_MIN));
    }
};
