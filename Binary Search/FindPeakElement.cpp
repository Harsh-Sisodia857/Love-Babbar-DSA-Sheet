int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n = arr.size();
    if(n == 1)
        return 0;
    if(arr[0] > arr[1]){
        return 0;
    }
    if(arr[n-1] > arr[n-2]){
        return n - 1;
    }
   
    int low = 0;
    int high = n - 2;
    while(low <= high){
        int mid = low + (high - low)/2;
        // mid is peak element
        if(arr[mid] > arr[mid-1] && arr[mid + 1] < arr[mid])
            return mid;
        // uprend
        if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid + 1]){
            low = mid + 1;
        }
        // downtrend
        else{
            high = mid - 1;
        }
    }
    return 0;
}
