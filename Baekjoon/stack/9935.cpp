#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    string str, bomb, result;
    stack<char> s;

    cin >> str >> bomb;

    int bomb_size=bomb.length();
    
    for(char c : str ) {

        s.push(c);
        
        if(s.top()==bomb.back() && s.size() >=bomb_size) {
        string tmp= ""; //임시저장

        for(int i=0; i<bomb_size; i++){
            tmp+=s.top();
            s.pop();
        }

        reverse(tmp.begin(),tmp.end());

        if(tmp!=bomb){
            for(char ch : tmp) {
                s.push(ch);
            }
        }
    }
}

    result="";
    while(!s.empty()){
        result+=s.top();
        s.pop();
    }

    reverse(result.begin(), result.end());

    if(result.empty()) {
        cout<<"FRULA"<<"\n";
    } else{
        cout <<result <<"\n";
    }

    return 0;
}