#include <stdio.h>
#include <string.h>

int main()
{
    char month[20];

    printf("Enter a month: ");
    fgets(month, sizeof(month), stdin);

    // Remove trailing newline if present
    month[strcspn(month, "\n")] = '\0';

    // Check month and print corresponding days
    if (strcmp(month, "January") == 0 || strcmp(month, "March") == 0 ||
        strcmp(month, "May") == 0 || strcmp(month, "July") == 0 ||
        strcmp(month, "August") == 0 || strcmp(month, "October") == 0 ||
        strcmp(month, "December") == 0)
    {
        printf("31 days\n");
    }
    else if (strcmp(month, "April") == 0 || strcmp(month, "June") == 0 ||
             strcmp(month, "September") == 0 || strcmp(month, "November") == 0)
    {
        printf("30 days\n");
    }
    else if (strcmp(month, "February") == 0)
    {
        printf("28 or 29 days\n");
    }
    else
    {
        printf("Invalid month\n");
    }

    return 0;
}

// #include <stdio.h>
// #include <string.h>

// // Function to convert month names into unique integer values
// int getMonthID(const char *month) {
//     if (strcmp(month, "January") == 0) return 1;
//     if (strcmp(month, "February") == 0) return 2;
//     if (strcmp(month, "March") == 0) return 3;
//     if (strcmp(month, "April") == 0) return 4;
//     if (strcmp(month, "May") == 0) return 5;
//     if (strcmp(month, "June") == 0) return 6;
//     if (strcmp(month, "July") == 0) return 7;
//     if (strcmp(month, "August") == 0) return 8;
//     if (strcmp(month, "September") == 0) return 9;
//     if (strcmp(month, "October") == 0) return 10;
//     if (strcmp(month, "November") == 0) return 11;
//     if (strcmp(month, "December") == 0) return 12;
//     return -1;  // Invalid month
// }

// int main() {
//     char month[20];

//     printf("Enter a month: ");
//     fgets(month, sizeof(month), stdin);

//     // Remove trailing newline if present
//     month[strcspn(month, "\n")] = '\0';

//     // Get integer ID for the month
//     int monthID = getMonthID(month);

//     // Use switch statement with integer values
//     switch (monthID) {
//         case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//             printf("31 days\n");
//             break;
//         case 4: case 6: case 9: case 11:
//             printf("30 days\n");
//             break;
//         case 2:
//             printf("28 or 29 days\n");
//             break;
//         default:
//             printf("Invalid month\n");
//     }

//     return 0;
// }
