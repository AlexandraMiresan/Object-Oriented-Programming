#include "Controller.h"
#include "UI.h"
//
// Created by Ale on 5/7/2025.
//
int main(){
  Controller controller = Controller();
  UI ui = UI(controller);
  ui.start();

  return 0;
}