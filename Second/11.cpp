#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Time {
    private:
        int hour, minute, second;

    public:
        Time() {
            hour = 0;
            minute = 0;
            second = 0;
        }

        Time(int h, int m, int s) { 
            hour = h;
            minute = m;
            second = s;
        }

        void display() { 
            cout << setfill('0') << setw(2) << hour ; cout << ":" ;
            cout << setfill('0') << setw(2) << minute ; cout << ":" ;
            cout << setfill('0') << setw(2) << second << endl;
        }

        Time operator-(const Time& t) {
        Time res; 
        int totalSec1 = (hour) * 3600 + (minute) * 60 + second; 
        int totalSec2 = (t.hour) * 3600 + (t.minute) * 60 + t.second;
        int totalSec = abs(totalSec1 - totalSec2);
        if(totalSec >= 43200)
            totalSec = 86400 - totalSec;
        res.hour = totalSec / 3600; 
        totalSec %= 3600;
        res.minute = totalSec / 60;
        res.second = totalSec % 60;
        return res; 
    }

        bool operator<(Time t) {
            int totalSeconds = hour * 3600 + minute * 60 + second;
            int tTotalSeconds = t.hour * 3600 + t.minute * 60 + t.second; 
            return totalSeconds < tTotalSeconds; 
        }


};

int main() {
    int n;
    cin >> n;

    Time time[n];
    Time minidiff = Time(24,0,0);
    for (int i = 0; i < n; i++) {
        int h, m, s;
        cin >> h >> m >> s;
        time[i] = Time(h, m, s);
    }
    for(int i = 0; i < n;i++){
        for(int j = 1; j < n; j++){
            if(i != j){
                if(time[i]-time[j] < minidiff){
                minidiff = time[i]-time[j];
            }
            }
        }
    }
    minidiff.display();
    return 0;
}