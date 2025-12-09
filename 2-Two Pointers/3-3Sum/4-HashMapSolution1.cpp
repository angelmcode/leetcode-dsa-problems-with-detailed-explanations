// Time Complexity: O(n^2 log n), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <algorithm> // needed to use sort function
#include <unordered_map> // needed to use hash map
#include <set> // needed to use set
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int countZero = 0;
      unordered_map<int,int> count; // Space O(n)

      for (int i = 0; i < nums.size(); i++) // Time O(n)
      {
         count.insert({nums[i], i});
         if(nums[i] != 0) countZero++;
      }

      if (countZero == 0) return {{0,0,0}};

      set<vector<int>> result;

      for (int i = 0; i < nums.size(); i++) // Time O(n^2 log n)
      {
         for (int j = i+1; j < nums.size(); j++)
         {

            int target = 0 - (nums[i] + nums[j]);

            if (count.count(target) && count[target] != i && count[target] != j)
            {
               vector<int> sum3 = {target, nums[i], nums[j]};
               sort(sum3.begin(), sum3.end());
               result.insert(sum3);
            }
         }
      }
      return vector<vector<int>>(result.begin(), result.end());
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