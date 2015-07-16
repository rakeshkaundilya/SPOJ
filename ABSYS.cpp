/* 
 * File:   ABSYS.cpp
 * Author: rakesh
 *
 * Created on 6 July, 2014, 1:51 AM
 */

#include <iostream>
#include<string>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int size1,size2,size3,r,spot,num[3]={0};
        string first,sign1,second,sign2,third;
        
        cin>>first>>sign1>>second>>sign2>>third;
     
        size1=first.size();
        size2=second.size();
        size3=third.size();
        
        for(r=0;r<size1;r++){
            if(first[r]>62){
                spot=0;
                break;
            }
            num[0]=10*num[0]+first[r]-48;
        }
        for(r=0;r<size2;r++){
            if(second[r]>62){
                spot=1;
                break;
            }
             num[1]=10*num[1]+second[r]-48;

        }
        for(r=0;r<size3;r++){
            if(third[r]>62){
                spot=2;
                break;
            }
             num[2]=10*num[2]+third[r]-48;
        }
        
        if(!spot)
            num[0]=num[2]-num[1];
        if(spot==1)
             num[1]=num[2]-num[0];
        if(spot==2)
            num[2]=num[0]+num[1];
       
         cout<<num[0]<<" "<<sign1<<" "<<num[1]<<" "<<sign2<<" "<<num[2]<<endl;   
        
        
        }
    return 0;
}

