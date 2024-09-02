//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_SUBJECT_H
#define ELABORATO12_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void notify() = 0;
    virtual void attach(Observer*o)=0;
    virtual void detach(Observer*o)=0;
    virtual ~Subject()=default;
};

#endif //ELABORATO12_SUBJECT_H