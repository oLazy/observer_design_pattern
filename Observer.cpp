#include "Observer.h"
#include <exception>
#include <stdexcept>

void Observer::changeObservedObject(void *obj) {
    subject->remove(this);
    this->subject = static_cast<Observable*>(obj);
    subject->add(this);
}

void Observable::add(Observer *observer) {
    _observingMe.push_back(observer);
}

void Observable::remove(Observer *observer) {
    for (auto it = _observingMe.begin(); it != _observingMe.end(); it++) {
        if (*it == observer) {
            _observingMe.erase(it);
            break;
        }
    }
}

void Observable::notify(Observer const &observer){
    for (auto o : _observingMe){
        if(o == &observer){
            o->update();
            return;;
        }
    }
    throw std::logic_error{"Cannot notify non-linked Observer"};
}

void Observable::notify() {
    for (auto observer : _observingMe){
        observer->update();
    }
}
