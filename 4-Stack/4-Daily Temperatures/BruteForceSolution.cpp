// Time Complexity: O(n^2) Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> result(temperatures.size(),0); // space O(n)
      for (int i = 0; i < temperatures.size(); i++) // time O(n^2)
      {
         for (int j = i+1; j < temperatures.size(); j++)
         {
            if (temperatures[j] > temperatures[i])
            {
               result[i]=j-i;
               break;
            }
         }
      }
      return result;
   }
};


int main (){
   Solution s;

   vector<int> tempentures = {30,38,30,36,35,40,28};
   
   vector<int> result = s.dailyTemperatures(tempentures);

   for (auto &&i : result)
   {
      cout << i << '\n';
   }
   return 0;
}