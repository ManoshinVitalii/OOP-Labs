#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <chrono>
#include <random>
#include <fstream>
#include <set>
#include <vector>
#include <time.h>
#include <map>
using namespace std;

enum NpcType {
    KnightType, PegasusType, DragonType
};

struct NPC;
struct Knight;
struct Pegasus;
struct Dragon;

struct VisitorFight {
    virtual bool visit(const shared_ptr<Knight>&) const = 0;
    virtual bool visit(const shared_ptr<Pegasus>&) const = 0;
    virtual bool visit(const shared_ptr<Dragon>&) const = 0;
};

struct ObserverFight {
    virtual void on_fight(const shared_ptr<NPC>&, const shared_ptr<NPC>&, bool) = 0;
};

class NPC : public enable_shared_from_this<NPC> {
    protected:
        short x;
        short y;
        NpcType type;
        vector<shared_ptr<ObserverFight>> observers;
    public:
        NPC(NpcType, short, short);
        NPC(NpcType, istream&);
        NpcType& gettype();
        void subscribe(const shared_ptr<ObserverFight>&);
        void fight_notify(const shared_ptr<NPC>&, bool);
        bool is_close(const shared_ptr<NPC>&, size_t) const;   
        short getX();
        short getY();
        virtual bool accept(const shared_ptr<VisitorFight>&, const shared_ptr<NPC>&) const = 0;
        virtual void save(ostream&);
        virtual void print() = 0;
        friend ostream& operator << (ostream&, NPC&);
        ~NPC() = default;
};
