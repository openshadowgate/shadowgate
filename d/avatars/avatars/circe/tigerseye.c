#include <std.h>
inherit "/std/armour";

int OWNED;
string owner;

void create() {
  ::create();
  set_name("ring");
  set_id(({"ring","tigers eye ring","rautha ring"}));
  set_short("%^RESET%^%^ORANGE%^Tigers eye Ring%^RESET%^");
  set_long("This ornate silver ring has been set with a round, highly "+
     "polished %^ORANGE%^tigers eye gem%^RESET%^.  Looking closely, "+
     "you can see a faint letter %^ORANGE%^'%^YELLOW%^R%^RESET%^"+
     "%^ORANGE%^' %^RESET%^inscribed within the gem among the swirling "+
     "%^ORANGE%^d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^k"+
     "%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r %^RESET%^%^ORANGE%^brown "+
     "pattern%^RESET%^.  The ring itself "+
     "seems a little battered and aged, a sign that this particular "+
     "piece of jewelry has been around for quite some time.");
  set_lore("This is rumored to be the ring of the Rautha family, "+
     "a family of desert traders.  Many secrets and stories have "+
     "been told of them, but none seem verifiable.");
  set_type("ring");
  set_limbs(({"left hand"}));
  set_weight(0);
  set_value(10);
  set_property("death keep",1);
  set_wear((:TO,"wearme":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
                set_size(TP->query_size());
        }
}

int wearme(){
        if((string)TPQN != owner) {
                tell_object(ETO,"The ring seems to resist your hand.");
                return 0;
        }
        tell_object(ETO,"%^RESET%^%^ORANGE%^You slip on the ring and "+
           "smirk as you remember the miserable bastard's fate.");
        tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" smirks as "+
           ""+ETO->QS+" wears the ring.",ETO);
        return 1;
}
