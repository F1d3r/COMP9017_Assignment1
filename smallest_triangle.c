#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Dynamic memory version.
// // Point List.
// struct PointList{
//     float x;
//     float y;
//     struct PointList* next;
// };

// // Create new Point List.
// struct PointList* List(){
//     struct PointList* head = (struct PointList*)malloc(sizeof(struct PointList));
    
//     head->next = NULL;
//     return head;
// }

// void insertPoint(struct PointList* head_of_List, float x, float y){
//     struct PointList* newPoint = (struct PointList*)malloc(sizeof(struct PointList));
//     // Give values to the new Point.
//     newPoint->x = x;
//     newPoint->y = y;
//     newPoint->next = NULL;
//     // Maintance the connections.
//     struct PointList* p = head_of_List;
//     // Update the pointer through the list.
//     while(p->next != NULL){
//         p = p->next;
//     }

//     p->next = newPoint;

// }

int main(){
    
    // int num;
    // int odd_even = 1;

    // while(scanf("%f", &num) != EOF){
    //     printf("%.2f", num);
    //     if(odd_even == 1){
    //         printf(", ");
    //         odd_even = 2;
    //     }else if(odd_even == 2){
    //         printf("\n");
    //         odd_even = 1;
    //     }
    //     getchar();
    // }



    float points[1000][2];
    float x;
    float y;
    int index = 0;
    int numOrder = 1;
    int valid = 1;
    char buff[100];

    // Read the stdin to the end.
    while(!feof(stdin)){
        // Read the input number, store it into the x.
        valid = scanf("%f", &x);
        // Check if there is only two decimal places of the num.
        if(x != roundf(x * 100) / 100){
            valid = 0;
        }

        

        // If the input is not valid, read the entire line and go to the next loop with next line.
        if(!valid){
            scanf("%[^\n]s", buff);
            printf("Invalid!\n");
            continue;;
        }

        printf("First number read: %f\n", x);


        // Read the input number, store it into the y.
        valid = scanf("%f", &y);
        // Check if there is only two decimal places of the num.
        if(y != roundf(y * 100) / 100){
            valid = 0;
        }

        // If the input is not valid, read the entire line and go to the next loop with next line.
        if(!valid){
            scanf("%[^\n]s", buff);
            printf("Invalid! Abort!\n");
            continue;;
        }

        printf("Second number read: %f\n", y);

        index++;
    }
    



    // while(!feof(stdin)){
    //     if(!(check = scanf("%f", &num))){
    //             scanf("%[^\n]s", buff);
    //     }
    //     printf("%d\n", check);
    //     printf("%.2f\n", num);
    //     if(numOrder == 1){
    //         if(check){
    //             if(num != roundf(num * 100)/100){
    //                 printf("invalid1!\n");
    //                 scanf("%[^\n]s", buff);
    //             }else{
    //                 printf("First number read: %.2f\n", num);
    //                 numOrder = 2;
    //             }
    //         }
    //     }else if(numOrder == 2){
    //         if(check){
    //             if(num != roundf(num * 100)/100){
    //                 printf("invalid2!, abort!\n");
    //                 scanf("%[^\n]s", buff);
    //                 numOrder = 1;
    //             }else{
    //                 printf("Second number read: %.2f\n", num);
    //                 numOrder = 1;
    //             }
    //         }
            
    //     }
    // }



    return 0;
}