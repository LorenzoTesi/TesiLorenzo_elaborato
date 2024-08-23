//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_SUBJECT_H
#define ELABORATO12_SUBJECT_H

#include "Observer.h"
#include <vector>
#include<memory>
class Subject {
public:
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject();
};

#endif //ELABORATO12_SUBJECT_H
