//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    Node* fun(Node *root , int t)
    {
        if(root==NULL)return NULL;

        int val = root->data;
        
        if(val==t)return root;
        
        if(t> val)fun(root->right, t);
        else
            fun(root->left, t);
        
    }
    
    int fun2(Node* root, int t)
    {
        if(root==NULL)return 0;
        
        int val = root->data;
        
        if(val==t)return t;
        
        if(t> val) return val +   fun2(root->right, t);
        else
           return  val + fun2(root->left, t);
        
    }
    
    int fun3(Node* root, int store)
    {
        if(root->left==NULL and root->right==NULL) return store- root->data;
        
        
        int a = INT_MIN;
        int b= INT_MIN;
        
        if(root->left!=NULL) a=  fun3(root->left,  store- root->data  );
        
        if(root->right!=NULL) b= fun3(root->right, store- root->data);
        
        return max(a, b);
    }
    
    int maxDifferenceBST(Node *root,int target){
        // Code here
        
        //return the node of target
        Node* val = fun(root, target);
        
        if(val==NULL)return -1;
        
        //returns the sum till target
        int store= fun2(root, target);
        
        // returns the maxdiff possible        
        return fun3(val, store);
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends