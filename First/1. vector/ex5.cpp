#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n,temp;
    cin >> n;
    vector<int>A;
    vector<int>B;
    for(int i = 0; i<n; i++){
        A.push_back(i+1);
    }
    while(A.size() != 0){
        B.insert(B.begin(),A[0]);
        A.erase(A.begin());
        A.push_back(A[0]); A.erase(A.begin());
        B.push_back(B[0]); B.erase(B.begin());
        }
    for(int i = 0; i < n-1 ; i++){
        cout << B[i] << ",";
    }
    cout << B[B.size()-1] << endl;
}