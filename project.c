
#include <stdio.h>

void print_instructions(){

 printf("These are the program's instructions\n");
 printf("[1] To add a new branch\n");
 printf("[2] To delete a branch\n");
 printf("[3] To calculate total sales of the company\n");
 printf("[4] To Calculate the percentage share of each branch\n");
 printf("[5] To print the month of the peak sales\n");
 printf("[6] To view sales of a given month for all branches (bubble sort)\n");
 printf("[7] To view sales of a given month for all branches (selection sort)\n");
 printf("[8] To view all branches\n");
 printf("[0] To quit\n");

}

void print_matrix(float company[][12] , int branches ){
 printf("\n++++++++++++++++++++++++++++\n");
 int i, j;
 for(i=0; i<20; i++) {
   for(j=0;j<12;j++) {
       if(company[i][j] !=0 ){
         printf("%f ", company[i][j]);
         if(j==11){
           printf("\n");
         }
       }
   }
 }
 printf("\n++++++++++++++++++++++++++++\n");
}


void add_branch(float company[][12],int branches){
     //search for first empty row
  int i , empty_place,z,y;
  int j=0;
  for(i=0; i<20; i++){
    if(company[i][0] ==0){
      company[i][0] =-1;
      empty_place=i;
      break;
    }
  }
 for(j=0; j<12;j++){
 printf("enter salesfor month %d:\n",j+1);
 scanf("%f", &company [empty_place][j]);
 }
 for(y=0;y<= branches;y++)
 {
   for(z=0;z<12;z++)
   {
     printf("%9.1f",company[y][z]);
   }
   printf("\n");
 }


}
void delete_branch(float company[][12],int branches) {

  int i , j ,x,y,z ;
  printf("enter a branch to delete:");
  scanf("%d",&x);
  x-=1 ;
for(i=x-1; i<12 ;i++){
    company[x][i]=0;

}

  for(y=0;y< branches;y++)
 {
   for(z=0;z<12;z++)
   {
     if(company[y][z] !=0){

}
printf("%9.1f",company[y][z]);

   }
   printf("\n");
 }
}
void calculate_total_sales(float company[][12],int branches){
 int  i , j ;
    float  total= 0.0;

   for(i= 0; i < branches ; i++) {
      total = total +  company[i][j];
      for(j=0;j<12;j++){
      total =total + company[j][i];


   }
    printf("\n calculate total sales of the company is %f.", total );

  }


 }
    void Calculate_the_percentage_share_of_each_branch(float company[]
    [12],int branches){
      int i , j ;
      float total= 0.0;
     float percentage;
     float total_sales;
     float  total_of_company;
   for(i= 0; i < branches; i++) {
      total = total + company[i][j];
      for(j=0;j<12;j++){
      total =total + company[j][i];
   }
    printf("\n calculate total sales of the company is %f.", total );
   }



       for(i=0;i<branches;i++){
         printf("\nEnter total sales for the branch,i+1");

       for(j=0;j>12;j++){
         printf("\nEnter total sales for the branch,j+1");
       }
      percentage = total_of_company / total_sales * 100.0;

      printf("Percentage = %.2f%%", percentage);

       }
    }

 void print_the_month_of_the_peak_sales(float company[][12],int branches){
    int arr[12] ;
    int month =0 ;
     float total, max;
     int i,j,x;
    for(i=0;i<12;i++){
      total=0.0;
      for(j=0;j<branches;j++){
        total=total+company[j][i];
      }

      arr[i]=total;
    }
     max=arr[0];
     for(x=0;x<12;x++){
       if(max<arr[x]){
         max=arr[x];
         month=x+1;
       }
     }
     printf("month %d has the peak sales %.1f \n",month,max);

 }

  void sales_of_a_given_month_for_all_branches(float company[][12],int branches){
     int i,j,temp,b ,p,x,t;
     float total;
     printf("enter month number want to sort it");
     scanf("%d",&b);
     b-=1;
     int a[branches];
     for(x=0;x<branches;x++)
     {
         a[x]=x+1;
     }

    for(i=1;i<branches;i++){
      for(j=0;j<branches-1;j++){
        if(company[j][b]<company[j+1][b]){
          temp=company[j][b];
          company[j][b]=company[j+1][b];
          company[j+1][b]=temp;
          t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;
        }
      }
    }
     for (int p= 0; p< branches;p++) {
    printf("branch %d : %0.1f",a[p],company[p][b]);
    printf("\n");
  }

}



    void a_given_month_for_all_branches(float company[][12],int branches){
     int i ,j ,temp ,min ,b,p;
   printf("enter branch number want to sort it");
   scanf("%d",&b);


 for(i=0;i<12-1;i++){
    min=i;
   for(j=i+1;j<12;j++){
   if(company[b][j]>company[b][min])
   {
     min=j;
   }
   if(min!=j)
   {
     temp=company[b][i];
     company[b][i]=company[b][min];
     company[b][min]=temp;
   }
   }
   }
   for(p=0;p<12;p++){
  printf("%0.1f",company[b][p]);


   }


    }



  int main(void) {
    int branches,i,j;
    float company[20][12]={0};
    printf("enter the number of branches \n");
    scanf("%d",&branches);
    for(i=0;i<branches;i++)
    {
      printf("sales for branch %d\n",i+1);
      for(j=0;j<12;j++)
      {
        printf("sales for month %d \n",j+1);
        scanf("%f",&company[i][j]);
      }
    }
  int user_input = 100;

  //print instruction

  while(user_input != 0){
    print_instructions();
    printf("user input:");
    scanf("%d", &user_input);
    switch(user_input){
     case 1:
       add_branch(company,branches);
      printf("branch_added");

       break;
     case 2:
      delete_branch(company,branches);
      printf("branch_deleted");

       break;

      case 3:
      calculate_total_sales( company,branches);

      break;

      case 4:
      Calculate_the_percentage_share_of_each_branch(company,branches);

     break;

    case 5:
     print_the_month_of_the_peak_sales(company,branches);
    break;

    case 6:
     sales_of_a_given_month_for_all_branches(company, branches);

    break;

    case 7:
    a_given_month_for_all_branches(company ,  branches);
    break;

    case 8:
    print_matrix(company,branches);

    break ;

    case 0:
    printf("\n ending program, see you around = D\n");

     break;



    }

  }
  return 0;
}


