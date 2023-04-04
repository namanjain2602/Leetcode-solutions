class Solution {
public:
    int partitionString(string s) {
        int partitions = 1;
        unordered_set<char> seen;
        for(auto letter: s) { 
            if(seen.find(letter) != seen.end()) {
                seen.clear();
                partitions++;
            }
            seen.insert(letter);
        }
        return partitions;
    }
};