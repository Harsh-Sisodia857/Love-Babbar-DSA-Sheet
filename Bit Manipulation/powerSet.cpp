#include<bits/stdc++.h>
using namespace std;

void powerSet(vector<string> &set,string s,int n){
    int size = (1 << n);
    cout << "Size : " << size << endl;
    for (int counter = 0; counter < size; counter++){
        string ans = "";
        for (int j = 0; j < n; j++){
            if((counter & (1 << j)) != 0)
                ans += s[j];
        }
        set.push_back(ans);
    }
}

int main(){
    string s = "abc";
    vector<string> set;
    powerSet(set, s, 3);
    for(auto it : set)
        cout << it << " ";
    return 0;
  }