/* 
 * File:   PALIN.cpp
 * Author: rakesh
 *
 * Created on 4 July, 2014, 3:01 PM
 */

#include <iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
int *num;
int r,z=0;
int increase(){
    int sub;
      for (sub = r/2; sub < r; sub++) {
                if (num[sub] >= 10) {
                     
                    num[sub]=0;
                    num[sub + 1]++;
                    //cout<<num[r]<<endl;
                    if(sub==r-1){
                              z=1;          
                    }
                }
                else break;
            }


}
int palin() {
    int q,m;
    for(q=0;q<r/2;q++){
        if(num[r/2-1-q]>=num[(r+1)/2+q]){
            if((num[r/2-1-q]>num[(r+1)/2+q])||(q==r/2-1)){
            num[r/2]++;
            break;}
        }
        else
            break;
    }
    increase();
     if(z)
            r++;
    for(q=0;q<r/2;q++){
       
        num[r/2-1-q]=num[(r+1)/2+q];
    }
    
}
    int main() {
        int t;
        cin >> t;
        while (t--) {
            getchar();
            int inc=0, sub, m, q, a;
            num = new int[1000001];
            string c;
            cin>>c;
            z=0;
            r = c.size();
            
            for (q = r - 1, a = 0; q >= 0; q--, a++) {
                num[a] = c[q] - 48;
            }
            if(r==1)
                num[0]++;

            palin();

            
        for (m = r-1 ; m >= 0; m--) {
           
            cout << num[m];
            
        }
        cout << endl;
        /*
            for(inc=1;inc;inc++){
             
                if(palin(r)){
                    for(m=r-1;m>=0;m--){
                cout<<num[m];
             
                    }
                cout<<endl;
                break;}
                    else
                        continue;
                
            
            }
         */
    }

    return 0;
}