//
// Created by loren on 30/08/2024.
//

#ifndef ELABORATO12_OBSERVER_H
#define ELABORATO12_OBSERVER_H

class Observer {
public:
    virtual void Update(const std::string &listname)=0;
    ~Observer()=default;
};

#endif //ELABORATO12_OBSERVER_H