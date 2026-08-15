class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
        long long min1 = LLONG_MAX, min2 = LLONG_MAX; 
        for(int i=0;i<n;i++){
            int x = nums[i];

            if(x>max1){
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if( x> max2){
                max3 = max2;
                max2 = x;
            } else if(x>max3){
                max3 = x;
            }
            if(x<min1){
                min2 = min1;
                min1 = x;
            }
            else if(x<min2){
                
                min2 = x;
            }
        }  
        long long ans1 = max1*max2*max3;
        long long ans2 = min1*min2*max1;

        return max(ans1,ans2); 
    }
};