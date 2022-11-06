//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    //Function to get the maximum total value in the knapsack.
    bool static comp(Item p1,Item p2)
    {
        return (double(p1.value)/(double)(p1.weight))>(double(p2.value)/(double)p2.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int w=0;
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(w+arr[i].weight<=W)
            {
                w+=arr[i].weight;
                ans+=arr[i].value;
            }
            else
            {
                double p=(double)arr[i].value/((double)(arr[i].weight));
                int left=W-w;
                p=p*left;
                ans+=p;
                break;
            }
        }
        return (double)ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends