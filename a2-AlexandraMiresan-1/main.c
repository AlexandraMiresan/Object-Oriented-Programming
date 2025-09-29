//
// Created by Ale on 3/6/2025.
//


#include <stdio.h>
#include "Controller/estateController.h"
#include "UI/UI.h"


int main() {
    // Step 1: Create the Service (which also initializes the Repository)
    Service *service = createService();

    // Step 2: Run the User Interface
    runUI(service);

    // Step 3: Clean up and free memory
    destroyService(service);

    printf(" Program terminated successfully.\n");
    return 0;
}
