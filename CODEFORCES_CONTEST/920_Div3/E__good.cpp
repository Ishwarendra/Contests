#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void bwin( int p,int q,int x1,int x){
        int movesa=(x1-x)/2;
        int movesb=(x1-x-2)/2;
        if(q>=movesa){
            cout<<"Draw"<<endl;
        }
        else {
            int gapleft=movesa+movesb-2*(q);
        if(gapleft>=p){
            cout<<"Bob"<<endl;
        }
        else{
             cout<<"Draw"<<endl;
        }
   
    }
}
void awin(int p,int q,int x1, int x){
        if(p<(x1-x-1)/2){
                int rem=(x1-x-1)/2-p;
                if(rem>=q-1){
                cout<<"Alice"<<endl;
                }
                else{
                cout<<"Draw"<<endl;
                }

        }
         else{
            cout<<"Draw"<<endl;
        }
}

signed main(){ 
 cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int h;
        cin>>h;
        int w;
        cin>>w;
        int x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        if(x>=x1){ 
            cout<<"Draw"<<endl;
        }
        else{
            if((x1-x)%2==1){
                 if(y==y1){
                    cout<<"Alice"<<endl;
                 }
                 else if(y>y1){
                    if(y-y1==1){
                        cout<<"Alice"<<endl;
                    }
                    else{
                        awin(y1-1,y-y1,x1,x);
                    }
                 }
                 else{
                    if(y1-y==1){
                        cout<<"Alice"<<endl;
                    }
                    else{
                        awin(w-y1,y1-y,x1,x);
                    }
                 }
            }
            else{
                if(y1==y){
                    cout<<"Bob"<<endl;
                }
                else{
                    if(y>y1){
                        bwin(y-y1,w-y,x1,x);
                       }
                       else{
                        bwin(y1-y,y-1,x1,x);

                       }
                }
            }  
        }
    }
}