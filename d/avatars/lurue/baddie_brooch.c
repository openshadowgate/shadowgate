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
  set_name("brooch");
  set_id(({
  "brooch of tonovi", "brooch",
  "tonovi brooch", "bane brooch" }));
  set_short("%^RESET%^sty%^BOLD%^%^WHITE%^l%^RESET%^ised"
            +" i%^BOLD%^%^GREEN%^r%^RESET%^on whe%^BOLD%^%^GREEN%^e%^RESET%^l br%^BOLD%^%^WHITE%^o"
            +"%^RESET%^och");
  set_long(
@LURUE
    A brooch in the form of a stylised iron wheel. The outer edge of the brooch symbolises the rim of the wheel, and a series of spokes lead into a 'hub' at the centre, on which a small pair of slave bracelets can be made out. There is a faint %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^een tin%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e%^RESET%^ around the hub of the wheel. The brooch has a pin at the back, allowing it to be fastened to most pieces of clothing.
LURUE
);
  set_lore("These brooches began to appear after"
          +" the Tonovi Civil War.  The wheel and slave bracelets had been one of the"
          +" popular symbols of Tonovi prior to the war, a symbol of status for those"
          +" who owned slaves.  Since the war, a few of these brooches began to turn up"
          +" with a slight green tinge and when worn by those who were blessed in the"
          +" war by Bane, the brooch is said to transform and display to all who view it"
          +" the true power of the city's leadership.");
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
            tell_object(ETO, "This is not your brooch. As you try to fasten it, the pin refuses to"
                        +" fasten into the clothing.");
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
          tell_object(ETO,"The magical spell protecting you conflicts with the magic in the brooch,"
                        +" and it forcefully repels your hand!");
          return 0;
        }
        protect = ETO;
        if (ETO->is_monster()==0){
          whose = (string)ETO->query_true_name();
        }
        protect->set_property("magic resistance",7);
        tell_object(ETO, "As you fix the brooch in place, the %^BOLD%^%^GREEN%^g%^RESET%^"
                        +"%^GREEN%^r%^BOLD%^%^GREEN%^een tin%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e"
                        +"%^RESET%^ around the hub of the wheel %^BOLD%^%^GREEN%^in%^BOLD%^%^WHITE%^t"
                        +"%^GREEN%^ensif%^BOLD%^%^WHITE%^i%^GREEN%^es%^RESET%^, sending out spikes of"
                        +" %^BOLD%^%^GREEN%^green light%^RESET%^. When it clears, the %^BOLD%^"
                        +"%^BLACK%^rim%^RESET%^ and %^BOLD%^%^BLACK%^spokes%^RESET%^ of the wheel"
                        +" motif have turned %^BOLD%^%^BLACK%^black%^RESET%^, and a"
                        +" %^BOLD%^%^GREEN%^green armored fist%^RESET%^ grips the slave bracelets in"
                        +" the centre of the wheel");
        tell_room(EETO, "As " + (string)ETO->QCN + "%^RESET%^%^ORANGE%^ fixes " 
          + (string) ETO->QP +" brooch in place, the %^BOLD%^%^GREEN%^g%^RESET%^"
                        +"%^GREEN%^r%^BOLD%^%^GREEN%^een tin%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e"
                        +"%^RESET%^ around the hub of the wheel %^BOLD%^%^GREEN%^in%^BOLD%^%^WHITE%^t"
                        +"%^GREEN%^ensif%^BOLD%^%^WHITE%^i%^GREEN%^es%^RESET%^, sending out spikes of"
                        +" %^BOLD%^%^GREEN%^green light%^RESET%^. When it clears, the %^BOLD%^"
                        +"%^BLACK%^rim%^RESET%^ and %^BOLD%^%^BLACK%^spokes%^RESET%^ of the wheel"
                        +" motif have turned %^BOLD%^%^BLACK%^black%^RESET%^, and a"
                        +" %^BOLD%^%^GREEN%^green armored fist%^RESET%^ grips the slave bracelets in"
                        +" the centre of the wheel", ETO);
        TO->set_short("%^BOLD%^%^BLACK%^black brooch displaying a %^BOLD%^%^GREEN%^green armored"
                     +" f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^st");
        TO->set_long("%^BOLD%^%^BLACK%^A black iron brooch in the form of a %^BOLD%^%^BLACK%^s"
                    +"%^RESET%^p%^BOLD%^%^BLACK%^o%^RESET%^k%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^"
                    +"%^BLACK%^w%^RESET%^h%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^%^BLACK%^l, displaying a"
                    +" %^BOLD%^%^GREEN%^green armored f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^st%^BOLD%^"
                    +"%^BLACK%^ in the center, gripping tightly onto a grim set of"
                    +" %^RESET%^slave bracelets%^BOLD%^%^BLACK%^.");
        return 1;
}


