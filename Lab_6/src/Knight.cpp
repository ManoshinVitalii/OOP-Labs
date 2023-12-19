#include "../headers/Knight.h"

Knight::Knight() : NPC(KnightType, 0, 0) {}

Knight::Knight(short x, short y) : NPC(KnightType, x, y) {}

Knight::Knight(istream& in) : NPC(KnightType, in) {}

bool KnightVisitor::visit(const shared_ptr<Knight>& defender) const {
    return 0;
}

bool KnightVisitor::visit(const shared_ptr<Pegasus>& defender) const {
    return 0;
}

bool KnightVisitor::visit(const shared_ptr<Dragon>& defender) const {
    return 1;
}

void Knight::save(ostream& out) {
    out << KnightType << endl;
    NPC::save(out);
}

bool Knight::accept(const shared_ptr<VisitorFight>& attacker_visitor, const shared_ptr<NPC>& attacker) const {
    shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    shared_ptr<NPC> npc_ptr = const_pointer_cast<NPC>(npc_const_ptr);
    shared_ptr<Knight> defender = dynamic_pointer_cast<Knight>(npc_ptr);
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result; 
}

ostream& operator << (ostream& out, Knight& person) {
    out << "Knightr = " << *static_cast<NPC*>(&person) << endl;
    return out;
}

void Knight::print() {
    cout << *this;
}
