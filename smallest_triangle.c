#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Program status tracker.
int comma_flag = 0;
int point_flag = 0;
int negative_flag = 0;
int zero_flag = 0;
int valid_flag = 1;
int digit_count = 0;
int point_count = 0;
int pre_input_code = 0;
int char_count = 0;
int current_input_code = 0;

float points[1000][2]; // Used to store points. The capacity of the program is 1000.
int closest_point_1 = 0;
int closest_point_2 = 0;
int closest_point_3 = 0;
float min_dist_sum = 1000;
float x = 0;
float y = 0;

char c; // Used to read char.


float cal_dist(float x1, float y1, float x2, float y2){
    float dist;
    dist = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
    return dist;
}


float calculate_total_distance(float x1, float y1, float x2, float y2, float x3, float y3){
    float distSum;
    distSum = cal_dist(x1, y1, x2, y2) + cal_dist(x1, y1, x3, y3) + cal_dist(x2, y2, x3, y3);
    return distSum;
}


int is_triangle(float x1, float y1, float x2, float y2, float x3, float y3){
    float area = 0;;
    area = 0.5 * abs((x1*(y2 - y3) + x2*(y3-y1) + x3*(y1-y2)));

    if(area > 0.001){
        return 1;
    }

    return 0;
}


// Clear the current line by read all characters.
void clear_line(){
    while (c != '\n' && !feof(stdin))
    {
        c = getchar();
        char_count ++;
    }
    // printf("A line has been claer.\n");
}


// Report invalid message.
void report_invalid(int errCode){
    // Send report message.
    // printf("Invalid Code %d: ", errCode);

    // switch (errCode)
    // {
    // // Invalid code 0: Other exception.
    // case 0:
    //     printf("Unexpected error.\n");
    //     break;
    // // Invalid code 1: Incorrect line leading.
    // case 1:
    //     printf("Incorrect line leading.\n");
    //     break;
    // // Invalid code 2: Incorrect input format/order.
    // case 2:
    //     printf("Incorrect input format/order.\n");
    //     break;
    // // Invalid code 3: Out of range.
    // case 3:
    //     printf("Out of range.\n");
    //     break;
    // // Invalid code 4: Duplicated point.
    // case 4:
    //     printf("Duplicated point.\n");
    // // Invalid code 5: Unexpected symbol.
    // case 5:
    //     printf("Unexpected symbol.\n");
    //     break;
    // // Invalid code 6: Multiple float point.
    // case 6:
    //     printf("Multiple float point.\n");
    //     break;
    // // Invalid code 7: Multiple comma.
    // case 7:
    //     printf("Multiple comma.\n");
    //     break;
    // // Invalid code 8: Multiple blank space.
    // case 8:
    //     printf("Multiple blank space.\n");
    //     break;
    // // Invalid code 9: Multiple minus sign.
    // case 9:
    //     printf("Multiple minus sign.\n");
    //     break;
    // // Invalid code 10: Exceed 2 decimal place.
    // case 10:
    //     printf("Exceed 2 decimal place.\n");
    //     break;
    // // Invalid code 11: Ungiven integer part.
    // case 11:
    //     printf("Ungiven integer part.\n");
    //     break;
    // // Invalid code 12: Ungiven fractional part.
    // case 12:
    //     printf("Ungiven fractional part.\n");
    //     break;
    // // Invalid code 13: Ungiven second number.
    // case 13:
    //     printf("Ungiven second number.\n");
    //     break;
    // // Invalid code 14: Duplicated point.
    // case 14:
    //     printf("Duplicated point.\n");
    //     break;
    // // Invalid code 15: Multiple integer part zeros.
    // case 15:
    //     printf("Multiple integer part zeros.\n");
    //     break;
    // // Invalid code 16: Blank line.
    // case 16:
    //     break;
    //     printf("Blank line.\n");
    // default:
    //     break;
    // }

    clear_line();
    comma_flag = 0;
    point_flag = 0;
    negative_flag = 0;
    zero_flag = 0;
    digit_count = 0;
    valid_flag = 0;
    // printf("Clear comma flag.\n");
    // printf("Clear point flag.\n");
    // printf("Clear negative flag.\n");
    // printf("Clear zero leading flag.\n");
    // printf("Clear digit count.\n\n");
    pre_input_code = 6;
    x = 0;
    y = 0;
}


