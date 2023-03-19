class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int index, TrieNode* curr) {
        if (index == word.length()) {
            return curr->isEndOfWord;
        }

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr && searchHelper(word, index + 1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if (curr->children[c - 'a'] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, curr->children[c - 'a']);
        }
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */