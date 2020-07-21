#include<iostream>
using namespace std;
int n,k,arr[200000],le,ri,x;
int mid;
bool check()
{
    //cout<<arr[mid]<<endl;
    if(x>arr[mid])
        return true;
    return false;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    // for(int i=0;i<n;i++)
    //     cout<<arr[i];
    for(int i=0;i<k;i++)
    {
        cin>>x;
        ri=n-1;
        le=0;
        while(le<=ri)
        {
            mid=(ri+le)/2;
            if(arr[mid]==x)
                break;
            if(check())
            {
                le=mid+1;
            }
            else
            {
                ri=mid-1;
            }
            //cout<<"mid="<<mid<<endl;
        }
        //cout<<"----------------------\n";
        //cout<<"mid="<<mid<<endl;
        if(arr[mid]!=x)
            cout<<0<<endl;
        else
            cout<<mid+1<<endl;
    }

    //system("PAUSE");
    return 0;
}
