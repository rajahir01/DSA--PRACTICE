#include<bits/stdc++.h>
using namespace std;

/// REPEATING AND MISSING NUMBER
/// IP= 3,1,3 , N=3
/// OP-> R=3,M=2


/// BRUTE METHOD
/// CREATE A FREQUENCY ARRAY OF N+1 SIZE AND COUNT THE FREQUENCY
/// FREQ>1 IS REPEATING AND FREQ=0 IS  MISSING

int RandM_brut(int arr[],int n)   /// TC=SC= O(n)
{
    int hash[n+1]={0};
    for(int i=0;i<n+1;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=0;i<n+1;i++)
    {
        if(hash[arr[i]] > 1){
            cout<<"REPEATING NO->"<<arr[i]<<endl;
        }
        if(hash[arr[i]]==0){
            cout<<"MISSING NO->"<<arr[i]<<endl;
        }
    }
    return 0;
}


int RandM_bet(int arr[], int n)
{
    int miss = 0, repeat = 0;

    for (int i = 0; i < n; ++i)
    {
        if(arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];

        else
            repeat = abs(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if(arr[i] > 0)
            miss = i+1;
    }

    cout<<"Missing: "<<miss<<" Repeating: "<<repeat;
     return 0;

}


// ANOTHER METHOD USING MATHS
/* vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}   */



// MOST OPTIMIZED SOLN


vector < int >Solution::repeatedNumber (const vector < int >&arr) {
    /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}
