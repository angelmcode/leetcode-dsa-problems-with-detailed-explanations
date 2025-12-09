//time complexity o(n); space complexity o(n);

#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <unordered_map> // needed to use the hashmap
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
      
      // make a hashmap call indices
      unordered_map<int, int> indices; // key->value 1-1,3-2,6-4
      
      // fill in indices with nums[i] like key, and its index like value
      for (int i = 0; i < nums.size(); i++)
      {
         indices[nums[i]] = i;
      }

      for (int i = 0; i < nums.size(); i++)
      {
         // determine the diference to get target for every element in the vector
         int diff = target - nums[i]; //3,5,3
         
         // look for diff in indices and make sure that it index dont be the same of the loop tracking nums vector, remember that the indices hashmap was fullfill previously
         if (indices.count(diff) && indices[diff] != i)
         {
            // if the condition is true return the index of the for loop tracking nums vector, and the index of diff in indices hashmap
            return {i, indices[diff]};
         }
         
      }
      
      // if dont exist to values that sum the target return a empty dynamic array
      return {};
    }   
};

int main() {

   int target = 6;
   vector<int> nums {3,1,3};

   vector<int> result = Solution::twoSum(nums,target);

   if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}