// Assignment 3 - Implement job sequencing with deadlines using a greedy method


#include<bits/stdc++.h>
using namespace std; 


struct Job 
{ 
    int id;	
    int dead; 
    int profit; 
}; 

class Solution 
{
    public:
   
    bool static comp(Job a, Job b){
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comp);
        int maxi=arr[0].dead;
        for(int i=1; i<n; i++){
            maxi=max(maxi, arr[i].dead);
        }
        vector<int>slots(maxi+1, -1);
        int cnt=0, tot_profit=0;
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){
                if(slots[j]==-1){
                    slots[j]=arr[i].dead;
                    cnt++;
                    tot_profit+=arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, tot_profit};
    } 
};


int main() 
{ 
    
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

}


// Time complexity - O(nlogn)
