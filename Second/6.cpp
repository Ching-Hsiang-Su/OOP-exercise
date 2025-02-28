#include <iostream>
#include <cmath>
using namespace std;

double dist_0(double a, double b){
    double d = sqrt(pow(a,2)+pow(b,2));
    return d;
}

int main(){
    int n,count=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c ;
        if (dist_0(a,b) <= c/2 ){
            count+=1;
        }
    }
    cout << count << endl ;
}