#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Ball{
    private:
        int two,twos,three,threes,penalty,penaltys;

    public:
        Ball(){
            two = 0;
            twos = 0;
            three = 0;
            threes = 0;
            penalty = 0;
            penaltys = 0;
        }
        Ball(int t,int ts,int th,int ths,int p,int ps){
            two = t;
            twos = ts;
            three = th;
            threes = ths;
            penalty = p;
            penaltys = ps;
        }

        void accuracy(){

            double a1 = (twos+threes+penaltys), b1 = (two+three+penalty);
            a1 = a1/b1;
            a1 = round(a1 * 10000) / 100;
            cout << fixed << setprecision(2)<< a1 << endl;
        }

        bool operator<(Ball b){
            int points1 = twos*2+ threes*3 + penaltys;
            int points2 = b.twos*2+ b.threes*3 + b.penaltys;
            return points1<points2;
        }
};

int main(){

    int n ;
    cin >> n;
    Ball b[n];
    int maxindex = n;

    for(int i = 0; i < n; i++){
        int t,ts,th,ths,p,ps;
        cin >> t >> ts >> th >> ths >> p >> ps;
        b[i] = Ball(t,ts,th,ths,p,ps);
        if(b[maxindex]<b[i]){
            maxindex = i;
        }
    }
    Ball maxpoint = b[maxindex];
    maxindex++;
    maxpoint.accuracy();
    return 0;
}