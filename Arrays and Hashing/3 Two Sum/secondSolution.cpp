#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
      
      unordered_map<int, int> indices;       // key -> value
      
      for (int i = 0; i < nums.size(); i++)
      {
         indices[nums[i]] = i;
      }

      for (int i = 0; i < nums.size(); i++)
      {
         int diff = target - nums[i];
         if (indices.count(diff) && indices[diff] != i)
         {
            return {i, indices[diff]};
         }
         
      }
      

      return {};
    }   
};

int main() {

   int target = 6;
   vector<int> nums {3,3};

   vector<int> result = Solution::twoSum(nums,target);

   if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}