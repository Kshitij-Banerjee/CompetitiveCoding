//
//  main.cpp
//  HR-AlmostSorted
//
//  Created by Kshitij Banerjee on 16/09/16.
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
typedef vector<long long> vi;
typedef vector<long long>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<long long,long long> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define ll long long

#define sz(a) long long((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned long long t;
    cin >> t;
    vector<unsigned long long> a(t,0);
    for(unsigned long long i  = 0;i < t; i ++ ){
        cin >> a[i];
        a[i] = a[i] -1;
    }
    
    vector<pair<long long, long long> > indice(t);
    for( long long i = 0; i < t; i ++ ) {
        indice[i] = mPR(a[i], i);
    }
    
    sort(indice.begin(), indice.end());
    
    
    unsigned long long count = 0;
    unsigned long long begin = 0;
    for( unsigned long long i = 0 ; i < indice.size(); i ++ ){
        indice[i].first = indice[i].second - i;
        if(indice[i].first != 0 ){
            count++;
            if( !begin ) begin = i+1;
        }
    }
    
    if( count == 0 )
        cout << "yes" << endl;
    else {
        if( count == 2)
            cout << "yes" << endl << "swap " << begin << " " << (abs(indice[begin-1].first) + begin) << endl;
        else {
            long long i = 0;
            for( ; i < t; i++ ){
                if( indice[i].first != 0 ) break;
            }
            indice.erase(indice.begin(), indice.begin()+i);
            for( i = t-1; i >0 ; i --){
                if( indice[i].first != 0 ) break;
            }
            indice.erase(indice.begin()+i+1, indice.end());
            
            
            bool palindrome = true;
            for( long long i = 0, j = indice.size()-1; i <= j; i++, j-- )
                if( abs(indice[i].first) != abs(indice[j].first) ){
                    palindrome = false;
                    break;
                }
            
            if( palindrome ) {
                cout << "yes" << endl << "reverse " << begin << " " << begin + indice[0].first << endl;
            }
            else
                cout << "no" << endl;
        }
    }
}

