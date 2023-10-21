#include<iostream>
using namespace std;
struct Mystack{
    int *arr;
    int n,top;
};
void init(Mystack *s){
    cout<<"enter capacity of stack \n";
    cin>>s->n;
    s->top=-1;
    s->arr=(int *)malloc(sizeof(int)*s->n);
}
int isempty(Mystack **s){
    if((*s)->top==-1)
    return 1;
    return 0;
}
int capacity(Mystack *s){
    return s->n;
}
int cuurrsize(Mystack *s){
    return s->top+1;
}
void push(Mystack *s,int x){
    if(s->top<s->n){

    s->top++;
    s->arr[s->top]=x;
    }

}
void pop(Mystack *s){
    if(!isempty(&s))
    s->top--;
}
void print(Mystack *s){
    for(int i=s->top;i>=0;i--){
        cout<<s->arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    Mystack * s=(Mystack*)malloc(sizeof(Mystack));
    init(s);
    push(s,10);
    push(s,20);
    push(s,30);
    print(s);
    pop(s);
    print(s);
    Mystack * s1=(Mystack*)malloc(sizeof(Mystack));
    init(s1);
    push(s1,30);
    push(s1,20);
    push(s1,10);
    print(s1);
    pop(s1);
    print(s1);
    return 0;
}