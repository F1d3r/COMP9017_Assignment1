#include <stdio.h>
#include <ctype.h>


// Flags used to determine program logic.
int commaFlag = 0;
int pointFlag = 0;
int negativeFlag = 0;

void clearLine(){
    char c;
    while((c = getchar()) != '\n'){}
    printf("\n");
}


void invalid(int errcode){
    
    // Clear all flags.
    commaFlag = 0;
    pointFlag = 0;
    negativeFlag = 0;

    switch (errcode)
    {
    // Comma leading line.
    case 0:
        // Report Error message.
        printf("Invalid Input(Incorrect leading line).\n");
        // Clear the current line.
        clearLine(); 
        break;
    case 1:
        printf("Invalid Input(Multiple comma).\n");
        clearLine();
        break;
    case 2:
        printf("Invalid Input(Unexpected input order).\n");
        clearLine();
        break;
    case 3:
        printf("Invalid Input(Multiple blank space).\n");
        clearLine();
        break;
    case 4:
        printf("Invalid Input(Ungiven fractional part).\n");
        clearLine();
        break;
    case 5:
        printf("Invalid Input(Ungiven integer part).\n");
        clearLine();
        break;
    case 6:
        printf("Invalid Input(Multiple float points).\n");
        clearLine();
        break;
    case 7:
        printf("Invalid Input(Multiple minus sign).\n");
        clearLine();
        break;
    case 8:
        printf("Invalid Input(Ungiven second number).\n");
        clearLine();
        break;
    case 9:
        printf("Invalid Input(Unexpected symbol).\n");
        clearLine();
        break;
    default:
        break;
    }
}



