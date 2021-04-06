#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("an invitation for Rosinden");
   set_short("A sheet of parchment with neat handwriting");
   set_id(({"paper","sheet of parchment","parchment", "invitation", "note"}));
   set_long(
      "This is piece of fine parchment with neat handwriting. It's from "+
      "Cynthia in Tabor to Rosinden near the Ekibi Caverns."
   );
   set("read",
      "\n%^BOLD%^%^CYAN%^Dearest Rosinden\n\n"+
      "I hope this letter finds you well. How long has it been since last we "+
      "met? A year? Ten? Time passes so quickly, I cannot tell anymore.\n\n"+
      "It would be a great pleasure if you would visit me in Tabor and "+
      "join me for a cup of tea. I can order some blueberry muffins from "+
      "Shadow. I would so love to show you my latest knitting project "+
      "and tell you about all the new adventurers who have visited me!\n\n"
      "Yours very affectionately,\n"+
      "Cynthia%^RESET%^"
   );
   set_weight(1);
   set_value(0);
}