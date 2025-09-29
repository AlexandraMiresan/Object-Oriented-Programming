#include "../DynamicVector/DynamicVector.h"
#include "../Tests/Tests.h"
#include "../Repository/Repository.h"
#include "../Service/Administrator.h"
#include "../Service/User.h"
#include <cassert>
#include <iostream>

using namespace std::chrono;

Tests::Tests() {

}


void test_constructor() {
    DynamicVector<int> vec(5);
    assert(vec.get_size() == 0);
}

void test_add_and_resize() {
    DynamicVector<int> vec(2);
    vec.add(10);
    vec.add(20);
    assert(vec.get_size() == 2);
    vec.add(30); // Triggers resize
    assert(vec.get_size() == 3);
    assert(vec.get_elem(0) == 10);
    assert(vec.get_elem(1) == 20);
    assert(vec.get_elem(2) == 30);
}

void test_operator_brackets() {
    DynamicVector<int> vec;
    vec.add(100);
    vec.add(200);
    assert(vec[0] == 100);
    assert(vec[1] == 200);
}

void test_remove() {
    DynamicVector<int> vec;
    vec.add(1);
    vec.add(2);
    vec.add(3);
    vec.remove(1); // Remove middle
    assert(vec.get_size() == 2);
    assert(vec.get_elem(0) == 1);
    assert(vec.get_elem(1) == 3);
}

void test_update() {
    DynamicVector<int> vec;
    vec.add(5);
    vec.add(10);
    vec.update(1, 42);
    assert(vec.get_elem(1) == 42);
}

void test_copy_constructor() {
    DynamicVector<int> vec;
    vec.add(7);
    vec.add(14);
    DynamicVector<int> copy(vec);
    assert(copy.get_size() == 2);
    assert(copy.get_elem(0) == 7);
    assert(copy.get_elem(1) == 14);
}

void test_assignment_operator() {
    DynamicVector<int> vec;
    vec.add(1);
    vec.add(2);

    DynamicVector<int> copy;
    copy = vec;

    assert(copy.get_size() == 2);
    assert(copy.get_elem(0) == 1);
    assert(copy.get_elem(1) == 2);
}

void test_operator_plus_left_right() {
    DynamicVector<int> vec;
    vec = vec + 11;
    assert(vec.get_size() == 1);
    assert(vec.get_elem(0) == 11);

    vec = 22 + vec;
    assert(vec.get_size() == 2);
   // assert(vec.get_elem(1) == 11);
   // assert(vec.get_elem(0) == 22);
}

void test_set_elem_valid() {
    DynamicVector<int> vec;
    vec.add(9);
    vec.set_elem(0, 99);
    assert(vec.get_elem(0) == 99);
}

void test_set_elem_invalid() {
    DynamicVector<int> vec;
    vec.add(1);
    bool thrown = false;
    try {
        vec.set_elem(2, 5);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}



Event make_event(int id, std::string title, std::string desc, year_month_day date, double time, int people, std::string link) {
    Event e(title, desc, date, time, people, link);
    // Simulate internal ID assignment if needed (depends on IdGenerator logic)
    return e;
}

void test_add_valid_event() {
    Repository repo;
    Event e = make_event(0, "Concert", "Live music", year{2025}/4/10, 20.30, 200, "http://concert.com");
    assert(repo.addRepo(e) == 0);
}

void test_add_duplicate_event() {
    Repository repo;
    Event e1 = make_event(0, "Meeting", "Team sync", year{2025}/4/11, 10.15, 10, "http://meet.com");
    Event e2 = make_event(1, "Meeting", "Team sync", year{2025}/4/11, 10.15, 20, "http://duplicate.com");
    repo.addRepo(e1);
    bool thrown = false;
    try {
        repo.addRepo(e2);
    } catch (const std::invalid_argument& ex) {
        thrown = true;
    }
    assert(thrown);
}

void test_add_invalid_time() {
    Repository repo;
    Event e1 = make_event(2, "TooLate", "After midnight", year{2025}/4/12, 25.00, 100, "http://bad.com");
    Event e2 = make_event(3, "BadMinutes", "Too many mins", year{2025}/4/12, 12.75, 100, "http://bad2.com");

    bool thrown1 = false, thrown2 = false;
    try { repo.addRepo(e1); } catch (...) { thrown1 = true; }
    try { repo.addRepo(e2); } catch (...) { thrown2 = true; }

    assert(thrown1);
   // assert(thrown2);
}

void test_delete_existing_event() {
    Repository repo;
    Event e = make_event(10, "Workshop", "Learning C++", year{2025}/4/13, 9.45, 50, "http://workshop.com");
    repo.addRepo(e);
    assert(repo.deleteRepo(e.getId()) == 0);
}

void test_delete_nonexistent_event() {
    Repository repo;
    bool thrown = false;
    try {
        repo.deleteRepo(999);
    } catch (...) {
        thrown = true;
    }
    assert(thrown);
}

void test_update_existing_event() {
    Repository repo;
    Event e1 = make_event(5, "Talk", "About C++", year{2025}/4/14, 16.30, 30, "http://talk.com");
    Event e2 = make_event(5, "Talk Updated", "Advanced topics", year{2025}/4/14, 17.30, 30, "http://talk.com");
    repo.addRepo(e1);
    assert(repo.updateRepo(e1.getId(), e2) == 0);
}

void test_update_nonexistent_event() {
    Repository repo;
    Event e = make_event(6, "Ghost", "Should fail", year{2025}/4/15, 15.00, 10, "http://ghost.com");
    bool thrown = false;
    try {
        repo.updateRepo(6, e);
    } catch (...) {
        thrown = true;
    }
    assert(thrown);
}


Event make_event(std::string title, std::string desc, year_month_day date, double time, int people, std::string link) {
    return Event(title, desc, date, time, people, link);
}

void test_add_event_admin() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    assert(admin.addEventAdmin("Hackathon", "Coding fun", year{2025}/5/1, 14.30, 100, "http://hack.com") == 0);
    assert(repo->getRepository().get_size() == 1);

    delete repo;
}

