#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Program status tracker.
int commaFlag = 0;
int pointFlag = 0;
int negativeFlag = 0;
int zeroFlag = 0;
int validFlag = 1;
int digitCount = 0;
int pointCount = 0;
int preInputCode = 0;
int charCount = 0;
int currentInputCode = 0;

float points[1000][2]; // Used to store points.
int minDistPoint1 = 0;
int minDistPoint2 = 0;
int minDistPoint3 = 0;
float minX1 = 0;
float minX2 = 0;
float minX3 = 0;
float minY1 = 0;
float minY2 = 0;
float minY3 = 0;
float minDistSum = 1000;
float x = 0;
float y = 0;

char c; // Used to read char.


float calDist(float x1, float y1, float x2, float y2){
    float dist;
    dist = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
    return dist;
}


float totalDist(float x1, float y1, float x2, float y2, float x3, float y3){
    float distSum;
    distSum = calDist(x1, y1, x2, y2) + calDist(x1, y1, x3, y3) + calDist(x2, y2, x3, y3);
    return distSum;
}


int isTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
    float area = 0;;
    area = 0.5 * abs((x1*(y2 - y3) + x2*(y3-y1) + x3*(y1-y2)));

    if(area > 0.001){
        return 1;
    }

    return 0;
}


// Clear the current line by read all characters.
void clearLine(){
    while (c != '\n' && !feof(stdin))
    {
        c = getchar();
        charCount ++;
    }
    // printf("A line has been claer.\n");
}


// Report invalid message.
void invalid(int errCode){
    // printf("Invalid Code %d: ", errCode);

    switch (errCode)
    {
    // Invalid code 0: Other exception.
    case 0:
        // printf("Unexpected error.\n");
        break;
    // Invalid code 1: Incorrect line leading.
    case 1:
        // printf("Incorrect line leading.\n");
        break;
    // Invalid code 2: Incorrect input format/order.
    case 2:
        // printf("Incorrect input format/order.\n");
        break;
    // Invalid code 3: Out of range.
    case 3:
        // printf("Out of range.\n");
        break;
    // Invalid code 4: Duplicated point.
    case 4:
        // printf("Duplicated point.\n");
    // Invalid code 5: Unexpected symbol.
    case 5:
        // printf("Unexpected symbol.\n");
        break;
    // Invalid code 6: Multiple float point.
    case 6:
        // printf("Multiple float point.\n");
        break;
    // Invalid code 7: Multiple comma.
    case 7:
        // printf("Multiple comma.\n");
        break;
    // Invalid code 8: Multiple blank space.
    case 8:
        // printf("Multiple blank space.\n");
        break;
    // Invalid code 9: Multiple minus sign.
    case 9:
        // printf("Multiple minus sign.\n");
        break;
    // Invalid code 10: Exceed 2 decimal place.
    case 10:
        // printf("Exceed 2 decimal place.\n");
        break;
    // Invalid code 11: Ungiven integer part.
    case 11:
        // printf("Ungiven integer part.\n");
        break;
    // Invalid code 12: Ungiven fractional part.
    case 12:
        // printf("Ungiven fractional part.\n");
        break;
    // Invalid code 13: Ungiven second number.
    case 13:
        // printf("Ungiven second number.\n");
        break;
    // Invalid code 14: Duplicated point.
    case 14:
        // printf("Duplicated point.\n");
        break;
    // Invalid code 15: Multiple integer part zeros.
    case 15:
        // printf("Multiple integer part zeros.\n");
        break;
    // Invalid code 16: Blank line.
    case 16:
        break;
        // printf("Blank line.\n");
    default:
        break;
    }

    clearLine();
    commaFlag = 0;
    pointFlag = 0;
    negativeFlag = 0;
    zeroFlag = 0;
    digitCount = 0;
    validFlag = 0;
    // printf("Clear comma flag.\n");
    // printf("Clear point flag.\n");
    // printf("Clear negative flag.\n");
    // printf("Clear zero leading flag.\n");
    // printf("Clear digit count.\n\n");
    preInputCode = 6;
    x = 0;
    y = 0;
}


// When get digit input, update the number.
void updateNum(int input){
    float * numPrt;

    numPrt = commaFlag ? &y : &x;

    if(pointFlag){
        if(negativeFlag){
            *numPrt = *numPrt - input * pow(0.1, digitCount);
        }else{
            *numPrt = *numPrt + input * pow(0.1, digitCount);
        }
    }else{
        if(negativeFlag){
            *numPrt = *numPrt * 10 - input;
        }else{
            *numPrt = *numPrt * 10 + input;
        }
    }

    // printf("The %c has been updated: %f.\n", commaFlag ? 'y' : 'x', *numPrt);
}


void writePoint(){
    // Check duplicated.
    int duplicate = 0;
    // printf("%f, %f\n", x, y);
    int outOfRange = (x < 50 && x > -50 && y < 50 && y > -50) ? 0 : 1;

    for(int i = 0; i < pointCount; i++){
        if(points[i][0] == x && points[i][1] == y){
            duplicate = 1;
        }
    }

    if(outOfRange){
        invalid(3);
    }else{
        if(duplicate){
            invalid(4);
        }else{
            points[pointCount][0] = x;
            points[pointCount][1] = y;
            pointCount++;
            // printf("A new point added. There have been %d points now.\n\n", pointCount); 
        }
    }

    // Clear x and y.
    x = 0;
    y = 0;
    
}


void readInput(){

    while((c = getchar()) !=EOF){
        charCount++;

        // Update current input code.
        if(isdigit(c) && c != '0')
        {
            currentInputCode = 1;
        }
        else if(c == ',')
        {
            currentInputCode = 2;
        }
        else if (c == ' ')
        {
            currentInputCode = 3;
        }
        else if (c == '.')
        {
            currentInputCode = 4;
        }
        else if (c == '-')
        {
            currentInputCode = 5;
        }
        else if (c == '\n')
        {
            currentInputCode = 6;
        }
        else if (c == '0')
        {
            currentInputCode = 7;
        }
        else{
            currentInputCode = 0;
        }
        
        // printf("--%d--%d--\n", preInputCode, currentInputCode);

        if(c != '\n'){
            // printf("A char read: %c\n", c);
        }else{
            // printf("A char read: \\n\n");
        }

        validFlag = 1;
        // Process according to current and previous input.
        switch (currentInputCode)
        {
            // Get an unexpected symbol.
            case 0:
                // Invalid.
                invalid(5);
                break;
            // Get a digit number exclusive 0.
            case 1:
                switch (preInputCode)
                {
                case 0:
                    // Write
                    updateNum((c-48));
                    break;
                case 1:
                    // Check validation.
                    if(pointFlag){
                        if(digitCount == 2){
                            // Invalid.
                            invalid(10);
                            break;
                        }else{
                            // Update digit count;
                            digitCount ++;
                            // printf("Digit updated. %d decimal now.\n", digitCount);
                        }
                    }

                    // Write number
                    updateNum((c-48));
                    break;
                case 2:
                    // Invalid.
                    invalid(2);
                    preInputCode = 6;
                    break;
                case 3:
                    // Write number
                    updateNum((c-48));
                    break;
                case 4:
                    // Update digit count.
                    digitCount ++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);

                    //Write number.
                    updateNum((c-48));
                    break;
                case 5:
                    //Write number.
                    updateNum((c-48));
                    break;
                case 6:
                    //Write number.
                    updateNum((c-48));
                    break;
                case 7:
                    if(pointFlag){
                        if(digitCount == 2){
                            invalid(10);
                            break;
                        }
                        digitCount++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);
                    }
                    // Check validation
                    else if(zeroFlag){
                        // Invalid.
                        invalid(15);
                        break;
                    }

                    //Write number.
                    updateNum((c-48));
                    break;
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
                break;
            // Get a comma.,
            case 2:
                switch (preInputCode)
                {
                case 0:
                    // Invalid.
                    invalid(2);
                    break;
                case 1:
                    if(commaFlag){
                        // Invalid.
                        invalid(7);
                        break;
                    }
                    commaFlag = 1;
                    pointFlag = 0;
                    negativeFlag = 0;
                    zeroFlag = 0;
                    digitCount = 0;
                    // printf("Comma flag set.\n");
                    // printf("Point flag clear.\n");
                    // printf("Negative flag clear.\n");
                    // printf("Zero leading flag clear.\n");
                    // printf("Digit count clear.\n");
                    break;
                case 2:
                    // Invalid.
                    invalid(7);
                    break;
                case 3:
                    // Invalid.
                    invalid(2);
                    break;
                case 4:
                    // Invalid.
                    invalid(12);
                    break;
                case 5:
                    // Invalid.
                    invalid(11);
                    break;
                case 6:
                    // Invalid.
                    invalid(1);
                    break;
                case 7:
                    if(commaFlag){
                        // Invalid.
                        invalid(7);
                        break;
                    }
                    commaFlag = 1;
                    pointFlag = 0;
                    negativeFlag = 0;
                    zeroFlag = 0;
                    digitCount = 0;
                    // printf("Comma flag set.\n");
                    // printf("Point flag clear.\n");
                    // printf("Negative flag clear.\n");
                    // printf("Zero leading flag clear.\n");
                    // printf("Digit count clear.\n");
                    break;
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
                break;
            // Get a blank space.
            case 3:
                switch (preInputCode)
                {
                case 0:
                    // Invalid.
                    invalid(1);
                    break;
                case 1:
                    // Invalid.
                    invalid(2);
                    break;
                case 2:
                    break;
                case 3:
                    // Invalid.
                    invalid(8);
                    break;
                case 4:
                    // Invalid.
                    invalid(12);
                    break;
                case 5:
                    // Invalid.
                    invalid(2);
                    break;
                case 6:
                    // Invalid.
                    invalid(1);
                    break;
                case 7:
                    // Invalid.
                    invalid(2);
                    break;
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
                break;
            // Get a float point.
            case 4:
                switch (preInputCode)
                {
                case 0:
                    // Invalid.
                    invalid(11);
                    break;
                case 1:
                    if(pointFlag){
                        // Invalid.
                        invalid(6);
                        break;
                    }else{
                        pointFlag = 1;
                        zeroFlag = 0;
                        // printf("Zero flag clear.\n");
                        // printf("Point flag set.\n");
                    }
                    break;
                case 2:
                    // Invalid.
                    invalid(2);
                    break;
                case 3:
                    // Invalid.
                    invalid(11);
                    break;
                case 4:
                    // Invalid.
                    invalid(6);
                    break;
                case 5:
                    // Invalid.
                    invalid(11);
                    break;
                case 6:
                    // Invalid.
                    invalid(11);
                    break;
                case 7:
                    if(pointFlag){
                        // Invalid.
                        invalid(6);
                        break;
                    }else{
                        pointFlag = 1;
                        zeroFlag = 0;
                        // printf("Zero flag clear.\n");
                        // printf("Point flag set.\n");
                    }
                    break;
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
                break;
            // Get a minus sign.
            case 5:
                switch (preInputCode)
                {
                case 0:
                    negativeFlag = 1;
                    // printf("Negative point set.\n");
                    break;
                case 1:
                    // Invalid.
                    invalid(2);
                    break;
                case 2:
                    // Invalid.
                    invalid(2);
                    break;
                case 3:
                    negativeFlag = 1;
                    // printf("Negative point set.\n");
                    break;
                case 4:
                    // Invalid.
                    invalid(2);
                    break;
                case 5:
                    // Invalid.
                    invalid(9);
                    break;
                case 6:
                    negativeFlag = 1;
                    // printf("Negative point set.\n");
                    break;
                case 7:
                    // Invalid.
                    invalid(2);
                    break;
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
                break;
            // Get a new line.
            case 6:
                switch (preInputCode)
                {
                case 0:
                    commaFlag = 0;
                    pointFlag = 0;
                    negativeFlag = 0;
                    zeroFlag = 0;
                    digitCount = 0;
                    // printf("Comma flag clear.\n");
                    // printf("Point flag clear.\n");
                    // printf("Negative flag clear.\n");
                    // printf("Zero leading flag clear.\n");
                    // printf("Digit count clear.\n\n");
                    break;
                case 1:
                    if(commaFlag){
                        commaFlag = 0;
                        pointFlag = 0;
                        negativeFlag = 0;
                        zeroFlag = 0;
                        digitCount = 0;
                        // printf("Comma flag clear.\n");
                        // printf("Point flag clear.\n");
                        // printf("Negative flag clear.\n");
                        // printf("Zero leading flag clear.\n");
                        // printf("Digit count clear.\n");
                        writePoint();
                        break;
                    }else{
                        // Invalid.
                        invalid(13);
                        break;
                    }
                case 2:
                    // Invalid.
                    invalid(13);
                    break;
                case 3:
                    // Invalid.
                    invalid(13);
                    break;
                case 4:
                    // Invalid.
                    invalid(12);
                    break;
                case 5:
                    // Invalid.
                    invalid(11);
                    break;
                case 6:
                    invalid(16);
                    // commaFlag = 0;
                    // pointFlag = 0;
                    // negativeFlag = 0;
                    // zeroFlag = 0;
                    // digitCount = 0;
                    // // printf("Comma flag clear.\n");
                    // // printf("Point flag clear.\n");
                    // // printf("Negative flag clear.\n");
                    // // printf("Zero leading flag clear.\n");
                    // // printf("Digit count clear.\n\n");
                    break;
                case 7:
                    if(commaFlag){
                        commaFlag = 0;
                        pointFlag = 0;
                        negativeFlag = 0;
                        zeroFlag = 0;
                        digitCount = 0;
                        // printf("Comma flag clear.\n");
                        // printf("Point flag clear.\n");
                        // printf("Negative flag clear.\n");
                        // printf("Zero leading flag clear.\n");
                        // printf("Digit count clear.\n");
                        writePoint();

                        break;
                    }else{
                        // Invalid.
                        invalid(13);
                        break;
                    }
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
            break;
            // Get a '0'.
            case 7:
                switch (preInputCode)
                {
                case 0:
                    //Write number.
                    updateNum((c-48));
                    zeroFlag = 1;
                    // printf("Zero leading flag set.\n\n");
                    break;
                case 1:
                    if(pointFlag){
                        digitCount ++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);
                    }
                    //Write number.
                    updateNum((c-48));
                    break;
                case 2:
                    // Invalid.
                    invalid(2);
                    break;
                case 3:
                    //Write number.
                    updateNum((c-48));
                    zeroFlag = 1;
                    // printf("Zero leading flag set.\n");
                    break;
                case 4:
                    digitCount ++;
                    // printf("Digit updated. %d decimal now.\n", digitCount);
                    //Write number.
                    updateNum((c-48));
                    break;
                case 5:
                    zeroFlag = 1;
                    // printf("Zero leading flag set.\n");
                    //Write number.
                    updateNum((c-48));
                    break;
                case 6:
                    //Write number.
                    updateNum((c-48));
                    zeroFlag = 1;
                    // printf("Zero leading flag set.\n");
                    break;
                case 7:
                    if(zeroFlag){
                        // Invalid.
                        invalid(15);
                        break;
                    }

                    // Update digit count.
                    if(pointFlag){
                        if(digitCount == 2){
                            invalid(10);
                            break;
                        }
                        digitCount++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);
                    }

                    //Write number.
                    updateNum((c-48));
                    break;
                default:
                    // Invalid.
                    invalid(0);
                    break;
                }
                break;
            default:
                break;
        }

        if(currentInputCode == 6){
            charCount = 0;
        }
        

        if(validFlag){
            preInputCode = currentInputCode;
        }
        
        // printf("valid: %d\n", validFlag);
    }


    // printf("valid: %d", validFlag);
    // Commit last point.
    if(validFlag && charCount != 0){
        writePoint();
    }

    
}


void printPoint(int count){
    printf("%.2f, %.2f\n", points[count][0], points[count][1]);
}


void printAllPoints(){
    // printf("%d points read.\n", pointCount);
    for(int i = 0; i < pointCount; i++){
        printPoint(i);
    }
}


void findClosest(){
    minDistSum = 1000;

    // If there is not sufficient points to form a triangle.
    if(pointCount < 3){
        // Just print all points.
        for(int i = 0; i < pointCount; i++){
            printPoint(i);
        }
        // Determine it is no a triangle.
        // printf("This is not a triangle\n");
    }else{
        // Find the closest 3 points.
        // int count;
        for(int i = 0; i < pointCount; i++){
            for(int j = 0; j < pointCount; j++){
                // Skip the duplicated points.
                if(j == i){
                    // printf("Duplicate.\n");
                    continue;
                }

                for(int k = 0; k < pointCount; k++){
                    // Skip the duplicated points.
                    if(k == j || k == i){
                        // printf("Duplicate.\n");
                        continue;
                    }else{
                        float distSum = totalDist(points[k][0], points[k][1], points[j][0], points[j][1], points[i][0], points[i][1]);
                        
                        if(distSum < minDistSum){
                            minDistSum = distSum;
                            minDistPoint1 = i;
                            minDistPoint2 = j;
                            minDistPoint3 = k;
                        }
                    }
                }
            }
        }

        // Print the information of three closest points.
        printPoint(minDistPoint1);
        printPoint(minDistPoint2);
        printPoint(minDistPoint3);
        

        // Check if they forms a triangle.
        if(isTriangle(points[minDistPoint1][0], points[minDistPoint1][1], points[minDistPoint2][0], points[minDistPoint2][1], points[minDistPoint3][0], points[minDistPoint3][1])){
            // printf("This is a triangle\n");
        }else{
            // printf("This is not a triangle\n");
        }
    }
}


int main(){
    
    readInput();

    printf("read %d points\n", pointCount);

    //printAllPoints();

    findClosest();
}