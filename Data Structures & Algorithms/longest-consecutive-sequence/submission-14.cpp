class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        int count = 1;
        set<int> sorted;
        for (size_t i = 0; i < nums.size(); i++)
            sorted.insert(nums[i]);
        auto it = sorted.begin();
        int longest = 1;
        auto prev = it;
        ++it;
        while (it != sorted.end())
        {
            auto curr = it;
            if (*prev + 1 == *curr)
                count++;
            else
            {
                longest = std::max(longest, count);
                count = 1;
            }
            prev = it;
            ++it;
        }
        return std::max(longest, count);
    }
};
