//转化逆波兰表达式
#include <iostream>
#include <stack>
using namespace std;
stack<char> stk;
int opPri(char s){
    switch(s){
    case '+':case '-':return 2;
    case '*':case '/':case '%':return 3;
    case '(':return 1;
    case ')':return 4;
    default:return 0;
    }
}
int main(){
    char s;
    while(s=getchar(),s!='\n'){
        if(!opPri(s)){
            printf("%c",s);
        }
        else if(stk.size()==0){
            stk.push(s);
        }
        else if(s==')'){
            while(s=stk.top(),stk.pop(),s!='('){
                printf("%c",s);
            }
        }
        else if(opPri(s)>opPri(stk.top())||s=='('){
            stk.push(s);
        }
        else{
            while(opPri(s)<=opPri(stk.top())){
                printf("%c",stk.top());
                stk.pop();
                if(!stk.size()) break;
            }
            stk.push(s);
        }
    }
    while(stk.size()){
        printf("%c",stk.top());
        stk.pop();
    }
    return 0;
}
