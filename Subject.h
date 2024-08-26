//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_SUBJECT_H
#define ELABORATO12_SUBJECT_H

class Subject {
public:

    virtual void notify() = 0;
    virtual ~Subject()=default;
};

#endif //ELABORATO12_SUBJECT_H
