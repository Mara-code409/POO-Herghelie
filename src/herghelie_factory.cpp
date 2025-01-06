#include "herghelie_factory.h"

Cal* HerghelieFactory::creazaCal(const std::string& tip, const std::string& nume,
                                const std::string& rasa, int varsta) {
    if (tip == "Curse") {
        return new CalCurse(nume, rasa, varsta, "Sanatos", 500.0, 'M', true, 0, 0, 60.0);
    }
    else if (tip == "Agrement") {
        return new CalAgrement(nume, rasa, varsta, "Sanatos", 450.0, 'F', false, 5, "Plimbare", 0);
    }
    return nullptr;
}

Activitate* HerghelieFactory::creeazaActivitate(const std::string& tip,
                                              const std::string& nume,
                                              const std::string& data) {
    if (tip == "Antrenament") {
        return new Antrenament(nume, data, "09:00", 60, 5, "Viteza", 5, "Default");
    }
    else if (tip == "Plimbare") {
        return new Plimbare(nume, data, "14:00", 120, 3, "Traseu standard", "Mediu", true);
    }
    return nullptr;
}
