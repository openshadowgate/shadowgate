// Goodies' cloak clasp, made by Lujke, plundering code from Thorn and Nienne

#include <std.h>

int old;
object protect;
string whose;

int resist_magic();

inherit "/std/armour";

create() {
  ::create();
  whose = "";
  set_property("clasp of magic protection", 1);
  set_name("clasp");
  set_id(({
  "clasp of magic protection", "clasp",
  "oak clasp", "leaf clasp" }));
  set_short("%^RESET%^%^ORANGE%^an %^RESET%^oaken%^ORANGE%^ cloak clasp%^RESET%^");
  set_long(
@LURUE
    %^ORANGE%^This is a simple cloak clasp, carved from %^RESET%^white oak%^ORANGE%^, in the form of an %^GREEN%^acorn%^ORANGE%^. Three tiny carved leaves curl around the %^GREEN%^acorn%^ORANGE%^, cradling itp. The %^GREEN%^acorn%^ORANGE%^ and leaves can be detached from each other, and each can be fastened to one side of the cloak.
LURUE
);
  set_lore("Harvested from trees at the heart of the forest, these"
          +" acorns come from trees that are often thousands, if not hundreds of"
          +" thousands of years old.  Gathered by elven druids and rangers from these"
          +" pristine places, they are said to carry the very essence of nature's magic"
          +" within their core.  Set into clasps, rings, necklaces and other types of"
          +" jewelry by elven artisans, long trained in handling such precious gifts of"
          +" nature, the essence contained in the core of the acorns is said to transfer"
          +" to the wearer, offering them protection against the elements.");
  set_property("lore difficulty",17);
  set_type("ring");
  set_ac(0);
  set_weight(5);
  set("value", 25);
  set_limbs(({"right hand","left hand"}));
  set_wear((:TO,"do_wear":));
  set_remove((:TO,"takeoff":));
}

int do_wear()
{
        object *stuff, onering, env;
        int i,j, flag;

        if(environment(TO)->is_monster()) return 1;
        if (whose != ""){
          if ((string)ETO->query_true_name() != whose){
            tell_object(ETO, "This is not your clasp. As you try to fasten it, the two sides refuse to"
                           +" come together.");
            return 0;
          }
        }
        stuff = ETO->all_armour();
        j = sizeof(stuff);
        for(i=0;i<j;i++){
            if((string)stuff[i]->query_type() == "ring" &&
            stuff[i]->query_property("clasp of magic protection")) {
                onering = stuff[i];
                flag = 1;
                break;
            }
        }
        if(flag){

            write("You are already wearing a clasp.");
            return 0;
        }
        if(ETO->query_property("raised psionic")) {
          tell_object(ETO,"The magical spell protecting you conflicts with the magic in the clasp,"
                        +" and it forcefully repels your hand!");
          return 0;
        }
        protect = ETO;
        if (ETO->is_monster()==0){
          whose = (string)ETO->query_true_name();
        }
        protect->set_property("magic resistance",7);
        tell_object(ETO, "%^ORANGE%^As you fix the clasp in place, the three tiny leaves open and"
          +" unfurl, taking on the hues of %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^WHITE%^e"
          +"%^RESET%^r%^ORANGE%^, %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^ld%^RESET%^"
          +"%^ORANGE%^ and %^BOLD%^%^WHITE%^m%^RESET%^i%^BOLD%^%^WHITE%^thr%^RESET%^i%^BOLD%^"
          +"%^WHITE%^l%^RESET%^");
        tell_room(EETO, "%^ORANGE%^As " + (string)ETO->QCN + "%^RESET%^%^ORANGE%^ fixes " 
          + (string) ETO->QP +" acorn cloak clasp in place, the three tiny leaves surrounding the"
          +" %^GREEN%^acorn%^ORANGE%^ open and unfurl, taking on the hues of %^RESET%^s%^BOLD%^"
          +"%^WHITE%^i%^RESET%^lv%^BOLD%^%^WHITE%^e%^RESET%^r%^ORANGE%^, %^BOLD%^%^YELLOW%^g%^RESET%^"
          +"%^ORANGE%^o%^BOLD%^%^YELLOW%^ld%^RESET%^%^ORANGE%^ and %^BOLD%^%^WHITE%^m%^RESET%^i"
          +"%^BOLD%^%^WHITE%^thr%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^", ETO);
        TO->set_short("A %^BOLD%^%^WHITE%^sh%^YELLOW%^i%^BOLD%^%^WHITE%^mm%^RESET%^e%^BOLD%^"
          +"%^WHITE%^r%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ng %^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^c"
          +"%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^n %^BOLD%^%^YELLOW%^cl%^RESET%^"
          +"%^ORANGE%^o%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^k %^RESET%^cl%^BOLD%^%^WHITE%^a%^RESET%^"
          +"%^ORANGE%^s%^RESET%^p");
        TO->set_long("%^ORANGE%^%^A %^BOLD%^%^WHITE%^sh%^YELLOW%^i%^BOLD%^%^WHITE%^mm%^RESET%^e"
          +"%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ng %^BOLD%^%^YELLOW%^cl%^RESET%^"
          +"%^ORANGE%^o%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^k %^RESET%^cl%^BOLD%^%^WHITE%^a%^RESET%^"
          +"%^ORANGE%^s%^RESET%^p%^ORANGE%^%^, in the design of a delicate %^GREEN%^a%^BOLD%^"
          +"%^GREEN%^c%^RESET%^%^GREEN%^o%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^n%^ORANGE%^ set against a"
          +" background of three beautiful leaves, in the hues of%^RESET%^ s%^BOLD%^%^WHITE%^i"
          +"%^RESET%^lv%^BOLD%^%^WHITE%^e%^RESET%^r, %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
          +"%^YELLOW%^ld%^RESET%^%^ORANGE%^%^ and %^BOLD%^%^WHITE%^m%^RESET%^i%^BOLD%^%^WHITE%^thr"
          +"%^RESET%^i%^BOLD%^%^WHITE%^l%^RESET%^");
        return 1;
}


