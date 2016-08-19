//============================================================================
// Name        : LRUCache.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

struct comp{

	bool operator()  (pair<int,int> l, pair<int,int> r) {
		return l.second > r.second;
	}
};


class LRUCache{
	priority_queue< pair<int,int >,vector< pair<int,int > >,comp >  q;
	map<int,int> pairs;
	map<int,int> v;
	int cap;

public:
    LRUCache(int capacity) {
    	cap = capacity;
    }

    int get(int key) {
    	v[key] = v[key] + 1;
    	return pairs[key];
    }

    void set(int key, int value) {

    	if(pairs.find(key) != pairs.end())
    		pairs[key] = value;
    	else
    	{
    		if(v.size() == cap){
    			pair<int,int> p = q.top();
    			v.erase(v.find(p.first));
    			v[key] = value;
    			q.pop();
    			q.push(pair<int,int>(key,value));
    		}
    	}
    }
};
