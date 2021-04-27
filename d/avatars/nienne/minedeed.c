#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("deed");
   set_id(({"mine deed","deed","parchment"}));
   set_short("%^RESET%^%^ORANGE%^a rolled parchment with a %^RED%^red seal%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^This parchment is touched with a few spots of%^RESET%^%^ORANGE%^ "
"grime%^BLACK%^%^BOLD%^, but is otherwise fairly official-looking.  It resembles a deed for ownership, "
"probably for land in some location.  A seal has been stamped upon it in %^RESET%^%^RED%^dark red "
"wax%^BLACK%^%^BOLD%^, of a %^RESET%^%^ORANGE%^foaming mug of ale%^BLACK%^%^BOLD%^ crossed by a "
"%^RESET%^%^WHITE%^sturdy pick%^BLACK%^%^BOLD%^.  You could probably %^YELLOW%^<unroll>%^BLACK%^ it to read "
"the deed.%^RESET%^\n");
   set_value(0);
   set_weight(0);
}

void init() {
   ::init();
   add_action("roll_fun","unroll");
}

int roll_fun(string str) {
   if(!str) {
     tell_object(TP,"What do you want to unroll?");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1) {
     tell_object(TP,"You can't unroll that.");
     return 0;
   }
   tell_room(ETP,"%^WHITE%^%^BOLD%^"+TP->QCN+" unrolls the parchment and reads over the deed.%^RESET%^",TP);
   tell_object(TP,"%^WHITE%^%^BOLD%^You unroll the parchment.  It reads as follows:\n\n%^RESET%^"
"%^ORANGE%^We do hereby be selling section thirteen of our mine to the dwarf that be known as Nalthic Stoneaxe,"
" to expand as he be seeing fit to do.  The section be part of the mine within the defines of Kinaro region, "
"in the north-north-east region, and be under title to the name of Rockfist.  This be current and settled on "
"11 Winterstime, 667 SG.\n\n%^RESET%^"
"%^BLACK%^%^BOLD%^There are two scratchy signatures at the bottom of the page, that you can just make out as "
"the names %^RESET%^%^ORANGE%^Tolnak%^BLACK%^%^BOLD%^ and %^RESET%^%^ORANGE%^Khaz Rockfist.\n%^RESET%^");
   return 1;
}
