//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_OBSERVER_H
#define ELABORATO12_OBSERVER_H

#include <string>
#include<memory>
class Observer {
public:
    virtual void update(const std::string& listName) = 0;
    virtual ~Observer();
};

#endif //ELABORATO12_OBSERVER_H
