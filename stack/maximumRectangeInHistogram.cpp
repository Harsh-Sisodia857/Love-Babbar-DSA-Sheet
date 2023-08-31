//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<long long> getNextSmaller(long long arr[],int n){
        vector<long long> nextSmaller(n);
        stack<long long> st; 
        st.push(-1);
        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            nextSmaller[i] = st.top(); 
            st.push(i);
            }
        return nextSmaller;
    }
    vector<long long> getPrevSmaller(long long arr[],int n){
        vector<long long> prevSmallest(n);
        stack<long long> st; 
        st.push(-1);
        for(int i = 0; i < n; i++){
           int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            prevSmallest[i] = st.top(); 
            st.push(i);
        }   
        return prevSmallest;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> nextSmaller(n);
        nextSmaller = getNextSmaller(arr,n);
        vector<long long> prevSmallest(n);
        prevSmallest = getPrevSmaller(arr,n);
        
        long long ans = INT_MIN;
        for(long long i = 0; i < n; i++){
           int length = arr[i];
           if(nextSmaller[i] == -1)
                nextSmaller[i] = n;
           long long breadth = nextSmaller[i] - prevSmallest[i] - 1;
           long long newArea = length*breadth;
           ans = max(ans,newArea);
        }
         
            
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends