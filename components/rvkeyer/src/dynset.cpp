#include "dynset.h"

DynSet::DynSet(LogHandler* handler) : logHandler(handler) {}

void DynSet::setParameter(const char* parameterName, int value) {
    logHandler->log(LogLevel::info, "Parameter set (stub)");
}

int DynSet::getParameter(const char* parameterName) {
    logHandler->log(LogLevel::info, "Parameter retrieved (stub)");
    return 0; // Placeholder return value
}

void DynSet::updateParameter(const char* parameterName, int value) {
    logHandler->log(LogLevel::info, "Parameter updated (stub)");
}