int takeoff()
{
        if(environment(TO)->is_monster()) return 1;
        protect->set_property("magic resistance",-7);
        tell_object(ETO, "As you unfasten the %^BOLD%^%^BLACK%^brooch%^RESET%^, the"
                        +" %^BOLD%^%^GREEN%^green armored f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^st"
                        +"%^RESET%^ at the center of the %^BOLD%^%^BLACK%^w%^RESET%^h"
                        +"%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^m%^BOLD%^%^BLACK%^o"
                        +"%^RESET%^t%^BOLD%^%^BLACK%^i%^RESET%^f glows with %^BOLD%^%^GREEN%^f%^BOLD%^"
                        +"%^WHITE%^i%^BOLD%^%^GREEN%^erce br%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^ghtness"
                        +"%^RESET%^. The light fades as the brooch comes free. When it does, the color"
                        +" of the brooch has reverted to a dull metallic grey and all that remains of"
                        +" the %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^st%^RESET%^ is a"
                        +" faint %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^een"
                        +" tin%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e%^RESET%^ around the hub of the"
                        +" wheel.");
        tell_room(EETO, "As " + (string)ETO->QCN + "%^RESET%^%^ORANGE%^ unfastens " 
          + (string) ETO->QP +" %^BOLD%^%^BLACK%^brooch%^RESET%^, the"
                        +" %^BOLD%^%^GREEN%^green armored f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^st"
                        +"%^RESET%^ at the center of the %^BOLD%^%^BLACK%^w%^RESET%^h"
                        +"%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^%^BLACK%^l %^RESET%^m%^BOLD%^%^BLACK%^o"
                        +"%^RESET%^t%^BOLD%^%^BLACK%^i%^RESET%^f glows with %^BOLD%^%^GREEN%^f%^BOLD%^"
                        +"%^WHITE%^i%^BOLD%^%^GREEN%^erce br%^BOLD%^%^WHITE%^i%^BOLD%^%^GREEN%^ghtness"
                        +"%^RESET%^. The light fades as the brooch comes free. When it does, the color"
                        +" of the brooch has reverted to a dull metallic grey and all that remains of"
                        +" the %^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^st%^RESET%^ is a"
                        +" faint %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^een"
                        +" tin%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e%^RESET%^ around the hub of the"
                        +" wheel.", ETO);
  set_short("%^RESET%^sty%^BOLD%^%^WHITE%^l%^RESET%^ised"
            +" i%^BOLD%^%^GREEN%^r%^RESET%^on whe%^BOLD%^%^GREEN%^e%^RESET%^l br%^BOLD%^%^WHITE%^o"
            +"%^RESET%^och");
  set_long(
@LURUE
    A brooch in the form of a stylised iron wheel. The outer edge of the brooch symbolises the rim of the wheel, and a series of spokes lead into a 'hub' at the centre, on which a small pair of slave bracelets can be made out. There is a faint %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^een tin%^RESET%^%^GREEN%^g%^BOLD%^%^GREEN%^e%^RESET%^ around the hub of the wheel. The brooch has a pin at the back, allowing it to be fastened to most pieces of clothing.
LURUE
);
        protect = 0;
        return 1;
}


