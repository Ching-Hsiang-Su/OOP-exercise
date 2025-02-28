#include<iostream>
using namespace std;

int main(){
    int n,a=0;
    int x,y;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x >> y;
        a=a+x*y;
    }
    cout << a << endl;
}