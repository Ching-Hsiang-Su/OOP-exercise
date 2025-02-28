#include<iostream>

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
        bool operator<(Ball b){
            int points1 = twos*2 - (two-twos) + threes*3 - (three-threes) + penaltys - (penalty-penaltys);
            int points2 = b.twos*2 - (b.two-b.twos) + b.threes*3 - (b.three-b.threes) + b.penaltys - (b.penalty-b.penaltys);
            return points1 < points2;
        }
};

int main(){

    int n ;
    cin >> n;
    Ball b[n];
    int maxindex = 0;

    for(int i = 0; i < n; i++){
        int t,ts,th,ths,p,ps;
        cin >> t >> ts >> th >> ths >> p >> ps;
        b[i] = Ball(t,ts,th,ths,p,ps);
    }
    for(int i = 0; i < n; i++){
        if(b[maxindex]<b[i]){
            maxindex = i;
        }

    }
    cout << maxindex+1 << endl;
    return 0;
}