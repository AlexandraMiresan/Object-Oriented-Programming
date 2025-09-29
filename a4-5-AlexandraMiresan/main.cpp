#include <iostream>

#include "Repository/Repository.h"
#include "Service/Administrator.h"
#include "Service/User.h"
#include "Tests/Tests.h"
#include "UI/UI.h"


//
// Created by Ale on 3/23/2025.
//
void addToRepo(Administrator &admin) {
    admin.addEventAdmin("Rock Concert", "A thrilling rock concert featuring various bands.", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{6}, std::chrono::day{15}}, 20.30, 150, "https://www.rockconcert.com");
    admin.addEventAdmin("Tech Innovations Conference", "Join us for the latest advancements in technology.", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{7}, std::chrono::day{20}}, 09.00, 300, "https://www.techconference.com");
    admin.addEventAdmin("Italian Cuisine Workshop", "Learn to make authentic Italian dishes!", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{8}, std::chrono::day{10}}, 16.00, 25, "https://www.cookingworkshop.com");
    admin.addEventAdmin("Book launch", "Join us for the latest advancements in technology.", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{7}, std::chrono::day{20}}, 09.00, 300, "https://www.crouton.net");
    admin.addEventAdmin("Untold", "Join us for the latest advancements in technology.", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{7}, std::chrono::day{20}}, 09.00, 300, "https://www.dogs.com");
    admin.addEventAdmin("Dogs Party", "Join us for the latest advancements in technology.", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{7}, std::chrono::day{20}}, 09.00, 300, "https://www.tech.com");
    admin.addEventAdmin("City Marathon", "Run through the city's beautiful streets and earn your medal!", std::chrono::year_month_day{std::chrono::year{2025}, std::chrono::month{9}, std::chrono::day{5}}, 07.00, 500, "https://www.citymarathon.com");
}


int main() {
    Repository repo = Repository();
    Tests test = Tests();
    test.runTests();
    Administrator admin = Administrator(&repo);
    addToRepo(admin);
    User user = User(&repo);
    UI ui = UI(admin, user);
    ui.start();

    return 0;
}
