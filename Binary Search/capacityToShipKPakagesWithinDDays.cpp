int dayRequired(vector<int> &weights, int w){
    int n = weights.size();
    int days = 0;
    int currSum = 0;
    for(int i = 0; i < n; i++){
        if(currSum + weights[i] <= w){
            currSum += weights[i];
        }else{
            days++;
            currSum = weights[i];
        }
    }
    if(currSum > 0)
        days++;
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int maxWeight = 0,sum = 0;
    int n = weights.size();
    for(int i = 0; i < n; i++){
        maxWeight = max(weights[i],maxWeight);
        sum += weights[i];
    }
    int low = maxWeight;
    int high = sum;
    while(low <= high){
        int mid = low + (high - low)/2;
        int days = dayRequired(weights,mid);
        // cout<<low<<" "<<high<<" "<<mid<<" "<<days<<endl;
        if(days <= d){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}