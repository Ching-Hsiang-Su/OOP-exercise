#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    Triangle() {
        a = b = c = 0;
    }
    Triangle(double sideA, double sideB, double sideC) {
        a = sideA;
        b = sideB;
        c = sideC;
    }
    ~Triangle() {
        cout << "destroy" << endl;
    }

    double getArea() {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    Triangle t2(6,6,6);
    int a,b,c;
    cin >> a >> b >> c;
    Triangle t1(a,b,c);

    double area1 = t1.getArea();
    double area2 = t2.getArea();

    if (area1 > area2) {
        cout << "first" << endl;
    } else if (area2 > area1) {
        cout << "second" << endl;
    } else {
        cout << "equal" << endl;
    }

    return 0;
}
