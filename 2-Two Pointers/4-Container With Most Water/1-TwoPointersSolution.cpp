// Time Complexity: O(n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int maxArea(vector<int>& height) {

      int maxArea = 0;

      int l = 0;
      int r = height.size()-1;

      while (l<r) // Time: O(n)
      {
         int conHeight = min(height[l], height[r]);
         int conWith = r - l;
         int Area = conHeight * conWith;

         maxArea = max(maxArea, Area);

         if (height[l] <= height[r]) {
            l++;
         }
         else if (height[l] >= height[r]) {
            r--;
         }
      }
      return maxArea;
    }
};

int main(){
   vector<int> numbers = {1,8,6,2,5,4,8,3,7};

   Solution r;

   int result = r.maxArea(numbers);

   
   cout << result << "\n";
}