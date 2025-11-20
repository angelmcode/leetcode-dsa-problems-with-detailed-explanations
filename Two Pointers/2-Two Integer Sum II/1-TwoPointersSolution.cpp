// Time Complexity: O(n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0; // Space: O(1)
        int end = numbers.size()-1; // Space O(1)

        while (start < end) // Time: O(n)
        {
         if (numbers[start] + numbers[end] == target) return {start+1, end+1};
         if (numbers[start] + numbers[end] > target) end--;
         if (numbers[start] + numbers[end] < target) start++;
        }
        return {};
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