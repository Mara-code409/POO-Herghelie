#ifndef HERGHELIE_PLIMBARE_H
#define HERGHELIE_PLIMBARE_H

#include "activitate.h"

class Plimbare : public Activitate {
private:
    std::string traseu;
    std::string dificultate;  // "Usor", "Mediu", "Dificil"
    bool ghidaj;

public:
    Plimbare();
    Plimbare(const std::string& nume, const std::string& data, const std::string& ora,
             int durata, int capacitateMaxima, const std::string& traseu,
             const std::string& dificultate, bool ghidaj);

    std::string getTip() const override;
    bool necesitaGhidaj() const;

    friend std::ostream& operator<<(std::ostream& out, const Plimbare& p);
    friend std::istream& operator>>(std::istream& in, Plimbare& p);
};

#endif
