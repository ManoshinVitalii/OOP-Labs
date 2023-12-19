#pragma once
#include "NPC.h"

class Pegasus : public NPC {
    public:
        Pegasus();
        Pegasus(short, short);
        Pegasus(istream&);
        bool accept(const shared_ptr<VisitorFight>&, const shared_ptr<NPC>&) const override;
        void save(ostream&) override;
        void print() override;
        friend ostream& operator << (ostream&, Pegasus&);
        ~Pegasus() = default;
};

struct PegasusVisitor : public VisitorFight {
    bool visit(const shared_ptr<Knight>&) const override;
    bool visit(const shared_ptr<Pegasus>&) const override;
    bool visit(const shared_ptr<Dragon>&) const override;
};
