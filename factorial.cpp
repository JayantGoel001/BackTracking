#include <iostream>
#define int long long int
using namespace std;
int factorial(int n){
    if (n==1){
        return 1;
    }
    return n * factorial(n-1);
}
int32_t main(){
    cout<<"Enter The Value of n:";
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<factorial(n)<<"\n";
}