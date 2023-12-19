#include "headers/NPC.h"
#include "headers/Knight.h"
#include "headers/Pegasus.h"
#include "headers/Dragon.h"
#include "headers/Factory.h"
#include "headers/Observers.h"
#include "headers/DataMethods.h"

map<NpcType, shared_ptr<VisitorFight>> visitors = {
    {KnightType, make_shared<KnightVisitor>()},
    {PegasusType, make_shared<PegasusVisitor>()},
    {DragonType, make_shared<DragonVisitor>()}
};


ostream& operator << (ostream& os, const set<shared_ptr<NPC>>& array) {
    for (auto& elem : array) 
        elem->print();
    return os;
}

void fight(const set<shared_ptr<NPC>>& array, set<shared_ptr<NPC>>& dead_list, size_t distance) {
    for (const auto& attacker : array) 
        for (const auto& defender : array) {
            if (attacker != defender && attacker->is_close(defender, distance) && dead_list.find(defender) == dead_list.end()) 
                if (defender->accept(visitors[attacker->gettype()], attacker)) {
                    dead_list.insert(defender);

                }
        }
}

int main() {
    srand(time(NULL));

    set<shared_ptr<NPC>> array;

    cout << "Generating ..." << endl;
    for (size_t i = 0; i < 40; ++i) 
        array.insert(Factory::Create(NpcType(rand() % 3), rand() % 500, rand() % 500));
    cout << "Saving ..." << endl;
    DataMethods::saveData(array, "npc.txt");

    cout << "Loading..." << endl;
    array = DataMethods::loadData("npc.txt");

    cout << array;

    cout << "Fighting..." << endl << array;
    for (size_t distance = 0; distance <= 500 && !array.empty(); distance += 30) {
        set<shared_ptr<NPC>> dead_list;

        fight(array, dead_list, distance);
        for (auto& dead : dead_list) {
            array.erase(dead);
        }
        cout <<"time = " << distance << " Fight stats ----------\n";
        cout << "distance = " << distance << "\n killed = " << dead_list.size() << "\n\n\n";
    }

    cout << "Survivors = " << endl << array;

    return 0;
}
