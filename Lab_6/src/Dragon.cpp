#include "../headers/Dragon.h"

Dragon::Dragon() : NPC(DragonType, 0, 0) {}

Dragon::Dragon(short x, short y) : NPC(DragonType, x, y) {}

Dragon::Dragon(istream &in) : NPC(DragonType, in) {}

bool DragonVisitor::visit(const shared_ptr<Knight> &defender) const {
    return 0;
}

bool DragonVisitor::visit(const shared_ptr<Pegasus> &defender) const {
    return 1;
}

bool DragonVisitor::visit(const shared_ptr<Dragon> &defender) const {
    return 0;
}

void Dragon::save(ostream &out) {
    out << DragonType << endl;
    NPC::save(out);
}

bool Dragon::accept(const shared_ptr<VisitorFight> &attacker_visitor, const shared_ptr<NPC> &attacker) const {
    shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    shared_ptr<NPC> npc_ptr = const_pointer_cast<NPC>(npc_const_ptr);
    shared_ptr<Dragon> defender = dynamic_pointer_cast<Dragon>(npc_ptr);
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

ostream &operator<<(ostream &out, Dragon &person) {
    out << "Dragonr = " << *static_cast<NPC *>(&person) << endl;
    return out;
}

void Dragon::print() {
    cout << *this;
}
