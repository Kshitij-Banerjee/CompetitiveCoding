//
//  main.cpp
//  CodeChef-AlphaBet
//
//  Created by Kshitij Banerjee on 27/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//
//  main.cpp
//  Grab-Task1
//
//  Created by Kshitij Banerjee on 21/08/16.
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

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string s;
    cin >> s;
    
    set<char> m;
    for(char i : s){
        m.insert(i);
    }
    int t;
    cin >> t;
    for( int i = 0; i < t; i++){
        string j;
        cin>> j;
        bool found = true;
        for( char i : j ){
            if( m.find(i) == m.end() ){
                found  = false;
                break;
            }
        }
        if( found )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
        
    return 0;
}
