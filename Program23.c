/*Program to add two sparse matrix
@Jubin Joy 
Roll No 35 
10/09/2025 */
#include<stdio.h>
void sparse(int mat[][10],int m,int n,int count,int s[][10])
{
s[0][0]=m;
s[0][1]=n;
s[0][2]=count;
int k=1,i,j;
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        if(mat[i][j]!=0)
        {
            s[k][0]=i;
            s[k][1]=j;
            s[k][2]=mat[i][j];
            k++;
        }
    }
}
}
int insert(int mat[][10],int m,int n)
{
    int i,j,count=0;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0)
            {
                count++;
            }
        }
    }
    return count;
}
void sum(int s1[][10],int s2[][10],int result[][10])
{
    int i=1,j=1,k=1;
    result[0][0]=s1[0][0];
    result[0][1]=s1[0][1];
    while(i<=s1[0][2] && j<=s2[0][2])
    {
        if(s1[i][0]<s2[j][0] || (s1[i][0]==s2[j][0] && s1[i][1]<s2[j][1]))
        {
            result[k][0]=s1[i][0];
            result[k][1]=s1[i][1];
            result[k][2]=s1[i][2];
            i++;
            k++;
        }
        else if(s1[i][0]>s2[j][0] || (s1[i][0]==s2[j][0] && s1[i][1]>s2[j][1]))
        {
            result[k][0]=s2[j][0];
            result[k][1]=s2[j][1];
            result[k][2]=s2[j][2];
            j++;
            k++;
        }
        else
        {
            result[k][0]=s1[i][0];
            result[k][1]=s1[i][1];
            result[k][2]=s1[i][2]+s2[j][2];
            i++;
            j++;
            k++;
        }
    }

    while(i<=s1[0][2]) {
        result[k][0]=s1[i][0];
        result[k][1]=s1[i][1];
        result[k][2]=s1[i][2];
        i++; k++;
    }
    while(j<=s2[0][2]) {
        result[k][0]=s2[j][0];
        result[k][1]=s2[j][1];
        result[k][2]=s2[j][2];
        j++; k++;
    }
    result[0][2]=k-1;
}
void display(int s[][10])
{
    int i;
    for(i=0;i<=s[0][2];i++)
    {
        printf("%d %d %d\n",s[i][0],s[i][1],s[i][2]);
    }
}
int main()
{
    int i,j,count;
    int a[10][10],b[10][10],m1,n1,m2,n2,s1[10][10],s2[10][10],result[10][10];
    printf("Enter the number of rows and columns of the first matrix:");
    scanf("%d%d",&m1,&n1);
    count=insert(a,m1,n1);
    printf("The sparse matrix is:\n");
    sparse(a,m1,n1,count,s1);
    display(s1);
    printf("Enter the number of rows and columns of the second matrix:");
    scanf("%d%d",&m2,&n2);
    count=insert(b,m2,n2);
    printf("The sparse matrix is:\n");
    sparse(b,m2,n2,count,s2);
    display(s2);
    if(m1!=m2 || n1!=n2)    
    {
        printf("Matrices cannot be added\n");
        return 0;
    }
    else
    {
        sum(s1,s2,result);
        printf("The sum of the two sparse matrices is:\n");
        display(result);
    }
    return 0;
}
