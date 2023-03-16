//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
       int curr=S ;
        string ans;
        curr--;  //reserving 1;
        for(int i=0;i<D;i++){
            ans=to_string(min(9,curr))+ans;
            curr-=min(9,curr);
            if(i==D-2){  //next calculating most significant digit so using reserve
                curr++;
            }
        }
        //smallest number calculated
        int i;
        for(i=D-1;i>0;i--){
            if(ans[i]!='0' && ans[i-1]<'9'){
                ans[i]--;
                ans[i-1]++;
                break;
            }
        }
        if(i==0)return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends