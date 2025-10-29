// time complexity O(n) space complexity O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector

using namespace std;

class Solution {
public:

    static vector<int> productExceptSelf(vector<int>& numbers) {
     // numbers              1,         2,        3,            4 
     // prefix       -1-   1=1,    1x2= 2, 1x2x3= 6,  1x2x3x4= 24
      // suffix   1x2x3x4 = 24, 2x3x4= 24,  3x4= 12,          4=4     -1-
      
      vector<int> preffix(numbers.size()+1); // Space: O(n)
      vector<int> suffix(numbers.size()+1);  // Space: O(n)
                                                   
      preffix[0]=1;
      for (int i=0; i<numbers.size(); i++) // Time: O(n)
      {
         preffix[i+1] = preffix[i] * numbers[i]; 
      }
      
      suffix[numbers.size()]=1;
      for (int i=numbers.size(); i>0; i--) // Time: O(n)
      {
         suffix[i-1] = suffix[i] * numbers[i-1]; 
      }

      vector<int> result(numbers.size()); // Space: O(n)

      for (int i = 0; i < numbers.size(); i++) // Time: O(n)
      {
         result[i] = preffix[i] * suffix[i+1];
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