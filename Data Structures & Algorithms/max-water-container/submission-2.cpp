class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int max = 0;
        int right = heights.size() - 1;
        int left = 0;
        while (left < right)
        {
            int area = std::min(heights[left], heights[right]) * (right - left);
            max = std::max(max, area);
            if (heights[left] >= heights[right])
                right--;
            else
                left++;
        }
        return max;
    }
};
