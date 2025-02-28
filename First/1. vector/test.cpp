#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    cout << v1[0] << " " << v1[1];
    v1.erase(v1.begin());
    cout << v1[0];
}