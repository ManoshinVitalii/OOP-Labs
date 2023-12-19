#pragma once
#include "NPC.h"

class Knight : public NPC {
    public:
        Knight();
        Knight(short, short);
        Knight(istream&);
        void print() override;
        void save(ostream&) override;
        friend ostream& operator << (ostream&, Knight&);
        bool accept(const shared_ptr<VisitorFight>&, const shared_ptr<NPC>&) const override;
        ~Knight() = default;
};

struct KnightVisitor : public VisitorFight {
    bool visit(const shared_ptr<Knight>&) const override;
    bool visit(const shared_ptr<Pegasus>&) const override;
    bool visit(const shared_ptr<Dragon>&) const override;
};
