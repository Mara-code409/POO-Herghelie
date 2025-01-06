#include "manager_herghelie.h"
#include <iostream>
#include <algorithm>

ManagerHerghelie* ManagerHerghelie::instanta = nullptr;

ManagerHerghelie* ManagerHerghelie::getInstanta() {
    if (instanta == nullptr) {
        instanta = new ManagerHerghelie();
    }
    return instanta;
}

void ManagerHerghelie::adaugaCal(Cal* cal) {
    if (cal == nullptr) return;
    cai.push_back(cal);
}

void ManagerHerghelie::adaugaActivitate(Activitate* activitate) {
    if (activitate == nullptr) return;
    activitati.push_back(activitate);
}

Cal* ManagerHerghelie::gasesteCal(const std::string& nume) {
    auto it = std::find_if(cai.begin(), cai.end(),
        [&nume](const Cal* c) { return c->getNume() == nume; });
    return (it != cai.end()) ? *it : nullptr;
}

Activitate* ManagerHerghelie::gasesteActivitate(const std::string& nume) {
    auto it = std::find_if(activitati.begin(), activitati.end(),
        [&nume](const Activitate* a) { return a->getNume() == nume; });
    return (it != activitati.end()) ? *it : nullptr;
}

void ManagerHerghelie::afiseazaCai() const {
    std::cout << "Lista cai:\n";
    for (const auto& cal : cai) {
        std::cout << *cal << "\n---------------\n";
    }
}

void ManagerHerghelie::afiseazaActivitati() const {
    std::cout << "Lista activitati:\n";
    for (const auto& activitate : activitati) {
        std::cout << *activitate << "\n---------------\n";
    }
}

ManagerHerghelie::~ManagerHerghelie() {
    for (auto cal : cai) delete cal;
    for (auto activitate : activitati) delete activitate;
}