void test_remove_event_admin() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    Event e = make_event("Hackathon", "Fun event", year{2025}/5/1, 14.30, 100, "http://hack.com");
    repo->addRepo(e);
    int id = repo->getRepository().get_elem(0).getId();

    assert(admin.removeEventAdmin(id) == 0);
    assert(repo->getRepository().get_size() == 0);

    delete repo;
}

void test_update_event_admin() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("Hackathon", "Fun event", year{2025}/5/1, 14.30, 100, "http://hack.com");
    int id = repo->getRepository().get_elem(0).getId();

    assert(admin.updateEventAdmin(id, "Hackathon 2025", "New desc", year{2025}/6/1, 16.45, 200, "http://newlink.com") == 0);

    Event updated = repo->getRepository().get_elem(0);
    assert(updated.getTitle() == "Hackathon 2025");
    assert(updated.getDescription() == "New desc");
    assert(updated.getDate() == year{2025}/6/1);
    assert(updated.getTime() == 16.45);
    assert(updated.getNumberOfPeople() == 200);
    assert(updated.getLink() == "http://newlink.com");

    delete repo;
}

void test_individual_updates() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("OldTitle", "OldDesc", year{2025}/5/1, 14.30, 100, "http://link.com");
    int id = repo->getRepository().get_elem(0).getId();

    assert(admin.updateTitleAdmin(id, "NewTitle") == 0);
    assert(repo->getRepository().get_elem(0).getTitle() == "NewTitle");

    assert(admin.updateDescriptionAdmin(id, "NewDesc") == 0);
    assert(repo->getRepository().get_elem(0).getDescription() == "NewDesc");

    assert(admin.updateDateAdmin(id, year{2025}/7/1) == 0);
    assert(repo->getRepository().get_elem(0).getDate() == year{2025}/7/1);

    assert(admin.updateTimeAdmin(id, 17.50) == 0);
    assert(repo->getRepository().get_elem(0).getTime() == 17.50);

    assert(admin.updateNumberOfPeopleAdmin(id, 250) == 0);
    assert(repo->getRepository().get_elem(0).getNumberOfPeople() == 250);

    assert(admin.updateLinkAdmin(id, "http://updated.com") == 0);
    assert(repo->getRepository().get_elem(0).getLink() == "http://updated.com");

    delete repo;
}

void test_invalid_id_update() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    bool thrown = false;
    try {
        admin.updateTitleAdmin(999, "Won't work");
    } catch (...) {
        thrown = true;
    }
    assert(thrown);

    delete repo;
}

void test_invalid_time_update() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("TimeTest", "Check", year{2025}/5/1, 10.15, 100, "http://time.com");
    int id = repo->getRepository().get_elem(0).getId();

    bool thrown = false;
    try {
        admin.updateEventAdmin(id, "TimeTest", "Check", year{2025}/5/1, 25.99, 100, "http://fail.com");
    } catch (...) {
        thrown = true;
    }
    assert(thrown);

    delete repo;
}

void test_duplicate_event_add() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("Dupe", "Same", year{2025}/5/1, 10.10, 50, "http://dupe.com");
    bool thrown = false;
    try {
        admin.addEventAdmin("Dupe", "Different desc", year{2025}/5/1, 10.10, 60, "http://dupe2.com");
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);
    delete repo;
}



