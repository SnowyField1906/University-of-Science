#include <iostream>
#include <math.h>

using namespace std;

int timSo2(long long n, int p)
{
    int res=0;
    for(long long i=p;i<=n;i*=p)
    {
        res+=n/i;
    }
    return res;
}
int main() {
    long long n;
    int p;
    cin >> n >> p;
    cout << timSo2(n,p);
    return 0;
}