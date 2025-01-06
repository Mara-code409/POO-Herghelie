#ifndef HERGHELIE_CAL_H
#define HERGHELIE_CAL_H

#include <string>
#include <iostream>

class Cal {
protected:
    std::string nume;
    std::string rasa;
    int varsta;
    std::string stare;  // "Sãnãtos", "Bolnav", "În antrenament"
    double greutate;
    char gen;           // 'M' sau 'F'
    bool pedigree;

public:
    Cal();
    Cal(const std::string& nume, const std::string& rasa, int varsta,
        const std::string& stare, double greutate, char gen, bool pedigree);
    Cal(const Cal& other);

    virtual Cal& operator=(const Cal& other);
    virtual std::string getTip() const = 0;

    // Getteri
    const std::string& getNume() const;
    const std::string& getRasa() const;
    int getVarsta() const;
    const std::string& getStare() const;
    double getGreutate() const;
    char getGen() const;
    bool hasPedigree() const;

    // Setteri
    void setStare(const std::string& stareaNoua);
    void setGreutate(double greutateNoua);

    // Operatori
    friend std::ostream& operator<<(std::ostream& out, const Cal& cal);
    friend std::istream& operator>>(std::istream& in, Cal& cal);
    bool operator<(const Cal& other) const;

    virtual ~Cal();
};

#endif
