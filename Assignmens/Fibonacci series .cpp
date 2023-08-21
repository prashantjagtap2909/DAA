// To calculate fibonacci value of number and count number of steps using Iterative and Recursive method.

#include <bits/stdc++.h> 
using namespace std;

int ItStepFibbonacci(int n){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    
    int cnt = 2;
    for(int i = 2; i < n; i++){
        cnt++;
        v.push_back(v[i - 1] + v[i - 2]);
    }
    return n;
}

int recSteps = 0;

int RecStepFibbonacci(int n){
    recSteps++;
    if(n < 0) return 0;
    if(n == 1 || n == 0) return 1;
    return RecStepFibbonacci(n - 1) + RecStepFibbonacci(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << "Fibbonacci Value : " << RecStepFibbonacci(n) <<endl;
    cout << "Steps required using Iteration : " << ItStepFibbonacci(n) <<endl;
    cout << "Steps required using recursion : " << rSteps <<endl;
    return 0;
}


/*
Recursive fibbonacci:
Time Complexity: O(n*2n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/
