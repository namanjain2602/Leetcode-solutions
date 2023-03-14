/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solver(string s,TreeNode* root,int &answr)
    {
        if(!root)return answr;
        s+=(root->val+'0');
        if(root->left==NULL&&root->right==NULL)
        {
            answr+=stoi(s);
            return answr;
        }
        if(root->left)
        solver(s,root->left,answr);
        if(root->right)
        solver(s,root->right,answr);
        return answr;
    }
    int sumNumbers(TreeNode* root) {
        string s;
        int answr=0;
         return solver(s,root,answr);
        //return answr;
    }
};