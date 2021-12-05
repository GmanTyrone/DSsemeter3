#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;


map<char,char> brackets={{'(',')'},
                         {'{','}'},
                         {'[',']'}};

string isbalanced(string s)
{
    stack<char>signos;
    for(int i=0;i<s.length();i++){
        if(s[i]!='{'&&s[i]!='}'&&s[i]!='('&&s[i]!=')'&&s[i]!='['&&s[i]!=']')continue;
        if(s[i]=='{'||s[i]=='('||s[i]=='[')signos.push(s[i]);
        else if(!signos.empty()&&brackets[signos.top()]==s[i])signos.pop();
        else return "badly nested";
    }

    if(signos.empty())return "balanced";
    else return "unbalanced";
}


int main(void)
{
    string ej1="{12{1(23}}))[]";//badly nested
    string ej2="123(34){34[54]}";//balanced
    string ej3="123(34){34[54]}{";//unbalanced

    cout<<isbalanced(ej1)<<endl;
    cout<<isbalanced(ej2)<<endl;
    cout<<isbalanced(ej3)<<endl;

    return 0;
}
