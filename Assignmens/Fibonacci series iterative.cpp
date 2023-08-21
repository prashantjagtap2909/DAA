// To calculate Fibonacci numbers and find its step count using iterative solution.


#include <bits/stdc++.h>
using namespace std;

int Fibonacci(int n){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
  
    int cnt = 2;
    for(int i = 2; i <= n; i++){
        cnt++;
        v.push_back(v[i - 1] + v[i - 2]);
    }
    return v[n];
}

int main(){
    int n;
    cin >> n;
    cout << "Fibonacci Value is : " << Fibonacci(n) << endl;
    cout << "Steps required to calculate are : " << n << endl;
   
    return 0;
}

/*
Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/
