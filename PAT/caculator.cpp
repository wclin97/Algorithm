#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node{
    double num;
    char op;
    bool flag;  // true表示操作数FALSE表示操作符
};
string str;
stack<node> s;
queue<node> q;
map<char,int> op;

void Change(){    //中缀表达式转后缀表达式
    //double num;
    node temp;
    for(int i = 0; i < str.length();){
        if(str[i] >='0' && str[i] <= '9'){
            temp.flag = true;
            temp.num = str[i++] - '0';          //记录操作数的最高位数位
            while(i < str.length() && str[i] >='0' && str[i] <= '9'){
                temp.num =  temp.num * 10 + (str[i] - '0');     //  更新这个操作数的每一位直到不再遇到数字
                i++;
            }
            q.push(temp);
        }else{
            temp.flag = false;        //如果遇到操作符
                                        //操作数优先级高入栈，否则出栈加入队列 直到 下一个栈顶比它高级
            while(!s.empty() && op[str[i] <= op[s.top().op]]){   //  使用map建立加减乘除和1，0 的映射，用来表示优先级
                q.push(s.top());        //队列为后缀表达式 ，栈为操作符栈
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){       //若操作符栈还有op，全部弹出至后缀表达式队列
        q.push(s.top());
        s.pop();
    }
}

double cal(){        //计算后缀表达式
    double temp1, temp2;
    node cur,temp;
    while(!q.empty()){
        cur = q.front();
        q.pop();   
        if(cur.flag == true) s.push(cur);
        else{
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op =='+') temp.num = temp1 + temp2;
            if(cur.op =='-') temp.num = temp1 - temp2;
            if(cur.op =='*') temp.num = temp1 * temp2;
            if(cur.op =='/') temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num;     //返回栈顶元素，是最后的结果
}
int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin, str), str != "0"){
        for(string::iterator it = str.end(); it != str.begin(); it--){
            if(*it == ' ') str.erase(it);    //去掉字符串中空格
        }
        while(!s.empty()) s.pop();
        Change();
        printf("%.2f\n",cal());
    }
    return 0;
}