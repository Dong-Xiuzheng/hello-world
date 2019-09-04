// 快速排序
#include <stdio.h>

int get_index_and_swap(int *array, int low, int high){

   int tmp = array[low];
   while (low < high){
       while(low < high && array[high] >= tmp){
           high--;
       }
       array[low] = array[high];

       while(low < high && array[low] <= tmp){
           low++;
       }
       array[high] = array[low];
   }
   array[low] = tmp;
   return low;
}

void qsort(int *array, int low, int high){
    if (low >= high){
        return;
    }

    int mid = get_index_and_swap(array, low, high);
    qsort(array, low, mid - 1);
    qsort(array, mid + 1, high);

    return;
}

int main(){
    int array[10] = {3,1,4,2,7,5,6,8,0,9};
    qsort(array, 0, 9);
    for (int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
