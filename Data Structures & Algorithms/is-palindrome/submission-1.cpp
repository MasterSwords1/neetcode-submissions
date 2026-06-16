class Solution {
public:
    bool isPalindrome(std::string s) {
	    std::string clean;
        for (int i = 0; i < s.size(); i++)
        {
            if (std::isalnum(s[i]))
                clean += std::tolower(s[i]);
        }
	    std::string reversed = clean;
	    std::reverse(reversed.begin(), reversed.end());
        return clean == reversed;
    }

};