int main(){

    // Used to read char.
    char c;
    // Track the points count read so far.
    int pointCount;
    // record previous one input.
    int preInputCode = 0; // 0 for NULL, 1 for digit, 2 for ',', 3 for '_', 4 for '.', 5 for '-';, 6 for '\n'
    float x = 0;
    float y = 0;

    while((c = getchar()) != EOF){
        if(isdigit(c)){
            printf("-%d %d- ", preInputCode, 1);
            switch (preInputCode){
            case 0:
                // W1
                printf("Writing to x.\n");
                preInputCode = 1;
                break;
            case 1:
                if(commaFlag){
                    // W2
                    printf("Writing to y.\n");
                    preInputCode = 1;
                    break;
                }else{
                    // W1
                    printf("Writing to x.\n");
                    preInputCode = 1;
                    break;
                }
            case 2:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 3:
                if(commaFlag){
                    // W2
                    printf("Writing to y.\n");
                    preInputCode = 1;
                }else{
                    // W1
                    printf("Writing to x.\n");
                    preInputCode = 1;
                }
                break;
            case 4:
                if(commaFlag){
                    // W2
                    printf("Writing to y.\n");
                    preInputCode = 1;
                }else{
                    // W1
                    printf("Writing to x.\n");
                    preInputCode = 1;
                }
                break;
            case 5:
                if(commaFlag){
                    // W2
                    printf("Writing to y.\n");
                    preInputCode = 1;
                }else{
                    // W1
                    printf("Writing to x.\n");
                    preInputCode = 1;
                }
                break;
            case 6:
                // W1
                printf("Writing to x.\n");
                preInputCode = 1;
                break;
            default:
                break;
            }
        }
        else if(c == ','){
            printf("-%d %d- ", preInputCode, 2);
            switch (preInputCode){
            case 0:
                // Invalid Code 0; Incorrect leading line.
                invalid(0); 
                preInputCode = 6;
                break;
            case 1:
                if(!commaFlag){
                    preInputCode = 2;
                    commaFlag = 1;
                    pointFlag = 0;
                    negativeFlag = 0;
                    printf("Set comma flag.\n");
                    printf("Clear point flag.\n");
                    printf("Clear negative flag.\n");
                    preInputCode = 2;
                    break;
                }else{
                    // Invalid Code 1; Multiple comma.
                    invalid(1);
                    preInputCode = 6;
                    break;
                }
            case 2:
                // Invalid Code 1; Multiple comma.
                invalid(1);
                preInputCode = 6;
                break;
            case 3:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 4:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 5:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 6:
                // Invalid Code 0; Incorrect leading line.
                invalid(0);
                preInputCode = 6;
                break;
            default:
                break;
            }
        }
        else if(c == ' '){
            printf("-%d %d- ", preInputCode, 3);
            switch (preInputCode){
            case 0:
                // Invalid Code 0; Incorrect leading line.
                invalid(0);
                preInputCode = 6;
                break;
            case 1:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 2:
                // Do nothing.
                preInputCode = 3;
                break;
            case 3:
                // Invalid Code 3; Multiple blank space.
                invalid(3);
                preInputCode = 6;
                break;
            case 4:
                // Invalid Code 4; Ungiven fractional part.
                invalid(4);
                preInputCode = 6;
                break;
            case 5:
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            case 6:
                // Invalid Code 0; Incorrect leading line.
                invalid(0);
                preInputCode = 6;
                break;
            default:
                break;
            }
        }
        else if(c == '.'){
            printf("-%d %d- ", preInputCode, 4);
            switch (preInputCode){
            case 0:
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            case 1:
                if(!pointFlag){
                    pointFlag = 1;
                    printf("Set point flag.\n");
                    preInputCode = 4;
                    break;
                }else{
                    // Invalid Code 6; Multiple floating points.
                    invalid(6);
                    preInputCode = 6;
                    break;
                }
            case 2:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            case 3:
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            case 4:
                // Invalid Code 6; Multiple floating points.
                invalid(6);
                preInputCode = 6;
                break;
            case 5:
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            case 6:
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            default:
                break;
            }
        }
        else if(c == '-'){
            printf("-%d %d- ", preInputCode, 5);
            switch (preInputCode){
            case 0:
                negativeFlag = 1;
                printf("Set negative flag.\n");
                preInputCode = 5;
                break;
            case 1:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 2:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                preInputCode = 6;
                break;
            case 3:
                negativeFlag = 1;
                printf("Set negative flag.\n");
                preInputCode = 5;
                break;
            case 4:
                // Invalid Code 2; Unexpected input order.
                invalid(2);
                // Invalid Code 4; Ungiven fractional part.
                invalid(4);
                preInputCode = 6;
                break;
            case 5:
                // Invalid Code 7; Multiple minus sign.
                invalid(7);
                preInputCode = 6;
                break;
            case 6:
                negativeFlag = 1;
                printf("Set negative flag.\n");
                preInputCode = 5;
                break;
            default:
                break;
            }
        }
        else if(c == '\n'){
            printf("-%d %d- ", preInputCode, 6);
            switch (preInputCode){
            case 0:
                commaFlag = 0;
                pointFlag = 0;
                negativeFlag = 0;
                preInputCode = 6;
                printf("Clear comma flag.\n");
                printf("Clear point flag.\n");
                printf("Clear negative flag.\n\n");
                preInputCode = 6;
                break;
            case 1:
                if(commaFlag){
                    commaFlag = 0;
                    pointFlag = 0;
                    negativeFlag = 0;
                    printf("Clear comma flag.\n");
                    printf("Clear point flag.\n");
                    printf("Clear negative flag.\n");
                    // Check X, Y;
                    printf("Check the fraction of X and Y.\n\n");
                    preInputCode = 6;
                    break;
                }else{
                    // Invalid Code 8; Ungiven second number.
                    invalid(8);
                    preInputCode = 6;
                    break;
                }
            case 2:
                // Invalid Code 8; Ungiven second number.
                invalid(8);
                preInputCode = 6;
                break;
            case 3:
                // Invalid Code 8; Ungiven second number.
                invalid(8);
                preInputCode = 6;
                break;
            case 4:
                // Invalid Code 4; Ungiven fractional part.
                invalid(4);
                preInputCode = 6;
                break;
            case 5:
                // Invalid Code 5; Ungiven integer part.
                invalid(5);
                preInputCode = 6;
                break;
            case 6:
                commaFlag = 0;
                pointFlag = 0;
                negativeFlag = 0;
                preInputCode = 6;
                printf("Clear comma flag.\n");
                printf("Clear point flag.\n");
                printf("Clear negative flag.\n\n");
                preInputCode = 6;
                break;
            default:
                break;
            }
        }
        // Other input: '+', characters...
        else{
            printf("-%d %d- ", preInputCode, 7);
            // Invalid Code 9; Unexpected symbol.
            invalid(9);
            preInputCode = 6;
            break;
        }


    }

    printf("%d\n", pointCount);


}