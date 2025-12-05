// Time Complexity: O(n^2), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int trap(vector<int>& height) {
      // Space O(1)
      if(height.empty()) return 0;
      int sumWater = 0;
      
      for (int i = 0; i < height.size(); i++) // Time: O(n)
      {
         int leftMax = height[i];
         int rightMax = height[i];

         for (int j = i-1; j > 0; j--)
         {
            leftMax = max(leftMax, height[j]);
         }

         for (int j = i+1; j < height.size(); j++)
         {
            rightMax = max(rightMax, height[j]);
         }

         int trappedWater = min(rightMax,leftMax) - height[i];

         sumWater += trappedWater;
      }
      return sumWater;
    }
};

int main(){
   vector<int> numbers = {0,2,0,3,1,0,1,3,2,1};

   Solution r;

   int result = r.trap(numbers);

   
   cout << result << "\n";
}