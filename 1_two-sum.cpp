/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/


/* 112 ms*/
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
                    return ret;
                }
            }
        }
    }
};


/* 先排序怎么样 快排  52ms*/
class Solution {
public:
	void quickSort(vector<int>& nums, int left, int right)
	{
		int i = left;
		int j = right;
		int temp = nums[left];
		if (left >= right) return;
		while (i != j)
		{
			while (i<j && nums[j] >= temp)	j--;
			if (j>i) nums[i] = nums[j];
			while (i<j&&nums[i] <= temp) i++;
			if (i<j) nums[j] = nums[i];
		}
		nums[i] = temp;
		quickSort(nums, left, i - 1);
		quickSort(nums, i + 1, right);
	}
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		multimap<int,int> save;
		auto size = nums.size();
		for (auto i = 0; i < size; ++i)
		{
			save.insert(pair<int, int>(nums[i],i));
		}
		quickSort(nums, 0, size - 1);

		int i = 0; 
		int j = size - 1;
		while(i < j)
		{
			int tmp = nums[i] + nums[j];
			if (tmp == target)
			{
				if (nums[i] == nums[j])
				{
					auto it = save.find(nums[i]);
					ret.push_back(it->second);
					it++;
					ret.push_back(it->second);
				}
				else
				{
					ret.push_back(save.find(nums[i])->second);
					ret.push_back(save.find(nums[j])->second);
				}
				return ret;
			}
			else if (tmp > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}

	}
};


/* 两遍哈希表 */
/* 一遍哈希表 */
/* 8 ms */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		map<int,int> save;
		auto size = nums.size();
		for (auto i = 0; i < size; ++i)
		{
			auto it = save.find(target - nums[i]);
			if (it != save.end())
			{
				ret.push_back(it->second);
				ret.push_back(i);
				return ret;
			}	
			save.insert(pair<int, int>(nums[i],i));
		}
		return ret;
    }
};