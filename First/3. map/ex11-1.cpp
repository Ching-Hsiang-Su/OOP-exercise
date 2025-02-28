#include<iostream>
#include<map>
#include<vector>

using namespace std;
int main(){
    int n,count=0;
    cin >> n;
    vector<string> v;
    map<string , string>maps;
    for (int i = 0; i < n; i++){
        string a,b;
        cin >> a >> b ; 
        v.push_back(a);
        maps.insert(make_pair(a,b));
    }
    for(int i = 0; i < n ;i++){
        if(v[i] == maps[maps[v[i]]]){
            count++;
        }
    }
    if(count)
        cout << "YES" << endl;
    else
        cout << "NO" <<endl;
}