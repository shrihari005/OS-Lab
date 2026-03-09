
#include <stdio.h>

int main()
{
    int n,i,choice;
    int at[20],bt[20],pr[20],rt[20];
    int wt[20]={0},tat[20]={0},done[20]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Arrival Time P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);

        printf("Priority P%d: ",i+1);
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    printf("\n1. Priority Non Preemptive\n2. Priority Preemptive\nEnter choice: ");
    scanf("%d",&choice);

    int time=0,completed=0,remain=n;
    float awt=0,atat=0;

    if(choice==1) // Non Preemptive
    {
        while(completed<n)
        {
            int highest=-1;

            for(i=0;i<n;i++)
                if(at[i]<=time && done[i]==0)
                    if(highest==-1 || pr[i]<pr[highest])
                        highest=i;

            if(highest==-1)
            {
                time++;
                continue;
            }

            wt[highest]=time-at[highest];
            time+=bt[highest];

            tat[highest]=wt[highest]+bt[highest];

            done[highest]=1;
            completed++;

            awt+=wt[highest];
            atat+=tat[highest];
        }
    }

    else if(choice==2) // Preemptive
    {
        while(remain!=0)
        {
            int highest=-1;

            for(i=0;i<n;i++)
                if(at[i]<=time && rt[i]>0)
                    if(highest==-1 || pr[i]<pr[highest])
                        highest=i;

            if(highest==-1)
            {
                time++;
                continue;
            }

            rt[highest]--;
            time++;

            if(rt[highest]==0)
            {
                remain--;

                tat[highest]=time-at[highest];
                wt[highest]=tat[highest]-bt[highest];

                awt+=wt[highest];
                atat+=tat[highest];
            }
        }
    }

    printf("\nProcess\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\n",i+1,wt[i],tat[i]);

    printf("\nAverage WT = %.2f",awt/n);
    printf("\nAverage TAT = %.2f",atat/n);

    return 0;
}
