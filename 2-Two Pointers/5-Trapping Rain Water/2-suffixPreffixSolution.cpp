// Time Complexity: O(n), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int trap(vector<int>& height) {
      if(height.empty()) return 0;
      vector<int> prefix(height.size(),0); // Space 0(n)
      vector<int> suffix(height.size(),0); // Space 0(n)
      
      int sumWater = 0;
      prefix[0] = height[0];
      for (int i = 1; i < height.size(); i++) // Time 0(n)
      {
         prefix[i] = max(prefix[i-1], height[i]);
      }

      suffix[height.size()-1] = height[height.size()-1];
      for (int i = height.size() - 2; i >= 0 ; i--) // Time 0(n)
      {
         suffix[i] = max(suffix[i+1], height[i]);
      }

      for (int i = 0; i < height.size(); i++) // Time 0(n)
      {
         int water = min(prefix[i], suffix[i]) - height[i];
         sumWater += water;
      }
      return sumWater;
    }
};

int main(){
   // vector<int> numbers = {0,1,0,2,1,0,1,3,2,1,2,1};
   vector<int> numbers = {4,2,0,3,2,5};

   Solution r;

   int result = r.trap(numbers);

   
   cout << result << "\n";
}