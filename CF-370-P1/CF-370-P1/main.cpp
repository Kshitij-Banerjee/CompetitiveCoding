//
//  main.cpp
//  CF-370-P1
//
//  Created by Kshitij Banerjee on 10/09/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, int> pii;
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <algorithm>
using namespace std;


vector<string> split(string pos) {
    vector<string> elems;
    stringstream ss(pos);
    string item;
    while(getline(ss, item, ' ')){
        elems.push_back(item);
    }
    return elems;
}

int main(int argc, const char * argv[]) {
    int x, y;
    cin >> x >> y;
    if( x > y)
    {
        int temp = y;
        y =x;
        x = temp;
    }
    
    vi arr(3, x);
    int count = 0;
    
    while( arr[0]!=y || arr[1]!=y || arr[2]!=y){
        auto min = (min_element(arr.begin(), arr.end()));
        auto max = (max_element(arr.begin(), arr.end()));
        vi::iterator other;
        for( vi::iterator i = arr.begin(); i != arr.end(); i ++){
            if( i != min && i != max){
                other = i;
                break;
            }
        }
        
        if(*min == y){
            vi::iterator temp = min;
            min = other;
            other = temp;
        }
        
        
        *min = abs(*other + *max) - 1;
        if( *min > y)
            *min = y;
        
        count++;
    }
    cout << count;
    return 0;
}
