/*Program to read and display a sparse matrix
@Jubin Joy 
Roll No 35 
10/09/2025 */
#include<stdio.h>
int a[10][10],m,n,s[10][10];
void sparse(int a[][10],int m,int n,int count)
{
s[0][0]=m;
s[0][1]=n;
s[0][2]=count;
int k=1,i,j;
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        if(a[i][j]!=0)
        {
            s[k][0]=i;
            s[k][1]=j;
            s[k][2]=a[i][j];
            k++;
        }
    }
}
}
void display()
{
    int i;
    printf("The sparse matrix is:\n");
    for(i=0;i<=s[0][2];i++)
    {
        printf("%d %d %d\n",s[i][0],s[i][1],s[i][2]);
    }
}
int main()
{
    int i,j,count;
    printf("Enter the number of rows and columns:");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
            {
                count++;
            }
        }
    }
    sparse(a,m,n,count);
    display();
    return 0;
}