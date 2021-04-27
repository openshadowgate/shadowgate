#include <std.h>
#include "../defs.h"
inherit OBJECT;

void create(){
        ::create();
        set_name("cello");
        set_id(({ "cello","polished cello","instrument" }));
        set_short("%^RESET%^%^ORANGE%^p%^RED%^o%^ORANGE%^lis%^RED%^he%^ORANGE%^d c%^RED%^el%^ORANGE%^lo%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^This fine stringed instrument is of considerable size and weight, more than would be reasonable to carry around on a daily basis.  It appears to be shaped "
"from b%^RED%^i%^ORANGE%^rchw%^RED%^o%^ORANGE%^od that has been polished to a rich finish, though a %^RED%^war%^MAGENTA%^me%^RED%^r %^ORANGE%^shade to the underside suggests a different timber, "
"perhaps to contribute to the tone of the instrument.  The body of the instrument is broad at both ends, drawn to a narrowed middle by two c-bouts, and is encircled by a decorative inlay of "
"purfling.  Four %^RESET%^strings %^ORANGE%^have been stretched from the %^BOLD%^%^BLACK%^e%^RESET%^b%^BOLD%^%^BLACK%^ony %^RESET%^%^ORANGE%^tailpiece, running up past the twin f-holes and over "
"the fingerboard.  Each is finally secured to a single %^BOLD%^%^BLACK%^ebon %^RESET%^%^ORANGE%^peg upon the scroll at the end of the instrument's narrow neck.  From the cello's broad base juts "
"a short endpin, giving a means to rest the instrument upon the floor when played without influencing its sound.  You could %^RESET%^replace cello%^ORANGE%^ when you're done, to put it back on "
"its stand.%^RESET%^");
        set_lore("%^BOLD%^%^WHITE%^The cello is not a commonly seen instrument, given far greater ease in transporting smaller instruments from place to place; smaller strings such as the lute, "
"lyre, and fiddle are more often favored.  Still, some are found particularly within the castles and courts of the most wealthy, for those that can afford to keep their own entertainers in "
"residence.  From all instruments, the cello is said to be the closest in tone to the male voice, and while still retaining a beautiful sound on its own, it is most often heard as part of an "
"ensemble, serving as a bass counterpoint to other stringed instruments.%^RESET%^");
        set_property("lore difficulty",15);
        set_weight(5);
        set_value(0);
        set_heart_beat(1);
}

void init() {
   ::init();
   add_action("replace_cello","replace");
}

int is_instrument() { return 1; }
int save_me(string file) { return 1; }

void remove_me() {
   object theroom;
   if(userp(ETO)) tell_object(ETO,"%^BOLD%^%^CYAN%^You realise just how heavy that cello was. Good thing you left it back in the tree.%^RESET%^");
   theroom = find_object_or_load(ROOMS"tree");
   theroom->reset_cello();
   TO->remove();
}

void heart_beat() {
   object environ;
   string myloc;
   if(!objectp(ETO)) { remove_me(); return; }
   if(userp(ETO)) {
     if(!objectp(EETO)) { remove_me(); return; }
     environ = EETO;
   }
   else environ = ETO;
   myloc = base_name(environ);
   if(myloc != ROOMS"tree" && myloc != ROOMS"bedroom" && myloc != ROOMS"workroom") { remove_me(); return; }
}

int replace_cello(string str) {
   if(!str) return 0;
   if(str != "cello") return 0;
   if(base_name(ETP) != ROOMS"tree") {
     tell_object(TP,"You realise this isn't where the cello is kept.");
     return 1;
   }
   tell_room(ETP,""+TP->QCN+" carefully sets the cello back on its stand.",TP);
   tell_object(TP,"You carefully set the cello back on its stand.");
   ETP->reset_cello();
   TO->remove();
   return 1;
}