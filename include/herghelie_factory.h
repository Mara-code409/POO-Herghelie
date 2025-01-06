#ifndef HERGHELIE_FACTORY_H
#define HERGHELIE_FACTORY_H

#include "cal_curse.h"
#include "cal_agrement.h"
#include "antrenament.h"
#include "plimbare.h"

class HerghelieFactory {
public:
    static Cal* creazaCal(const std::string& tip, const std::string& nume,
                         const std::string& rasa, int varsta);

    static Activitate* creeazaActivitate(const std::string& tip,
                                       const std::string& nume,
                                       const std::string& data);
};

#endif
