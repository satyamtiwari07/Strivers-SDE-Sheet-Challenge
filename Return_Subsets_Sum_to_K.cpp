void f(int idx, int sum,int k, vector<int>&arr,vector<int>&temp, vector<vector<int>>&ans){
    // if(sum>k) return;

    if(idx>=arr.size()){
        if(k==sum and temp.size()){
            ans.push_back(temp);
        }
        return ;
    }

    f(idx+1,sum,k,arr,temp,ans);

    temp.push_back(arr[idx]);
    sum+=arr[idx];
    f(idx+1,sum,k,arr,temp,ans);
    temp.pop_back();

}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    f(0,0,k,arr,temp,ans);
    return ans;
}
