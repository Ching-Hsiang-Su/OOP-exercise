#include <iostream>
#include <cmath>
using namespace std;

double dist(double a, double b){
    double d = sqrt(pow(a-6,2)+pow(b-6,2));
    return d;
}

int main(){
    int n,count=0;
    cin >> n;
    for(int i=0;i<n;i++){
        double a,b,c; //注意要用double，除法後才會保持浮點數
        cin >> a >> b >> c ;
        if ((dist(a,b) <= (c/2)+6) && (dist(a,b) >= fabs((c/2)-6))){
            count+=1;
        }
    }
    cout << count << endl ;
}