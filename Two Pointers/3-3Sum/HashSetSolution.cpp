// Time Complexity: O(n^3), Space Complexity: O(m)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates at i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            unordered_map<int, int> seen;  // value -> index

            for (int j = i + 1; j < nums.size(); j++) {
                int target = -nums[i] - nums[j];

                // If we have seen the target in this loop
                if (seen.count(target)) {
                    result.push_back({nums[i], target, nums[j]});

                    // Skip duplicates at j
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                        j++;
                }

                // Add current number AFTER checking
                seen[nums[j]] = j;
            }
        }

        return result;
    }
};


int main(){
   vector<int> numbers = {-1,0,1,2,-1,-4};

   Solution r;

   vector<vector<int>> result = r.threeSum(numbers);

   for (auto &n : result)
   {
      for (int &i : n)
      {
         cout << i << ",";  
      }
      cout << '\n'; 
   }
}