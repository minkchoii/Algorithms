#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    string str, bomb, result;
    stack<char> s;

    cin >> str >> bomb; //전체문자열, 폭발문자열 입력받아

    int bomb_size=bomb.length(); //폭발문자열길이구해
    
    for(char c : str ) {

        s.push(c); //일단 스택에 넣어
        
        if(s.top()==bomb.back() && s.size() >=bomb_size) {  //폭발문자열 끝부분이 방금넣은 값과 같고 전체스택사이즈가 폭발문자열보다 길 때 검사해
        string tmp= ""; //임시저장

        for(int i=0; i<bomb_size; i++){
            tmp+=s.top();
            s.pop();  //임시문자열로 일단 꺼내
        }

        reverse(tmp.begin(),tmp.end()); //반대로 꺼내지니까 다시정렬해

        if(tmp!=bomb){
            for(char ch : tmp) {
                s.push(ch);  //폭발문자열이랑 다른거 확인 시 다시 넣어줌
            }
        }
    }
}

    result=""; 
    while(!s.empty()){
        result+=s.top();
        s.pop();  //결과문자열꺼내줌
    }

    reverse(result.begin(), result.end()); //정렬

    if(result.empty()) {
        cout<<"FRULA"<<"\n";
    } else{
        cout <<result <<"\n";
    }

    return 0;
}