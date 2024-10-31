#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura Member
struct Member {
    string first_name;
    string last_name;
    int age;
};

// Estructura Club
struct Club {
    string name;
    string creation_date;
    int max_capacity;
    vector<Member*> members;
};

// Función para crear un nuevo club
Club* createClub(const string& name, const string& creation_date, int max_capacity) {
    Club* newClub = new Club;
    newClub->name = name;
    newClub->creation_date = creation_date;
    newClub->max_capacity = max_capacity;
    return newClub;
}

// Función para registrar un miembro en un club
bool addMemberToClub(Club* club, const string& first_name, const string& last_name, int age) {
    if (club->members.size() >= club->max_capacity) {
        cout << "El club ha alcanzado su capacidad máxima." << endl;
        return false;
    }
    Member* newMember = new Member{first_name, last_name, age};
    club->members.push_back(newMember);
    return true;
}

// Función para listar todos los clubes creados
void listClubs(const vector<Club*>& clubs) {
    for (const auto& club : clubs) {
        cout << "Nombre del club: " << club->name << ", Fecha de creación: " << club->creation_date
             << ", Capacidad máxima: " << club->max_capacity << endl;
    }
}

// Función para listar los miembros de un club específico
void listMembers(const Club* club) {
    cout << "Miembros del club " << club->name << ":" << endl;
    for (const auto& member : club->members) {
        cout << "Nombre: " << member->first_name << " " << member->last_name
             << ", Edad: " << member->age << endl;
    }
}

// Función para contar el número total de miembros en un club
int countMembers(const Club* club) {
    return club->members.size();
}

int main() {
    vector<Club*> clubs;
    int option;

    do {
        cout << "\nGestión de Clubes y Miembros\n";
        cout << "1. Crear un nuevo club\n";
        cout << "2. Listar todos los clubes\n";
        cout << "3. Registrar un miembro en un club\n";
        cout << "4. Listar los miembros de un club\n";
        cout << "5. Calcular el número total de miembros en un club\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> option;

        if (option == 1) {
            string name, creation_date;
            int max_capacity;
            cout << "Ingrese el nombre del club: ";
            cin >> name;
            cout << "Ingrese la fecha de creación: ";
            cin >> creation_date;
            cout << "Ingrese la capacidad máxima: ";
            cin >> max_capacity;
            clubs.push_back(createClub(name, creation_date, max_capacity));
            cout << "Club creado con éxito.\n";
        } else if (option == 2) {
            listClubs(clubs);
        } else if (option == 3) {
            string club_name, first_name, last_name;
            int age;
            cout << "Ingrese el nombre del club: ";
            cin >> club_name;
            bool club_found = false;
            for (auto& club : clubs) {
                if (club->name == club_name) {
                    cout << "Ingrese el nombre del miembro: ";
                    cin >> first_name;
                    cout << "Ingrese el apellido del miembro: ";
                    cin >> last_name;
                    cout << "Ingrese la edad del miembro: ";
                    cin >> age;
                    if (addMemberToClub(club, first_name, last_name, age)) {
                        cout << "Miembro registrado con éxito.\n";
                    }
                    club_found = true;
                    break;
                }
            }
            if (!club_found) {
                cout << "Club no encontrado.\n";
            }
        } else if (option == 4) {
            string club_name;
            cout << "Ingrese el nombre del club: ";
            cin >> club_name;
            bool club_found = false;
            for (const auto& club : clubs) {
                if (club->name == club_name) {
                    listMembers(club);
                    club_found = true;
                    break;
                }
            }
            if (!club_found) {
                cout << "Club no encontrado.\n";
            }
        } else if (option == 5) {
            string club_name;
            cout << "Ingrese el nombre del club: ";
            cin >> club_name;
            bool club_found = false;
            for (const auto& club : clubs) {
                if (club->name == club_name) {
                    cout << "Número total de miembros: " << countMembers(club) << endl;
                    club_found = true;
                    break;
                }
            }
            if (!club_found) {
                cout << "Club no encontrado.\n";
            }
        }
    } while (option != 0);

    // Liberar memoria
    for (auto& club : clubs) {
        for (auto& member : club->members) {
            delete member;
        }
        delete club;
    }

    return 0;
}
