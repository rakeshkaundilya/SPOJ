/* 
 * File:   BYTESM2.cpp
 * Author: root
 *
 * Created on 5 September, 2014, 9:38 PM
 */

#include <iostream>
using namespace std;
int *data,*stone,rows,cols;


int phil(int i, int j) {
    int m = 101 * i + j;
    
    if(i==rows-1){
        return stone[101*i+j];
    }
    else if(j==cols-1){
        return data[m]=stone[101*i+j]+max(phil(i+1,j-1),phil(i+1,j));
    }
    else if(j==0){
        return data[m]=stone[101*i+j]+max(phil(i+1,j+1),phil(i+1,j));
    }
    else if (data[m]){
        return data[m];
    }
    else{
        return data[m] = stone[101*i+j] + max(max(phil(i + 1, j), phil(i + 1, j - 1)), phil(i + 1, j + 1));
    }
};

int main() {
    int test,total,i,j;
    cin>>test;
    while (test--) {
        total=0;
        cin >> rows>>cols;
        data = new int[101*rows+cols];
        total=0;
        stone = new int[101*rows+cols];
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++)
                cin >> stone[101*i+j];
        }
        for(i=0;i<cols;i++)
            total=max(phil(0,i),total);
        cout<<total<<endl;
    }
    return 0;
}

