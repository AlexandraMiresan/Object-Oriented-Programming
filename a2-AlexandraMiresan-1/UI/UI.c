// //
// // Created by Ale on 3/6/2025.
// //
//

#include <stdio.h>

#include <string.h>
#include "../Controller/estateController.h"

void printMenu() {
    printf("\n========== Estate Management System ==========\n");
    printf("1. Add Estate\n");
    printf("2. Delete Estate\n");
    printf("3. Update Estate\n");
    printf("4. Search Estates (Sorted by Price)\n");
    printf("5. Display Estates by Type & Surface\n");
    printf("0. Exit\n");
    printf("==============================================\n");
    printf("Choose an option: ");
}

// Function to read estate details from the user
void readEstateInput(char* type, char* address, double* surface, double* price) {
    printf("Enter type (house/apartment/penthouse): ");
    scanf("%s", type);
    while (strcmp(type, "house") != 0 && strcmp(type, "apartment") != 0 && strcmp(type, "penthouse") != 0) {
        printf("ERROR!Please enter type (house/apartment/penthouse): ");
        scanf("%s", type);
    }
    printf("Enter address of estate: ");
    while (getchar() != '\n') {
    }
    fgets(address, 100, stdin);
    if (strlen(address) > 0 && address[strlen(address) - 1] == '\n') {
        address[strlen(address) - 1] = '\0';
    }

    printf("Enter surface area: ");
    scanf("%lf", surface);

    printf("Enter price: ");
    scanf("%lf", price);
}

