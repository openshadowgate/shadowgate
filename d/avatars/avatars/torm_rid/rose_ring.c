// recrafted ring of protection

#include <std.h>
inherit ARMOUR;

create() {
	::create();
  	set_name("ring");
   set_id(({"ring of protection", "ring", "protection","ruby ring",
   	"band","ruby band","rose ring"}));
   set_obvious_short("a %^BOLD%^%^RED%^ruby ring%^RESET%^");
   set_short("a %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by "+
   	"%^CYAN%^ring %^GREEN%^of "+
		"%^YELLOW%^pr%^WHITE%^o%^YELLOW%^tec%^WHITE%^tio%^YELLOW%^n%^RESET%^");
   set_long("%^CYAN%^This ring is made from a %^RED%^large ruby "+
   	"%^CYAN%^that was carefully cut and shaped into a band with "+
   	"intricate carvings and %^YELLOW%^gold inlay%^RESET%^%^CYAN%^.  The "+
   	"carvings are delicate and appear to be %^ORANGE%^ancient %^CYAN%^and "+
   	"%^BOLD%^%^MAGENTA%^elven%^RESET%^%^CYAN%^.  The %^YELLOW%^gold inlay "+
   	"%^RESET%^%^CYAN%^accentuates the carvings by echoing each bend and "+
   	"curve of each %^MAGENTA%^elven glyph%^CYAN%^.  On the top of the "+
   	"band are two detailed and beautiful carvings.  In the center is "+
   	"a %^BOLD%^%^RED%^rose %^RESET%^%^CYAN%^in %^BOLD%^%^GREEN%^full "+
   	"bloom %^RESET%^%^CYAN%^and reclining, next to the "+
   	"%^BOLD%^%^RED%^rose%^RESET%^%^CYAN%^, is a "+
   	"%^YELLOW%^l%^RESET%^%^ORANGE%^ar%^YELLOW%^ge "+
   	"%^RESET%^%^ORANGE%^l%^YELLOW%^io%^RESET%^%^ORANGE%^n "+
   	"%^CYAN%^with his paws placed protectively about the "+
   	"%^BOLD%^%^RED%^rose%^RESET%^%^CYAN%^.  The %^BOLD%^%^RED%^rose carving "+
   	"%^RESET%^%^CYAN%^is offset with %^RED%^ruby dust %^CYAN%^filling "+
   	"the carved lines and the lion is highlighted with %^YELLOW%^gold "+
   	"%^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^white gold "+
   	"%^YELLOW%^i%^WHITE%^nl%^YELLOW%^a%^WHITE%^y%^RESET%^%^CYAN%^.  "+
   	"There is an inscription on the inner side of the ring.%^RESET%^");
   set_lore("This ring was commisioned by a ranger to be given as a "+
    	"token of love to his lady.  The ranger searched far and wide for "+
    	"the components of the ring and a sufficently skilled crafts person "+
    	"to combine them into this wondrous item.  Once found the singular "+
    	"ring was fabricated surpassing even the skill of the artisan.  The "+
    	"lion was the ranger's totem and the rose represents the lady.");
	set_type("ring");
	set("read","\n\n     %^BOLD%^%^RED%^@%^RESET%^%^GREEN%^-} %^BOLD%^Trust "+
		"in %^MAGENTA%^yourself %^RESET%^%^GREEN%^ {-%^BOLD%^%^RED%^@\n"+
		"     @%^RESET%^%^GREEN%^-} %^BOLD%^for the %^CYAN%^power "+
		"%^GREEN%^lies %^RESET%^%^GREEN%^{-%^BOLD%^%^RED%^@\n"+
		"     @%^RESET%^%^GREEN%^-} %^BOLD%^%^YELLOW%^within."+
		"            %^RESET%^%^GREEN%^{-%^BOLD%^%^RED%^@%^RESET%^\n");
   set("language","elven");   
   set_ac(0);
   set_weight(1);
   set_value(4500);
   set_limbs(({"right hand","left hand"}));
   set_property("enchantment",4);
   set_wear((:TO,"do_wear":));
	set_remove((:TO,"remove_func":));
}

int do_wear() {
  	object *stuff;
   int i,j, flag;

   stuff = TP->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++) {
   	if(!objectp(stuff[i])) continue;
      if((string)stuff[i]->query_type() == "ring") {
      	if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         	flag = 1;
            break;
        	}
     	}
 	}
   if(flag) {
   	write("%^BOLD%^The magic of the ring already worn prevents you from wearing this one!");
      return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->query_cap_name()+"'s "+
		"places the %^RED%^ruby ring %^MAGENTA%^on "+ETO->query_possessive()+" "+
		"finger and smiles briefly!%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^You slide the %^RED%^ruby ring "+
		"%^MAGENTA%^on your finger and catch a brief, but pleasant, "+
		"scent of %^RESET%^%^GREEN%^forest %^BOLD%^%^CYAN%^air%^MAGENTA%^.%^RESET%^");
   return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETO->query_cap_name()+" removes "+
		"the %^BOLD%^%^RED%^ruby ring %^RESET%^%^MAGENTA%^with a small "+
		"%^CYAN%^sigh%^MAGENTA%^.%^RESET%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You remove the %^BOLD%^%^RED%^ruby "+
		"ring %^RESET%^%^MAGENTA%^and feel a measure of "+
		"%^BOLD%^%^WHITE%^protection %^RESET%^%^MAGENTA%^leave you.%^RESET%^");
	return 1;
}

