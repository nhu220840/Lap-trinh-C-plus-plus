#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

int main(){
    int n; cin >> n;
    vector<string> v;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(string x : v) cout << x;
}