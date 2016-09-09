

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
using namespace std;

string rem( string input) {
    
    std::stringstream ss;
    for( auto i : input){
        if( i != '.' || i != ',')
            ss << i;
    }
    
    return ss.str();
}

vector<string> split(string pos) {
    vector<string> elems;
    stringstream ss(pos);
    string item;
    while(getline(ss, item, ' ')){
        elems.push_back(rem(item));
    }
    return elems;
}

set<string> split_uniq(string pos) {
    set<string> elems;
    stringstream ss(pos);
    string item;
    while(getline(ss, item, ' ')){
        item.erase(remove(item.begin(), item.end(), ','), item.end());
        item.erase(remove(item.begin(), item.end(), '.'), item.end());
        elems.insert(item);
    }
    return elems;
}

struct comp {
    bool operator()( const pair<int, int>& i, const pair<int, int>& j) const{
        
        if (i.second == j.second) {
            if (i.first < j.first)
                return true;
            else
                return false;
        }
        else if(i.second>j.second)
            return true;
        
        return false;
    }
}comparator;

int main() {
    
    string line;
    getline(cin, line);
    set<string> keywords = split_uniq(line);
    
    map<int,int> hotels;
    
    int T;
    cin >> T;
    
    while( T--){
        int H;
        cin >> H;
        
        string line;
        getline(cin, line);
        getline(cin, line);
        vector<string> review = split(line);
        
        for( auto i : review){
            if( keywords.find(i) != keywords.end() ){
                hotels[H]++;
            }
        }
    }
    vector<pair<int,int> > vec;
    for( auto i : hotels){
        vec.push_back(mPR(i.first, i.second));
    }
    
    sort(vec.begin(), vec.end(), comparator);
    
    for( auto i : vec){
        cout << i.first << " ";
    }
    
    return 0;
}

