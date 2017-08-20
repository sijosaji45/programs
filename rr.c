#include<stdio.h> 
 
int main() 
{ 
 int h[100];
 int c;
  int count,j,n,time,remain,flag=0,time_quantum,temp; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(at[j]>at[j+1])
      {
         temp=at[j];
         at[j]=at[j+1];
         at[j+1]=temp;
         temp=bt[j];
         bt[j]=bt[j+1];
         bt[j+1]=temp;
         temp=rt[j];
         rt[j]=rt[j+1];
         rt[j+1]=temp;
      }
    }
  }
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
      h[c]=count+1;
      c++;
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
      h[c]=count+1;
      c++;
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  for(int i=0;i<=c;i++)
  {
    printf("%d p", h[i]);
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
