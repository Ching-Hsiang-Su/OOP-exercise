#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    int a,b,c;
    double area = 0,s = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a >> b >> c;
        s = (a + b + c) / 2;
        area = area + sqrt(s * (s - a) * (s - b) * (s - c));
    }
    //area = round(area * 100) / 100;
    cout << area << endl;
}