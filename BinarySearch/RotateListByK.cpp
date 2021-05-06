vector<int> solve(vector<int>& nums, int k) {
    if(k==0 || k==nums.size()) return nums;
    int n=nums.size();
    if(k<n/2){
    while(k--) {
        for(int i=0; i<nums.size()-1; i++){
            swap(nums[i], nums[i+1]);
        }
    }}
    else{
        k = n-k;
    while(k--) {
        for(int i=n-1; i>0; i--){
            swap(nums[i], nums[(i+1)%n]);
        }
    }}
    return nums;
}

//optimised

vector<int> solve(vector<int>& nums, int k) {
    // everyone jumps k steps ahead..
    // thats it.

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());

    return nums;
}
