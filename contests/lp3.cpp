#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vlong;
typedef vector<vlong> vvlong;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int m = 26;
        vint f1(m), f2(m);
        set<int> s1, s2;
        for(auto &x : word1) f1[x - 'a']++, s1.insert(x - 'a');
        for(auto &x : word2) f2[x - 'a']++, s2.insert(x - 'a');

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i != j && f1[i] && f2[j]) {
                    if(f1[i] == 1) s1.erase(i);
                    if(f2[j] == 1) s2.erase(j);

                    bool b1 = false, b2 = false;
                    // insert if not present
                    if(s2.find(i) == s2.end()) s2.insert(i), b2 = true;
                    if(s1.find(j) == s1.end()) s1.insert(j), b1 = true;

                    if(s1.size() == s2.size()) return true;

                    // revert insertion if inserted
                    if(b1) s1.erase(j);
                    if(b2) s2.erase(i);

                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }

        return false;
    }
};