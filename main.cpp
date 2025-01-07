#include "cal_curse.h"
#include "cal_agrement.h"
#include "antrenament.h"
#include "plimbare.h"
#include "herghelie_factory.h"
#include "manager_herghelie.h"
#include "exceptii.h"
#include "gestiune.h"
#include <iostream>
#include <limits>

void afiseazaMeniu() {
    std::cout << "\n=== MENIU HERGHELIE ===\n";
    std::cout << "1. Adauga cal de curse\n";
    std::cout << "2. Adauga cal de agrement\n";
    std::cout << "3. Adauga antrenament\n";
    std::cout << "4. Adauga plimbare\n";
    std::cout << "5. Afiseaza toti caii\n";
    std::cout << "6. Afiseaza toate activitatile\n";
    std::cout << "7. Cauta cal dupa nume\n";
    std::cout << "8. Cauta activitate dupa nume\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alegeti o optiune: ";
}

void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ManagerHerghelie* manager = ManagerHerghelie::getInstanta();
    HerghelieFactory factory;
    int optiune;

    do {
        afiseazaMeniu();
        std::cin >> optiune;
        clearInputStream();

        try {
            switch (optiune) {
                case 1: {
                    std::cout << "\nIntroduceti datele calului de curse:\n";
                    std::string nume, rasa;
                    int varsta;

                    std::cout << "Nume: ";
                    std::getline(std::cin, nume);
                    std::cout << "Rasa: ";
                    std::getline(std::cin, rasa);
                    std::cout << "Varsta: ";
                    std::cin >> varsta;

                    Cal* cal = factory.creeazaCal("Curse", nume, rasa, varsta);
                    manager->adaugaCal(cal);
                    std::cout << "Cal de curse adaugat cu succes!\n";
                    break;
                }
                case 2: {
                    std::cout << "\nIntroduceti datele calului de agrement:\n";
                    std::string nume, rasa;
                    int varsta;

                    std::cout << "Nume: ";
                    std::getline(std::cin, nume);
                    std::cout << "Rasa: ";
                    std::getline(std::cin, rasa);
                    std::cout << "Varsta: ";
                    std::cin >> varsta;

                    Cal* cal = factory.creeazaCal("Agrement", nume, rasa, varsta);
                    manager->adaugaCal(cal);
                    std::cout << "Cal de agrement adaugat cu succes!\n";
                    break;
                }
                case 3: {
                    std::cout << "\nIntroduceti datele antrenamentului:\n";
                    std::string nume, data;

                    std::cout << "Nume antrenament: ";
                    std::getline(std::cin, nume);
                    std::cout << "Data (YYYY-MM-DD): ";
                    std::getline(std::cin, data);

                    Activitate* activitate = factory.creeazaActivitate("Antrenament", nume, data);
                    manager->adaugaActivitate(activitate);
                    std::cout << "Antrenament adaugat cu succes!\n";
                    break;
                }
                case 4: {
                    std::cout << "\nIntroduceti datele plimbarii:\n";
                    std::string nume, data;

                    std::cout << "Nume plimbare: ";
                    std::getline(std::cin, nume);
                    std::cout << "Data (YYYY-MM-DD): ";
                    std::getline(std::cin, data);

                    Activitate* activitate = factory.creeazaActivitate("Plimbare", nume, data);
                    manager->adaugaActivitate(activitate);
                    std::cout << "Plimbare adaugata cu succes!\n";
                    break;
                }
                case 5: {
                    std::cout << "\nLista tuturor cailor:\n";
                    manager->afiseazaCai();
                    break;
                }
                case 6: {
                    std::cout << "\nLista tuturor activitatilor:\n";
                    manager->afiseazaActivitati();
                    break;
                }
                case 7: {
                    std::string nume;
                    std::cout << "Introduceti numele calului: ";
                    std::getline(std::cin, nume);

                    Cal* cal = manager->gasesteCal(nume);
                    if (cal) {
                        std::cout << "\nCal gasit:\n" << *cal << "\n";
                    } else {
                        std::cout << "Cal negasit!\n";
                    }
                    break;
                }
                case 8: {
                    std::string nume;
                    std::cout << "Introduceti numele activitatii: ";
                    std::getline(std::cin, nume);

                    Activitate* activitate = manager->gasesteActivitate(nume);
                    if (activitate) {
                        std::cout << "\nActivitate gasita:\n" << *activitate << "\n";
                    } else {
                        std::cout << "Activitate negasita!\n";
                    }
                    break;
                }
                case 0:
                    std::cout << "La revedere!\n";
                    break;
                default:
                    std::cout << "Optiune invalida!\n";
            }
        }
        catch (const ExceptieHerghelie& e) {
            std::cout << "Eroare: " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Eroare neasteptata: " << e.what() << "\n";
        }

    } while (optiune != 0);

    return 0;
}
