#include<stdio.h>
int main(){
    int locks,stocks,barrels,tlocks=0,tstocks=0,tbarrels=0;
    float lprice=45.0,sprice=30.0,bprice=25.0,sales=0,comm;
    while(1){
        printf("Enter the number of locks,stocks,barrels(enter-1 for exit)");
        scanf("%d",&locks);
        if(locks==-1) break;
        scanf("%d%d",&stocks,&barrels);
        if(locks<1||locks>70||stocks<1||stocks>80||barrels<1||barrels>90){
            printf("Out fo range");
            continue;
        }
        if(tlocks+locks>70||tstocks+stocks>80||tbarrels+barrels>90){
            printf("Limit exceed");
            continue;
        }

        tlocks+=locks;
        tstocks+=stocks;
        tbarrels+=barrels;

    }

    if(tlocks>0&&tstocks>0&&tbarrels>0){
        sales=tlocks*lprice+tstocks*sprice+tbarrels*bprice;
        printf("Toatl sales is %.2f\n",sales);
        if(sales>1800)
        comm=100+120+0.2*(sales-1800);
        else if(sales>1000)
        comm=100+0.15*(sales-1000);
        else
        comm=0.1*sales;
    printf("Commision is %.2f\n",comm);
    }
    else{
        printf("No comm");
    }

return 0;

}