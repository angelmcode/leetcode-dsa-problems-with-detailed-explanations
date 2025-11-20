// Time Complexity: O(n), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <unordered_map>
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      unordered_map<int, int> mapNumbers; // Space: O(n)

      for (int i = 0; i < numbers.size(); i++) // Time: O(n)
      {
         mapNumbers.insert({numbers[i],i});
      }

      for (int i = 0; i < numbers.size(); i++) // Time: O(n)
      {
         int diff = target - numbers[i];
         if (mapNumbers.count(diff) && mapNumbers[diff] != i)
         {
            return {min(i+1, mapNumbers[diff]+1), max(i+1, mapNumbers[diff]+1)};
         }
      }
      return {};
    }
};

int main(){
   vector<int> numbers = {2,2,3,4};

   Solution r;

   vector<int> result = r.twoSum(numbers, 4);

   for (int &n : result)
   {
      cout << n << '\n';  
   }
}