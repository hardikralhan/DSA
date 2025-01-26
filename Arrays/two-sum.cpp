#include <iostream>
using namespace std;

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if((nums[i]+nums[j]) == target){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

// hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            int moreNeeded = target - nums[i];
            if(mpp.find(moreNeeded) != mpp.end()){
                return {i,mpp[moreNeeded]};
            }
            mpp[nums[i]] = i;  //{value: index of value}
        }
        return {-1,-1};
    }
};


// using 2 pointer (not suitable for same numbers [3,3] in array
// because map cannot have 2 same keys, we are storing array value as key and index as value
// because we need index from the map)

// this solution is best if we dont have to tell index of elements.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){ // add indexes into map
            mpp[nums[i]] = i;  //{value: index of value}
        }
        int left = 0; 
        int right = nums.size()-1;
        sort(nums.begin(), nums.end());

        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum<target){
                left++;
            }else if(sum>target){
                right--;
            }else{
                return {mpp[nums[left]], mpp[nums[right]]};
            }
        }
        return {-1,-1};
    }
};