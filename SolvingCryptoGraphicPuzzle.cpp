#include<iostream>
#include<vector>
using namespace std;
class node
{
public:
    char c;
    int v;
    node()
    {
        c='A';
        v=0;
    }
    node(char c,int v)
    {
        this->c=c;
        this->v=v;
    }
};
bool checkSum(node *ar,int c,string s1,string s2,string s3)
{
    int val1=0,val2=0,val3=0,m=1;
    for(int i=s1.length()-1;i>=0;i--)
    {
        int j;
        char ch=s1[i];
        for(j=0;j<c;j++)
        {
            if(ch==ar[j].c)
            {
                break;
            }
        }
        val1+=m*ar[j].v;
        m*=10;
    }
    m=1;
    for(int i=s2.length()-1;i>=0;i--)
    {
        int j;
        char ch=s2[i];
        for(j=0;j<c;j++)
        {
            if(ar[j].c==ch)
            {
                break;
            }
        }
        val2+=m*ar[j].v;
        m*=10;
    }
    m=1;
    for(int i=s3.length()-1;i>=0;i--)
    {
        int j;
        char ch=s3[i];
        for(j=0;j<c;j++)
        {
            if(ar[j].c==ch)
            {
                break;
            }
        }
        val3+=m*ar[j].v;
        m*=10;
    }
    if(val1+val2==val3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool permutation(int c,node *ar,int n,string s1,string s2,string s3,vector<int> use)
{
    if(n-1==c)
    {
        for(int i=0;i<10;i++)
        {
            if(use[i]==0)
            {
                ar[n].v=i;
                if(checkSum(ar,c,s1,s2,s3))
                {
                    cout<<"Solution is:\n";
                    for(int j=0;j<c;j++)
                    {
                        cout<<" "<<ar[j].c<<" = "<<ar[j].v<<endl;
                    }
                    return true;
                }
            }
        }
        return false;
    }
    for(int i=0;i<10;i++)
    {
        if(use[i]==0)
        {
            ar[n].v=i;
            use[i]=1;
            if(permutation(c,ar,n+1,s1,s2,s3,use))
            {
                return true;
            }
            else
            {
                use[i]=0;
            }
        }
    }
    return false;
}
bool solveCryptographic(string s1,string s2,string s3)
{
    int c=0;
    int l1=s1.length();
    int l2=s2.length();
    int l3=s3.length();
    vector<int> freq(26);
    for(int i=0;i<l1;i++)
    {
        ++freq[s1[i]-'A'];
    }
    for(int i=0;i<l2;i++)
    {
        ++freq[s2[i]-'A'];
    }
    for(int i=0;i<l3;i++)
    {
        ++freq[s3[i]-'A'];
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]>0)
        {
            c++;
        }
    }
    if(c>10)
    {
        cout<<"Invalid strings";
        return false;
    }
    node *ar=new node[c];
    for(int i=0,j=0;i<26;i++)
    {
        if(freq[i]>0)
        {
            ar[j].c=char(i+'A');
            j++;
        }
    }
    vector<int> use(10);
    return permutation(c,ar,0,s1,s2,s3,use);
}
int main()
{
    string s1="SEND";
    string s2="MORE";
    string s3="MONEY";
    if(solveCryptographic(s1,s2,s3)==false)
    {
        cout<<"No solution";
    }
}
