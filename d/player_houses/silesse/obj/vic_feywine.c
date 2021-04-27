inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("wine");
   set_id(({"wine","glass of wine","feywine","ruby red wine","glass of feywine","drink"}));
   set_strength(75);
   set_weight(1);
   set_type("alcoholic");
   set_empty_name("glass");
   set_short("A glass of ruby red wine");
   set_destroy();
   set_long("A dark, ruby red wine that catches the available light "+
      "like a diamond.  It sparkles with an almost magical glistening.");
   set_my_mess("You drink the feywine and feel an almost magical, blissful peace wash over you as your skin starts to tingle all over.  The glass almost slips from your hands as you hear a faerie giggling in your ear.  You set the glass down, letting the wine take full effect.");
   set_your_mess("drinks the feywine and smiles while setting the glass back down, eyes fluttering closed for a long moment.");
}
