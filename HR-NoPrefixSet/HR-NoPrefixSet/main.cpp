//
//  main.cpp
//  HR-NoPrefixSet
//
//  Created by Kshitij Banerjee on 08/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
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

struct comp{
    bool operator()( string l, string r ) {
        return !(l.length() < r.length());
    }
}comparator;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<string> arr;
    
    while( N-- ){
        string inp;
        cin >> inp;
        arr.pb(inp);
    }
    
    unordered_map<string,string> prefixes;
    for( vector<string>::reverse_iterator rit = arr.rbegin();
        rit != arr.rend(); rit++ ){
        
        string str = *rit;
        if( prefixes.find(str) != prefixes.end() )
        {
            cout << "BAD SET" << endl;
            cout << prefixes.find(str)->second;
            return 0;
        }
        for( int i = 0; i < str.length()+1; i++ ){
            prefixes[str.substr(0,i)] = str;
        }
    }
    
    cout << "GOOD SET" << endl;
    
    return 0;
}
