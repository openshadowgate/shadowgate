#include <std.h>
inherit "/d/common/obj/misc/chest";

void create(){
	::create();
	set_name("ancient tomb");
	set_id(({ "tomb", "sarcophagus" }));
	set_short("%^YELLOW%^An ornate sarcophogus%^RESET%^");
	set_obvious_short("%^YELLOW%^An ornate sarcophagus%^RESET%^");
	set_long("%^YELLOW%^The sarcophagus is tall, almost four feet from the floor and six feet long.  You suspect that it is made from a dense hardwood, but it has been finished in fine gold plating.  %^RED%^C%^YELLOW%^ol%^GREEN%^or%^BLUE%^ful %^YELLOW%^images have been painted on every square inch of the coffin, depicting images of ancient Tsarven origin.  The lid is still fixed in place.%^RESET%^");
      set_open_long("%^YELLOW%^The sarcophagus is tall, almost four feet from the floor and six feet long.  You suspect that it is made from a dense hardwood, but it has been finished in fine gold plating.  %^RED%^C%^YELLOW%^ol%^GREEN%^or%^BLUE%^ful %^YELLOW%^images have been painted on every square inch of the coffin, depicting images of ancient Tsarven origin.  The lid is still fixed in place.%^RESET%^\n\n%^BOLD%^%^WHITE%^It is currently open.%^RESET%^");
      set_closed_long("%^YELLOW%^The sarcophagus is tall, almost four feet from the floor and six feet long.  You suspect that it is made from a dense hardwood, but it has been finished in fine gold plating.  %^RED%^C%^YELLOW%^ol%^GREEN%^or%^BLUE%^ful %^YELLOW%^images have been painted on every square inch of the coffin, depicting images of ancient Tsarven origin.  The lid is still fixed in place.%^RESET%^\n\n%^BOLD%^%^WHITE%^It is currently closed.%^RESET%^");
	set("read","%^RED%^You cannot decipher the symbols and letters%^RESET%^");
      set("langage","common");
	set_weight(5);
	set_value(0);
      set_max_internal_encumbrance(120);
      toggle_lock();
}

void init() {
   ::init();
   add_action("setweight_fun","setweight");
   add_action("setdescs_fun","setdescs");
}

int setweight_fun(string mystring) {
   if(!mystring) return 0;
   switch(mystring) {
     case "heavy": TO->set_weight(999); break;
     case "light": TO->set_weight(5); break;
     default: return 0;
   }
   return 1;
}

int setdescs_fun(string mystring) {
   string mydesc, myflag;
   if(!mystring) return 0;
   if(sscanf(mystring,"%s %s", myflag, mydesc) != 2) return 0;
   if(myflag == "open") {
     set_open_long(mydesc);
     return 1;
   }
   if(myflag == "closed") {
     set_closed_long(mydesc);
     return 1;
   }
   return 0;
}