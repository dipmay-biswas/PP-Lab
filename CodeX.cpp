#include<iostream>
using namespace std;

int main(){
int a1,a2,a3;
cin>>a1>>a2>>a3;

if((a1+a2) % 2==0 && a1+a2>0){
    cout<< "YES" << endl;
}
else if((a2+a3) % 2==0 && a2+a3>0){
    cout<< "YES" << endl;
}
else if((a1+a3) % 2==0 && a1+a3>0){
    cout<< "YES" << endl;
}
else{
    cout << "NO" << endl;
}
return 0;
}