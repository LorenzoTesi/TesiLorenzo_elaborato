//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_SUBJECT_H
#define ELABORATO12_SUBJECT_H


#include <vector>
#include<memory>
class Subject {
public:

    virtual void notify() = 0;
    virtual ~Subject();
};

#endif //ELABORATO12_SUBJECT_H
