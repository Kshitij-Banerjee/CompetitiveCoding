
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
    
    int T;
    
    cin >> T;
    for( int i =0 ;i < T; i ++){
        int M;
        cin >> M;
        vvi stack(M);
        int total = 0;
        for( int j = 0; j < M ; j++){
            int K;
            cin >> K;
            for ( int k =0; k < K; k++ ){
                int in;
                cin >> in;
                total++;
                stack[j].push_back(in);
            }
        }
        int j = 0;
        for( ; j < total ; j++){
            int k;
            cin >> k;
            
            int x = 0;
            for( ; x < M; x++ ){
                if( stack[x].back() == k ){
                    stack[x].pop_back();
                    cout << "found in " << x << endl;
                    break;
                }
            }
            if( x == M )
            {
                cout << "No" << endl;
                break;
            }
        }
        
        if( j == total )
            cout << "Yes" << endl;
    }
    
    return 0;
}
