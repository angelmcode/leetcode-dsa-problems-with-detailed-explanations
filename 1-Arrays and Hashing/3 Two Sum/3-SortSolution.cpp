// time complexity o(n log n) space complexity o(n)

#include <iostream> // needed to use input output operations
#include <vector> // needed to use vector
#include <algorithm> // needed to use sort function
using namespace std; // needet to not write std:: everytime

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {

      // create a vector which sotrage a pair in every index
      vector<pair<int, int>> nums2;
      
      // fill in the vector with the values of vector nums and its respective indexs
      for (int i = 0; i < nums.size(); i++)
      {
         nums2.push_back({nums[i],i});
      }

      // we sort the vector pair
      sort(nums2.begin(),nums2.end());
      
      // create two pointer in the beginig in the end of nums, but use them in nums2 which is the pair vector
      int i=0;
      int j = nums.size() - 1;

      while (i<j)
      {
         // sum the 2 pointers
         int sum = nums2[i].first + nums2[j].first;
         //if the sum is equal to the target, we found the answer
         if (sum == target)
         {
            // so return the index storage in the pair vector for i and for j
            return {nums2[i].second,nums2[j].second};

         } else if (sum < target) //instead if sum is not equal to traget and sum is less than traget
         {
            //increase i by 1
            i++;
         } else // if is not the case
         {
            // subtract 1 in j
            j--;
         } 
         
      } 

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