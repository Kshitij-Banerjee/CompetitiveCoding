//
//  main.cpp
//  Leet-StockMax
//
//  Created by Kshitij Banerjee on 19/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int>::iterator vit;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() <= 1)
            return 0;
        
        for( int i = 0; i < prices.size()-1; i++ ){
            if(prices[i] == prices[i+1])
                prices[i] = INT_MAX;
        }
        
        for( vit it = prices.begin(); it != prices.end(); ){
            if( *it == INT_MAX ){
                it = prices.erase(it);
            }
            else it++;
        }
        
        int buy_price;
        int total_profit = 0;
        bool finding_high;
        
        if( prices[1] > prices[0]){
            buy_price = prices[0];
            finding_high = true;
        }
        else{
            finding_high = false;
        }
        
        
        for( int i = 1; i < prices.size() - 1; i ++ ){
            if( finding_high) {
                if((prices[i-1] < prices[i]) && (prices[i+1] < prices[i])) {
                    total_profit += (prices[i] - buy_price);
                    finding_high = false;
                }
            }
            else
            {
                if( prices[i] < prices[i-1] && (prices[i] < prices[i+1]))
                {
                    buy_price = prices[i];
                    finding_high = true;
                }
            }
            
        }
        
        if( finding_high ){
            total_profit += (*(prices.end()-1) - buy_price);
        }
        
        return total_profit;

    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 4,0,1,0,0,0,6,1,4 };
    vector<int> v(arr, arr+9);
    Solution s;
    cout << s.maxProfit(v);
    return 0;
}
