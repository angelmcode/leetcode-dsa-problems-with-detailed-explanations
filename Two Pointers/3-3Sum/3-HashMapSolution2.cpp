// Time Complexity: O(n^2), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <algorithm> // needed to use sort function
#include <unordered_map> // needed to use hash map
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end()); // Time O(n log n)
      unordered_map<int, int> count; // Space O(n)

      for (int &n : nums) // Time O(n)
      {
         count[n]++;
      }
      
      vector<vector<int>> result; // Space O(m)
      for (int i = 0; i < nums.size(); i++) // Time O(n^2)
      {
         count[nums[i]]--;
         if(i>0 && nums[i] == nums[i-1]) continue;
         
         for (int j = i+1; j < nums.size(); j++)
         {
            count[nums[j]]--;
            if(j>i+1 && nums[j] == nums[j-1]) continue;

            int target = -(nums[i] + nums[j]);
            if (count[target]>0)
            {
               result.push_back({nums[i],nums[j],target});
            }
         }

         for (int j = i+1; j < nums.size(); j++)
         {
            count[nums[j]]++;
         }
      }
      return result;
    }
};

int main(){
   vector<int> nums = {0,0,0};

   Solution r;

   vector<vector<int>> result = r.threeSum(nums);

   for (auto &n : result)
   {
      for (int &i : n)
      {
         cout << i << ",";  
      }
      cout << '\n'; 
   }
}