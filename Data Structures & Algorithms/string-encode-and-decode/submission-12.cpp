class Solution {
public:

    string encode(vector<string>& strs)
    {
        string encoded = "";
        for (size_t i = 0; i < strs.size(); i++)
        {
            encoded += strs[i] + "\r";
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> decoded;
        stringstream ss(s);
        string word;
        while (getline(ss, word, '\r'))
            decoded.push_back(word);
        return decoded;
    }
};
