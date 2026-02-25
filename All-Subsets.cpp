class Solution {
public:
void getallsubsets(vector<vector<int>>&allsubsets,vector<int>&ans,vector<int>&nums,int i){
    if(i==nums.size()){
        allsubsets.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    getallsubsets(allsubsets,ans,nums,i+1);
    ans.pop_back();
    getallsubsets(allsubsets,ans,nums,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allsubsets;
        getallsubsets(allsubsets,ans,nums,0);
        return allsubsets;
        
    }
};
