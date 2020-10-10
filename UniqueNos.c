#include<stdio.h>
int uniqueDigitsHash(int num)// 6
{// 23432%10 = 2
    int hash[10]={0};
    while(num)
    {
        if(hash[num%10]==1)
            return 0;
        hash[num%10]++;
        num/=10;
    }
    return 1;
}   
int main()
{
    int t,start,end;
    scanf("%d",&t);
    int arr[100001];
    arr[0]=1;
    for(int i=1;i<100001;i++) // 10^5*6 < 10^6   10^5 * 10 = 10^6
    {
        if(uniqueDigitsHash(i)==1)
        {
            arr[i] = arr[i-1]+1;
        }
        else
        {
            arr[i] = arr[i-1];
        }
        
    }
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&start,&end);
        printf("%d\n",arr[end]-arr[start-1]);
    }
}