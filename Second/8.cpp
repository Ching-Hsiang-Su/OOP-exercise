#include <iostream>
#include <cmath>

using namespace std;

bool isObtuse(double x1, double x2, double x3, double y1, double y2, double y3) {
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    return (a*a + b*b < c*c) || (a*a + c*c < b*b) || (b*b + c*c < a*a);
}

double dist(double a,double b,double c,double d){
    double dist = sqrt(pow(a-c,2)+pow(b-d,2));
    return dist;
}

int main() {
    int n;
    cin >> n;

    int obtuse_count = 0,tri_count = 0;
    for (int i = 0; i < n; i++) {
        double x1, x2, x3, y1, y2, y3,a,b,c;
        cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
        a = dist(x1,y1,x2,y2);
        b = dist(x1,y1,x3,y3);
        c = dist(x2,y2,x3,y3);
        if((a+b-c)>0 && (a+c-b)>0 && (b+c-a)>0){
            tri_count++;
            if (isObtuse(x1, x2, x3, y1, y2, y3)) {
                obtuse_count++;
            }
        }
    }
    if(tri_count)
        cout << obtuse_count << endl;
    else
        cout << "NA" << endl;
    return 0;
}