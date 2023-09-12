#include "subject.h"
#include "display.h"
#include <vector>

void Subject::attach(VisualDisplay *o) { observers.emplace_back(o); }

void Subject::detach(VisualDisplay *o) {
  for (auto it = observers.begin(); it != observers.end(); ) {
    if (*it == o) it = observers.erase(it);
    else ++it;
  }
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->printBoard();
}
