#include<bits/stdc++.h>
using namespace std;
int p = 31;
int n = 1e5;
int mod = 1e9;
vector<long long> power(n);

long long calculateHash(string str){
    long long hash = 0;
    for(int i = 0; i < str.length(); i++){
        hash = (hash + (str[i] - 'a' + 1) * power[i]) % mod;
    }
    return hash;
}

int main(){
    vector<string> str = {"aa","ab","abc","aa","ab"};

    // precomputing powers
    power[0] = 1;
    for(int i = 1; i < n + 1; i++){
        power[i] = (power[i - 1] * 31) % mod;
    }
    vector<long long> hashStr(str.size());
    for (int i = 0; i < str.size(); i++){
        hashStr[i] = calculateHash(str[i]);
    }
    int distinct = 0;
    sort(hashStr.begin(), hashStr.end());
    for (int i = 0; i < str.size(); i++){
        if (i == 0 || hashStr[i] != hashStr[i - 1])
        {
            distinct++;
        }
    }
    cout << "Distinct String are : " << distinct << endl;
    auto temp = ("abc" - 'a');
    cout <<"Difference is : "<< temp;
    return 0;
}