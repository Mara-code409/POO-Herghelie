#ifndef HERGHELIE_ANTRENAMENT_H
#define HERGHELIE_ANTRENAMENT_H

#include "activitate.h"

class Antrenament : public Activitate {
private:
    std::string tipAntrenament;  // "Viteza", "Anduranta", "Forta"
    int intensitate;             // 1-10
    std::string instructor;

public:
    Antrenament();
    Antrenament(const std::string& nume, const std::string& data, const std::string& ora,
                int durata, int capacitateMaxima, const std::string& tipAntrenament,
                int intensitate, const std::string& instructor);

    std::string getTip() const override;
    int getIntensitate() const;

    friend std::ostream& operator<<(std::ostream& out, const Antrenament& ant);
    friend std::istream& operator>>(std::istream& in, Antrenament& ant);
};

#endif
