// time complexity: O(n²)  space complexity: O(n)

#include <iostream> // needed to input output operations
#include <vector> // needed to use vector

using namespace std;

class Solution {
public:

    static vector<int> productExceptSelf(vector<int>& numbers) {

      vector<int> result(numbers.size(),1);// Space: O(n)

      for (int i = 0; i < numbers.size(); i++) // TIme: O(n²)
      {
         for (int j = 0; j < numbers.size(); j++)
         {
            if(i != j){
               result[i] *= numbers[j];
            }
         }
         
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