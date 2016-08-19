#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        if( nums.size() <= 1) return false;
        vector<int> s;
        
        for( int i =0 ;i < k; i++ ){
            s.push_back(nums[i]);
        }
        
        for( int i = k; i < nums.size(); i++){
            s.push_back(nums[i]);
            cout << *(s.end()-1) << ":" << *s.begin() << endl;
            sort(s.begin(), s.end());
            if( *(s.end()-1) - *s.begin() <= t )
                return true;
            s.erase(s.begin());
        }
        
        return false;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { -1, -1 };
    vector<int> vi(arr, arr+2);
    
    Solution s;
    cout << s.containsNearbyAlmostDuplicate(vi, 1, 0) << endl;
    return 0;
}
