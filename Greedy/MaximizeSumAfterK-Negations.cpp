//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int sumOfArray(long long int a[],int n){
        long long int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        return sum;
    }
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int i = 0;
        for(i = 0; i < n; i++){
            if(a[i] < 0 && k != 0){
                a[i] = -a[i];
                k--;
            }else{
                break;
            }
        }
        if(k != 0){
            if(k % 2 == 0){
                k = 0;
            }else{
                if(a[i] > a[i-1]){
                    a[i-1] = -a[i-1];
                }
                else{
                    a[i] = -a[i];
                }
            }
        }
        return sumOfArray(a,n);
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends