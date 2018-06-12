#include<bits/stdc++.h>
using namespace std;
/*counting sort can be implemented only if
 *the maximum value of the array is less than
 *the size of the array
 */
 /*Time cmplexity: O(n+k) because
  *we are traversing
  *1) array aux[k] which takes O(k) time
  *2) array  a[n] and the sortedA[n] which takes O(n) time
 */
 /*Space cmplexity: O(n+k) because
  *we are taking two arrays
  *1) array aux[k] to store frequncy
  *2) array sortedA[n] to store sorted array
 */
void counting_sort(int n,int a[],int aux[],int sortedA[])
{

    /*in counting sort we have to count the frequency of each
     *number and store it in the array aux[] that has the size of the
     *maximum value of the array a[]
    */
    int k = 0;

    // First, find the maximum value in a[]
    for(int i=0;i<n;i++)
    {
        k = max(k,a[i]);
    }

    // Initialize the elements of aux[] with 0
    memset(aux,0,sizeof(aux));

    /* Store the frequencies of each distinct element of a[],
     *by mapping its value as the index of aux[] array
     */
    for(int i=0; i<n; i++) {
        aux[a[i]]++;
    }

    int j = 0;
    for(int i=0; i<=k; i++) {
        int tmp = aux[i];
        /* aux stores which element occurs how many times,
         *Add i in sortedA[] according to the number of times i occurred in a[]
         */
        while(tmp--) {

            sortedA[j] = i;
            j++;
        }
    }
    for(int i=0;i<j;i++)
    {
        cout<<sortedA[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,i,j;
    cin>>n;
    int a[100005],aux[100005],sortedA[100005];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

     counting_sort(n,a,aux,sortedA);


}
