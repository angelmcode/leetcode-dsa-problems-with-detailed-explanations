// time complexity O(n) space complexity O(n)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector

using namespace std;

class Solution {
public:

    static vector<int> productExceptSelf(vector<int>& numbers) {
     // numbers                           1,         2,        3,            4 
     // result                 1          1          2         6,           24
     // iteration  24,        24,        12,         4         1
      
     vector<int> result(numbers.size(),1); // Space: O(n)

     for (int i = 1; i < numbers.size(); i++) // Time: O(n)
     {
       result[i] = numbers[i-1] * result[i-1];
     }
     
     int suffix = 1;
     for (int i = result.size()-1; i >= 0; i--) // Time: O(n)
     {
       result[i] *= suffix;
       suffix *= numbers[i];
     }

     return result;
    }
};

int main(){
   vector<int> input = {1,2,3,4};
   vector<int> numbers = Solution::productExceptSelf(input);

   for (auto &n : numbers)
   {
    cout << n << '\n';  
   }

   return 0;
}