// When get digit input, update the number.
void update_number(int input){
    float * numPrt;

    numPrt = comma_flag ? &y : &x;

    if(point_flag){
        if(negative_flag){
            *numPrt = *numPrt - input * pow(0.1, digit_count);
        }else{
            *numPrt = *numPrt + input * pow(0.1, digit_count);
        }
    }else{
        if(negative_flag){
            *numPrt = *numPrt * 10 - input;
        }else{
            *numPrt = *numPrt * 10 + input;
        }
    }

    // printf("The %c has been updated: %f.\n", commaFlag ? 'y' : 'x', *numPrt);
}


// Write two coordinate x and y to the point.
void write_point(){
    // Check duplicated.
    int duplicate = 0;
    // printf("%f, %f\n", x, y);
    int outOfRange = (x < 50 && x > -50 && y < 50 && y > -50) ? 0 : 1;

    for(int i = 0; i < point_count; i++){
        if(points[i][0] == x && points[i][1] == y){
            duplicate = 1;
        }
    }

    if(outOfRange){
        report_invalid(3);
    }else{
        if(duplicate){
            report_invalid(4);
        }else{
            if(point_count != 1000){
                points[point_count][0] = x;
                points[point_count][1] = y;
                point_count++;
            }
            // printf("A new point added. There have been %d points now.\n\n", pointCount); 
        }
    }

    // Clear x and y.
    x = 0;
    y = 0;
    
}


