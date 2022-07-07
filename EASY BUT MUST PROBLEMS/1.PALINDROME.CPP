// CHECK IF THE NUMBER IS PALINDROME OF NOT
int number;
int temp=number;
int rev=0;
while(temp!=0)
{
  int r=temp%10;
  rev=rev*10+r;
  temp=temp/10;
}
if(temp==rev)
{
return true;
}




// CHECK IF THE STRING IS PALINDROME OR NOT

//METHOD -1  REVERSE THE ORIGINAL STRING AND COMPARE
string s;
string r=s;
reverse(r.begin(), r.end());
if(s==r){
return yes;
}
//TC- O(N)
//SC- O(N)

// METHOD -2
// DIVIDE THE STRING INTO MID AND COMPARE EACH CHAR FROM LOW-MID TO MID-HIGH
// IF ALL SAME TRUE ELSE FALSE
string orig;
for(int i;i<orig.length()/2;i++)
{
  if(orig[i] == orig[orig.length()-i-1])
  {
    return true;
  }
}
