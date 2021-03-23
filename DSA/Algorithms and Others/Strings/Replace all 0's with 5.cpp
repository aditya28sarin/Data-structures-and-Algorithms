int convertFive(int n)
{
int number=0,i=0;
while(n!=0)
{
   int x=n%10;

   if(x==0)
   {
       x=5;
       number=number+pow(10,i)*x;
   }
   else
   {
       number=number+pow(10,i)*x;
   }
   n=n/10;
   i++;
}
return number;
}
