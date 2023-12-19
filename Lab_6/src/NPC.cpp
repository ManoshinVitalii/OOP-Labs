#include "../headers/NPC.h"

NPC::NPC(NpcType t, short _x, short _y) : type(t), x(_x), y(_y) {}

void NPC::subscribe(const shared_ptr<ObserverFight>& observer) {
    observers.push_back(observer);
}

void NPC::fight_notify(const shared_ptr<NPC>& defender, bool win) {
    for (auto& elem : observers) {
        elem->on_fight(shared_from_this(), defender, win);
    }
}

bool NPC::is_close(const shared_ptr<NPC>& other, size_t distance) const {
    return (x - other->x) * (x - other->x) + (y - other->y) * (y - other->y) <= distance * distance;
}

short NPC::getX() {
    return x;
}

short NPC::getY() {
    return y;
}

NpcType& NPC::gettype() {
    return type;
}

NPC::NPC(NpcType t, istream& in) : type(t) {
    in >> x;
    in >> y;
}

void NPC::save(ostream& os) {
    os << x << endl;
    os << y << endl;
}

ostream& operator << (ostream& os, NPC& npc) {
    os << "[x = " << npc.x << ", y = " << npc.y <<"]";
    return os;
}
