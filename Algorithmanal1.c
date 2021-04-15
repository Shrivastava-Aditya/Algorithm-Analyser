// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>
#define msize 100000
int arr[msize];

double autofill(int arr[msize],int size)
{
    printf("Autofilling the array...\n");
        clock_t t;
        t = clock();
        for(int i=0;i<size;i++){arr[i] = size-i;}
        t = clock() - t;
        t = (double)t;
        printf("Autofilling done.\n");
        return t;
}
void printArray(int arr[msize],int size){
    printf("Elements given in the list are \n[");
    for(int i=0;i<size;i++){printf("%d,",arr[i]);}
    printf("]\n");
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
            printf("Elements given in the list are \n[");
                for(int i=0;i<size;i++){printf("%d,",arr[i]);}
                printf("]\n");
        }
        else
        {
        t = autofill(arr,size);
        
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Elements given in the list are \n[");
                for(int i=0;i<size;i++){printf("%d,",arr[i]);}
                printf("]\n");
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
        printf("Elements given in the list are \n[");
                for(int i=0;i<size;i++){printf("%d,",arr[i]);}
                printf("]\n");
        printf("\n----\n");
        } else{
        t = autofill(arr,size);
        
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Elements given in the list are \n[");
                for(int i=0;i<size;i++){printf("%d,",arr[i]);}
                printf("]\n");
        printf("\n----\n");
      }
} 
    else if(size>=1000){
      printf("\nperfect! You enter the size %d\n",size);
      printf("\nAt this point we should autofill the array,since its unrealistic to fill the array manually\nTherefore we have an option to autofill the array by that is optimised for worst case scenerio.\n\n");
      t = autofill(arr,size);
        
        printf("Time took to autofill the array is %ld microseconds\n\n",t);
        printf("Elements given in the list are \n[");
                for(int i=0;i<size;i++){printf("%d,",arr[i]);}
                printf("]\n");
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
double insertionSort(int arr[], int n)
{
    int i, key, j;
    clock_t t;
    t = clock();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    t = t - clock();
    return t;
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
double mergeSort(int arr[], int l, int r)
{
    clock_t t;
    t = clock();
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
    t = clock()-t;
    return t;
}


int main() {
  // printf greetings statement.
  clock_t t;
  printf(" \nNote : For better results please enter the size which is a little larger than human intuition and which is under computer powers! A good range of size lies between 100 to 100,000\n\n");
  
  int size = takeInput();
  printf("time taken : %f\n\n",mergeSort(arr,0,size-1));
  printArray(&arr,size);
  
  
    return 0;
}
