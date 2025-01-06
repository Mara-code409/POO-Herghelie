#ifndef HERGHELIE_ACTIVITATE_H
#define HERGHELIE_ACTIVITATE_H

#include <string>
#include <iostream>

class Activitate {
protected:
    std::string nume;
    std::string data;       // "YYYY-MM-DD"
    std::string ora;        // "HH:MM"
    int durata;             // in minute
    int capacitateMaxima;

public:
    Activitate();
    Activitate(const std::string& nume, const std::string& data, const std::string& ora,
               int durata, int capacitateMaxima);
    Activitate(const Activitate& other);

    virtual std::string getTip() const = 0;

    const std::string& getNume() const;
    const std::string& getData() const;
    const std::string& getOra() const;
    int getDurata() const;
    int getCapacitate() const;

    friend std::ostream& operator<<(std::ostream& out, const Activitate& act);
    friend std::istream& operator>>(std::istream& in, Activitate& act);

    virtual ~Activitate() = default;
};

#endif
