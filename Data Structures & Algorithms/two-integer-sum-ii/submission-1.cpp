class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        size_t start = 0;
        size_t end = nums.size() - 1;
        vector<int> pos;
        
        while (start <= end)
        {
            if (nums[start] + nums[end] == target)
            {
                pos.push_back(start + 1);
                pos.push_back(end + 1);
                break;
            }
            if (nums[start] + nums[end] > target)
                end--;
            else
                start++;
        }
        return pos;
    }
};
