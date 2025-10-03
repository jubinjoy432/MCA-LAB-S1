/*program used to demonstrate polynomial addition
@Jubin Joy
Roll No 35 
10/09/2025 */

#include<stdio.h>

int a[10],b[10],c[10];     
int degree1,degree2,maxdegree;    


void display(int degree,int poly[]){  //function for displaying polynomial
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


void read(){  //function for read the polynomial
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


void sum(){    //function for add two polynomial
    int i;
    if(degree1>degree2){   
        maxdegree=degree1;
    }
    else{
        maxdegree=degree2;
    }
    for(i=0;i<=maxdegree;i++){
        int d=0,e=0;
        if(i<=degree1){
            d = a[i];
        }
        if(i<=degree2){
            e = b[i];
        }
        c[i]=d+e;
    }
    printf("\n Sum is \n");
    display(maxdegree,c);
}

int main(){
    read();
    sum();
    return 0;
}