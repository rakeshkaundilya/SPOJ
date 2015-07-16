/* 
 * File:   STAMPS.cpp
 * Author: rakesh
 *
 * Created on 17 July, 2014, 1:51 PM
 */

#include <iostream>
#include<algorithm>
using namespace std;

int main() {

    int r,scn,stamp,frnd,a;
    cin>>r;
    for(scn=1;scn<=r;scn++){
        cin>>stamp>>frnd;
        int num[frnd],p,sum=0;
        a=0;
        for(p=0;p<frnd;p++)
            cin>>num[p];
        sort(num,num+frnd);
        for(p=frnd-1;p>=0;p--){
            sum=sum+num[p];
            if(sum>=stamp){
                a=1;
                break;
            }
        }
        if(a){
            cout<<"Scenario #"<<scn<<":"<<endl<<(frnd-p)<<endl<<"\n";
        }
        else
          cout<<"Scenario #"<<scn<<":"<<endl<<"impossible"<<endl<<"\n";
           
    }
    
    return 0;
}

