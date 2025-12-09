// Time Complexity: O(n log n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      // Space O(1)
      for (int i = 0; i < numbers.size(); i++) // Time O(n log n)
      {
         int diff = target - numbers[i];
         int bS = binarySearch(numbers, diff, i);
         
         if ( bS != -1 && bS != i)
         {
            return {min(i+1, bS+1), max(i+1, bS+1)};
         }
         

      }
      return {};
    }

    int binarySearch(vector<int>& numbers, int& diff, int& i) {
      int start = i+1;
      int end = numbers.size()-1;
      
      while (start <= end)
      {
         int middle = start + (end - start) / 2;

         if (numbers[middle] == diff) return middle;
         if (numbers[middle] < diff)
         {
            start = middle+1;
         } else if (numbers[middle] > diff)
         {
            end = middle-1;
         }
      }
      return -1;
    }
};

int main(){
   vector<int> numbers = {2,3,4};

   Solution r;

   vector<int> result = r.twoSum(numbers, 6);

   for (int &n : result)
   {
      cout << n << '\n';  
   }
}