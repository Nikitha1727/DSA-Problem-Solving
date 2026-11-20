
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int num : nums) {
            mp[num]++;
        }

        // Create buckets based on frequency
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto it : mp) {
            int num = it.first;
            int freq = it.second;

            buckets[freq].push_back(num);
        }

        // Collect k most frequent elements
        vector<int> result;

        for (int i = buckets.size() - 1; i >= 0; i--) {

            for (int num : buckets[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
