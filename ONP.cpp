/* 
 * File:   ONP.cpp
 * Author: rakesh
 *
 * Created on 15 December, 2014, 12:58 PM
 */

#include <iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> data;
int main() {
    int test,i,z;
    char var;
    string input,output;
    cin>>test;
    while(test--){
        output="";
        cin>>input;
        z=input.size();
        for(i=0;i<z;i++){
            var=input[i];
            if(var>='a' && var <='z')
                output=output+var;
            else if(var=='+'||var== '-'|| var== '*'||var== '/'||var== '^' )
                data.push(var);
            else if(var==')'){
                output=output+data.top();
                data.pop();
            }
        }
        cout<<output<<endl;
        
    }
    return 0;
}

