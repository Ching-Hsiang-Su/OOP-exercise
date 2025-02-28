#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Get input sequence
    vector<int> nums;
    vector<int> temp1;
    vector<int> temp2;

    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    for(int i = 0;i < n ;i++){
        if(nums[i] > 0){
            temp1.push_back(nums[i]);
        }
    }    

    for(int i = 0;i < n ;i++){
        if(nums[i] < 0){
            temp2.push_back(nums[i]);
        }
    }

    for(int i = 0;i < temp2.size() ;i++){
        temp1.push_back(temp2[i]);
    }

    // Output transformed sequence
    for (int i = 0; i < temp1.size()-1; i++) {
        cout << temp1[i] << " ";
    }
    cout << temp1[temp1.size()-1];
    cout << endl;

    return 0;
}
