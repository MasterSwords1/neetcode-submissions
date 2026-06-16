class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> dict;
        int biggestK = 1;
        vector<int> out;
        for (auto num: nums)
        {
            dict[num]++;
            if (biggestK < dict[num])
                biggestK = dict[num];
        }
        while (k--)
        {
            int b = biggestK;
            while (b)
            {
                map<int, int>::iterator it = std::find_if(
                    dict.begin(), dict.end(),
                    [&b](const auto& kv)
                    {return kv.second == b;});
                if (it != dict.end())
                {
                    out.push_back(it->first);
                    dict.erase(it);
                    break ;
                }
                --b;
            }
        }
        return out;
    }
};
