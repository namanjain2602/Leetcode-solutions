//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool isknown(vector<vector<int>>& M,int i,int j,int n)
    {
        if(M[i][j]==1)
        return true;
        return false;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        s.push(i);
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(isknown(M,a,b,n))
            s.push(b);
            else
            s.push(a);
        }
        int ans=s.top();
        bool rowcheck=false;
        int cc=0;
        for(int i=0;i<n;i++)
        {
            if(M[ans][i]==0)
            cc++;
        }
        if(cc==n)
        rowcheck=true;
        int rc=0;
        bool colcheck=false;
        for(int i=0;i<n;i++)
        {
            if(M[i][ans]==1)
            rc++;
        }
        if(rc==n-1)
        colcheck=true;
        if(rowcheck&&colcheck)
        return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends