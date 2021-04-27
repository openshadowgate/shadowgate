inherit "/std/food.c";

void create(){
   ::create();
   set_name("fruit");
   set_destroy();
   set_poison(0);
   set_strength(10);
   set_weight(1);
   set_value(0);
}
