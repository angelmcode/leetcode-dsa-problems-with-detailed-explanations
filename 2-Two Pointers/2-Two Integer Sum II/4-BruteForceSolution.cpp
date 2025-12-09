// Time Complexity: O(n^2), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Space O(1)
        for (int i = 0; i < numbers.size(); i++) // Time O(n^2)
        {
            for (int j = i+1; j < numbers.size(); j++)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    return {i+1,j+1};
                }
            }
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