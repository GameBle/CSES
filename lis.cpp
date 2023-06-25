class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        // this solution will be required to trace the lis (to print it)
        // int n = arr.size();
        // vector<int> dp(n,1);
        // vector<int> storePrevIndex(n);
        // for(int i = 0; i < n; i++){
        //     storePrevIndex[i] = i;
        // }
        // int maxi = 1, maxiInd = 0;
        // for(int i = 0; i < n; i++){
        //     for(int prev = 0; prev < i; prev++){
        //         if(arr[prev] < arr[i]){
        //             if(1+dp[prev] > dp[i]){
        //                 dp[i] = 1+dp[prev];
        //                 storePrevIndex[i] = prev;
        //             }
        //         }
        //     }
        //     if(dp[i] > maxi){
        //         maxi = dp[i];
        //         maxiInd = i;
        //     }
        // }
        // while(storePrevIndex[maxiInd] != maxiInd){
        //     cout<<arr[maxiInd]<<" "; // isko just reverse karna hai
        //     maxiInd = storePrevIndex[maxiInd];
        // }
        // cout<<endl;
        // return maxi;

        // using binary search
        // in this method actual lis is not generated but it's length is.
        int n = (int)arr.size();
        vector<int> res;
        res.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            int ind = lower_bound(res.begin(),res.end(),arr[i]) - res.begin();
            if(ind == res.size()){
                res.push_back(arr[i]);
            }else{
                res[ind] = arr[i];
            }
        }
        int len = res.size();
        return len;
    }
};