// Read from input and get coordinate from it.
void read_from_input(){

    while((c = getchar()) !=EOF){
        char_count++;
        valid_flag = 1;
        
        // Update current input code.
        if(isdigit(c) && c != '0')
        {
            current_input_code = 1;
        }
        else if(c == ',')
        {
            current_input_code = 2;
        }
        else if (c == ' ')
        {
            current_input_code = 3;
        }
        else if (c == '.')
        {
            current_input_code = 4;
        }
        else if (c == '-')
        {
            current_input_code = 5;
        }
        else if (c == '\n')
        {
            current_input_code = 6;
        }
        else if (c == '0')
        {
            current_input_code = 7;
        }
        else{
            current_input_code = 0;
        }
        
        // printf("--%d--%d--\n", preInputCode, currentInputCode);

        if(c != '\n'){
            // printf("A char read: %c\n", c);
        }else{
            // printf("A char read: \\n\n");
        }
        

        // Process according to current and previous input.
        switch (current_input_code)
        {
            // Get an unexpected symbol.
            case 0:
                // Invalid.
                report_invalid(5);
                break;
            // Get a digit number exclusive 0.
            case 1:
                switch (pre_input_code)
                {
                case 0:
                    // Write
                    update_number((c-48));
                    break;
                case 1:
                    // Check validation.
                    if(point_flag){
                        if(digit_count == 2){
                            // Invalid.
                            report_invalid(10);
                            break;
                        }else{
                            // Update digit count;
                            digit_count ++;
                            // printf("Digit updated. %d decimal now.\n", digitCount);
                        }
                    }

                    // Write number
                    update_number((c-48));
                    break;
                case 2:
                    // Invalid.
                    report_invalid(2);
                    pre_input_code = 6;
                    break;
                case 3:
                    // Write number
                    update_number((c-48));
                    break;
                case 4:
                    // Update digit count.
                    digit_count ++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);

                    //Write number.
                    update_number((c-48));
                    break;
                case 5:
                    //Write number.
                    update_number((c-48));
                    break;
                case 6:
                    //Write number.
                    update_number((c-48));
                    break;
                case 7:
                    if(point_flag){
                        if(digit_count == 2){
                            report_invalid(10);
                            break;
                        }
                        digit_count++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);
                    }
                    // Check validation
                    else if(zero_flag){
                        // Invalid.
                        report_invalid(15);
                        break;
                    }

                    //Write number.
                    update_number((c-48));
                    break;
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
                break;
            // Get a comma.,
            case 2:
                switch (pre_input_code)
                {
                case 0:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 1:
                    if(comma_flag){
                        // Invalid.
                        report_invalid(7);
                        break;
                    }
                    comma_flag = 1;
                    point_flag = 0;
                    negative_flag = 0;
                    zero_flag = 0;
                    digit_count = 0;
                    // printf("Comma flag set.\n");
                    // printf("Point flag clear.\n");
                    // printf("Negative flag clear.\n");
                    // printf("Zero leading flag clear.\n");
                    // printf("Digit count clear.\n");
                    break;
                case 2:
                    // Invalid.
                    report_invalid(7);
                    break;
                case 3:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 4:
                    // Invalid.
                    report_invalid(12);
                    break;
                case 5:
                    // Invalid.
                    report_invalid(11);
                    break;
                case 6:
                    // Invalid.
                    report_invalid(1);
                    break;
                case 7:
                    if(comma_flag){
                        // Invalid.
                        report_invalid(7);
                        break;
                    }
                    comma_flag = 1;
                    point_flag = 0;
                    negative_flag = 0;
                    zero_flag = 0;
                    digit_count = 0;
                    // printf("Comma flag set.\n");
                    // printf("Point flag clear.\n");
                    // printf("Negative flag clear.\n");
                    // printf("Zero leading flag clear.\n");
                    // printf("Digit count clear.\n");
                    break;
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
                break;
            // Get a blank space.
            case 3:
                switch (pre_input_code)
                {
                case 0:
                    // Invalid.
                    report_invalid(1);
                    break;
                case 1:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 2:
                    break;
                case 3:
                    // Invalid.
                    report_invalid(8);
                    break;
                case 4:
                    // Invalid.
                    report_invalid(12);
                    break;
                case 5:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 6:
                    // Invalid.
                    report_invalid(1);
                    break;
                case 7:
                    // Invalid.
                    report_invalid(2);
                    break;
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
                break;
            // Get a float point.
            case 4:
                switch (pre_input_code)
                {
                case 0:
                    // Invalid.
                    report_invalid(11);
                    break;
                case 1:
                    if(point_flag){
                        // Invalid.
                        report_invalid(6);
                        break;
                    }else{
                        point_flag = 1;
                        zero_flag = 0;
                        // printf("Zero flag clear.\n");
                        // printf("Point flag set.\n");
                    }
                    break;
                case 2:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 3:
                    // Invalid.
                    report_invalid(11);
                    break;
                case 4:
                    // Invalid.
                    report_invalid(6);
                    break;
                case 5:
                    // Invalid.
                    report_invalid(11);
                    break;
                case 6:
                    // Invalid.
                    report_invalid(11);
                    break;
                case 7:
                    if(point_flag){
                        // Invalid.
                        report_invalid(6);
                        break;
                    }else{
                        point_flag = 1;
                        zero_flag = 0;
                        // printf("Zero flag clear.\n");
                        // printf("Point flag set.\n");
                    }
                    break;
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
                break;
            // Get a minus sign.
            case 5:
                switch (pre_input_code)
                {
                case 0:
                    negative_flag = 1;
                    // printf("Negative point set.\n");
                    break;
                case 1:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 2:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 3:
                    negative_flag = 1;
                    // printf("Negative point set.\n");
                    break;
                case 4:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 5:
                    // Invalid.
                    report_invalid(9);
                    break;
                case 6:
                    negative_flag = 1;
                    // printf("Negative point set.\n");
                    break;
                case 7:
                    // Invalid.
                    report_invalid(2);
                    break;
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
                break;
            // Get a new line.
            case 6:
                switch (pre_input_code)
                {
                case 0:
                    comma_flag = 0;
                    point_flag = 0;
                    negative_flag = 0;
                    zero_flag = 0;
                    digit_count = 0;
                    // printf("Comma flag clear.\n");
                    // printf("Point flag clear.\n");
                    // printf("Negative flag clear.\n");
                    // printf("Zero leading flag clear.\n");
                    // printf("Digit count clear.\n\n");
                    break;
                case 1:
                    if(comma_flag){
                        comma_flag = 0;
                        point_flag = 0;
                        negative_flag = 0;
                        zero_flag = 0;
                        digit_count = 0;
                        // printf("Comma flag clear.\n");
                        // printf("Point flag clear.\n");
                        // printf("Negative flag clear.\n");
                        // printf("Zero leading flag clear.\n");
                        // printf("Digit count clear.\n");
                        write_point();
                        break;
                    }else{
                        // Invalid.
                        report_invalid(13);
                        break;
                    }
                case 2:
                    // Invalid.
                    report_invalid(13);
                    break;
                case 3:
                    // Invalid.
                    report_invalid(13);
                    break;
                case 4:
                    // Invalid.
                    report_invalid(12);
                    break;
                case 5:
                    // Invalid.
                    report_invalid(11);
                    break;
                case 6:
                    report_invalid(16);
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
                    if(comma_flag){
                        comma_flag = 0;
                        point_flag = 0;
                        negative_flag = 0;
                        zero_flag = 0;
                        digit_count = 0;
                        // printf("Comma flag clear.\n");
                        // printf("Point flag clear.\n");
                        // printf("Negative flag clear.\n");
                        // printf("Zero leading flag clear.\n");
                        // printf("Digit count clear.\n");
                        write_point();

                        break;
                    }else{
                        // Invalid.
                        report_invalid(13);
                        break;
                    }
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
            break;
            // Get a '0'.
            case 7:
                switch (pre_input_code)
                {
                case 0:
                    //Write number.
                    update_number((c-48));
                    zero_flag = 1;
                    // printf("Zero leading flag set.\n\n");
                    break;
                case 1:
                    if(point_flag){
                        digit_count ++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);
                    }
                    //Write number.
                    update_number((c-48));
                    break;
                case 2:
                    // Invalid.
                    report_invalid(2);
                    break;
                case 3:
                    //Write number.
                    update_number((c-48));
                    zero_flag = 1;
                    // printf("Zero leading flag set.\n");
                    break;
                case 4:
                    digit_count ++;
                    // printf("Digit updated. %d decimal now.\n", digitCount);
                    //Write number.
                    update_number((c-48));
                    break;
                case 5:
                    zero_flag = 1;
                    // printf("Zero leading flag set.\n");
                    //Write number.
                    update_number((c-48));
                    break;
                case 6:
                    //Write number.
                    update_number((c-48));
                    zero_flag = 1;
                    // printf("Zero leading flag set.\n");
                    break;
                case 7:
                    if(zero_flag){
                        // Invalid.
                        report_invalid(15);
                        break;
                    }

                    // Update digit count.
                    if(point_flag){
                        if(digit_count == 2){
                            report_invalid(10);
                            break;
                        }
                        digit_count++;
                        // printf("Digit updated. %d decimal now.\n", digitCount);
                    }

                    //Write number.
                    update_number((c-48));
                    break;
                default:
                    // Invalid.
                    report_invalid(0);
                    break;
                }
                break;
            default:
                break;
        }

        if(current_input_code == 6){
            char_count = 0;
        }
        

        if(valid_flag){
            pre_input_code = current_input_code;
        }
        
        // printf("valid: %d\n", validFlag);
    }


    // printf("valid: %d", validFlag);
    // Commit last point.
    if(valid_flag && char_count != 0){
        write_point();
    }

    
}


// Print a point with given index.
void print_point(int count){
    printf("%.2f, %.2f\n", points[count][0], points[count][1]);
}


// Print all points written so far.
void print_all_points(){
    // printf("%d points read.\n", pointCount);
    for(int i = 0; i < point_count; i++){
        print_point(i);
    }
}


// Find the close three points from all points so far.
void find_closest_three_point(){
    min_dist_sum = 1000;

    // If there is not sufficient points to form a triangle.
    if(point_count < 3){
        // Just print all points.
        for(int i = 0; i < point_count; i++){
            print_point(i);
        }
        // Determine it is no a triangle.
        printf("This is not a triangle\n");
    }else{
        // Find the closest 3 points.
        // int count;
        for(int i = 0; i < point_count; i++){
            for(int j = i+1; j < point_count; j++){

                for(int k = j+1; k < point_count; k++){
                    float distSum = calculate_total_distance(points[k][0], points[k][1], points[j][0], points[j][1], points[i][0], points[i][1]);
                    if(distSum < min_dist_sum){
                        min_dist_sum = distSum;
                        closest_point_1 = i;
                        closest_point_2 = j;
                        closest_point_3 = k;
                    }
                }
            }
        }

        // Print the information of three closest points.
        print_point(closest_point_1);
        print_point(closest_point_2);
        print_point(closest_point_3);
        

        // Check if they forms a triangle.
        if(is_triangle(points[closest_point_1][0], points[closest_point_1][1], points[closest_point_2][0], points[closest_point_2][1], points[closest_point_3][0], points[closest_point_3][1])){
            printf("This is a triangle\n");
        }else{
            printf("This is not a triangle\n");
        }
    }
}


int main(){
    
    read_from_input();

    printf("read %d points\n", point_count);

    // printAllPoints();

    find_closest_three_point();
}