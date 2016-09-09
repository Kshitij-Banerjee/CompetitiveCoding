//
//  main.cpp
//  Anuj-BK-1
//
//  Created by Kshitij Banerjee on 08/09/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>

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
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <algorithm>
using namespace std;


vector<ll> split(string pos) {
    vector<ll> elems;
    stringstream ss(pos);
    string item;
    while(getline(ss, item, ' ')){
        elems.push_back(atoi(item.c_str()));
    }
    return elems;
}

int main() {
    
    string words;
    getline(cin, words);
    vector<ll> numbers = split(words);
    
    cout << numbers[0] ;
    
    for( int i = 1; i < numbers.size(); i++){
        long long difference = numbers[i] - numbers[i-1];
        if( difference > 127 || difference < -127 )
            cout << " -128" << " " << difference;
        else
            cout << " " << difference;
        
    }
    return 0;
}
