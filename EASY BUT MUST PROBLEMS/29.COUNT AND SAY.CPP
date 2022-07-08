

 if (n == 1)      return "1";
    if (n == 2)      return "11";
 
  //https://leetcode.com/problems/count-and-say/submissions/

    string str = "11";
    for (int i = 3; i<=n; i++)
    {
        
        str += '$';
        int len = str.length();
 
        int cnt = 1;
        string  tmp = ""; 
 
        // Process previous term to find the next term
        for (int j = 1; j < len; j++)
        {
            // If current character doesn't match
            if (str[j] != str[j-1])
            {
                // Append count of str[j-1] to temp
                tmp += cnt + '0';
 
                // Append str[j-1]
                tmp += str[j-1];
 
                // Reset count
                cnt = 1;
            }
 
            //  If matches, then increment count of matching
            // characters
            else cnt++;
        }
 
        str = tmp;
    }
 
    return str;
