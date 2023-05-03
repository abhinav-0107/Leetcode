class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>ans;
        vector<int>temp;
        
        map<int,int>mp1;
        for(int i=0;i<n1;i++){
            mp1[nums1[i]]++;
        }
        map<int,int>mp2;
        for(int i=0;i<n2;i++){
            mp2[nums2[i]]++;
        }
        
        for(int i=0;i<n1;i++){
            if(mp2[nums1[i]]==0){
                if(mp1[nums1[i]]==1){
                    temp.push_back(nums1[i]);
                }
                mp1[nums1[i]]--;
            }
        }
        ans.push_back(temp);
        temp.clear();
        for(int i=0;i<n2;i++){
            if(mp1[nums2[i]]==0){
                if(mp2[nums2[i]]==1){
                temp.push_back(nums2[i]);
                }
                mp2[nums2[i]]--;
            }
        }
        ans.push_back(temp);

        return ans;
    }
};