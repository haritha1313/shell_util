#include<stdio.h>
#include<conio.h>
#include<string.h>
int n;
int main()
{
    int b[20],b1[20],i,j,blocks[20][20],sz[20];
    char F[20][20],S[20],ch;
    printf("\n Enter no. of Files ::");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter file %d name ::",i+1);
        scanf("%s",&F[i]);
        printf("\n Enter file%d size(in kb)::",i+1);
        scanf("%d",&sz[i]);
        printf("\n Enter blocksize of File%d(in bytes)::",i+1);
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        b1[i]=(sz[i]*1024)/b[i];
        printf("\n\nEnter blocks for file%d",i+1);
        for(j=0;j<b1[i];j++)
        {
            printf("\n Enter the %dblock ::",j+1);
            scanf("%d",&blocks[i][j]);
        }
    }
    do
    {
        printf("\nEnter the Filename ::");
        scanf("%s",&S);
        for(i=0;i<n;i++)
        {
            if(strcmp(F[i],S)==0)
            {
                printf("\nFname\tFsize\tBsize\tNblocks\tBlocks\n");
                printf("\n---------------------------------------------\n");
                printf("\n%s\t%d\t%d\t%d\t",F[i],sz[i],b[i],b1[i]);
                for(j=0;j<b1[i];j++)
                    printf("%d->",blocks[i][j]);
            }
        }
        printf("\n---------------------------------------------\n");
        printf("\nDo U want to continue ::(Y:n)");
        scanf("%d",&ch);
    }while(ch!=0);
}
/*Input and Output;-

 Enter no. of Files ::2

 Enter file 1 name ::x.c

 Enter file1 size(in kb)::1

 Enter blocksize of File1(in bytes)::512

 Enter file 2 name ::y.c

 Enter file2 size(in kb)::1

 Enter blocksize of File2(in bytes)::512

 Enter blocks for file1

 Enter the 1block ::1000

 Enter the 2block ::1001

 Enter blocks for file2

 Enter the 1block ::2000

 Enter the 2block ::2001

 Enter the Filename ::x.c

Fname   Fsize   Bsize   Nblocks Blocks
---------------------------------------------
x.c     1       512     2       1000->1001->
---------------------------------------------

Do U want to continue ::(Y:n)1

Enter the Filename ::y.c

Fname   Fsize   Bsize   Nblocks Blocks
---------------------------------------------
y.c     1       512     2       2000->2001->
---------------------------------------------

Do U want to continue ::(Y:n)0
*/
