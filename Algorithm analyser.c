// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>
#define msize 100000
int arr[msize];

double autofill(int arr[msize])
{
    printf("Autofilling the array...\n");
        clock_t t;
        int size;
        t = clock();
        for(int i=0;i<size;i++){arr[i] = size-i;}
        t = clock() - t;
        t = (double)t;
        printf("Autofilling done.\n");
        return t;
}
void printArray(int arr[msize],int size){
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int takeInput()
{   
    printf("\nPlease enter the size of array to be sorted: ");
    int size;
    scanf("%d",&size);
    clock_t t;
    
    if(size>=100 && size <1000){
      printf("\nperfect! You enter the size %d\n",size);
      printf("\n We presume that enterring %d elements in array to be sorting will be a complex task, so we have an automatic filler that fills the array optimised to give you the result for worst case scenerio\nWould you like to give automation a go. Or you'll enter the values manually?\n",size);
      printf("To autofill, press any number, to manually fill press 0\n");
      printf("Enter the input : ");
      int input;
      scanf("%d",&input);
        if(input==0)
        {
        printf("Enter %d Elements manually please : ",size);
        for(int i=0;i<size;i++){
            printf("element [%d] : ",i);
            scanf("%d",&arr[i]);}
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Do you want to see the initial array (1/0)? : ");
        int init;
        scanf("%d",&init);
            if(init==1){
                printf("Elements given in the list are : \n");
                for(int i=0;i<size;i++)
                    {printf("%d ",arr[i]);}
        }   else if(init==0){
            printf("Okay! you don't wish to see elements.");
            }
        }
        else
        {
        t = autofill(arr);
        
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Do you want to see the initial array (1/0)? : ");
        int init;
        if(scanf("%d",&init)==1){
            printf("Elements given in the list are : \n");
            for(int i=0;i<size;i++){printf("%d ",arr[i]);}
        }
        printf("\n----\n");
    }
    }
    else if(size>10 && size<100){
      printf("Good! since the size of the array is considerably fair, we have two options, either we can autofill the array using our algorithm optimised to check the worst case scenerio for sorting, or we could manually take the input.\n\n");
      printf("To autofill press any number, to manually fill press 0\n");
      printf("Enter the input : ");
      int input;
      scanf("%d",&input);
      if(input==0)
      {
        printf("Enter %d Elements manually please : \n",size);
        for(int i=0;i<size;i++){
            printf("element [%d] : ",i);
            scanf("%d",&arr[i]);}
        printf("Do you want to see the initial array (1/0)? : ");
        int init;
        if(scanf("%d",&init)==1)
        {
            printf("Elements given in the list are : \n");
            for(int j=0;j<size;j++){printf("%d ",arr[j]);}
        }
        printf("\n----\n");
        } else{
        t = autofill(arr);
        
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Do you want to see the initial array (1/0)? : ");
        int init;
        if(scanf("%d",&init)==1){
            printf("Elements given in the list are : \n");
            for(int i=0;i<size;i++){printf("%d ",arr[i]);}
        }
        printf("\n----\n");
      }
} 
    else if(size>=1000){
      printf("\nperfect! You enter the size %d\n",size);
      printf("\nAt this point we should autofill the array,since its unrealistic to fill the array manually\nTherefore we have an option to autofill the array by that is optimised for worst case scenerio.\n\n");
      t = autofill(arr);
        
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Do you want to see the initial array (1/0)? : ");
        int init;
        if(scanf("%d",&init)==1){
            printf("Elements given in the list are : \n");
            for(int i=0;i<size;i++){printf("%d ",arr[i]);}
        }
        printf("\n----\n");} 
    else{
      printf("size : %d --> too inappropriate size to give the appropriate result required for analysis of algorithm.\n\n",size);
      printf("Try again\n");
      takeInput(arr);
  }
  return size;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

  
double selectionSort(int arr[], int n)
{
    clock_t t;
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    t = clock();
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    t = clock() - t;
    return t;
}
double bubbleSort(int arr[], int n)
{
    clock_t t;
   int i, j;
   t = clock();
   for (i = 0; i < n-1; i++){
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
       }
   }
   t = clock() - t;
   return t;
   
}


int main() {
  // printf greetings statement.
  clock_t t;
  printf(" \nNote : For better results please enter the size which is a little larger than human intuition and which is under computer powers! A good range of size lies between 100 to 100,000\n\n");
  
  int size = takeInput();
  printf("time taken : %f\n\n",bubbleSort(&arr,size));
  printArray(&arr,size);
  
  
    return 0;
}
