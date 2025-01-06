#ifndef HERGHELIE_CAL_AGREMENT_H
#define HERGHELIE_CAL_AGREMENT_H

#include "cal.h"

class CalAgrement : public Cal {
private:
    int nivelDocilitate;  // 1-10
    std::string specializare;  // "Plimbare", "Dresaj", "Salt"
    int oreDresaj;

public:
    CalAgrement();
    CalAgrement(const std::string& nume, const std::string& rasa, int varsta,
                const std::string& stare, double greutate, char gen, bool pedigree,
                int nivelDocilitate, const std::string& specializare, int oreDresaj);

    std::string getTip() const override;
    void adaugaOreDresaj(int ore);
    int getNivelDocilitate() const;

    friend std::ostream& operator<<(std::ostream& out, const CalAgrement& cal);
    friend std::istream& operator>>(std::istream& in, CalAgrement& cal);
};

#endif
