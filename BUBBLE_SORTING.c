#include <stdio.h>


void swap(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}


void AscendingOrder(int elements[], int index_transferred){
    for(int x=0; x<index_transferred - 1; x++){
        for(int y=0; y<index_transferred - x - 1; y++){
            if(elements[y] > elements[y + 1]){
                swap(&elements[y], &elements[y + 1]);
            }
        }
    }
}

void DescendingOrder(int elements[], int index_transferred){
    for(int x=0; x<index_transferred - 1; x++){
        for(int y=0; y<index_transferred - x - 1; y++){
            if(elements[y] < elements[y + 1]){
                swap(&elements[y], &elements[y + 1]);
            }
        }
    }
}

int main(){

    int index;

    printf("Enter how many elements: ");
    scanf("%d", &index);

    int elements[index];

    printf("Enter the elements %d times: ", index);
    for(int i=0; i<index; i++){
        scanf("%d", &elements[i]);
    }
    
    int choice;

    printf("(1)AscendingOrder\n");
    printf("(2)DescendingOrder\n");
    printf("Select from(1-2): ");
    scanf("%d",&choice );

    if(choice == 1){

        AscendingOrder(elements, index);
        printf("Ascending Order: \n");
    } else if(choice==2){
        DescendingOrder(elements, index);
        printf("Descending Order: \n");
    } else {
        printf("INVALID CHOICE!!\n");
    }


   for(int i=0; i<index; i++){
    printf("%d\n", elements[i]);
   }
}