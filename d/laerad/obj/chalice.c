//Coded by Bane//
//New desc, lore, added color to message and clarified the syntax 3/27/05 - Cythera
#include <std.h>
#include <daemons.h>
inherit OBJECT;
int flag;
int uses;
int count;
void create(){
	::create();
   	set_id(({"chalice","cup","chalice of purity","white gold chalice"}));
    	set_name("chalice of purity");
	set_short("%^BOLD%^%^WHITE%^Chalice of "+
		"%^GREEN%^P%^WHITE%^u%^CYAN%^r%^GREEN%^i%^WHITE%^t"
		"%^CYAN%^y%^RESET%^");
    	set_obvious_short("%^BOLD%^%^WHITE%^A white gold chalice%^RESET%^");
    	set_long("%^BOLD%^%^WHITE%^Crafted from white gold, "+
		"this small chalice features detailed carvings around"+
		" its surface.  The carvings take shape of a graceful "+
		"unicorn standing in the middle of a tranquil %^GREEN%^"+
		"forest scene%^WHITE%^.  The lush forest around the "+
		"unicorn is highly detailed, from the texture of the"+
		" bark to the shape of the leaves.  The unicorn's long"+
		" flowing main has been depicted as floating in the "+
		"air.  With her head bent low, the unicorn is touching"+
		" the surface of a %^CYAN%^still pool%^WHITE%^ of water"+
		" with her %^YELLOW%^h%^WHITE%^o%^YELLOW%^r%^WHITE%^n."+
		"  The stem of the chalice tapers in before coming to "+
		"rest on a round base. Inlaid in the base of this chalice"+
		" are square cut %^GREEN%^emeralds%^WHITE%^, teardrop "+
		"shaped %^CYAN%^aquamarines%^WHITE%^, and triangles of"+
		" iv%^YELLOW%^o%^WHITE%^ry. The ripples of the pool "+
		"seem to spell out something.");
	set_lore("First created by the faiths of Eldath and Mielikki,"+
		" the Chalice of Purity symbolized the main themes of both"+
		" goddesses.  The unicorn is used to symbolize purity and"+
		" cleansing, while the still pool is an icon of Eldath's"+
		" tranquility.  With merging of Eldath into Istishia, the"+
		" faith of Istishia has continued to create these chalices"+
		" with the priests of Mielikki.");
	set_property("lore difficulty",9);
	set_read("%^BOLD%^%^CYAN%^\nTo feel the blessings of purity "+
		"simply %^GREEN%^measure liquid%^CYAN%^.\nAnd %^GREEN%^drink"+
		" liquid%^CYAN%^ from this chalice.");
	set_language("common");
	set_weight(7);
//	set_weight(10);
//   	set_value(1000);
	set_value(1800);
    set_heart_beat(1);
}

int query_value() {if (uses != 0) return 0; else return 1500; }
void init(){
    ::init();
    add_action("drink_me","drink");
    add_action("measure_me","measure");
}
int drink_me(string str){
    if(!str) return notify_fail("Drink what?\n");
    if("liquid" != str) return 0;
   if(uses > 8) {
	write("%^BOLD%^The chalice's power has disappeared forever.");
	return 1;
    }
    if(flag == 0){
	tell_object(TP,"%^BOLD%^%^CYAN%^You drink the liquid from the chalice.");
	tell_room(ETO,"%^BOLD%^%^CYAN%^"+TP->QCN+" drinks the liquid from the"+
		" white gold chalice.",TP);
	call_out("heal_me",5,TP);
	uses += 1;
	flag = 1;
	return 1;
    }
    write("%^GREEN%^There isn't enough liquid left in the chalice to drink yet.");
   return 1;
}
int measure_me(string str){
    if(!str) return notify_fail("Measure what?\n");
    if("liquid" != str) return 0;
   if(uses > 8) {
        write("%^BOLD%^The chalice's power has disappeared forever.");
        return 1;
    }
    if(flag == 0){
	write("%^BOLD%^%^CYAN%^The stones on the cup start to"+
		" glow as the chalice fills with crystal clear water.");
	return 1;
    }
    write("%^BOLD%^%^GREEN%^The cup is still replenishing itself.");
    return 1;
}
int heal_me(object targ) {
    write("%^BOLD%^%^CYAN%^You feel your wounds heal and the impurities"+
		" from your body disappear.");
    targ->add_hp(targ->query_max_hp()/2);
    targ->add_poisoning(-100);
    POISON_D->clear_poisons_by_dc(targ, 50, 0);
    return 1;
}
void heart_beat(){
   if(uses <= 8) {
        if(count > 2){
	    flag = 0;
            count = 0;
//      set_value(0);
	}
    }
    else set_heart_beat(0);
    count++;
}
int isMagic(){
 	int x;
 	x = ::isMagic();
 	x = x+1;
 	return x;
}
