// 674. Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.
*/

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size(), i = 0, j, result = 0;
		while (i < len) {
			j = i;
			while (i + 1 < len and nums[i] < nums[i + 1]) {
				++i;
			}
			++i;
			if (result < i - j) {
				result = i - j;
			}
		}
		return result;
	}
};