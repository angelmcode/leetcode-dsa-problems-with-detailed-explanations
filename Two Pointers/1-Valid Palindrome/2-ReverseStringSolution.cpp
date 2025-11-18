// Time Complexity: O(n), Space Complexity: O(n)
#include <iostream> // needed to input output operations
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    bool isPalindrome(string s) {
        string cleanS; // Space: O(n)
        for (char &c : s) // Time: O(n)
        {
            if (isalnum(c)) cleanS.push_back(tolower(c));
        }

        string rCleanS; // Space: O(n)
        rCleanS.assign(cleanS.rbegin(),cleanS.rend());
        
        return cleanS == rCleanS; // Time: O(n)
    }
};

int main(){
   string s = "98";

   Solution r;

   bool result = r.isPalindrome(s);

   cout << result << '\n';
}