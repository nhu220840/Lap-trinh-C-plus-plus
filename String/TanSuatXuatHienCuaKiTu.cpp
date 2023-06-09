#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    set<char> printed;
    for(char c : s){
        if(printed.count(c) == 0){
            cout << c << " " << mp[c] << endl;
            printed.insert(c);
        }
    }
}