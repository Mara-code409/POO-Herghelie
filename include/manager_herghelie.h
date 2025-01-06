#ifndef HERGHELIE_MANAGER_H
#define HERGHELIE_MANAGER_H

#include "cal.h"
#include "activitate.h"
#include <vector>
#include <memory>

class ManagerHerghelie {
private:
    static ManagerHerghelie* instanta;
    std::vector<Cal*> cai;
    std::vector<Activitate*> activitati;

    // Constructor privat (Singleton)
    ManagerHerghelie() = default;

public:
    // Evităm copierea și atribuirea
    ManagerHerghelie(const ManagerHerghelie&) = delete;
    ManagerHerghelie& operator=(const ManagerHerghelie&) = delete;

    static ManagerHerghelie* getInstanta();

    void adaugaCal(Cal* cal);
    void adaugaActivitate(Activitate* activitate);

    Cal* gasesteCal(const std::string& nume);
    Activitate* gasesteActivitate(const std::string& nume);

    void afiseazaCai() const;
    void afiseazaActivitati() const;

    ~ManagerHerghelie();
};

#endif
