#include<iostream>

using namespace std;

int main()
    {
        int n,m; cin>>n>>m;
        
        int ans =0;
        
        while(true)
            {
                n-=m;
                ans++;
                if(n<=0){
                    cout<<ans;
                    break;
                } 
            }
        
        return 0;
    }
