//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        if(D*9 < S)
            return "-1";
        if(D == 1 && S > 9)
            return "-1";
        string s = "";
        int newSum = S-1;
        while(D > 1 && newSum > 0){
            if(newSum > 9){
                s = s + "9";
                newSum = newSum - 9;
            }else{
                s = to_string(newSum) + s;
                newSum = 0;
            }
            D--;
        }
        newSum += 1;
        s = to_string(newSum) + s;
        D = D - 1;
        if(D > 0){
            char firstDigit = s[0];
            s = s.substr(1);
            while (D != 0) {
                s = "0" + s;
                D--;
            }
            s = firstDigit + s;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends