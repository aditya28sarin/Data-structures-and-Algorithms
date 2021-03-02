// URL: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

 int min=salary[0],max=salary[0];
    double sum=0;
    
    for(int i=0;i<salary.size();i++)
    {
        if(salary[i]<min)
            min=salary[i];
        
        else if(salary[i]>max)
            max=salary[i];
        
        sum+=salary[i];
    }
    
    sum-=(min+max);

    return (sum)/(salary.size()-2);
