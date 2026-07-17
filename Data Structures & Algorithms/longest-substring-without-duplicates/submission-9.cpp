class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t count = 1;
        if (s.empty())
            return 0;
        size_t j = 0;
        size_t i = 1;
        std::unordered_map<char, int> alpha;
        while (i < s.size())
        {
            if (s[i] == s[j])
                j++;
            else if (alpha.find(s[i]) != alpha.end())
            {
                alpha.clear(); j = i; 
            }
            else
                alpha[s[i]] = 1;
            i++;
            // std::unordered_set<char> seq(s.begin() + j, s.begin() + i);
            // std::cout << seq.size() << endl;
            // std::cout << alpha.size() << endl;
            count = max(count, alpha.size() + 1);
        }
        return count;
    }
};
