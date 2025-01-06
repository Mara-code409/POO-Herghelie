#include "cal_agrement.h"

CalAgrement::CalAgrement()
    : Cal(), nivelDocilitate(1), specializare("Plimbare"), oreDresaj(0) {}

CalAgrement::CalAgrement(const std::string& nume, const std::string& rasa, int varsta,
                         const std::string& stare, double greutate, char gen, bool pedigree,
                         int nivelDocilitate, const std::string& specializare, int oreDresaj)
    : Cal(nume, rasa, varsta, stare, greutate, gen, pedigree),
      nivelDocilitate(nivelDocilitate), specializare(specializare), oreDresaj(oreDresaj) {}

std::string CalAgrement::getTip() const {
    return "Cal de agrement";
}

void CalAgrement::adaugaOreDresaj(int ore) {
    oreDresaj += ore;
    if (nivelDocilitate < 10) {
        nivelDocilitate++;
    }
}

int CalAgrement::getNivelDocilitate() const {
    return nivelDocilitate;
}

std::ostream& operator<<(std::ostream& out, const CalAgrement& cal) {
    out << static_cast<const Cal&>(cal)
        << "\nNivel docilitate: " << cal.nivelDocilitate
        << "\nSpecializare: " << cal.specializare
        << "\nOre dresaj: " << cal.oreDresaj;
    return out;
}

std::istream& operator>>(std::istream& in, CalAgrement& cal) {
    in >> static_cast<Cal&>(cal);

    std::cout << "Nivel docilitate (1-10): ";
    in >> cal.nivelDocilitate;

    std::cout << "Specializare (Plimbare/Dresaj/Salt): ";
    std::getline(in >> std::ws, cal.specializare);

    std::cout << "Ore dresaj: ";
    in >> cal.oreDresaj;

    return in;
}
