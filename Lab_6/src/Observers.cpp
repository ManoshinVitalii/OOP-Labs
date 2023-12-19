#include "../headers/Observers.h"

shared_ptr<ObserverFight> TextObserver::get() {
    static TextObserver instance;
    return shared_ptr<ObserverFight>(&instance, [](ObserverFight*) {});
}

void TextObserver::on_fight(const shared_ptr<NPC>& attacker, const shared_ptr<NPC>& defender, bool win) {
    if (win) { 
        cout << "\nMurder ------\n";
        attacker->print();
        defender->print();
    }
}

std::string FileObserver::NPCname(const NpcType& type) {
    if(type == KnightType) 
        return "Knight";  
    if(type == PegasusType) 
        return "Pegasus";   
    if(type == DragonType) 
        return "Dragon";
    throw invalid_argument("Unknown NPC type");
}

shared_ptr<ObserverFight> FileObserver::get() {
    static FileObserver instance;
    return shared_ptr<ObserverFight>(&instance, [](ObserverFight*) {});
}

void FileObserver::on_fight(const shared_ptr<NPC>& attacker, const shared_ptr<NPC>& defender, bool win) {
    if (win) {
        if (!fs.is_open()) {
            fs.open("log.txt");
        }
        fs << "\nMurder ------\n";
        fs << NPCname(attacker->gettype()) << " =  ";
        fs << "[x = " << attacker->getX() << ", y = " << attacker->getY() << "]" << endl;
        fs << NPCname(defender->gettype()) << " = ";
        fs << "[x = " << defender->getX() << ", y = " << defender->getY() << "]" << std::endl;
    }
}
