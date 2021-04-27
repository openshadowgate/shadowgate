#include <std.h>
inherit "/d/common/obj/weapon/morningstar";

int charges;
void set_my_long();

void create(){
    ::create();
    set_name("scepter");
    set_id(({ "scepter", "adamantium scepter", "jeweled scepter", "scepter of the locust" }));
    set_short("%^BOLD%^%^WHITE%^Sc%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^pt%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r of the L%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^cu%^RESET%^%^GREEN%^s%^BOLD%^%^WHITE%^t%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A %^MAGENTA%^j%^GREEN%^e%^MAGENTA%^w%^BLACK%^e%^GREEN%^l%^MAGENTA%^e%^BLACK%^d %^WHITE%^adamantium scepter%^RESET%^");
    set_long("It's a scepter, yay.");
    set("read","%^BOLD%^%^BLACK%^Summon the Locust %^RESET%^and he shall "
"consume your enemies.");
    set("langage","drow");
    set_value(2000);
    set_lore("Very little is known of this item. Though looking closely "
"one can see that the gems used in its creation are very different then "
"anything found on the surface.  In fact, the very architecture of the "
"scepter makes it seem drowish in nature.  Studying the glyphs also "
"suggests this further as the language appears to be a variation of the "
"drow language.  Why they would create such a thing though, is a "
"mystery.");
    set_property("lore difficulty",22);
    set_property("enchantment",2);
    set_hit((:TO,"hit_func":));
    charges = 15;
    set_my_long();
}

int hit_func(object targ){
    if(!objectp(targ)) return 0;
    if(!objectp(ETO)) return 0;
    if(random(1000) < 150) {
      tell_room(EETO,"%^BOLD%^%^GREEN%^The wings of "+ETOQCN+"'s "
"scepter's head piece unfurl revealing razor sharp edges that slice "
"through "+targ->QCN+" skin!%^RESET%^",({ETO,targ}));
      tell_object(ETO,"%^BOLD%^%^GREEN%^The wings of the scepter's head "
"piece unfurl revealing razor sharp edges that slice through "+targ->QCN+
" skin!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^GREEN%^The wings of "+ETOQCN+"'s "
"scepter's head piece unfurl revealing razor sharp edges that slice "
"through your skin!%^RESET%^");
      return roll_dice(2,4)+0;
    }
}

void init() {
    ::init();
    add_action("summon_me","summon");
}

void summon_me(string str){
   int i, j;
   object ob;
   j = random(4)+5;
   if(!objectp(ETO)) return 0;
   if(!str || str != "the locust") {             
     tell_object(TP,"What are you trying to summon?");
     return 1;
   }
   if(!TO->query_wielded()){ 
     tell_object(TP,"You must be holding the scepter to use it.");
     return 1;
   }
   if(!charges) {
     tell_object(TP,"There are no gems left to break!");
     return 1;
   }
   if (present("summoned locust",ETP)) {
     tell_object(TP,"You can't summon multiple sets of locusts.");
     return 1;
   }
   charges--;
   set_my_long();
   new("/d/avatars/nienne/amulet/_summon_locusts")->use_spell(TP,0,20);
   return 1;
}

void reset_me() {
   charges = 15;
}

void set_my_long() {
    set_long("%^BOLD%^%^WHITE%^This strange and bizzare item appears to "
"be some sort of scepter.  Made from %^BLACK%^silvery adamantium "
"%^WHITE%^it is about four feet long and wrapped in the center with thick "
"cords of %^BLACK%^black leather %^WHITE%^to give it a solid, secure "
"grip.  The head of the shaft has been formed into the shape of a large "
"jeweled scepter.  The carapace of the creature is made out of a type of "
"%^GREEN%^dark green%^WHITE%^, almost black stone, while the legs, eyes, "
"mandibles and extended wings are crafted from shards of a %^MAGENTA%^"
"dark purple %^WHITE%^gem.  Oddly neither stone seems to sparkle or "
"reflect the light but rather gives off a dark aura that makes them look "
"%^BLACK%^dim %^WHITE%^and %^BLACK%^lusterless%^WHITE%^. The base of the scepter "
"is likewise bejeweled.  The large round knob is set with several circles "
"of small round pieces of alternating gemstones, "+charges+" pairs in all "
"each of a purple and a green gem.  Etched between these rings of gems "
"are some %^BLACK%^glyphs %^WHITE%^that might be read.%^RESET%^");
}