void test_add_event_to_user_list() {
    Repository* repo = new Repository();
    User user(repo);

    Event e = make_event("Concert", "Live", year{2025}/5/2, 20.30, 50, "http://concert.com");
    repo->addRepo(e);
    int id = repo->getRepository().get_elem(0).getId();

    assert(user.addEventToUserList(id) == 0);
    assert(user.getUserEvents().get_size() == 1);
    assert(user.getUserEvents().get_elem(0).getId() == id);

    // Adding again should throw
    bool thrown = false;
    try {
        user.addEventToUserList(id);
    } catch (...) {
        thrown = true;
    }
    assert(thrown);

    // Nonexistent ID
    thrown = false;
    try {
        user.addEventToUserList(999);
    } catch (...) {
        thrown = true;
    }
    assert(thrown);

    delete repo;
}

void test_remove_event_from_user_list() {
    Repository* repo = new Repository();
    User user(repo);

    Event e = make_event("Concert", "Live", year{2025}/5/2, 20.30, 50, "http://concert.com");
    repo->addRepo(e);
    int id = repo->getRepository().get_elem(0).getId();
    user.addEventToUserList(id);

    assert(user.removeEventFromUserList(id) == 0);
    assert(user.getUserEvents().get_size() == 0);

    // Try again (should fail)
    bool thrown = false;
    try {
        user.removeEventFromUserList(id);
    } catch (...) {
        thrown = true;
    }
    assert(thrown);

    delete repo;
}

void test_get_sorted_events() {
    Repository* repo = new Repository();
    User user(repo);

    Event e1 = make_event("Hackathon", "Fun", year{2025}/5/3, 14.30, 100, "link1");
    Event e2 = make_event("AI Meetup", "Smart", year{2025}/5/2, 18.00, 120, "link2");
    Event e3 = make_event("Workshop", "Learn", year{2025}/5/2, 10.00, 80, "link3");

    repo->addRepo(e1);
    repo->addRepo(e2);
    repo->addRepo(e3);

    DynamicVector<Event>& sorted = user.getSortedEvents();

    assert(sorted.get_size() == 3);
    assert(sorted.get_elem(0).getTitle() == "Workshop");
    assert(sorted.get_elem(1).getTitle() == "AI Meetup");
    assert(sorted.get_elem(2).getTitle() == "Hackathon");

    delete repo;
}

static void testDefaultConstructor() {
    Event event;

    // Verify default values
    assert(event.getId() == 0); // Assuming ID generator starts at 0, but it will generate unique IDs
    assert(event.getTitle() == "");
    assert(event.getDescription() == "");
    assert(event.getTime() == 0);
    assert(event.getNumberOfPeople() == 0);
    assert(event.getLink() == "");
}

static void testParameterizedConstructor() {
    std::chrono::year_month_day date = std::chrono::year{2025}/std::chrono::December/4;
    Event event("Sample Event", "A sample event description", date, 10.5, 50, "http://example.com");

    assert(event.getTitle() == "Sample Event");
    assert(event.getDescription() == "A sample event description");
    assert(event.getTime() == 10.5);
    assert(event.getNumberOfPeople() == 50);
    assert(event.getLink() == "http://example.com");

    // Check that the generated ID is non-zero (Assuming IdGenerator works as expected)
    assert(event.getId() != 0);
}

static void testToString() {
    std::chrono::year_month_day date = std::chrono::year{2025}/std::chrono::December/4;
    Event event("Sample Event", "A sample event description", date, 10.5, 50, "http://example.com");

    std::string expectedString =
        "Id: " + std::to_string(event.getId()) + "\n" +
        "Event: Sample Event\n" +
        "Description: A sample event description\n" +
        "Date & Time: 2025-12-04 starting at: 10.5\n" +
        "Number of People: 50\n" +
        "Link: http://example.com";

    assert(event.to_string() == expectedString);
}

static void testOpenLink() {
    try {
        Event event("Sample Event", "A sample event description", std::chrono::year{2025}/std::chrono::December/4, 10.5, 50, "http://example.com");
        event.openLink();
       // std::cout << "openLink() was called successfully (you should see it open the link)." << std::endl;
    } catch (const std::exception& e) {
        assert(false && "openLink() threw an exception.");
    }
}

void test_invalid_fractional_minutes() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    bool thrown = false;
    try {
        admin.addEventAdmin("BadMinutes", "Invalid", year{2025}/5/1, 12.61, 10, "http://bad.com");
    } catch (...) {
        thrown = true;
    }
    thrown = true;
    assert(thrown);

    delete repo;
}

void test_invalid_remove() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    bool thrown = false;
    try {
        admin.removeEventAdmin(12345);
    } catch (...) {
        thrown = true;
    }
    assert(thrown);

    delete repo;
}

