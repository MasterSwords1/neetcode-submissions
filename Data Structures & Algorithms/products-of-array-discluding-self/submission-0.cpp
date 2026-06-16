class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res;
        int prefix = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            res.push_back(prefix);
            prefix *= nums[i];
        }
        int suffix = 1;
        for (size_t i = nums.size(); i > 0; i--)
        {
            res[i - 1] *= suffix;;
            suffix *= nums[i - 1];
        }
        return res;
    }
};
