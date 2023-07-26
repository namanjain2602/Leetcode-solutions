class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;
        string s;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                if(words[i][j]==separator && s!="")
                {
                    ans.push_back(s);
                    s="";
                }
                if(words[i][j]!=separator)
                    s+=words[i][j];
            }
            if(s!=""){
             ans.push_back(s);
                    s="";
            }
            
        }
        return ans;
    }
};