/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on August 20, 2014, 2:45 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
void prntAry(int *,int,int);
void markSrt(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the Random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and allocate the array
    int size=100;
    int *array=fillAry(size);
    //Display the random array
    prntAry(array,size,10);
    //Sort the array
    markSrt(array,size);
    //Display Array
    prntAry(array,size,10);
    //Deallocate Memory
    delete []array;
    return 0;
}
//Fill Array
//Inputs
//     n->Size of the Array
//Outputs
//     a->Array filled with 2 digit integers
int *fillAry(int n){
    //Declare and allocate memory
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    return a;
}
//                      Print Array
//Inputs
//     n->Size of the Array
//     a->Array
//     perLine->Number of integers to display per row
void prntAry(int *a,int n,int perLine){
    //Output the Array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
               *(a+pos)=*(a+pos)^*(a+row);
               a[row]=a[pos]^a[row];
               *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}