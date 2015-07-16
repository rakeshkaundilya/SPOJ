/* 
 * File:   CANTON.cpp
 * Author: rakesh
 *
 * Created on 6 July, 2014, 12:43 AM
 */

#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int point,num=1,den=2,r,constant=3,count=0,val=0;
        
        cin>>point;
    
        for(r=1;r<point-1;r++){
            if(count){
                if(count==1){
                    den++;
                    val=0;
                }
                else if(count==2){
                    num++;
                    val=1;
                }
                count=0;
            }
            else {
                if(val){
                    num--,den++;
                    if(num==1)
                        count=1;
                }
                else{
                    den--,num++;
                    if(den==1)
                        count=2;
                }
            }
        }
        if(point==1)
            num=den=1;
        cout<<"TERM "<<point<<" IS "<<num<<"/"<<den<<endl;
    
    
    }
    
    return 0;
}

