class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t count = 1;
        if (s.empty())
            return 0;
        size_t j = 0;
        size_t i = 1;
        std::unordered_set<char> alpha;
        while (i < s.size())
        {
            if (s[i] == s[j])
                j++;
            else if (alpha.find(s[i]) != alpha.end())
            {
                alpha.clear(); j = i; 
            }
            else
                alpha.insert(s[i]);
            i++;
            std::unordered_set<char> seq(s.begin() + j, s.begin() + i);
            count = max(count, seq.size());
        }
        return count;
    }
};
