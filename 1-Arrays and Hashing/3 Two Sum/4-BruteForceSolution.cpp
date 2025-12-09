// time complexity: O(n²); space complecity: 0(1);

#include <iostream> // needed to use input and output operations
#include <vector> //needed to use vertor
using namespace std; // needet to not write std:: everytime

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {

      vector<int> indexes(2,0);

      // we use 2 nested loops for make the comparison, and because of this get 0(n²) time complexity
      for (int i = 0; i < nums.size(); i++)
      {
         // j=i+1 ensures that the same index is not compare with itself
         for (int j = i +1; j < nums.size(); j++)
         {
            if (nums[i] + nums[j] == target)
            {
               indexes[0] = i;
               indexes[1] = j;
               return indexes;
            }
            
         }
         
      }
      
    }
};