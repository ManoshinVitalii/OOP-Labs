#pragma once
#include "NPC.h"

class Dragon : public NPC {
    public:
        Dragon();
        Dragon(short, short);
        Dragon(istream&);
        bool accept(const shared_ptr<VisitorFight>&, const shared_ptr<NPC>&) const override;
        void save(ostream&) override;
        void print() override;
        friend ostream& operator << (ostream&, Dragon&);
        ~Dragon() = default;
};

struct DragonVisitor : public VisitorFight {
    bool visit(const shared_ptr<Knight>&) const override;
    bool visit(const shared_ptr<Pegasus>&) const override;
    bool visit(const shared_ptr<Dragon>&) const override;
};
