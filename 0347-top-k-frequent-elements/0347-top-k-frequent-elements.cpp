
        



class Solution {

public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();

        map<int,int>mp;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;

        }

        vector<pair<int,int>>v;

        for(auto it:mp){

            v.push_back({it.second,it.first});

        }

        sort(v.begin(),v.end());

        vector<int>ans;

        int i=v.size()-1;

        while(k--){

            ans.push_back(v[i].second);

            i--;

        }

        return ans;

    }

};