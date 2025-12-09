// Time Complexity: O(n^2), Space Complexity: O(1)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) // Time: O(n^2)
        {
            for (int j = 0; j < height.size(); j++)
            {
                int conHeight = min(height[i], height[j]);
                int conWidth = j- i;
                int Area = conHeight * conWidth;
                maxArea = max(maxArea, Area);
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