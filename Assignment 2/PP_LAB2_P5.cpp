#include<iostream>
using namespace std;
template <typename T>
struct Mystack{
    T *arr;
    int n,top;
};
template <typename T>
void init(Mystack<T> *s){
    cout<<"enter capacity of stack \n";
    cin>>s->n;
    s->top=-1;
    s->arr=(T*)malloc(sizeof(T)*s->n);
}
template <typename T>
int isempty(Mystack<T> **s){
    if((*s)->top==-1)
    return 1;
    return 0;
}
template <typename T>
int capacity(Mystack<T> *s){
    return s->n;
}
template <typename T>
int cuurrsize(Mystack<T> *s){
    return s->top+1;
}
template <typename T>
void push(Mystack<T> *s,T x){
    if(s->top<s->n){
    s->top++;
    s->arr[s->top]=x;
    }

}
template <typename T>
void pop(Mystack<T> *s){
    if(!isempty<T>(&s))
    s->top--;
}
template <typename T>
void print(Mystack<T> *s){
    for(int i=s->top;i>=0;i--){
        cout<<s->arr[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    Mystack<int> * s=(Mystack<int>*)malloc(sizeof(Mystack<int>));
    init(s);
    push(s,10);
    push(s,20);
    push(s,30);
    print(s);
    pop(s);
    print(s);
    Mystack<char> * s1=(Mystack <char>*)malloc(sizeof(Mystack<char>));
    init(s1);
    push(s1,'A');
    push(s1,'B');
    push(s1,'C');
    print(s1);
    pop(s1);
    print(s1);
    return 0;
}