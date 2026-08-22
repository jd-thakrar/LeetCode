#include<stdio.h>
#include<conio.h>

void swap(double *i, double *j){
    double temp = *i;
    *i = *j;
    *j = temp;
}


void sort(int n, double ratio[], double weights[], double profit[]){
    
    for(int i = 0; i<n; i++){
        for(int j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(&ratio[j],&ratio[j+1]);
                swap(&weights[j],&weights[j+1]);
                swap(&profit[j],&profit[j+1]);
            }
        }
    }
}

double knapsack(int n, int w, double weights[], double profit[]){
    double ratio[n];
    for(int i=0; i<n;i++){
        ratio[i] = profit[i] / weights[i];
    }

    sort(n,ratio, weights, profit);
    
    double total_profit = 0;

    for(int i = 0 ; i<n ; i++){
        if(weights[i] <= w){
            w -= weights[i];
            total_profit += profit[i]; 
        }else{
            double fraction = profit[i]/weights[i];
            total_profit = total_profit + (fraction * w);
            break;
        }
    }
    return total_profit;
}

int main(){
    
    int n,w;
    
    printf("Enter number of elemet: ");
    scanf("%d", &n);

    printf("Enter capacity of the bag: ");
    scanf("%d", &w);
    double weights[n];
    printf("Enter the %d elements for the weight: ", n);
    for(int i=0; i<n; i++){
        scanf("%lf", &weights[i]);
    }
    double profits[n];
    printf("Enter the Profit: ", n);
    for(int i=0; i<n; i++){
        scanf("%lf", &profits[i]);
    }
    double total_profit = knapsack(n,w, weights, profits);
    printf("MAXIMUM PROFIT: %lf",total_profit);
    return 0;

}