int takeoff()
{
        if(environment(TO)->is_monster()) return 1;
        protect->set_property("magic resistance",-7);
        tell_object(ETO, "%^ORANGE%^As you unfasten the clasp, the %^BOLD%^%^WHITE%^sh%^YELLOW%^i"
          +"%^BOLD%^%^WHITE%^mm%^RESET%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ng"
          +" %^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^a%^BOLD%^%^WHITE%^v%^RESET%^e"
          +"%^BOLD%^%^WHITE%^s %^RESET%^%^ORANGE%^slowly fade, and shrink back into their tiny carved"
          +" places around the carved oak %^GREEN%^acorn%^ORANGE%^.%^RESET%^");
        tell_room(EETO, "%^ORANGE%^As " + (string)ETO->QCN + "%^RESET%^%^ORANGE%^ unfastens " 
          + (string) ETO->QP +" cloak clasp, the %^BOLD%^%^WHITE%^sh%^YELLOW%^i%^BOLD%^%^WHITE%^mm"
          +"%^RESET%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ng %^BOLD%^%^YELLOW%^l"
          +"%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^a%^BOLD%^%^WHITE%^v%^RESET%^e%^BOLD%^%^WHITE%^s"
          +" %^RESET%^%^ORANGE%^slowly fade, and shrink back into their tiny carved places around the"
          +" carved oak %^GREEN%^acorn%^ORANGE%^.%^RESET%^", ETO);
  set_short("%^RESET%^%^ORANGE%^an %^RESET%^oaken%^ORANGE%^ cloak clasp%^RESET%^");
  set_long(
@LURUE
    %^ORANGE%^This is a simple cloak clasp, carved from %^RESET%^white oak%^ORANGE%^, in the form of an %^GREEN%^acorn%^ORANGE%^. Three tiny carved leaves curl around the %^GREEN%^acorn%^ORANGE%^, cradling itp. The %^GREEN%^acorn%^ORANGE%^ and leaves can be detached from each other, and each can be fastened to one side of the cloak.
LURUE
);
        protect = 0;
        return 1;
}


