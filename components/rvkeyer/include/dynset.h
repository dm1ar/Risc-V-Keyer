#ifndef DYNSET_H
#define DYNSET_H

#include "log_handler.h"

class DynSet {
public:
    DynSet(LogHandler* handler);
    void setParameter(const char* parameterName, int value);
    int getParameter(const char* parameterName);
    void updateParameter(const char* parameterName, int value);

private:
    LogHandler* logHandler;
};

#endif // DYNSET_H
