class Solution {
public:
    int trap(vector<int>& height)
    {
        vector<int> prefix(height.size()); 
        vector<int> suffix(height.size());

        if (height.size() < 3)
            return 0;
        int max = height[0];
        prefix[0] = max;
        for (size_t i = 1; i < height.size(); i++)
        {
            prefix[i] = std::max(prefix[i - 1], height[i]);
        }
        max = height[height.size() - 1];
        suffix[height.size() - 1] = max;
        for (long i = height.size() - 2; i >= 0; i--)
        {
            suffix[i] = std::max(suffix[i + 1], height[i]);
        }
        max = 0;
        for (size_t i = 0; i < height.size(); i++)
        {
            max += std::min(prefix[i], suffix[i]) - height[i];
        }
        return max;
    }
};
