#include <stdio.h>

void monthly_report(float monthly_sales[], char month[][25]){ 
  //Prints monthly report.
  printf("Monthly Sales Report for 2022:\n");
  printf("%-10s %-10s\n","Month", "Sales");

  for (int i = 0; i <= 11; i++){  //prints monthly sales line by line
    printf("%-10s $%-10.2f\n", month[i], monthly_sales[i]);
  }
  printf("\n");
}

void sales_summary(float monthly_sales[], char month[][25]){
  //Prints sales summary: minimum, maximum, and average sales.
  int max_indx = 0, min_indx = 0;
  float total = 0;

  for (int i = 0; i <= 11; i++){  //iterates through monthly sales to find index containing max and min value
    if (monthly_sales[i] > monthly_sales[max_indx]){
      max_indx = i; //reassigns max sales index
    }
    if (monthly_sales[i] < monthly_sales[min_indx]){
      min_indx = i; //reassigns min sales index
    }
    total += monthly_sales[i];
  }

  float avg = total/12; //average sales

  printf("Sales Summary:\n");
  printf("Minimum Sales: $%-10.2f (%s)\n",monthly_sales[min_indx], month[min_indx]);
  printf("Maximum Sales: $%-10.2f (%s)\n",monthly_sales[max_indx], month[max_indx]);
  printf("Average Sales: $%-10.2f\n",avg);
  printf("\n");
}

void moving_avg(float monthly_sales[], char month[][25]){
  //Prints the Six-Month Moving Average Report.
  printf("Six-Month Moving Average Report:\n");

  for (int i = 0; i <= 6; i++){ //iterates from January to June
    float total = 0, avg;
    for (int j = i; j <= i + 5; j++){ //iterates from current month to six months after
      total += monthly_sales[j]; //totals the sales for the six months
    }
    avg = total/6; //moving average
    printf("%-10s - %-10s $%.2f\n", month[i], month[i+5], avg);
  }

  printf("\n");
}

void sales_report(float monthly_sales[], char month[][25]){
  //Prints Sales Report from highest to lowest sales.
  float ordered_sales[12];
  int indx_order[12];

  for (int i = 0; i <= 11; i++){ 
    ordered_sales[i] = monthly_sales[i]; //creates a copy of monthly sales to be mutated
    indx_order[i] = i; //creates an array of indices from 0 to 11 to be mutated
  }

  //Bubble sorts from max to min.
  for (int i = 0; i <= 11; i++){ //loops through each index
    for (int j = 0; j <= 11 - i; j++){ //loops through current index to end of array, not including last element

    //If value at current index is less than the value at the next index, the values are swapped.
      if (ordered_sales[j] < ordered_sales[j + 1]){
        float temp_sales = ordered_sales[j];
        ordered_sales[j] = ordered_sales[j + 1];
        ordered_sales[j + 1] = temp_sales;

    //The indices are also swapped.
        int temp_indx = indx_order[j];
        indx_order[j] = indx_order[j + 1];
        indx_order[j + 1] = temp_indx;
      }
    }
  }

  printf("Sales Report (Highest to Lowest):\n");
  printf("%-10s %-10s\n","Month", "Sales");

  //Prints the month and monthly sales from highest to lowest.
  for (int i = 0; i <= 11; i++){
    int indx = indx_order[i];
    printf("%-10s $%-10.2f\n", month[indx], ordered_sales[i]);
  }

  printf("\n");
}

int main(){
  //Asks user for monthly sales and displays a report using helper functions.
  float monthly_sales[12];
  char month[12][25] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  printf("Enter monthly sales for 2022:\n");

  //Asks for user input for sales per month separately.
  for (int i = 0; i <= 11; i++){
    printf("%s: $", month[i]);
    scanf("%f", &monthly_sales[i]);
  }

  printf("\n");

  //Calls helper functions to print sales report.
  monthly_report(monthly_sales, month);
  sales_summary(monthly_sales, month);
  moving_avg(monthly_sales, month);
  sales_report(monthly_sales, month);

  return 0;
}