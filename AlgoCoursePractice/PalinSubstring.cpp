#include <iostream>
#include <string>
using namespace std;

    bool isPalindrome(string ss, int s, int e) {
        bool isPalin = true;
        for(int i = 0; i < (e-s+1)/2; i++) {
            if(ss[s+i] != ss[e-i]) {
                isPalin = false;
                break;
            }
        }
        return isPalin;
    }

    string longestPalindromeAux(string s, int i, int j) {
        if(i == j) {
            return s.substr(i,1);
        }
        if(isPalindrome(s, i, j)) {
            return s.substr(i, j - i + 1);
        }
        string r1 = longestPalindromeAux(s, i + 1, j);
        string r2 = longestPalindromeAux(s, i, j - 1);
        if(r1.length() > r2.length()) return r1;
        return r2;
    }
    
int main() {
    string s = "";
    cout << longestPalindromeAux(s, 0, s.length()-1);
    return 0;
}    