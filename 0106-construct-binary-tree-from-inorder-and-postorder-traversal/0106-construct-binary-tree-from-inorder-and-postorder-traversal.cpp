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
     void createmap(vector<int>inorder,map<int,int>&nodetoindex,int n)
    {
        for(int i=0;i<n;i++)
        nodetoindex[inorder[i]]=i;
    }
    TreeNode* solve(vector<int>inorder,vector<int>postorder,int &index,int inorderstart,int inorderend,int n,map<int,int> &nodetoindex)
    {
        if(index<0||inorderstart>inorderend)
        return NULL;
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);
        int pos=nodetoindex[element];
        root->right=solve(inorder,postorder,index,pos+1,inorderend,n,nodetoindex);
        root->left=solve(inorder,postorder,index,inorderstart,pos-1,n,nodetoindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=postorder.size();
         int postorderindex=n-1;
        map<int,int>nodetoindex;
        createmap(inorder,nodetoindex,n);
        TreeNode* root=solve(inorder,postorder,postorderindex,0,n-1,n,nodetoindex);
        return root;
    }
};