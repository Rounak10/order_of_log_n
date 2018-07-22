#include<bits/stdc++.h>
using namespace std;

bool isValid(char ch){
    return (isdigit(ch) && ch > '0');
}
int decode_ways(string s, int index, int solution[]){

    if(index < 0)
        return 1;
    if(!isValid(s[index]))
        return 0;
    if(solution[index] != -1)
        return solution[index];

    int answer = 0;
    answer += decode_ways(s,index-1,solution);

    if(index-1 >=0 && (isdigit(s[index])&& (s[index - 1] - '0')*10 + s[index] - '0') <= 26)
        answer += decode_ways(s,index-1,solution);

    return solution[index] = answer;
}
int main()
{

    int solution[101];
    string str = "1234";
    memset(solution, -1, str.length()*sizeof(int));
    if(str.length() == 0)
        return 0;
    cout<<decode_ways(str,str.length()-1,solution);

}
