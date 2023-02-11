#include<iostream>
using namespace std;

void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int currele = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>currele)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=currele;
    }
}

int main()
{
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter element:";
        cin>>arr[i];
    }
    insertionsort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}