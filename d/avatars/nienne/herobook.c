#include <std.h>
inherit OBJECT;

int isused;

void create() {
   set_name("dusty tome");
   set_id(({ "tome","tattered tome","dusty tome","dusty and tattered tome" }));
   set_short("%^RESET%^%^ORANGE%^dusty and tattered tome%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This tome seems terribly old and %^CYAN%^fragile%^ORANGE%^.  Dust sheds from its pages "
"with any movement, along with the crumbling fragments of those same torn and rotted leaves of %^RESET%^parchment"
"%^ORANGE%^.  Entire sections are missing in some spots, while most of the pages between are too damaged, faded or torn "
"to read.  The only ones you can find that are still whole and undamaged are near the back of the book.  A header at the "
"top of the page reads %^RESET%^'Heroism'%^ORANGE%^, while the spidery writing beneath it gleams with hints of the "
"%^BOLD%^%^CYAN%^ar%^RESET%^%^CYAN%^ca%^BOLD%^ne%^RESET%^%^ORANGE%^.  An inkling strikes you, that perhaps you could "
"%^YELLOW%^learn heroism%^RESET%^%^ORANGE%^ from its pages...%^RESET%^");
   set_value(15003);
   set_weight(5);
   isused = 0;
}

void init() {
   ::init();
   add_action("use_fun","learn");
}

int use_fun(string str) {
   if(!str) return 0;
   if(str != "heroism") return 0;
   if(isused) {
     tell_object(TP,"The remaining pages are useless, it seems.  There is nothing to learn from them.");
     return 1;
   }
   if((string)TP->query_name() != "drille") {
     tell_object(TP,"You can't make enough sense of the script to learn that spell.");
     return 1;
   }
   tell_object(TP,"%^ORANGE%^You carefully scan your eyes once, twice, three times over the text upon the pages, "
"murmuring the words softly as you do.  Just as you're definitely sure you'll be able to remember them without a mistake, "
"they shimmer and fade, leaving the pages completely blank.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TP->QCN+" carefully scans "+TP->QP+" eyes once, twice, three times over the text upon the "
"pages, murmuring softly.  Just as "+TP->QS+" finishes, the letters shimmer and fade, leaving the pages completely "
"blank.%^RESET%^",TP);
   TP->add_mastered_spell("heroism");
   TO->set_value(10);
   TO->set_long("%^RESET%^%^ORANGE%^This tome seems terribly old and %^CYAN%^fragile%^ORANGE%^.  Dust sheds from its "
"pages with any movement, along with the crumbling fragments of those same torn and rotted leaves of %^RESET%^parchment"
"%^ORANGE%^.  Entire sections are missing in some spots, while most of the pages between are too damaged, faded or torn "
"to read.  The only ones you can find that are still whole and undamaged are near the back of the book, and they are all "
"completely %^RESET%^blank%^ORANGE%^.%^RESET%^");
   isused = 1;
   return 1;
}