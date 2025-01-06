#include "plimbare.h"

Plimbare::Plimbare()
    : Activitate(), traseu(""), dificultate("Usor"), ghidaj(false) {}

Plimbare::Plimbare(const std::string& nume, const std::string& data, const std::string& ora,
                   int durata, int capacitateMaxima, const std::string& traseu,
                   const std::string& dificultate, bool ghidaj)
    : Activitate(nume, data, ora, durata, capacitateMaxima),
      traseu(traseu), dificultate(dificultate), ghidaj(ghidaj) {}

std::string Plimbare::getTip() const {
    return "Plimbare";
}

bool Plimbare::necesitaGhidaj() const {
    return ghidaj;
}

std::ostream& operator<<(std::ostream& out, const Plimbare& p) {
    out << static_cast<const Activitate&>(p)
        << "\nTraseu: " << p.traseu
        << "\nDificultate: " << p.dificultate
        << "\nGhidaj: " << (p.ghidaj ? "Da" : "Nu");
    return out;
}

std::istream& operator>>(std::istream& in, Plimbare& p) {
    in >> static_cast<Activitate&>(p);

    std::cout << "Traseu: ";
    std::getline(in >> std::ws, p.traseu);

    std::cout << "Dificultate (Usor/Mediu/Dificil): ";
    std::getline(in >> std::ws, p.dificultate);

    std::cout << "Necesita ghidaj? (1-Da/0-Nu): ";
    in >> p.ghidaj;

    return in;
}
