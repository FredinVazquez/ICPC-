#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main()
    {
        int n,x; 
        cin>>n>>x;
        vector<int> v;
        unordered_set<int> s;
        int number;
        int ans =0 ;
        for(int i=0;i<n;i++)
            {
                cin>>number;

                for(int j=1;j*number<=x;j++)
                    {
                        if(s.find(j*number)==s.end()){
                            ans++;
                            s.insert(j*number);
                        } 
                            
                    }

            }
        cout<<ans<<endl;
        return 0;
    }
