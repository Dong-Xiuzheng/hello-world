// 冒泡排序实现
#include <stdio.h>

void bubble_sort(int *array, int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - i -1; j++){
            if (array[j] > array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1]=tmp;
            }
	    }
    }
    return;
}

int main(){
    int array[10] = {3,1,4,2,7,5,6,8,0,9};
    bubble_sort(array, 10);
    for (int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
