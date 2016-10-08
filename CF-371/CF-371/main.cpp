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
#include <numeric>

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

#include <unordered_map>
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

string pattern( string num ){
    stringstream ss;
    for( int i = (18L - num.size()); i != 0; i -- )
        ss << "0";
    for( auto a : num ){
        if( atoi(&a) %2 == 0 )
            ss << 0;
        else
            ss << 1;
    }
   // cout << ss.str();
    
    return ss.str();
}

static int change = 0;
void solve( vector<int>& a, int start, int end ){
    
    if( start >= end ) return;
   int sum = accumulate(a.begin()+start, a.begin() + end + 1, 0);
    
    int avg = sum / a.size();
    
    int mid = start + (end -start)/2;
    change += a[ mid ] - avg ;
    a[mid] = avg;
    
    for( int i = mid+1; i < end; i++){
        if( a[i] < avg ) {
            change += (avg - a[i] + 1);
            a[i] = avg+1;
        }
    }
    
    for( int i =0 ;i < mid; i ++){
        if( a[i] > avg ){
            change += (a[i] - avg + 1 );
            a[i] = avg -1;
        }
    }
    
    solve( a, 0, mid -1 );
    solve( a, mid+1, end );
}

int main(int argc, const char **){
    
    
    int T;
    cin >> T;
    vector<int> arr(T, 0);
    for( int i = 0 ;i < T;i ++ )
        cin >> arr[i];
    
    solve( arr, 0, T );
    
    cout << change << endl;
}

//    int t;
//    cin >> t;
//    
//    unordered_map<string, int > hashmap;
//    
//    while( t-- ){
//        char op;
//        cin >> op;
//        string num;
//        cin >> num;
//        
//        
//        if( op == '+' )
//            hashmap[pattern(num)]++;
//        if( op == '-' )
//            hashmap[pattern(num)]--;
//        if( op == '?' )
//        {
//            cout << hashmap[pattern(num)] << endl;
//        }
//    }
//}
//    int i ;
//    cin >> i;
//    
//    unordered_map<long ,int> map;
//    for( int j =0 ;j < i; j++){
//        long k;
//        cin >> k;
//        map[k]++;
//    }
//    
//    
//    if( map.size() > 3 )
//        cout << "NO" << endl;
//    else if(map.size() == 3){
//        
//        vector<long> m;
//        for( auto i : map )
//            m.pb(i.first);
//        sort(m.begin(), m.end() );
//        if( (m[1] - m[0]) == (m[2] - m[1]) )
//            cout << "YES" << endl;
//        else
//            cout << "NO" << endl;
//    }
//    else
//        cout << "YES" << endl;
// }
