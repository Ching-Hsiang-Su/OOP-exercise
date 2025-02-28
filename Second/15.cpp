#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int marks[5];

public:
    Student(){
        name = "";
        marks[0] = 0;
        marks[1] = 0;
        marks[2] = 0;
        marks[3] = 0;
        marks[4] = 0;
    }
    Student(string n, int m1, int m2, int m3, int m4, int m5) {
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        marks[3] = m4;
        marks[4] = m5;
    }

    double average() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return (double)sum / 5;
    }

    string getName() {
        return name;
    }
};

int main() {
    int n;
    cin >> n;
    Student studs[n];
    for (int i = 0; i < n; i++) {
        string name;
        int m1, m2, m3, m4, m5;
        cin >> name >> m1 >> m2 >> m3 >> m4 >> m5;
        studs[i] = Student(name, m1, m2, m3, m4, m5);
    }

    int scholarshipCount = 0;
    double bestAverage = 0;
    string bestName;
    for (int i = 0; i < n; i++) {
        double avg = studs[i].average();
        if (avg > 9) {
            scholarshipCount++;
        }
        if (avg > bestAverage) {
            bestAverage = avg;
            bestName = studs[i].getName();
        }
    }

    cout << scholarshipCount << endl;
    cout << bestName << endl;

    return 0;
}