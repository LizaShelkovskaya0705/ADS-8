// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}
void Train::addCage(bool lamp) {
  Cage*  ncage = new Cage;
  ncage->lamp = lamp;
  if (first == nullptr) {
    first = ncage;
    first->next = first;
    first->prev = first;
  }
  ncage->next = first;
  ncage->prev = first->prev;
  first->prev->next = ncage;
  first->prev = ncage;
}

int Train::getLength() {
  Cage* current = first;
  current->lamp = true;
  int count = 0;
  while (current) {
    current = current->next;
    if (current->lamp == false) {
      count++;
      countOp++;
    } else {
      current->lamp = false;
      countOp++;
      count++;
      for (int i = 0; i < count; i++) {
        current = current->prev;
        countOp++;
      }
      if (current->lamp == false) return count;
      else
        count = 0;
    }
  }
  return 0;
}

int Train::getOpCount() {
  return countOp;
}
