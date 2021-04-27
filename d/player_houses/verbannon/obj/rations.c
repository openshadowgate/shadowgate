inherit "/std/food";

void create(){
   ::create();
   set_name("rations");
   set_id(({"rations","military rations","food"}));
   set_short("%^BOLD%^%^BLACK%^milit%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ry r%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^tions%^RESET%^");
   set_long("PREMIUM military rations! Some powdered meat, hard dry crackers, a dry nutritious sludge for soup, and for dessert, either some fruit and molasses candy or some honey brittle.");
   set_my_mess("The powdered meat and candy was yum. The crackers and sludge soup are much harder to take, with their repulsive texture. Malnutrition can't be that bad, can it?\n");
   set_your_mess("scarfs down tastier rations and stares in dismay at the rest.\n");
   set_destroy();
   set_value(0);
   set_weight(0);
   set_strength(10);
}