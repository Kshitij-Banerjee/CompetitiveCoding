//
//  main.cpp
//  IB-strstr
//
//  Created by Kshitij Banerjee on 13/10/16.
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


int strStr(const string &haystack, const string &needle) {
    
    int search = 0;
    int window = 0;
    
    for( int i = 0; i < needle.length(); i ++ ) search += needle[i];
    for( int i = 0; i < needle.length(); i ++ ) window += haystack[i];
    int i = 0;
    int j = needle.length()-1;
    
    while( ++j < haystack.length() &&
          !((search == window) && (haystack.compare(i,needle.length(), needle) == 0))
          ){
        window -= haystack[i++];
        window += haystack[j];
    }
    
    cout << "hi" << endl;
    
    if( (search == window) && haystack.compare(i,needle.length(), needle) == 0){
        return i;
    }
    else
        return -1;
    
    
    
    cout << "hi";
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << strStr("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba", "babaaa");
    return 0;
}
