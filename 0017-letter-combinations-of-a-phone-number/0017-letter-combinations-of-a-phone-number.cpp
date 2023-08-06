class Solution {
public:
    void lc(vector<string>&pad,vector<string>&ans,string digits,string &t,int i)
    {
        if(i==digits.size())
        {
            ans.push_back(t);
            return;
        }
        string temp=pad[digits[i]-'0'];
        for(int it=0;it<temp.size();it++)
        {
            t.push_back(temp[it]);
            lc(pad,ans,digits,t,i+1);
            t.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
    vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string t;
        lc(pad,ans,digits,t,0);
        return ans;
    }
};