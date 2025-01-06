#include "cal.h"

Cal::Cal()
    : nume(""), rasa(""), varsta(0), stare("Sanatos"),
      greutate(0.0), gen('M'), pedigree(false) {}

Cal::Cal(const std::string& nume, const std::string& rasa, int varsta,
         const std::string& stare, double greutate, char gen, bool pedigree)
    : nume(nume), rasa(rasa), varsta(varsta), stare(stare),
      greutate(greutate), gen(gen), pedigree(pedigree) {}

Cal::Cal(const Cal& other)
    : nume(other.nume), rasa(other.rasa), varsta(other.varsta),
      stare(other.stare), greutate(other.greutate),
      gen(other.gen), pedigree(other.pedigree) {}

Cal& Cal::operator=(const Cal& other) {
    if (this != &other) {
        nume = other.nume;
        rasa = other.rasa;
        varsta = other.varsta;
        stare = other.stare;
        greutate = other.greutate;
        gen = other.gen;
        pedigree = other.pedigree;
    }
    return *this;
}

const std::string& Cal::getNume() const { return nume; }
const std::string& Cal::getRasa() const { return rasa; }
int Cal::getVarsta() const { return varsta; }
const std::string& Cal::getStare() const { return stare; }
double Cal::getGreutate() const { return greutate; }
char Cal::getGen() const { return gen; }
bool Cal::hasPedigree() const { return pedigree; }

void Cal::setStare(const std::string& stareaNoua) {
    stare = stareaNoua;
}

void Cal::setGreutate(double greutateNoua) {
    greutate = greutateNoua;
}

std::ostream& operator<<(std::ostream& out, const Cal& cal) {
    out << "Nume: " << cal.nume
        << "\nRasa: " << cal.rasa
        << "\nVarsta: " << cal.varsta
        << "\nStare: " << cal.stare
        << "\nGreutate: " << cal.greutate << " kg"
        << "\nGen: " << cal.gen
        << "\nPedigree: " << (cal.pedigree ? "Da" : "Nu");
    return out;
}

std::istream& operator>>(std::istream& in, Cal& cal) {
    std::cout << "Nume: ";
    std::getline(in >> std::ws, cal.nume);

    std::cout << "Rasa: ";
    std::getline(in >> std::ws, cal.rasa);

    std::cout << "Varsta: ";
    in >> cal.varsta;

    std::cout << "Greutate (kg): ";
    in >> cal.greutate;

    std::cout << "Gen (M/F): ";
    in >> cal.gen;

    std::cout << "Are pedigree? (1-Da/0-Nu): ";
    in >> cal.pedigree;

    return in;
}

bool Cal::operator<(const Cal& other) const {
    return this->greutate < other.greutate;
}

Cal::~Cal() {}
