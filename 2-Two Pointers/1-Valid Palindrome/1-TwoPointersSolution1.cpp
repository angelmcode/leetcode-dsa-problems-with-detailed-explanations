// Time Complexity: O(n), Space Complexity: O(1)
#include <iostream> // needed to input output operations
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;
        
        // Space O(1)
        int start = 0; 
        int end = s.size()-1;

        while (start < end) // Time: O(n)
        {   if (!isAlfaNumeric(s[start]))
            {
              start++;
              continue;
            } else if (!isAlfaNumeric(s[end]))
            {
                end--;
                continue;
            }
        
            if (tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;    
        }
        return true;
    }

    bool isAlfaNumeric(char ch){
            if ( (ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') )
            {
                return true;
            } else
            {
                return false;
            } 
        }
};

int main(){
   string s = "98";

   Solution r;

   bool result = r.isPalindrome(s);

   cout << result << '\n';
}