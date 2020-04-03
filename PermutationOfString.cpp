#include<iostream>
using namespace std;
void permuatationsOfString(string str,int l,int r)
{
    if(l==r)
    {
        cout<<str<<endl;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(str[i],str[l]);
            permuatationsOfString(str,l+1,r);
            swap(str[i],str[l]);
        }
    }
}
int main()
{
    string str;
    cout<<"Enter the string :\n";
    cin>>str;
    int n=str.size();
    cout<<"\nPermutation of string is:\n";
    permuatationsOfString(str,0,n-1);

}
