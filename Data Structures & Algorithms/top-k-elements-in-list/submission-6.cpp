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
        using int_pair = std::pair<int, int>;
        vector<int_pair> pairs;
        for (map<int, int>::iterator it = dict.begin(); it != dict.end(); ++it)
        {
            pairs.push_back(std::make_pair(it->first, it->second));
        }
        std::sort(pairs.begin(), pairs.end(),
            [](const auto& left, const auto& right){
                return left.second > right.second;
            });
        int i = 0;
        while (k--)
        {
            out.push_back(pairs[i++].first);
        }
        // while (k--)
        // {
        //     int b = biggestK;
        //     while (b)
        //     {
        //         map<int, int>::iterator it = std::find_if(
        //             dict.begin(), dict.end(),
        //             [&b](const auto& kv)
        //             {return kv.second == b;});
        //         if (it != dict.end())
        //         {
        //             out.push_back(it->first);
        //             dict.erase(it);
        //             break ;
        //         }
        //         --b;
        //     }
        // }
        return out;
    }
};
