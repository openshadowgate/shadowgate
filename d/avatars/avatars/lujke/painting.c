#include <std.h>
inherit OBJECT;


void create(){
      set_name("painting");
      set_id(({"painting", "framed painting", "prop", "painting prop"}));
      set_short("%^BOLD%^%^WHITE%^a framed painting%^RESET%^");
      set_long("%^BOLD%^%^WHITE%^The following scene has a muxture of"
              +" calmness and determination. The artist has captured a"
              +" perfect example of a clear %^BOLD%^%^BLACK%^night sky"
              +"%^BOLD%^%^WHITE%^. The %^BOLD%^%^CYAN%^bright sliver"
              +"%^BOLD%^%^WHITE%^ of a crecent moon centers the sky with"
              +" just a few tendrils of cloud lingering around it. A"
              +" short distance away, among a clustering of stars is a"
              +" %^BOLD%^%^YELLOW%^satellite.\n%^BOLD%^%^WHITE%^It is a"
              +" beautiful scene in itself, however if one were to look"
              +" closer, it very much seems like the shimmery cloud"
              +" tendrils reach out towards the satellite, as if waiting"
              +" for it to brush across what very subtly looks like the"
              +" palm of a woman."
              +"\n\n%^BOLD%^%^CYAN%^The painting is signed at the bottom"
              +" with the outline of a %^BOLD%^%^MAGENTA%^pink butterfly"
              +" %^BOLD%^%^CYAN%^and the initials: %^BOLD%^%^GREEN%^A.K."
              +"%^RESET%^"); 
    	set_weight(5);
   	set_value(100);
}
