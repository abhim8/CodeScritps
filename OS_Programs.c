
// FCFS:
#include<stdio.h>
void main(){
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<n;i++) printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
}


 





// b) sjf
#include<stdio.h>
#include<conio.h>
void main(){
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(bt[i]>bt[k]){
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<n;i++) printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
    
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
}


// C) RR:
#include<stdio.h>
void main(){
    int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
    float awt=0,att=0,temp=0;

    printf("Enter the no of processes -- ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter Burst Time for process %d -- ", i+1);
        scanf("%d",&bu[i]);
        ct[i]=bu[i];
    }
    printf("\nEnter the size of time slice -- ");
    scanf("%d",&t);
    max=bu[0];
    for(i=1;i<n;i++)
        if(max<bu[i])
            max=bu[i];
    for(j=0;j<(max/t)+1;j++)
        for(i=0;i<n;i++)
        if(bu[i]!=0)
            if(bu[i]<=t){
                tat[i]=temp+bu[i];
                temp=temp+bu[i];
                bu[i]=0;
            }
            else{
                bu[i]=bu[i]-t;
                temp=temp+t;
            }
    
    for(i=0;i<n;i++){
        wa[i]=tat[i]-ct[i];
        att+=tat[i];
        awt+=wa[i];
    }
    printf("\nThe Average Turnaround time is -- %f",att/n);
    printf("\nThe Average Waiting time is -- %f ",awt/n);

    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++) printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);
}



 


// 4)PRIORITY:
#include<stdio.h>
void main(){
    int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp;
    float wtavg, tatavg;

    printf("Enter the number of processes --- ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i] = i;
        printf("Enter the Burst Time & Priority of Process %d --- ",i);
        scanf("%d %d",&bt[i], &pri[i]);
    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(pri[i] > pri[k]){
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=pri[i];
                pri[i]=pri[k];
                pri[k]=temp;
            }
    
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for(i=0;i<n;i++) printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);
    
    printf("\nAverage Waiting Time is --- %f",wtavg/n);
    printf("\nAverage Turnaround Time is --- %f",tatavg/n);
}



// syscall 1
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
int main (){
  int n, fd;
  char buff[50]; // declaring buffer
  //message printing on the display
  printf ("Enter text to write in the file:\n");
  //read from keyboard, specifying 0 as fd for std input device
  //Here, n stores the number of characters      
  n = read (0, buff, 50);
  // creating a new file using open.
  fd = open ("file", O_CREAT | O_RDWR, 0777);
  //writting input data to file (fd)
  write (fd, buff, n);
  //Write to display (1 is standard fd for output device)
  write (1, buff, n);
  //closing the file
  int close(int fd);
  return 0;
}


------------------------
// 
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
void main(){
    char d[10]; int c,op; DIR *e;
    struct dirent *sd;
    printf("**menu**\n1.create dir\n2.remove dir\n 3.read dir\n enter ur choice");
    scanf("%d",&op);
    switch(op){
        case 1: printf("enter dir name\n"); scanf("%s",&d); c=mkdir(d,777);
            if(c==1) printf("dir is not created");
            else printf("dir is created"); 
        break;
        case 2: printf("enter dir name\n"); scanf("%s",&d); c=rmdir(d);
            if(c==1) printf("dir is not removed");
            else printf("dir is removed"); 
        break;
        case 3: printf("enter dir name to open"); scanf("%s",&d); e=opendir(d);
            if(e==NULL) printf("dir does not exist"); 
            else{
                printf("dir exist\n"); while((sd=readdir(e))!=NULL) printf("%s\t",sd->d_name);
            }
            closedir(e);
        break;
    }
}

-----------------------------
#include<stdio.h> 
struct file{
    int all[10]; int max[10]; int need[10]; int flag;
};
void main(){
    struct file f[10]; int fl;
    int i, j, k, p, b, n, r, g, cnt=0, id, newr; int avail[10],
    seq[10];
    printf("Enter number of processes -- "); scanf("%d",&n);
    printf("Enter number of resources -- "); scanf("%d", &r);
    for(i=0;i<n; i++){
        printf("Enter details for P %d", i); printf("\n Enter allocation\t -- \t"); 
        for(j=0;j<r; j++)
            scanf("%d", &f[i].all[j]); 
        printf("Enter Max\t\t -- \t"); 
        for(j=0;j<r; j++) 
            scanf("%d", &f[i].max[j]); 
        f[i].flag=0;
    }
    printf("\n Enter Available Resources\t -- \t"); 
    for(i=0;i<r; i++)
        scanf("%d", &avail[i]);
    printf("\n Enter New Request Details -- ");
    printf("\n Enter pid \t -- \t");
    scanf("%d", &id);
    printf("Enter Request for Resources \t -- \t"); 
    for(i=0;i<r; i++){
        scanf("%d", &newr);
        f[id].all[i] += newr; avail[i]=avail[i] - newr;
    }
    for(i=0;i<n; i++){
        for(j=0;j<r; j++){
            f[i].need[j]=f[i].max[j]-f[i].all[j]; 
            if(f[i].need[j]<0)
                f[i].need[j]=0; 
        } 
    } 
    cnt=0; fl=0; 
    while(cnt!=n){
        g=0;
        for(j=0;j<n; j++){
            if(f[j].flag==0){ 
                b=0;
                for(p=0;p<r; p++){
                    if(avail[p]>=f[j].need[p]) 
                        b=b+1;
                    else 
                        b=b-1;
                }
                if(b==r){
                    printf("\n P %d is visited", j); seq[fl++]=j;
                    f[j].flag=1; 
                    for(k=0;k<r; k++)
                        avail[k]=avail[k]+f[j].all[k]; 
                    cnt=cnt+1;
                    printf("("); 
                    for(k=0;k<r; k++) 
                        printf("%3d",avail[k]);
                    printf(")"); g=1; 
                } 
            } 
        }
        if(g==0){
            printf("\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED");
            printf("\n SYSTEM IS IN UNSAFE STATE"); goto y; 
        } 
    } 
    printf("\n SYSTEM IS IN SAFE STATE");
    printf("\n The Safe Sequence is -- ("); for(i=0;i<fl; i++) printf("P %d ",seq[i]);
    printf(")");
    y: printf("\n Process\t\t Allocation\t\t Max\t\t\t Need\n"); 
    for(i=0;i<n;i++){
        printf("P %d\t", i); 
        for(j=0;j<r; j++) 
            printf("%6d",f[i].all[j]);
        for(j=0;j<r; j++) 
            printf("%6d",f[i].max[j]); 
        for(j=0;j<r; j++) 
            printf("%6d",f[i].need[j]); 
        printf("\n");
    } 
}
