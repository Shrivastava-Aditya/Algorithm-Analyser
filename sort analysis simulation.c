// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define msize 100000
int arr[msize];

double autofill(int arr[msize],int size)
{
    printf("Autofilling the array...\n");
        clock_t t;
        int lower = 0;
        t = clock();
        int i;
        srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % ((size*10) - lower + 1)) + lower;
    }
        t = clock() - t;
        t = (double)t;
        printf("Autofilling done.\n");
        return t;
}
double autofillworst(int arr[msize],int size)
{
    printf("Autofilling the array for worst case...\n");
        clock_t t;
        int lower = 0;
        t = clock();
        int i;
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
        t = clock() - t;
        t = (double)t;
        printf("Autofilling done.\n");
        return t;
}
void printArray(int arr[msize],int size)
{
    printf("Elements given in the list are \n[");
    for(int i=0;i<size;i++){printf("%d,",arr[i]);}
    printf("]\n\n");
}
void permissionPrint(int arr[msize],int size)
{
    int i;
    while(1)
    {
        printf("Do you want to see the array?(1/0) : ");
        scanf("%d",&i);
        if(i==1){
        printf("Array after sorting is\n");
        printArray(arr,size);
        break;
        } else if(i==0) {
            printf("You don't wish to see the array elements. Okay!\n\n"); break;
        } else {
            printf("Wrong input\n\n");
        }
        
    }
    printf("\n\n");
}
int takeInput()
{   
    printf("\nPlease enter the size of array to be sorted: ");
    int size;
    scanf("%d",&size);
    clock_t t;
    
    if(size>=100 && size <1000){
      printf("\nperfect! You enter the size %d\n",size);
      printf("\n We presume that enterring %d elements in array to be sorting will be a complex task, For this reason we have 2 auto-fillers that fills the array optimised to give you the result for Average case And Worst case scenerio\nWould you like to give automation a go. Or you'll enter the values manually?\n",size);
      printf("\nTo Autofill for the worst case press 1\nTo Autofill for Average Press 2\nTo Manually fill press 0\n");
      while(1)
      {
        printf("Enter the input : ");
        int input;
        scanf("%d",&input);
        if(input==0)
        {
            printf("Enter %d Elements manually please : ",size);
            for(int i=0;i<size;i++){
                printf("element [%d] : ",i);
                scanf("%d",&arr[i]);}
                permissionPrint(arr,size);
                break;
        }
        else if(input==2)
        {
            t = autofill(arr,size);
        
            printf("Time took to autofill the array is %ld microseconds\n\n",t);
            permissionPrint(arr,size);
            printf("\n----\n");
            break;
        }
        else if(input==1)
        {
            t=autofillworst(arr,size);
            printf("Time took to autofill the array is %ld microseconds\n\n",t);
            permissionPrint(arr,size);
            printf("\n----\n");
            break;
        }
        else{
            printf("Wrong input, Try Again\n");
        }
      }
    }
    else if(size>10 && size<100){
      printf("Good! since the size of the array is considerably fair, we have two options, either we can autofill the array using our algorithm optimised to check the Average case scenerio for sorting, or we could manually take the input.\n\n");
      printf("\nTo Autofill for the worst case press 1\nTo Autofill for Average Press 2\nTo Manually fill press 0\n");
      while(1)
      {
        printf("Enter the input : ");
        int input;
        scanf("%d",&input);
        if(input==0)
        {
            printf("Enter %d Elements manually please : ",size);
            for(int i=0;i<size;i++){
                printf("element [%d] : ",i);
                scanf("%d",&arr[i]);}
                permissionPrint(arr,size);
                break;
        }
        else if(input==2)
        {
            t = autofill(arr,size);
        
            printf("Time took to autofill the array is %ld microseconds\n\n",t);
            permissionPrint(arr,size);
            printf("\n----\n");
            break;
        }
        else if(input==1)
        {
            t=autofillworst(arr,size);
            printf("Time took to autofill the array is %ld microseconds\n\n",t);
            permissionPrint(arr,size);
            printf("\n----\n");
            break;
        }
        else{
            printf("Wrong input, Try Again\n");
        }
      }
    } 
    else if(size>=1000){
      printf("\nperfect! You enter the size %d\n",size);
      printf("\nAt this point we should autofill the array,since its unrealistic to fill the array manually\nTherefore we have an option to autofill the array by that is optimised for Average case and Worst case scenerio.\n\n");
      printf("\nPress 1 for Average case scenerio\nPress 2 for Worst Case scenerio\n");
        while(1)
        {
        printf("Enter the input : ");
        int input;
        scanf("%d",&input);
        if(input==1)
        {
            t = autofill(arr,size);
        
            printf("Time took to autofill the array is %ld microseconds\n\n",t);
            permissionPrint(arr,size);
            printf("\n----\n");
            break;
        }
        else if(input==2)
        {
            t=autofillworst(arr,size);
            printf("Time took to autofill the array is %ld microseconds\n\n",t);
            permissionPrint(arr,size);
            printf("\n----\n");
            break;
        }
        else{
            printf("Wrong input, Try Again\n");
        }
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
    t = clock() -t;
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
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
  
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
  
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
  
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
  
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
  
// The main function to that sorts arr[] of size n using 
// Radix Sort
double radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    clock_t t;
    t = clock();
    int m = getMax(arr, n);
  
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
    t = clock()-t;
    return t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
double quicksort(int a[], int p, int r)    
{
    clock_t t;
    t = clock();
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
    t = clock() - t;
    return t;
}
void sortBuffer(int arr[msize],int size)
{
    int ch;
    printf("time taken by Merge Sort: %f seconds \n\n",mergeSort(arr,0,size-1)*0.000001);
    printf("time taken by Bubble Sort: %f seconds \n\n",bubbleSort(arr,size)*0.000001);
    printf("time taken by Selection Sort: %f seconds \n\n",selectionSort(arr,size)*0.000001);
    printf("time taken by Insertion Sort: %f seconds \n\n",insertionSort(arr,size)*0.000001);
    printf("time taken by Radix Sort: %f  seconds \n\n",radixsort(arr,size)*0.000001);
    printf("time taken by quick Sort: %f seconds \n\n",quicksort(arr,0,size-1)*0.000001);
    printf("----");
    printf("\n- - After Sorting - -\n");
    permissionPrint(arr,size);
}
double sortComparator(int arr[msize],int size)
{
    clock_t t1,t2;
    int ch1,ch2;
    printf("\nWe are comparing 2 sort functions\n");
    printf("Press the number for according to thee sorting function you wanna compare.\n");
    printf("1 : Bubble Sort\n2 : Selection Sort\n3 : MergeSort\n4 : Insertion sort\n5 : Radix Sort\n6 : Quick sort\n");
    printf("Enter your choice : ");
    scanf("%d",&ch1);
    switch(ch1)
        {
            case 1 : t1 = bubbleSort(arr,size); break;
            case 2 : t1 = selectionSort(arr,size); break;
            case 3 : t1 = mergeSort(arr,0,size-1); break;
            case 4 : t1 = insertionSort(arr,size);break;
            case 5 : t1 = radixsort(arr,size); break;
            case 6 : t1 = quicksort(arr,0,size-1);break;
        }
    printf("Enter the other sort function you wanna compare with.\n");
    printf("Enter your choice : ");
    scanf("%d",&ch2);
    switch(ch2)
        {
            case 1 : t2 = bubbleSort(arr,size); break;
            case 2 : t2 = selectionSort(arr,size); break;
            case 3 : t2 = mergeSort(arr,0,size-1); break;
            case 4 : t2 = insertionSort(arr,size);break;
            case 5 : t2 = radixsort(arr,size); break;
            case 6 : t2 = quicksort(arr,0,size-1);break;
        }
    printf("\n\nThe Time taken by 1st function of choice is :  %ld microseconds\nThe time taken by 2nd function of choice is : %ld microseconds\n",t1,t2);
    printf("The time difference is, %ld microseconds: \n",t2-t1);
    if(t2>t1){
        printf("\nWe can simpy say that 1st function is faster\n");
    }
    if(t1>t2){
    printf("\nWe can simpy say that 2nd function is faster\n\n\n");
    }
    return t2-t1;
}
void description()
{
    printf("\nThis project is Known as sort algorithm analyser\nThe main theme of this project is comparison between two sorts.\nIn this project we will be knowing in detail about each sort\nThe sorts in this project are : Bubble sort, Selection sort, Merge sort, Insertion sort, Radix sort and Quick sort\n\n");
}
void sortDetails()
{
    int ch;
    printf("\n----\n");
    while(1)
    {
    printf("Press the number for according to the sorting function you wanna know about.\n");
    printf("1 : Bubble Sort\n2 : Selection Sort\n3 : MergeSort\n4 : Insertion sort\n5 : Radix Sort\n6 : Quick sort\nAny other number for exit\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
        {
            case 1 : printf("\nBubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.\nWorst Case Time Complexity: O(n*n)\n");break;
            case 2 : printf("\nThe selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.\nTime Complexity: O(n2) as there are two nested loops.\n");break;
            case 3 : printf("\nMerge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves.\nTime Complexity: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.\nTime Complexity: O(nlogn)\n");break;
            case 4 : printf("Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.\nTime Complexity: O(n^2) \n");break;
            case 5 : printf("\nRadix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.\n");break;
            case 6 : printf("\nQuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. \nBest-case performance: O(n log n)\n");break;
            default : printf("\n\nExiting Now...\n\n"); return;
        }
    }
}

int main() {
  // printf greetings statements.
  clock_t t;
  int ch;
  description();
  printf("\nThe main purpose of the project is to get you famialarise with some of the very basic building block of computer algorithms,\nThe project works in following steps\n1. We give input\n2. The Input gets Arranged in array\n3. We select the required option from main menu\n3. There are some Special Function Like sort comparator That is used to compare between to sorting algorithms\n4. Array gets sorted\n5. Time gets recorded\n6. We can analyse the different Time taken by the different sorting algorithms\n\nPress Any key To Continue\n");
  getchar();
  printf("\nPress Any Key to Take input\n");
  getchar();
  printf(" \nNote : For better results please enter the size which is a little larger than human intuition and which is under computer powers! A good range of size lies between 100 to 100,000\n\n");
  
  int size = takeInput();
  while(1)
  {
      printf("Press 1 for project desription\nPress 2 for details about sort functions we are using in this project\nPress 3 for sort Buffer\nPress 4 for comparing 2 sort function\npress 5 for more info on sort function\nPress anyother key to return\n\n");
      printf("Enter the valid input : ");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1 : description(); break;
          case 2 : sortDetails();break;
          case 3 : sortBuffer(arr,size);break;
          case 4 : sortComparator(arr,size);break;
        //  case 5 : moreInfo();break;
          default : return 0;
      }
  }
    return 0;
}

//Add interative quick sort and merge sort.
