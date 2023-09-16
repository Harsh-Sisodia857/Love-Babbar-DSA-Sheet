//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	// i represent arrival time and j represent departure time
    	int i = 0,j = 0;
    	// count store the current maximum platform needed and res store maximum platform
    	int count = 0,res = INT_MIN;
    	while(i < n){
    	    // if arrival time is smaller than departure time increase the count
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        res = max(res,count);
    	        i++;
    	    }else{
    	        count--;
    	        j++;
    	    }
    	}
    	return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends