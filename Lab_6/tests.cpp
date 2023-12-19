#include "../headers/NPC.h"
#include "../headers/Knight.h"
#include "../headers/Pegasus.h"
#include "../headers/Dragon.h"
#include "../headers/Factory.h"
#include "../headers/Observers.h"

#include <gtest/gtest.h>

TEST(test_01, Test)
{
    shared_ptr<NPC> ptr = make_shared<Knight>(2, 2);
    ASSERT_TRUE(ptr->gettype() == 0 && ptr->getX() == 2 && ptr->getY() == 2);
}

TEST(test_02, Test)
{
    shared_ptr<NPC> ptr1 = make_shared<Dragon>(0, 0);
    shared_ptr<NPC> ptr2 = make_shared<Pegasus>(10, 10);
    ASSERT_TRUE(ptr1->is_close(ptr2, 20));
}

TEST(test_03, Test)
{
    shared_ptr<NPC> ptr1 = make_shared<Dragon>(0, 0);
    shared_ptr<NPC> ptr2 = make_shared<Pegasus>(10, 10);
    ASSERT_FALSE(ptr1->is_close(ptr2, 2));
}

TEST(test_04, Test)
{
    KnightVisitor visitor;
    shared_ptr<Knight> ptr = make_shared<Knight>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_05, Test)
{
    KnightVisitor visitor;
    shared_ptr<Pegasus> ptr = make_shared<Pegasus>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_06, Test)
{
    KnightVisitor visitor;
    shared_ptr<Dragon> ptr = make_shared<Dragon>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(test_07, Test)
{
    Knight s;
    s.~Knight();
}

TEST(test_08, Test)
{
    Knight s(2, 2);
    ASSERT_TRUE(s.gettype() == 0 && s.getX() == 2 && s.getY() == 2);
}

TEST(test_09, Test)
{
    shared_ptr<NPC> defender = make_shared<Knight>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Dragon>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<DragonVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_10, Test)
{
    shared_ptr<NPC> defender = make_shared<Knight>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Knight>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<KnightVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_11, Test)
{
    shared_ptr<NPC> defender = make_shared<Knight>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Pegasus>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<PegasusVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_12, Test)
{
    PegasusVisitor visitor;
    shared_ptr<Knight> ptr = make_shared<Knight>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_13, Test)
{
    PegasusVisitor visitor;
    shared_ptr<Pegasus> ptr = make_shared<Pegasus>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_14, Test)
{
    PegasusVisitor visitor;
    shared_ptr<Dragon> ptr = make_shared<Dragon>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_15, Test)
{
    Pegasus d;
    d.~Pegasus();
}

TEST(test_16, Test)
{
    Pegasus d(2, 2);
    ASSERT_TRUE(d.gettype() == 1 && d.getX() == 2 && d.getY() == 2);
}

TEST(test_17, Test)
{
    shared_ptr<NPC> defender = make_shared<Pegasus>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Dragon>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<DragonVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(test_18, Test)
{
    shared_ptr<NPC> defender = make_shared<Pegasus>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Knight>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<KnightVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_19, Test)
{
    shared_ptr<NPC> defender = make_shared<Pegasus>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Pegasus>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<PegasusVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_20, Test)
{
    DragonVisitor visitor;
    shared_ptr<Knight> ptr = make_shared<Knight>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_21, Test)
{
    DragonVisitor visitor;
    shared_ptr<Pegasus> ptr = make_shared<Pegasus>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(test_22, Test)
{
    DragonVisitor visitor;
    shared_ptr<Dragon> ptr = make_shared<Dragon>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(test_23, Test)
{
    Dragon o;
    o.~Dragon();
}

TEST(test_24, Test)
{
    Dragon o(2, 2);
    ASSERT_TRUE(o.gettype() == 2 && o.getX() == 2 && o.getY() == 2);
}

TEST(test_25, Test)
{
    shared_ptr<NPC> defender = make_shared<Dragon>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Knight>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<KnightVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(test_26, Test)
{
    shared_ptr<NPC> defender = make_shared<Dragon>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Pegasus>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<PegasusVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_27, Test)
{
    shared_ptr<NPC> defender = make_shared<Dragon>(2, 2);
    shared_ptr<NPC> attacker = make_shared<Dragon>(3, 3);
    shared_ptr<VisitorFight> visitor_ptr = make_shared<DragonVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(test_28, Test)
{
    shared_ptr<NPC> ptr = Factory::Create(KnightType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 0 && ptr->getX() == 1 && ptr->getY() == 1);
}

TEST(test_29, Test)
{
    shared_ptr<NPC> ptr = Factory::Create(DragonType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 2 && ptr->getX() == 1 && ptr->getY() == 1);
}

TEST(test_30, Test)
{
    shared_ptr<NPC> ptr = Factory::Create(PegasusType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 1 && ptr->getX() == 1 && ptr->getY() == 1);
}

TEST(test_31, Test)
{
    shared_ptr<NPC> ptr;
    ASSERT_ANY_THROW(ptr = Factory::Create(NpcType(534), 2, 2));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
