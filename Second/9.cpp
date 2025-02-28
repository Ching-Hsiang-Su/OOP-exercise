#include<iostream>
#include <iomanip>
using namespace std;

class Time {
    private:
        int hour, minute, second;

    public:
        Time() { // 沒有傳入引數的建構子，時間設為0
            hour = 0;
            minute = 0;
            second = 0;
        }

        Time(int h, int m, int s) { // 有傳入引數的建構子，初始化時間
            hour = h;
            minute = m;
            second = s;
        }

        void display() { // 顯示時間 << setfill('0') << setw(2)
            cout << setfill('0') << setw(2) << hour ; cout << ":" ;
            cout << setfill('0') << setw(2) << minute ; cout << ":" ;
            cout << setfill('0') << setw(2) << second << endl;
        }

        Time operator/(int div) { // 複寫 "/" 運算子
            Time t;
            int totalsec = hour * 3600 + minute * 60 + second; // 將時間轉換為總秒數
            totalsec /= div; // 總秒數除以div
            t.hour = totalsec / 3600; // 計算小時數
            totalsec %= 3600;
            t.minute = totalsec / 60; // 計算分鐘數
            t.second = totalsec % 60; // 計算秒數
            return t; // 回傳計算後的時間
        }
};

int main() {
    int h, m, s, n;
    cin >> n;
    cin >> h >> m >> s;
    Time t1(h, m, s); // 創建時間t1
    
    for(int i = 0; i < n; i++) { // 進行n次操作
        Time t2 = t1 / 3; // 計算原本時間的三分之一
        t2.display(); // 顯示計算後的時間
        t1 = t2; // 將計算後的時間設為新的時間
    }
    return 0;
}