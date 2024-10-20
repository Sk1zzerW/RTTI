#include <iostream>
#include <vector>
#include <string>

namespace GameUnits {
    class Position {
    public:
        float x, y;

        Position(float x = 0, float y = 0) : x(x), y(y) {}

        void print() const {
            std::cout << "Position: (" << x << ", " << y << ")\n";
        }
    };

    class Unit {
    protected:
        std::string name;
        Position position;

    public:
        Unit(std::string name, Position pos) : name(name), position(pos) {}

        virtual void attack() const = 0;

        void print() const {
            std::cout << "Unit: " << name << "\n";
            position.print();
        }
    };

    class Weapon {
    private:
        std::string weaponName;
        int damage;

    public:
        Weapon(std::string name, int dmg) : weaponName(name), damage(dmg) {}

        void use() const {
            std::cout << "Using weapon: " << weaponName << " with damage: " << damage << "\n";
        }
    };

    class Warrior : public Unit {
    private:
        Weapon weapon;

    public:
        Warrior(std::string name, Position pos, Weapon w)
            : Unit(name, pos), weapon(w) {}

        void attack() const override {
            std::cout << name << " attacks!\n";
            weapon.use();
        }
    };
}

namespace GameBattle {
    class Team {
    private:
        std::string teamName;
        std::vector<GameUnits::Unit*> members;

    public:
        Team(std::string name) : teamName(name) {}

        void addMember(GameUnits::Unit* unit) {
            members.push_back(unit);
        }

        void battleCry() const {
            std::cout << teamName << " is ready to battle!\n";
            for (const auto& member : members) {
                member->print();
            }
        }
    };
}

namespace Utility {
    class IPrint {
    public:
        virtual void print() const = 0;
    };

    template<typename T>
    class Array {
    private:
        std::vector<T> elements;

    public:
        void add(const T& element) {
            elements.push_back(element);
        }

        void print() const {
            for (const auto& element : elements) {
                element.print();
            }
        }
    };
}

int main() {
    using namespace GameUnits;
    using namespace GameBattle;
    using namespace Utility;

    Position warriorPos(10, 20);
    Weapon sword("Sword", 15);
    Warrior warrior("Knight", warriorPos, sword);

    Team team("Brave Warriors");
    team.addMember(&warrior);

    team.battleCry();

    return 0;
}
//P.S Я не уверен в том, правильно ли выполнено задание. Я немного не понял эту тему, поэтому посмотрел немного видеороликов в интернете.