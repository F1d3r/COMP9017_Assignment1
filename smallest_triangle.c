#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calDist(float x1, float y1, float x2, float y2, float x3, float y3){
    return sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2))) + sqrt((pow((x1 - x3), 2) + pow((y1 - y3), 2))) + sqrt((pow((x3 - x2), 2) + pow((y3 - y2), 2)));
}

int isTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
    float area = 0;;
    area = 0.5 * abs((x1*(y2 - y3) + x2*(y3-y1) + x3*(y1-y2)));

    if(area > 0.001){
        return 1;
    }else{
        return 0;
    }

}

int main(){

    float points[1000][2];
    float x;
    float y;
    int index = 0;
    int valid = 1;
    char buff[100];
    float minDist = 142;
    float minX1 = 0;
    float minX2 = 0;
    float minX3 = 0;
    float minY1 = 0;
    float minY2 = 0;
    float minY3 = 0;

    // Read the stdin to the end.
    while(!feof(stdin)){

        // Read the first input number, store it into the x.
        valid = scanf("%f", &x);
        // Check if there is only two decimal places of the num.
        if(x != roundf(x * 100) / 100){
            valid = 0;
        }

        // If the input is not valid, read the entire line and go to the next loop with next line.
        if(!valid){
            //scanf("%[^\n]s", buff);
            //if(fgets(buff, sizeof(buff), stdin))
            fgets(buff, sizeof(buff), stdin);
            printf("Invalid!\n");
            continue;;
        }


        // Read the input number, store it into the y.
        getchar();
        getchar();
        

        // Read the second input number, store it into y.
        valid = scanf("%f", &y);
        // Check if there is only two decimal places of the num.
        if(y != roundf(y * 100) / 100){
            valid = 0;
        }

        // If the input is not valid, read the entire line and go to the next loop with next line.
        if(!valid){
            //scanf("%[^\n]s", buff);
            //if(fgets(buff, sizeof(buff), stdin))
            fgets(buff, sizeof(buff), stdin);
            printf("Invalid! Abort!\n");
            continue;;
        }

        getchar();

        points[index][0] = x;
        points[index][1] = y;
        
        index++;
    }

    // Print message to report the read points.
    printf("read %d points\n", index-1);

    // Print all points.
    // for(int i = 0; i < index-1; i ++){
    //     printf("%.2f, %.2f\n", points[i][0], points[i][1]);
    // }


    if(index < 3){
        for(int i = 0; i < index - 1; i++){
            printf("%.2f, %.2f\n", points[index][0], points[index][1]);
        }
        printf("This is not a triangle\n");
    }else{
        // Find the closest 3 points.
        // int count;
        for(int i = 0; i < index-1; i++){
            for(int j = 0; j < index-1; j++){
                if(j == i){
                    // count++;
                    // printf("Duplicate %d.\n", count);
                    continue;
                }

                for(int k = 0; k < index -1; k++){
                    if(k == j || k == i){
                        // count++;
                        // printf("Duplicate %d.\n", count);
                        continue;
                    }else{
                        float temp = calDist(points[k][0], points[k][1], points[j][0], points[j][1], points[i][0], points[i][1]);
                        if(temp < minDist){
                        minDist = temp;
                        minX1 = points[k][0];
                        minX2 = points[j][0];
                        minX3 = points[i][0];
                        minY1 = points[k][1];
                        minY2 = points[j][1];
                        minY3 = points[i][1];
                        }
                    }


                }
            }
        }

    
        printf("%.2f, %.2f\n", minX3, minY3);
        printf("%.2f, %.2f\n", minX2, minY2);
        printf("%.2f, %.2f\n", minX1, minY1);

        // Check if they forms a triangle.
        if(isTriangle(minX1, minY1, minX2, minY2, minX3, minY3)){
            printf("This is a triangle\n");
        }else{
            printf("This is not a triangle\n");
        }
    }


    return 0;
}

