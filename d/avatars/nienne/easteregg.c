inherit "/std/food.c";
#define FILLING ({"%^ORANGE%^gooey ca%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^a%^BLACK%^%^BOLD%^m%^RESET%^%^ORANGE%^el","%^BOLD%^%^GREEN%^m%^WHITE%^i%^GREEN%^nt","%^BOLD%^%^MAGENTA%^%^BOLD%^st%^RED%^r%^MAGENTA%^awb%^RED%^e%^MAGENTA%^rry","%^ORANGE%^crun%^YELLOW%^c%^RESET%^%^ORANGE%^hy hon%^YELLOW%^e%^RESET%^%^ORANGE%^ycomb","%^BOLD%^%^BLACK%^haze%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^nut pr%^RESET%^a%^BOLD%^%^BLACK%^line","%^MAGENTA%^turk%^RED%^is%^MAGENTA%^h de%^RED%^li%^MAGENTA%^ght","%^YELLOW%^zesty l%^GREEN%^e%^YELLOW%^mon","%^ORANGE%^jaffa or%^RED%^an%^ORANGE%^ge"})

int i;

void create(){
   ::create();
   i = random(sizeof(FILLING));
   set_name("easter egg");
   set_id(({"egg","easter egg","Egg","handmade egg","handmade easter egg"}));
   set_short("%^BLACK%^%^BOLD%^a handmade easter egg%^RESET%^");
   set_long("%^RESET%^This is a %^MAGENTA%^yummy %^RESET%^easter egg!  Its %^ORANGE%^chocolate shell %^RESET%^"
"is crisp and patterned with %^BOLD%^%^BLACK%^cra%^YELLOW%^c%^BOLD%^%^BLACK%^k marks %^RESET%^from the mould "
"it was crafted in.  Solid %^BOLD%^%^WHITE%^s%^MAGENTA%^ug%^WHITE%^ar%^MAGENTA%^-i%^WHITE%^ci%^MAGENTA%^ng "
"%^RESET%^forms the shape of a %^BOLD%^%^WHITE%^happy bunny %^RESET%^on the side.  You wonder what %^RED%^fi"
"%^ORANGE%^ll%^GREEN%^in%^RED%^g %^RESET%^it might have.%^RESET%^");
   set_destroy();
   set_poison(0);
   set_strength(0);
   set_my_mess("%^RESET%^%^CYAN%^You pop the egg in your mouth and are delighted by the %^RESET%^"
+FILLING[i]+"%^RESET%^%^CYAN%^ filling!%^RESET%^");
   set_your_mess("%^RESET%^gobbles up the cookies and seems delighted with the "+FILLING[i]+"%^RESET%^ "
"filling!");
   set_weight(0);
   set_value(0);
}

string query_type() {
   return FILLING[i];
}