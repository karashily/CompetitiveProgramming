#include <iostream>
#include <string>
#include <vector>
using namespace std;

int* failure_fn (string pattern) {
    int m = pattern.length();
    int* pi = new int[m+1];
    pi[0] = 0;
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q <= m; q++) {
        while(k>0 && pattern[k+1] != pattern[q]) k = pi[k];
        if(pattern[k+1] == pattern[q]) k++;
        pi[q] = k;
    }
    return pi;
}

vector<int> KMP_matcher(string text, string pattern) {
    vector<int> occ;
    int n = text.length();
    int m = pattern.length();
    int* pi = failure_fn(pattern); 
    int q = 0;
    for(int i = 0; i < n; i++) {
        while(q > 0 && text[i] != pattern[q+1]) q = pi[q];
        if(pattern[q+1] == text[i]) q++;
        if(q == m-1) {
            occ.push_back(i - m + 1);
            q = pi[q];
        }
    }
    return occ;
}

int main() {
    string pattern = "aba";
    string text = "abcaabacaba";
    vector<int> occ = KMP_matcher(text, pattern);
    for(int i = 0; i < occ.size(); i++) {
        cout << occ[i] << " ";
    }
    return 0;
}