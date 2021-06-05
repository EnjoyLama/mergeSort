#include <stdio.h>
#include <stdlib.h>

int array[] = {38,27,43,3,9,82,10};
int array_size = sizeof(array)/sizeof(array[0]);

void printArray(int *parray, int array_size){

    while(array_size){
        printf("%d ", *parray);
        parray++;
        array_size--;
    }
    printf("\n");
}

void merge(int *parray, int begin, int medium, int end){
    int index_first = 0;
    int index_sec = 0;

    int size_array_first = medium - begin +1;
    int size_array_sec = end-medium;

    int *cpy_first = (int *) malloc(size_array_first*sizeof(int));
        if(cpy_first == 0){
            puts("memory error");
            exit(1);
        }
   
    int *cpy_sec = (int *) malloc(size_array_sec*sizeof(int));
        if(cpy_sec == 0){
            puts("memory error 2");
            exit(1);
        }

    int index_origin = begin;
    for(int element = 0; element < size_array_first; element++){
        *(cpy_first+element) = *(parray+element+index_origin);
        //printf("cpy_first element : %d\n", cpy_first[element]);
    }
    puts("After Copy First\n");
    printArray(cpy_first, size_array_first);
    index_origin = medium+1;
    for(int element = 0; element < size_array_sec; element++){
        *(cpy_sec+element) = *(parray+element+index_origin);

    }


    index_origin = begin;
    //printArray(cpy_first, sizeof(cpy_first)/sizeof(cpy_first[0]));
    //printArray(cpy_sec, sizeof(cpy_sec)/sizeof(cpy_sec[0]));
/*
    int index = 0;
    while(cpy_first[index_first] < cpy_sec[index_sec])
    {
        *(parray+begin+index) = cpy_first[index_first];
        index_first++;
        index++;
    }
*/
    while(index_first < size_array_first && index_sec < size_array_sec){
        if(cpy_first[index_first] < cpy_sec[index_sec]){
            //*(parray+begin+index_first) = cpy_first[index_first];
            //*(parray+medium+index_sec) = cpy_sec[index_sec];
            index_sec++;
            index_first++;
        }
        else if(cpy_first[index_first] >= cpy_sec[index_sec]){
            *(parray+begin+index_first) = cpy_sec[index_sec];
            *(parray+medium+index_sec+1) = cpy_first[index_first];
            index_first++;
            index_sec++;
        }
        index_origin++;
    }

    while(index_first < size_array_first){
        *(parray+index_origin) = cpy_first[index_first];
        index_first++;
        index_origin++;
    }
    while(index_sec < size_array_sec){
        *(parray+index_origin) = cpy_sec[index_sec];
        index_sec++;
        index_origin++;
    }
    
    if(cpy_first)
        free(cpy_first);
    if(cpy_sec)
        free(cpy_sec);

}

void divide(int *parray, int begin, int end){
    if(begin<end){
        printf("divide indexes : %d,%d\n",begin,end);
        printArray(array, array_size);

        int medium = (end-begin)/2 + begin;

        divide(parray, begin, medium);
        divide(parray, medium+1, end);

        merge(parray, begin, medium, end);
    }
}


int main(){
    divide(&array[0], 0, array_size-1);
    printArray(array, array_size);

    return 0;
}





