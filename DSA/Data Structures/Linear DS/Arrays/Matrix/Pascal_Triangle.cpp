int main()
 {
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int a[n][n];
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<=i;j++)
           {
               if(j==0||j==i)
               a[i][j]=1;
               else 
               a[i][j]=a[i-1][j-1]+a[i-1][j];
           }
       }
       for(int i=0;i<n;i++)
       cout<<a[n-1][i]<<" ";
       cout<<endl;
    
   }
}