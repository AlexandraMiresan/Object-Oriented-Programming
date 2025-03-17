#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//problem4


void print_menu() {
    printf("1. Read a vector.\n");
    printf("2. Compute the approximated value of square root of a positive real number.\n");
    printf("3. Find the longest contiguous subsequence such that the difference "
        "of any two consecutive elements is a prime number.\n");
    printf("0. Exit.\n");
}

void read_vector(int *vector, int size) {
    //read a vector of size "size" from the keyboard
    printf("Enter the numbers of elements you want to read: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector[i]);
    }

}

int read_choice() {
    //read the choice
    int choice = 0;
    scanf("%d", &choice);
    return choice;
}

void compute_square_root(int number, int precision) {
    //uses the binary search method to find the square root
    int start = 0, end = number;
    int mid = 0;

    double ans = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }

        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }

    //compute the fractional part
    //if the number is a perfect square the fractional part will not be computed
    if (ans * ans != number) {
        double fractional_part = 0.1;
        for (int i = 0; i < precision; i++) {
            while (ans * ans <= number) {
                ans += fractional_part;
            }

            ans = ans - fractional_part;
            fractional_part = fractional_part / 10;
        }
    }

    //print the result
    printf("The square root of the number %d with %d digits precision is %.*f\n.", number, precision, precision, ans);
}

int is_prime(int number) {
    //checks if a number is prime
    if (number <= 1) return 0;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return 0;
    }

    return 1;
}


void longest_contiguous_subsequence(int *vector, int size, int *result) {
    //initialize variables for current and maximum subsequences
    int longest_contiguous_subsequence = 0;
    int longest_current_subsequence = 0;
    int start = 0, end = 0;
    int current_start = 0, current_end = 0;

    //go through each element of the vector
    for (int i = 0; i < size - 1; i++) {
        //check if the difference between two consecutive numbers is prime
        //update the current subsequence accordingly, and the current start and ending positions
        if (is_prime(vector[i] - vector[i + 1])) {
            longest_current_subsequence++;
            current_end = i + 1;
        } else {
            longest_current_subsequence = 0;
            current_start = i + 1;
        }
        //check if the current subsequence is longer that the maximum subsequence
        //update the maximum subsequence and the start and end positions if required
        if (longest_current_subsequence > longest_contiguous_subsequence) {
            longest_contiguous_subsequence = longest_current_subsequence;
            start = current_start;
            end = current_end;
        }
    }

    result[0] = start;
    result[1] = end;

}

void print_vector(int *vector, int start, int end) {
    //print the longest continuous subsequence
    for (int i = start; i <= end; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");


}

void app() {
    //starts the application
    int *vector = NULL;
    int size = 0;
    while (1) {
        print_menu();
        int choice = read_choice();
        switch (choice) {
            case 1:
                printf("Enter the size of the vector: ");
                scanf("%d", &size);
                vector = (int *) malloc((size) * sizeof(int));
                read_vector(vector, size);
                break;

            case 2:
                int number = 0;
                printf("Enter a number: ");
                scanf("%d", &number);
                while(number <= 0) {
                    printf("Please enter a positive number: ");
                    scanf("%d", &number);
                }

                int precision = 0;
                printf("Enter the digit precision: ");
                scanf("%d", &precision);
                compute_square_root(number, precision);
                break;

            case 3:
                if (vector == NULL) {
                    printf("The vector is empty. Please use choice 1 to read a vector.\n");
                } else {
                    int result[2] = {0};
                    longest_contiguous_subsequence(vector, size, result);

                    print_vector(vector, result[0], result[1]);
                }
                break;

            case 0:
                if (vector != NULL) {
                    free(vector);
                }
                exit(0);

            default:
                printf("Invalid choice.");
        }
    }


}

int main() {
    app();
    return 0;
}
