#ifndef HERGHELIE_CAL_CURSE_H
#define HERGHELIE_CAL_CURSE_H

#include "cal.h"
#include <vector>
#include <deque>

class CalCurse : public Cal {
private:
    int numarCurse;
    int victorii;
    double vitezaMaxima;
    std::vector<double> timpiiCurse;        // Timpi pentru fiecare cursă
    std::deque<std::string> adversari;      // Ultimii adversari întâlniți

public:
    CalCurse();
    CalCurse(const std::string& nume, const std::string& rasa, int varsta,
             const std::string& stare, double greutate, char gen, bool pedigree,
             int numarCurse, int victorii, double vitezaMaxima);

    std::string getTip() const override;

    void adaugaCursa(bool castigata, double timp, const std::string& adversar);
    double getRataVictorii() const;
    double getTimeMediu() const;
    std::vector<double> getTopTimpi(int n) const;    // Returnează top n cei mai buni timpi

    friend std::ostream& operator<<(std::ostream& out, const CalCurse& cal);
    friend std::istream& operator>>(std::istream& in, CalCurse& cal);
};

#endif
