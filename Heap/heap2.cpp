#include<bits/stdc++.h>
using namespace std;
int main(){
    string t = "dcda";
    string s = "adc";
    if(s.size() > t.size()){
        cout << "NO\n";
        return 0;
    }
    if(s.size() == t.size()){
        if(s  == t){
            cout << "YES\n";
            return 0;
        }
        else{
            cout << "NO\n";
            return 0;
        }
    }
    sort(s.begin(), s.end());
    string ans = t;
    int n = t.size();
    int start = 0;
    for(int i = 0; i<= t.size()-s.size(); i++){
        sort(t.begin() + start, t.begin()+start + s.size());
        cout << t << '\n';
        if(t.find(s) < t.size()){
            cout << "YES\n";
            return 0;
        }
        else{
            start++;
        }
        t = ans;
        

    }
    cout << "NO\n";
    return 0;
}