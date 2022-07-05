#include<bits/stdc++.h>
using namespace std;
  /// BRUTE METHOD
 /// FIND DUPLICATES ASSUMING THERE IS ONLY ONE DUPLICATE

 int duplicateBRUT(int arr[],int n)   /// T.C. -> O(nlogn)
 {                                    /// S.C. -> O(1)
     sort(arr,arr+n);
     for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1] && i<n){
            cout<<"DUPLICATE IS->"<<arr[i]<<endl;
        }
     }
     return 0;

 }


 /// BETTER METHOD- HASHING
 int duplicateBET(int arr[], int n)   /// T.C. = S.C. = O(n)
 {
     int hash[n]={0};  /// creating a hash frequency array
     for(int i=0;i<n;i++)
     {
         hash[arr[i]]++;  /// frequency count
     }
     for(int i=0;i<n;i++){
         if(hash[arr[i]] > 1)   /// CHECK WHERE IS COUNT >2 THAT WILL BE OUR DUPLICATE
         {
             cout<<"DUPLICATE IS ->"<<arr[i]<<endl;
         }
     }
     return 0;
 }
  /// OPTIMAL METHOD
  /// LL CYCLE METHOD
  /// TORTOISE METHOD
int duplicateOPT(int arr[], int n)
{
    int slow=arr[0];  /// ONE STEP
    int fast=arr[0];  /// TWO STEP

    do{
        slow=arr[slow]; ///one step
        fast=arr[arr[fast]]; /// two step
    }while(slow!=fast);

    fast=arr[0];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }
    cout<<"DUPLICATE IS ->"<<slow<<endl;
    return slow;

}

int  main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"1-> BRUTE\n 2->BETTER\n 3->OPTIMAL\n"<<endl;
    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        duplicateBRUT(arr,n);

    case 2:
        duplicateBET(arr,n);
    case 3:
        duplicateOPT(arr,n);
    }
    return 0;
}
