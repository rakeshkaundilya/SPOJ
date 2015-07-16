/* 
 * File:   OLOLO.cpp
 * Author: rakesh
 *
 * Created on 6 December, 2014, 6:30 PM
 */

#include <stdio.h>
using namespace std;

int main() {;
    int npiyani,i;
    unsigned long int total,num;
    scanf("%d",&npiyani);
    for(i=0;i<npiyani;i++){
        scanf("%lu",&num);
        total=total^num;
    }
    printf("%lu\n",total);
    return 0;
}

