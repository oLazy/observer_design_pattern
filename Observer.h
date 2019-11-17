#ifndef OBSERVER_PATTERN_OBSERVER_H
#define OBSERVER_PATTERN_OBSERVER_H
//
// Created by Eric Mandolesi on 2019-02-09.
//

#ifndef SAMPEI_OBSERVER_H
#define SAMPEI_OBSERVER_H

#include <vector>

class Observable;

class Observer{
public:
    virtual void update() = 0;

    void changeObservedObject(void *obj);

protected:
    Observable* subject{nullptr};
};

class Observable{
public:
    virtual void add(Observer *observer);

    void remove(Observer *observer);

    void notify(Observer const &observer);

    void notify();

protected:
    std::vector<Observer*> _observingMe;
};


#endif //SAMPEI_OBSERVER_H


#endif //OBSERVER_PATTERN_OBSERVER_H