//time complexity o(n); space complexity o(n);

#include <iostream> // needed to use input output operations
#include <vector> // needed to use the dynamic array
#include <unordered_map> // needed to use the hashmap
using namespace std; // needed to not write std:: everytime

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
      
      // make a hashmap call indices
      unordered_map<int, int> indices;       // key -> value
      

      for (int i = 0; i < nums.size(); i++)
      {
         // determine the diference for get the target value by every element 
         int diff = target - nums[i]; // 3, 5 ,3

         // if diff is found in indices hashmap
         if (indices.count(diff))
         {
            // return the index for the value of diff, and the current index in the for loop which track nums vector
            return {indices[diff], i};
         }

         // but if diff is not found in indices hashmap, insert the value of nums[i] like key, and his index like value
         indices.insert({nums[i],i});
         
      }
      // beacuse indices hashmap is empty in the begining and fill it as the for loop dont found diff, only we needed 1 for loop 

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