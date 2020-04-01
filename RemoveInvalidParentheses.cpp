#include<bits/stdc++.h>
using namespace std;
bool isParenthesis(char c)
{
    return (c=='(' || c==')');
}
bool isValidString(string str)
{
    int cnt=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            cnt++;
        }
        else if(str[i]==')')
        {
            cnt--;
        }
        if(cnt<0)
        {
            return false;
        }
    }
    return (cnt==0);
}
void removeInvalidParenthesis(string str)
{
    if(!str.empty())
    {
        set<string> visit;
        queue<string> q;
        string temp;
        bool level;
        q.push(str);
        visit.insert(str);
        while(!q.empty())
        {
            str=q.front();
            q.pop();
            if(isValidString(str))
            {
                cout<<str<<endl;
                level=true;
            }
            if(!level)
            {
                for(int i=0;i<str.length();i++)
                {
                    if(isParenthesis(str[i]))
                    {
                       temp=str.substr(0,i) +str.substr(i+1);
                       if(visit.find(temp)==visit.end())
                       {
                           q.push(temp);
                           visit.insert(temp);
                       }
                    }
                }
            }
        }

    }
}
int main()
{
    cout<<"Enter the expression:"<<endl;
    string str;
    cin>>str;
    removeInvalidParenthesis(str);
}
