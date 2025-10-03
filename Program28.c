/*program used to demonstrate polynomial multiplication
@Jubin Joy
Roll No 35 
10/09/2025 */

#include<stdio.h>

int a[10],b[10],c[20];             
int degree1,degree2,maxdegree;    

void display(int degree,int poly[]){    //function to display polynomial
    int i;
    for(i=degree;i>=0;i--){
        if(poly[i]==0)continue;
        if(i!=degree && poly[i] > 0){
            printf("+");
        }
        else if(poly[i]<0){
            printf("-");
        }
        if(poly[i]<0){
            printf("%d",-poly[i]);
        }
        else{
            printf("%d",poly[i]);
        }
        if(i>0){
            printf("x^%d",i);
        }

    }
}

void read(){  //function to read polynomial
    int i;
    printf("Enter the degree of first polynomial\n");
    scanf("%d",&degree1);
    printf("Enter the degree of second polynomial\n");
    scanf("%d",&degree2);

    printf("Enter the coefficients from constant term of first polynomial \n");
    for(i=0;i<=degree1;i++){   
        printf("Coefficient of x^%d: ", i);
        scanf("%d",&a[i]);
    }
    printf("First polynomial is\n");
    display(degree1,a);

    printf("\nEnter the coefficients from constant term of second polynomial \n");
    for(i=0;i<=degree1;i++){   
        printf("Coefficient of x^%d: ", i);
        scanf("%d",&b[i]);
    }
    printf("Second polynomial is\n");
   display(degree2,b);

}
void mul(){   //function to multiply two polynomial
    int i,j;
    maxdegree=degree1+degree2;
    for(i=0;i<=degree1;i++){ 
        for(j=0;j<=degree2;j++){
            c[i+j]+=a[i]*b[j];

        }
    }
    printf("\n Product is \n");
    display(maxdegree,c);

}


int main(){
    read();
    mul();
    return 0;

}