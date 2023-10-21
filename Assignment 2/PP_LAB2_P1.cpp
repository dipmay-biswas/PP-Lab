#include<iostream>
using namespace std;
struct sdata{
string name;
string dept;
int age;
int year;
};
void StudentReadData(sdata * arr,int n){
    cout<<"enter "<<"name "<<"dept "<<"age "<<"year \n";
    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].dept>>arr[i].age>>arr[i].year;
    }
}
void print(sdata *arr,int n){
cout<<"display "<<"name "<<"dept "<<"age "<<"year \n";
            for(int i=0;i<n;i++){
        cout<<arr[i].name<<" "<<arr[i].dept<<" "<<arr[i].age<<" "<<arr[i].year<<"\n";
    }
}
int main(){
    int n;
    cout<<"enter number of students"<<endl;
    cin>>n;
    sdata arr[n];
    StudentReadData(arr,n);
    print(arr,n);
}