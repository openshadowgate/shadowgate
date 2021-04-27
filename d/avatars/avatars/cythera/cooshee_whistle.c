#include <std.h>
#include <daemons.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("wooden whistle");
    set_id(({"whistle","wooden whistle","wood whistle"}));
    set_obvious_short("%^RESET%^%^ORANGE%^A carved wooden whistle%^RESET%^");
    set_short("%^RESET%^%^GREEN%^Whistle of the Cooshee%^RESET%^");
    set_long("%^RESET%^%^GREEN%^Carved out of %^ORANGE%^oak%^GREEN%^, "+
		"this wooden whistle is fashioned into the silhouette of a"+
		" %^BOLD%^cooshee%^RESET%^%^GREEN%^, or an elven dog.   The"+
		" wood has been shaped to a smooth finish, though the %^YELLOW%^"+
		"g%^RESET%^%^ORANGE%^ra%^YELLOW%^i%^RESET%^%^ORANGE%^n%^GREEN%^ is"+
		" clearly visible.  Green accents have been painted onto the wood,"+
		" in a traditional elven style.  The wooden whistle is strung on a "+
		"silken cord, allowing it to be kept close by.%^RESET%^\n");
    set_weight(1);
    set_size(2);
    set_value(0);
    set_type("ring");
    set_limbs(({"neck"}));
    set_wear((:TO,"wearme":));
}

int wearme(){
        tell_object(ETO,"%^GREEN%^You slip the whistle over your neck, keeping it close by.");
        tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" slips a whistle on a"+
		" cord around "+ETO->QP+" neck.",ETO);
        TO->set_overallStatus(100);
        return 1;
}

void init() {
    ::init();
    add_action("summon_em","summon");
}

int summon_em(string str) {
    object ob;
    if(!str) {
      notify_fail("Summon what?");
      return 0;
    }
    if(str != "cooshee") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(!TO->query_worn()) {
      tell_object(TP,"You should try wearing the whistle first.");
      return 1;
    }
    if((string)TP->query_name() != "phade") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(present("cooshee")) {
      tell_object(TP,"That is already here!");
      return 1;
    }
    tell_object(ETO,"%^GREEN%^You bring the whistle to your lips and blow, releasing a high pitched call.");
    tell_room(EETO,"%^GREEN%^"+ETO->QCN+" brings a whistle to "+ETO->QP+" lips, releasing a high pitched call.",ETO);
    ob=find_object_or_load("/d/avatars/cythera/cooshee");
    ob->move(EETO);
    return 1;
}