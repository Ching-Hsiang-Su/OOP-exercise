#include <iostream>

using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle() {
        width = 0.0;
        height = 0.0;
    }
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double getArea() {
        return width * height;
    }
    double getPerimeter() {
        return 2 * (width + height);
    }
};

int main() {
    Rectangle rect1(6, 9);
    int choice,a,b;
    cin >> choice >> a >> b;
    Rectangle rect2(a, b);
    if (choice == 1){
        double totalArea = rect1.getArea() + rect2.getArea();
        cout << totalArea << endl;
    }
    else if (choice == 2){
        double totalPerimeter = rect1.getPerimeter() + rect2.getPerimeter();
        cout << totalPerimeter << endl;
    }
    return 0;
}
