#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr = {7, 10,4,3,20,15};
        int n = arr.size();
        int k = 3;
        priority_queue<int> pq;
        for(int i = 0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i = k; i<n; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        cout << pq.top() << '\n';
}