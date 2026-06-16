class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers)
    {
        vector<vector<int> > res;
        vector<int> n;
        vector<int> nums = numbers;
        std::sort(nums.begin(), nums.end());

        int i = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int k = nums.size() - 1;
            int j = i + 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                {
                    n = {nums[i], nums[j], nums[k]};
                    if (std::find(res.begin(), res.end(), n) == res.end())
                        res.push_back(n);
                    j++;
                }
            }
        }
        // vec.erase( unique( vec.begin(), .end() ), res.end() );
        return res;
        
    }
};
