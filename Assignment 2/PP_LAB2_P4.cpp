#include <iostream>
using namespace std;

template <typename T>
void sortArray(T a[], int n) 
{    
    // boolean variable to check that  
    // whether it is sorted or not 
    bool b = true; 
    while (b) { 
        b = false; 
        for (size_t i=0; i<n-1; i++) { 
  
            // swapping the variable 
            // for sorting order 
            if (a[i] > a[i + 1]) { 
                T temp = a[i]; 
                a[i] = a[i + 1]; 
                a[i + 1] = temp; 
                b = true; 
            } 
        } 
    } 
}
template <typename T>
void printArray(T a[], int n) 
{ 
    for (size_t i = 0; i < n; ++i)  
        cout << a[i] << "   ";     
    cout << endl; 
}
int main(){
    int arr[]={1,3,2,4};
    sortArray(arr,4);
    printArray(arr,4);
}