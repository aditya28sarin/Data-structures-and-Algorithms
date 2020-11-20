
//User function Template for C++

// Function to perform bitwise manipulations
// a, b and c are input integers
void bitWiseOperation(int a, int b, int c){

    int d=a^a;
    int e=c^b;

     cout<<d<<endl;
     cout<<e<<endl;
     cout<<(a&b)<<endl;
     cout<<(c | (a^a))<<endl;
     cout<<~e<<endl;
