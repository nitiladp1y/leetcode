/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/


/* 164 ms*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        auto size = nums.size();
        for(auto i = 0;i < size; ++i)
        {
            for(auto j = i+1; j < size; ++j)
            {
                if(nums[i]+nums[j]==target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};
