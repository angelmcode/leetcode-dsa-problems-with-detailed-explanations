// Time Complexity: O(n), Space Complexity: O(n)
#include <iostream> // needed to input output operations
#include <vector> // needed to use vector
using namespace std; // needed to avoid write std:: every time

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;
        vector<char> ch; // Space: O(n)

        for (char &i : s) // Time: O(n)
        {
            int val = i;
            if ( (val >= 'a' && val <= 'z') ||(val >= 'A' && val <= 'Z') || (val >= '0' && val < '9') )
            {
                ch.push_back(tolower(i));
            }
        }

        int start = 0;
        int end = ch.size()-1;
        int len = ch.size() / 2;

        while (start < len+1 && end > len-1) // Time: O(n)
        {
            if (ch[start] != ch[end]) return false;
            start++;
            end--;    
        }
        return true;
    }
};

int main(){
   string s = "race a car";

   Solution r;

   bool result = r.isPalindrome(s);

   cout << result << '\n';
}