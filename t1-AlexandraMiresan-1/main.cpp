//
// Created by Ale on 4/2/2025.
//
#include <iostream>

#include "Repository.h"
#include "Service.h"
#include "Tests.h"
#include "UI.h"
using namespace std;
int main() {
  // Tests tests = Tests();
  // tests.runAllTests();
  Repository repo = Repository();
  Service serv = Service(repo);
  UI ui = UI(serv);
  ui.start();
  return 0;
}
