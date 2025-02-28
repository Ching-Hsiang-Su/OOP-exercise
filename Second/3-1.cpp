#include <iostream>
#include <cmath>

using namespace std;

double calculate_area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}

int main() {
    int n;
    cin >> n;
    double a, b, c, area, total_area = 0.0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        area = calculate_area(a, b, c);
        total_area += area;
    }
    cout << fixed;
    cout.precision(2);
    cout << total_area << endl;

    return 0;
}
