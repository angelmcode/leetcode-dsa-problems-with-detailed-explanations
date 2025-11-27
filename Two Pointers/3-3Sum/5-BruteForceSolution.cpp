// Time Complexity: O(n^3), Space Complexity: O(m)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
#include <set>
#include <algorithm>
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers) {
      sort(numbers.begin(),numbers.end()); //Time O(n log n)
      set<vector<int>> res; // Space O(m)

      for (int i = 0; i < numbers.size(); i++) //Time O(n^3)
      {
         for (int j = i+1; j < numbers.size(); j++)
         {
            for (int k = j+1; k < numbers.size(); k++)
            {
               if (numbers[i] + numbers[j] + numbers[k] == 0)
               {
                  res.insert({numbers[i],numbers[j],numbers[k]});
               }
               
            }
         }
      }
      return vector<vector<int>>(res.begin(), res.end()); // Space O(m)
    }
};

int main(){
   vector<int> numbers = {-1,0,1,2,-1,-4};

   Solution r;

   vector<vector<int>> result = r.threeSum(numbers);

   for (auto &n : result)
   {
      for (int &i : n)
      {
         cout << i << ",";  
      }
      cout << '\n'; 
   }
}