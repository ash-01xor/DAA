#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r)
{
    // size of the temporary array's
    int n1 = mid-l+1; 
    int n2 = r-mid;

    // temp arrays which store the right and the left halves
    int a[n1];
    int b[n2];  

    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) // compares a and b
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1) // compares remaining elements in arr1
    {
        arr[k]=a[i];
        k++;
        i++;   
    }
    while(j<n2) // compares the elements in arr2
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesort(arr,l,mid); // from left till mid
        mergesort(arr,mid+1,r); // from mid till right
        merge(arr,l,mid,r); // merge both left and right halves
    }
}

int main()
{
    int arr[]={5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n - 1);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}