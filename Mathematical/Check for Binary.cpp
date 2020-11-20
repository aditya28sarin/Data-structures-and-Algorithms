// Return true if str is binary, else false
bool isBinary(string str)
{
  int count=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='0' || str[i]=='1')
        {
            count++;
        }
    }

    if(count==str.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}
