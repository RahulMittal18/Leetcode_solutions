//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{ 
    const static int N  = 1e5+5;
    int isPrime[N];
    
  public:
  Solution()
    {
        
        memset(isPrime, true, sizeof(isPrime));
 
        isPrime[0] = isPrime[1] = false;
     
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
    }

 
    int shortestPath(int Num1,int Num2)
    {   
        string num2 = to_string(Num2);
        queue<string> q;
        int ans = 0;
        // int N = prime.size();
        map<int,int> mp;
        q.push(to_string(Num1));
        mp[Num1]=1;
        while(!q.empty()){
            int n = q.size();
            for(int ii=0;ii<n;ii++){
                string str = q.front();
                q.pop();
                if(str==num2) return ans;
             
                for(int j=0;j<4;j++){
                    for(int k=0;k<10;k++){
                        if(k==0 && j==0) continue;
                        string temp = str;
                        temp[j] = '0'+ k;
                        int numb = stoi(temp);
                        if(!mp[numb] && isPrime[numb]){
                            q.push(temp);
                            mp[numb]=1;
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends