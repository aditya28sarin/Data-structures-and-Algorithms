//User function Template for C++
class test: public student
{
    public:
    float marks[5];
    void set_marks(float *arr)
    {
        for(int i=0;i<5;i++)
        {
           marks[i]=arr[i];
        }

    }
};

class result: public test
{
    public:
    int sum=0,avg,i=0;
    void display()
    {
        for( i=0;i<5;i++)
        {
           sum=sum+marks[i];
        }
        avg=sum/i;

          cout<<roll_number<<" "<<sum<<" "<<avg<<endl;
    }
};
