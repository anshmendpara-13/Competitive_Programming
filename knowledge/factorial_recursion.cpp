#include <bits/stdc++.h>

using namespace std;

int fact(int n){
    if (n==1)
    {
        return 1;
    }
    return fact(n-1)*n;
    
}

int main()
{
    int n;
    cin >> n;
    int total = fact(n);
    cout << total <<endl;
    return 0;
}