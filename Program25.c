/*program used to read and display polynomial 
@Jubin Joy
Roll No 35 
10/09/2025 */


#include<stdio.h>
int poly[20];   
int degree;     

void read(){     //function for reading the polynomial terms 
    int i;
    printf("Enter the degree of polynomial\n");
    scanf("%d",&degree);
    printf("Enter the coefficients from constant term \n");
    for(i=0;i<=degree;i++){   
        printf("Coefficient of x^%d: ", i);
        scanf("%d",&poly[i]);
    }

}

void display(){      // Function to display polynomial in standard form
    int i;
    for(i=degree;i>=0;i--){      
        if(poly[i]==0)continue;  
        if(i!=degree && poly[i]>0){    
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

int main(){
    read();
    display();
    return 0;
}