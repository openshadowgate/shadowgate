#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("deceased thief");
   set_id(({"thief","body","deceased thief","dead_thief","deceased human","human corpse","dessicated corpse","corpse"}));
   set_short("a dessicated corpse");
   set_long("%^RESET%^%^ORANGE%^Before you lays a crumpled human body, its worn "
      "leather armor blackened as is customary of the thieves of Tharis. "
      "His body is a dry husk drawn taut over his bones, and his gnarled "
      "fingers grip tightly to a tattered piece of blood-stained cloth. "
      "On closer inspection you realize that his fingertips are missing, "
      "and the bloodstains on his cracked lips may be an indication of "
      "why... truly a horrible way to go.%^RESET%^");
   set_value(0);
   set_weight(80);
}
