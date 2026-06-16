class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string> > out;
        for (size_t i = 0; i < strs.size(); i++)
        {
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            // if (!out[sorted].empty())
            // {
            //     // vector<string> word;
            //     // word.push_back(strs[i]);
            //     out[sorted].push_back(strs[i]);
            //     continue ;
            // }
            out[sorted].push_back(strs[i]);
        }
        vector<vector<string> > hh;
        for (map<string, vector<string> >::iterator it = out.begin(); it != out.end(); ++it)
        {
            hh.push_back(it->second);
        }
        return hh;
    }
};