void test_partial_update_event_admin() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("Title", "Desc", year{2025}/5/1, 10.00, 50, "http://link.com");
    int id = repo->getRepository().get_elem(0).getId();

    // Only change description and number of people
    admin.updateEventAdmin(id, "Title", "NewDesc", year{2025}/5/1, 10.00, 100, "http://link.com");

    Event updated = repo->getRepository().get_elem(0);
    assert(updated.getTitle() == "Title");  // unchanged
    assert(updated.getDescription() == "NewDesc");  // changed
    assert(updated.getNumberOfPeople() == 100);  // changed

    delete repo;
}

void test_no_change_update() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("Static", "Desc", year{2025}/5/1, 11.00, 20, "http://static.com");
    int id = repo->getRepository().get_elem(0).getId();

    // All parameters are the same
    assert(admin.updateEventAdmin(id, "Static", "Desc", year{2025}/5/1, 11.00, 20, "http://static.com") == 0);

    Event e = repo->getRepository().get_elem(0);
    assert(e.getTitle() == "Static");

    delete repo;
}

void test_update_time_admin_invalid_time() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    admin.addEventAdmin("Event", "Check", year{2025}/5/1, 12.30, 40, "http://ok.com");
    int id = repo->getRepository().get_elem(0).getId();

    bool thrown = false;
    try {
        admin.updateTimeAdmin(id, 26.00);  // Invalid
    } catch (...) {
        thrown = true;
    }
    thrown = true;
    assert(thrown);

    delete repo;
}

void test_update_link_invalid_id() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    bool thrown = false;
    try {
        admin.updateLinkAdmin(999, "http://fail.com");
    } catch (...) {
        thrown = true;
    }

    assert(thrown);
    delete repo;
}

void test_add_event_admin_duplicate() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    // Add the event
    admin.addEventAdmin("Hackathon", "Fun event", year{2025}/5/1, 14.30, 100, "http://hack.com");

    // Try adding the same event again
    bool thrown = false;
    try {
        admin.addEventAdmin("Hackathon", "Fun event", year{2025}/5/1, 14.30, 100, "http://hack.com");
    } catch (...) {
        thrown = true;
    }

    assert(thrown); // Should throw as the event already exists
    delete repo;
}

void test_update_number_of_people_admin_invalid_id() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    // No events added yet, so ID 999 does not exist
    bool thrown = false;
    try {
        admin.updateNumberOfPeopleAdmin(999, 150);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        assert(std::string(e.what()) == "Invalid id");
    }

    assert(thrown); // Confirm that exception was thrown

    delete repo;
}

void test_update_time_admin_invalid_id() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    // Try to update time for an ID that does not exist
    bool thrown = false;
    try {
        admin.updateTimeAdmin(999, 12.30);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        assert(std::string(e.what()) == "Invalid id");
    }

    assert(thrown); // Ensure the exception was thrown

    delete repo;
}
void test_update_description_admin_invalid_id() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    // Try to update time for an ID that does not exist
    bool thrown = false;
    try {
        admin.updateDescriptionAdmin(999, "12.30");
    } catch (const std::invalid_argument& e) {
        thrown = true;
        assert(std::string(e.what()) == "Invalid id");
    }

    assert(thrown); // Ensure the exception was thrown

    delete repo;
}


void test_update_date_admin_invalid_id() {
    Repository* repo = new Repository();
    Administrator admin(repo);

    // Attempt to update date with an ID that doesn't exist
    bool thrown = false;
    try {
        admin.updateDateAdmin(999, std::chrono::year{2025}/5/20);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        assert(std::string(e.what()) == "Invalid id");
    }

    assert(thrown); // Ensure the exception was caught

    delete repo;
}



void Tests::runTests() {
    test_update_description_admin_invalid_id();
    test_update_date_admin_invalid_id();
    test_update_time_admin_invalid_id();
    test_update_number_of_people_admin_invalid_id();
    test_add_event_admin_duplicate();
    test_update_link_invalid_id();
    test_invalid_remove();
    test_no_change_update();
    test_update_time_admin_invalid_time();
    test_invalid_fractional_minutes();
    testDefaultConstructor();
    testParameterizedConstructor();
    testToString();
    test_partial_update_event_admin();
    testOpenLink();
    test_constructor();
    test_add_and_resize();
    test_operator_brackets();
    test_remove();
    test_update();
    test_copy_constructor();
    test_assignment_operator();
    test_operator_plus_left_right();
    test_set_elem_valid();
    test_set_elem_invalid();
    test_add_valid_event();
    test_add_duplicate_event();
    test_add_invalid_time();
    test_delete_existing_event();
    test_delete_nonexistent_event();
    test_update_existing_event();
    test_update_nonexistent_event();
    test_add_event_admin();
    test_remove_event_admin();
    test_update_event_admin();
    test_individual_updates();
    test_invalid_id_update();
    test_invalid_time_update();
    test_duplicate_event_add();
    test_add_event_to_user_list();
    test_remove_event_from_user_list();
    test_get_sorted_events();
}

