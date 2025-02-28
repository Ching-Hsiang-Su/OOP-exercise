#include<iostream>
#include<map>

using namespace std;
int main(){
    int m,q;
    cin >> m;
    map<int, int>studs;

    for (int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        if (studs.find(temp) != studs.end())
            studs[temp]++;
        else 
            studs.insert(make_pair(temp,1));
    }
    cin >> q;
    for(int i = 0;i < q; i++){
        int temp;
        cin >> temp;
        if (i < q-1)
            cout << studs[temp] <<" ";
        else 
            cout << studs[temp] << endl;
    }
}