#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class VisualDisplay;

class Subject {
  std::vector<VisualDisplay*> observers;
 public:
  void attach(VisualDisplay *o);
  void detach(VisualDisplay *o);
  void notifyObservers();
  virtual ~Subject() = default;
};

#endif
