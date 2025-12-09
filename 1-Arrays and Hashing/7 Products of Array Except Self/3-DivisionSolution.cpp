// time complexity: O(n)   space complexity: O(n)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector

using namespace std;

class Solution {
public:

    static vector<int> productExceptSelf(vector<int>& numbers) {
     // 0,2,0,4  8
      int zero=0;
      int prod = 1;
      vector<int> result(numbers.size(),1); // Space: O(n)

      for (int i = 0; i < numbers.size(); i++) // Time: 0(n)
      {
         if (numbers[i] == 0)
         {
            zero++;
         } else {
            prod *= numbers[i]; 
         }        
      }
      for (int i = 0; i < numbers.size(); i++) // Time: O(n)
      {
         if (zero == 1 && numbers[i] == 0 )
         {
            result[i] = prod;
         } else if(zero==1 && numbers[i] != 0){
            result[i] = 0;
         }else if(zero > 1){
            result[i] = 0;
         } else if(zero == 0)
         {
            result[i] = prod / numbers[i];
         }
         
      }
      
      return result;
    }
};

int main(){
   vector<int> input = {0,2,3,4};
   vector<int> numbers = Solution::productExceptSelf(input);

   for (auto &n : numbers)
   {
    cout << n << '\n';  
   }

   return 0;
}