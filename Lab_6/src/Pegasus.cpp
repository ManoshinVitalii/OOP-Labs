#include "../headers/Pegasus.h"

Pegasus::Pegasus() : NPC(PegasusType, 0, 0) {}

Pegasus::Pegasus(short x, short y) : NPC(PegasusType, x, y) {}

Pegasus::Pegasus(istream &in) : NPC(PegasusType, in) {}

bool PegasusVisitor::visit(const shared_ptr<Knight> &defender) const {
    return 0;
}

bool PegasusVisitor::visit(const shared_ptr<Pegasus> &defender) const {
    return 0;
}

bool PegasusVisitor::visit(const shared_ptr<Dragon> &defender) const {
    return 0;
}

void Pegasus::save(ostream &out) {
    out << PegasusType << endl;
    NPC::save(out);
}

bool Pegasus::accept(const shared_ptr<VisitorFight> &attacker_visitor, const shared_ptr<NPC> &attacker) const {
    shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    shared_ptr<NPC> npc_ptr = const_pointer_cast<NPC>(npc_const_ptr);
    shared_ptr<Pegasus> defender = dynamic_pointer_cast<Pegasus>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fight_notify(defender, result);

    return result;
}

ostream &operator<<(ostream &out, Pegasus &person) {
    out << "Pegasusr = " << *static_cast<NPC *>(&person) << endl;
    return out;
}

void Pegasus::print() {
    cout << *this;
}
