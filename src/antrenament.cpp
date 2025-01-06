#include "antrenament.h"

Antrenament::Antrenament()
    : Activitate(), tipAntrenament(""), intensitate(1), instructor("") {}

Antrenament::Antrenament(const std::string& nume, const std::string& data, const std::string& ora,
                         int durata, int capacitateMaxima, const std::string& tipAntrenament,
                         int intensitate, const std::string& instructor)
    : Activitate(nume, data, ora, durata, capacitateMaxima),
      tipAntrenament(tipAntrenament), intensitate(intensitate), instructor(instructor) {}

std::string Antrenament::getTip() const {
    return "Antrenament";
}

int Antrenament::getIntensitate() const {
    return intensitate;
}

std::ostream& operator<<(std::ostream& out, const Antrenament& ant) {
    out << static_cast<const Activitate&>(ant)
        << "\nTip antrenament: " << ant.tipAntrenament
        << "\nIntensitate: " << ant.intensitate
        << "\nInstructor: " << ant.instructor;
    return out;
}

std::istream& operator>>(std::istream& in, Antrenament& ant) {
    in >> static_cast<Activitate&>(ant);

    std::cout << "Tip antrenament (Viteza/Anduranta/Forta): ";
    std::getline(in >> std::ws, ant.tipAntrenament);

    std::cout << "Intensitate (1-10): ";
    in >> ant.intensitate;

    std::cout << "Instructor: ";
    std::getline(in >> std::ws, ant.instructor);

    return in;
}
