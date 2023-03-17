class Trie {
    Trie* word[26]={};
    bool isterminal=false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie * node=this;
        for(char ch:word)
        {
            ch=ch-'a';
            if(!node->word[ch])node->word[ch]=new Trie();
            node=node->word[ch];
        }
        node->isterminal=true;
    }
    
    bool search(string word) {
        Trie * node=this;
        for(char ch:word)
        {
            ch-='a';
            if(!node->word[ch])return false;
            node=node->word[ch];
        }
        return node->isterminal;
    }
    
    bool startsWith(string prefix) {
         Trie * node=this;
        for(char ch:prefix)
        {
            ch-='a';
            if(!node->word[ch])return false;
            node=node->word[ch];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */