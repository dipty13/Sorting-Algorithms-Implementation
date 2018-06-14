#include<bits/stdc++.h>
using namespace std;
int arr[10005];
void countsort(int n,int place)
{
    int range = 10;
    int i,freq[range]= {0};        //range for integers is 10 as digits range from 0-9
    int output[n];
    for(i=0; i<n; i++)
    {
        freq[(arr[i]/place)%range]++;
    }
    for(i=1; i<range; i++)
    {
        freq[i]+=freq[i-1];
    }
    for(i=n-1; i>=0; i--)
    {
        output[freq[(arr[i]/place)%range]-1]=arr[i];
        freq[(arr[i]/place)%range]--;
    }
    for(i=0; i<n; i++)
    {
        arr[i]=output[i];
    }
}
void radixsort(int n,int maxx)            //maxx is the maximum element in the array
{
    int mul=1;
    while(maxx)
    {
        countsort(n,mul);
        mul*=10;
        maxx/=10;
    }
}
int main()
{
    int n,i,mx=-1;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        mx = max(mx,arr[i]);
    }
    radixsort(n,mx);
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
