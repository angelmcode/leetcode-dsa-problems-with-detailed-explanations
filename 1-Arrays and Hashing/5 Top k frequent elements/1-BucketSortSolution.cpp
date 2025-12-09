// time complexity: O(n) space compexity: O(n)

#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <unordered_map> // neede to use the hash map
#include <algorithm>
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; // 1:3, 2:3, 3:2 Space: O(n)

        for (int &n : nums)
        {
         count[n]++; // Time: O(n)
        }

        vector<vector<int>> buckets(nums.size()+1); // 0:0 - 1:0 - 2:3 - 3:1,2 Space: O(n)

        for (auto &pair : count)
        {
         buckets[pair.second].push_back(pair.first); // Time: O(n)
        }
        
        vector<int> result; // Space: O(k)

        for (int i = buckets.size()-1; i > 0; i--) // Time: O(n)
        {
         auto bucket = buckets[i];
         for (int &b : bucket)
         {
            result.push_back(b);
            if (result.size() == k)
            {
            return result;
            }
         }
        }
        return result;
    };
};

int main() {

   vector<int> nums = {1,1,1,2,2,2,3,3};
   int k = 2;

   vector<int> result = Solution::topKFrequent(nums, k);
   
   for (int r : result)
   {
      cout << r << '\n';
   }
   return 0;
}