// Function to run the UI
void runUI(Service* service) {
    int option;
    char type[50], address[100], searchStr[100];
    double surface, price;
    int size;

    while (1) {
        printMenu();
        scanf("%d", &option);
        getchar(); // Consume newline character

        switch (option) {
            case 1: {  // Add Estate
                readEstateInput(type, address, &surface, &price);
                int result = addElementToController(service, type, address, surface, price);
                if (result == 1) printf("Estate added successfully!\n");
                else printf("Error adding estate.\n");
                break;
            }

            case 2: {  // Delete Estate
                printf("Enter address of the estate to delete: ");
                scanf("%s", address);
                int result = deleteEstateFromController(service, address);
                if (result == 1) printf(" Estate deleted successfully!\n");
                else printf(" Estate not found.\n");
                break;
            }

            case 3: {  // Update Estate
                readEstateInput(type, address, &surface, &price);
                int result = updateEstateController(service, type, address, surface, price);
                if (result == 0) printf(" Estate updated successfully!\n");
                else printf(" Error updating estate.\n");
                break;
            }

            case 4: {  // Search Estates (Sorted by Price)
                printf("Enter search string or nothing to see all the estates: ");
                while (getchar() != '\n') {
                }
                fgets(searchStr, 100,stdin);

                if (searchStr[strlen(searchStr) - 1] == '\n') {
                    searchStr[strlen(searchStr) - 1] = '\0';
                }

                if (strlen(searchStr) == 0) {
                    searchStr[0] = '\0';
                }
                size = getSize(service->repo->dynamicArray);
                DynamicArray* result = searchEstatesController(service, searchStr, &size);

                if (size == 0) {
                    printf("No matching estates found.\n");
                } else {
                    printf("\nFound %d estates sorted by price:\n", size);
                    for (int i = 0; i < size; i++) {
                        printf(" %s | %s | %.2lf sqm | $%.2lf\n",
                               result->elems[i]->type, result->elems[i]->address,
                               result->elems[i]->surface, result->elems[i]->price);
                    }
                }
                destroyArray(result);
                break;
            }

            case 5: {  // Display Estates by Type & Surface
                printf("Enter type: ");
                scanf("%s", type);
                printf("Enter minimum surface area: ");
                scanf("%lf", &surface);

                size = getSize(service->repo->dynamicArray);
                DynamicArray* result = displayEstatesByType(service, type, surface, &size);

                if (size == 0) {
                    printf("No estates found matching your criteria.\n");
                } else {
                    printf("\n Estates of type '%s' with surface > %.2lf sqm:\n", type, surface);
                    for (int i = 0; i < size; i++) {
                        printf(" %s | %s | %.2lf sqm | $%.2lf\n",
                               result->elems[i]->type, result->elems[i]->address,
                               result->elems[i]->surface, result->elems[i]->price);
                    }
                }
                destroyArray(result);
                break;
            }

            case 0: {  // Exit
                printf(" Exiting the program...\n");
                return;
            }

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

// #include "UI.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
//
// #include "Controller/estateController.h"
// #include "Repository/estates_repository.h"
//
//
// void print_menu() {
//     printf("Real Estate Management\n");
//     printf("--------------\n");
//     printf("1. Add estate.\n");
//     printf("2. Delete estate.\n");
//     printf("3. Update estate.\n");
//     printf("4. Display estate.\n");
//     printf("0. Exit\n");
// }
//
// int readChoice() {
//     int choice = 0;
//
//     printf("Enter your choice (an integer number): ");
//
//     scanf("%d", &choice);
//
//     return choice;
// }
//
// void printEstates(Estate *estates, int size) {
//     if (size == 0) {
//         printf("No Estates found\n");
//         return;
//     }
//
//     printf("List of Estates:\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d. Type: %s, Address: %s, Surface: %lf, Price: %lf.", i + 1, estates[i].type, estates[i].address,
//                estates[i].surface, estates[i].price);
//         printf("\n");
//     }
// }
//
// void uiAddEstate() {
//     char *type = (char *) malloc(20 * sizeof(char));
//     char *address = (char *) malloc(100 * sizeof(char));
//     double surface, price;
//
//     printf("Enter type (house/apartment/penthouse): ");
//     scanf("%s", type);
//     while (strcmp(type, "house") != 0 && strcmp(type, "apartment") != 0 && strcmp(type, "penthouse") != 0) {
//         printf("ERROR!Please enter type (house/apartment/penthouse): ");
//         scanf("%s", type);
//     }
//     printf("Enter address of estate: ");
//     while (getchar() != '\n') {
//     }
//     fgets(address, 100, stdin);
//     if (strlen(address) > 0 && address[strlen(address) - 1] == '\n') {
//         address[strlen(address) - 1] = '\0';
//     }
//     printf("Enter surface: ");
//     scanf("%lf", &surface);
//     printf("Enter price of estate: ");
//     scanf("%lf", &price);
//
//     if (addEstateController(type, address, surface, price) == 1) {
//         printf("Successfully added Estate\n");
//     } else if(addEstateController(type, address, surface, price) == 2) {
//         printf("ERROR!Nothing should be null!\n");
//     }else {
//         printf("ERROR! Could not add Estate\n");
//     }
//
//     free(type);
//     free(address);
// }
//
//
// void uiDeleteEstate() {
//     char *address = (char *) malloc(100 * sizeof(char));
//     printf("Enter address of estate to delete: ");
//     while (getchar() != '\n') {
//     }
//     fgets(address, 100, stdin);
//     if (strlen(address) > 0 && address[strlen(address) - 1] == '\n') {
//         address[strlen(address) - 1] = '\0';
//     }
//
//     if (deleteEstateController(address) == 1) {
//         printf("Operation was successful!\n");
//     } else {
//         printf("Failed to delete Estate\n");
//     }
//
//     free(address);
//
// }
//
// void uiUpdateEstate() {
//     char *address = (char *) malloc(100 * sizeof(char));
//     char *newType = (char *) malloc(20 * sizeof(char));
//     double newSurface, newPrice;
//
//     printf("Enter the address of the estate you want to update: ");
//     while (getchar() != '\n') {
//     }
//     fgets(address, 100, stdin);
//     if (strlen(address) > 0 && address[strlen(address) - 1] == '\n') {
//         address[strlen(address) - 1] = '\0';
//     }
//     printf("Enter new type (house/apartment/penthouse): ");
//     scanf("%s", newType);
//     while (strcmp(newType, "house") != 0 && strcmp(newType, "apartment") != 0 && strcmp(newType, "penthouse") != 0) {
//         printf("ERROR!Please enter type (house/apartment/penthouse): ");
//         scanf("%s", newType);
//     }
//     printf("Enter new surface: ");
//     scanf("%lf", &newSurface);
//     printf("Enter new price: ");
//     scanf("%lf", &newPrice);
//
//     if (updateEstateController(newType, address, newSurface, newPrice) == 1) {
//         printf("Operation was successful!\n");
//     } else {
//         printf("Failed to update Estate\n");
//     }
//
//     free(address);
//     free(newType);
//
// }
//
// void uiDisplayEstates() {
//     char *searchStr = malloc(100 * sizeof(char));
//     printf("Enter search string or nothing to see all the estates: ");
//     while (getchar() != '\n') {
//     }
//     fgets(searchStr, 100,stdin);
//
//     if (searchStr[strlen(searchStr) - 1] == '\n') {
//         searchStr[strlen(searchStr) - 1] = '\0';
//     }
//
//     if (strlen(searchStr) == 0) {
//         searchStr[0] = '\0';
//     }
//
//     int size;
//     Estate *estates = searchEstatesController(searchStr, &size);
//
//     printEstates(estates, size);
//
//     free(estates);
//     free(searchStr);
// }
//
// void add_to_repo() {
//     addEstateController("house", "str. Teodor Mihali,33-35", 34.00, 100000);
//     addEstateController("apartment", "str. Ploiesti, 21A", 55, 120000);
//     addEstateController("penthouse", "str. Lt.Calin, 1B", 60, 150000);
//     addEstateController("house", "str. Aurel Vlaicu", 50, 130000);
//     addEstateController("house", "str. Florilor, 67C", 44, 99000);
//     addEstateController("penthouse", "str. Alverna, 40D", 80, 270000);
//     addEstateController("house", "str. Crinilor, 12A", 24, 89000);
//
// }
//
//
// void startUI() {
//     add_to_repo();
//     while (1) {
//         print_menu();
//         int choice = readChoice();
//         switch (choice) {
//             case 1:
//                 uiAddEstate();
//                 break;
//             case 2:
//                 uiDeleteEstate();
//                 break;
//             case 3:
//                 uiUpdateEstate();
//                 break;
//             case 4:
//                 uiDisplayEstates();
//                 break;
//             case 0:
//                 exit(0);
//             default:
//                 printf("Invalid Choice\n");
//         }
//     }
// }
