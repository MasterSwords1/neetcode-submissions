class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string> > out;
        for (size_t i = 0; i < strs.size(); i++)
        {
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            out[sorted].push_back(strs[i]);
        }
        vector<vector<string> > hh;
        std::transform(out.begin(), out.end(), std::back_inserter(hh), [](auto &kv){ return kv.second;});
        out.clear();
        return hh;
    }
};
