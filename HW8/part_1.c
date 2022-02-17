#include <stdio.h>
#include <math.h>
#define SIZE 500
void generate_hofstadters_sequence (int *arr, int n)
{
  if (n == 2)
  {
    arr[n] = 1;
    arr[n - 1] = 1;
  }
  else
  {
    generate_hofstadters_sequence(arr, n-1);
    arr[n] = arr[n - arr[n - 1]] + arr[n - arr[n - 2]];
  }
    
}

int find_max (int arr[], int index, int max_value)
{
  if (index== 2)
    return max_value;
  int current_max = max_value < arr[index] ? arr[index] : max_value; 
  return find_max(arr, index - 1, current_max);
}
void set_all_zero(int arr[])
{
  int i;
  for (i=0;i<SIZE+1;i++)
    arr[i] = 0;
}
int sum_array (int arr[])
{
  if (arr[0] == SIZE)
    return 0;
  arr[0] +=1;
  return arr[arr[0]] + sum_array(arr);
}

double std_array(int arr[], double *mean, int n, int index)
{
  if (index==0)
  {
    *mean /= (double)n;
    //printf("%lf\n",*mean);
    return 0;
  }
  else
    *mean += arr[index];
 
  double so_far = std_array(arr, mean, n, index-1);
  double current_diff = (*mean - arr[index]);
  double current_val = ( current_diff * current_diff) + so_far;
  //printf("current_val = %.2lf\n",current_val);
  if (n == index)
    current_val = (double)sqrt(current_val/n);
  return current_val;
}

void print_arr(int *arr,int n)
{
  int i =0;
  for (i=1;i<n+1;i++)
  {
    printf("%d. item of the serie is %d\n",i,arr[i]);
  }
}
void show_part1_menu()
{
  printf("--------------\n");
  printf("1) Fill Array\n");
  printf("2) Find Biggest Number\n");
  printf("3) Calculate Sum\n");
  printf("4) Calculate Standard Deviation\n");
  printf("5) Exit\n");
  printf("--------------\n");
}
void menu_part1(int arr[])
{
  int n, choice;
  double mean=0,std=0;
  set_all_zero(arr);
  printf("Please specify the n value: ");
  scanf("%d", &n);
  printf("\n");
  while (choice != 5)
  {
    show_part1_menu();
    printf("\nPlease make your choice: ");
    scanf("%d", &choice);
    printf("\n");
    switch(choice)
    {
      case 1: generate_hofstadters_sequence(arr, n);print_arr(arr, n);break;
      case 2: printf("The max value of the serie is %d\n",find_max(arr,n,0));break;
      case 3: printf("The sum of the serie is %d\n",sum_array(arr));break;
      case 4: printf("The STD of the serie %.2lf\nThe mean of the serie is %.2lf\n",std_array(arr, &mean, n, n), mean);break;
      case 5: printf("Part 1 is terminated.\n");break;
      default: printf("Wrong choice!\n");
    }
  }

  
}
int main(void) {
  int arr[501];
  menu_part1(arr);
  return 0;
}