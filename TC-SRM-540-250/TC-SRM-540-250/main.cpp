//
//  main.cpp
//  TC-SRM-540-250
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
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <algorithm>



class RandomColoringDiv2{
private:
    int calcd1( int start, int max, int d1, int d2){
        
        int rstart = start - d2 < 0 ? start - d1 : d2 - d1;
        int rend = start + d2 > max ? max - start - d1 : d2 - d1;
        
        return rstart + rend;
    }
    
    int calcd2( int start, int max, int d2){
        
        int rstart = start - d2 < 0 ? start : d2;
        int rend = start + d2 > max ? max - start : d2;
        return rstart + rend ;
    }
    
public:
    int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2){
        
        if( d1 > d2 ) return 0;
        int total = 1;
        maxR--;
        maxG--;
        maxB--;
        
        for( int i =0; i < 3;i ++ ){
            int Rrange = i == 0 ? calcd1(startR, maxR, d1, d2) : calcd2(startR, maxR, d2);
            int Grange = i == 1 ? calcd1(startG, maxG, d1, d2) : calcd2(startG, maxG, d2);
            int Brange = i == 2 ? calcd1(startB, maxB, d1, d2) : calcd2(startB, maxB, d2);
            
            total *= Rrange + Grange + Brange;
        }
        
        return total;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    RandomColoringDiv2 s;
    std::cout << s.getCount(5, 1, 1, 2, 0, 0, 0, 1);
    return 0;
}
