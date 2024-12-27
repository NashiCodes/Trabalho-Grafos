//
// Created by Nashi on 27/12/2024.
//

#ifndef STORAGE_H
#define STORAGE_H



template<class T>
class Storage final {
public:
    virtual ~Storage() = default;

    virtual void add(T info){};
    virtual T get(int ID){}
};



#endif //STORAGE_H
