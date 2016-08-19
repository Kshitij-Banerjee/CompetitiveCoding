//============================================================================
// Name        : Leet-LongestSubStringNotRepeatable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		if(s.empty()) return 0;

		set<char> seen;

		int count = 0;
		int start = 0;
		int end = 0;

		for (char c : s) {

			cout << "char: " << c << endl;

			if (seen.find(c) == seen.end()) {
				cout << "inside seen.find" << endl;
				seen.insert(c);
				end++;
			} else {
				count = max(end - start, count);
				while (s[start] != c){
					seen.erase(s[start++]);
				}
				end ++;
				start ++;

				cout << "at end" << end << start << endl;
			}
		}

		count = max(end -start, count);
		return count;
	}
};

int main() {
	Solution s;
	int ans = s.lengthOfLongestSubstring("bpfb");
	cout << "answer is : " << ans <<endl;
	return ans;
}
