#include<bits/stdc++.h>
using namespace std;

void KMPSearch(string pattern,string txt){
    // creating pie chart ( Longest prefix which is suffix also )
    int n = pattern.length();
    vector<int> lps(0, n);
    for (int i = 1; i < n; i++){
        int j = lps[i - 1];
        while(j > 0 && pattern[j] != pattern[i]){
            j = lps[j-1];
        }
        if(pattern[j] == txt[i])
            j++;
        lps[i] = j;
    }
}

int main(){
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}