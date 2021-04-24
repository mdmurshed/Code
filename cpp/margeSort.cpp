#include<bits/stdc++.h>
using namespace std;


vector <int> v1;
int test = 1;

void marge(int arr[],int n,int m)
{

    cout <<n << " " << m << endl;
    int i,j;
    int dif = (m+n);
    int mid = dif/2;
    cout << n << " " << mid << " : " << mid+1 << " " << m << endl;
    //cout <<"start: " << endl;
    for(i=n,j=mid+1; i<=mid&& j<=m;)
    {
        if(arr[i]<=arr[j])
        {
           // cout << " i1 : " << arr[i] ;
            v1.push_back(arr[i]);
            i++;
        }
        else
        {
            //cout << " j1 : " << arr[j] ;
            v1.push_back(arr[j]);
            j++;
        }
    }
    if(i<=mid)
    {
        for(; i<=mid;)
        {
            //cout << " i2 : " << arr[i] ;
            v1.push_back(arr[i]);
            i++;
        }
    }
    if(j<=m)
    {
        for(; j<=m;)
        {
           // cout << " j2 : " << arr[j] ;
            v1.push_back(arr[j]);
            j++;
        }
    }
    cout << "line : ";
    for(int x=n,xx=0; x<=m; x++,xx++)
    {
        arr[x] = v1[xx];
        cout << arr[x] << " ";
    }
    cout << endl;
    v1.clear();

}


void margeSort(int arr[],int n,int m)
{
    int mid = (n+m)/2;
    int i=1;
    if(n==m)
        return;
    margeSort(arr,n,mid);
    margeSort(arr,mid+1,m);
    cout << "n = " << n << " , m = "<< m << endl;
    // int dif = m+n;
    // int mi= dif/2;
    //  cout << n << " " << mi << " : " << mi+1 << " " << m << endl;
    marge(arr,n,m);

}




int main()
{
    // one index forward
    int arr[] = {0,3,1,6,2,8,2,5,9};
    for(int i=1; i<=8; i++)
        cout << arr[i] << " ";
    cout << endl;
    margeSort(arr,1,8);
    for(int i=1; i<=8; i++)
        cout << arr[i] << " ";
}

