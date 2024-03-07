#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class TStudent{
    public:
        int _id = 0;
        TStudent* _next = nullptr;
};

TStudent* InitTStudent();

#endif