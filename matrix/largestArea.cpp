//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> prevSmallest(int *arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> prev(n);
        for(int i = 0; i < n; i++){
            int currElement = arr[i];
            while(s.top() != -1 && arr[s.top()] >= currElement){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
        return prev;
    }
    vector<int> nextSmallest(int *arr,int n){
        stack<int> s;
        s.push(-1);
        vector<int> next(n);
        for(int i = n-1; i >= 0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i])
                s.pop();
            next[i] = s.top();
            s.push(i);
        }
        return next;
    }
    int largestRectangleArea(int *arr,int n){
        vector<int> next(n);
        next = nextSmallest(arr,n);
        vector<int> prev(n);
        prev = prevSmallest(arr,n);
        int area = INT_MIN;
        for(int i = 0; i < n; i++){
            int l = arr[i];
            if(next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0],m);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] != 0)
                    M[i][j] += M[i-1][j];
                else
                    M[i][j] = 0;
            }
            area = max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends