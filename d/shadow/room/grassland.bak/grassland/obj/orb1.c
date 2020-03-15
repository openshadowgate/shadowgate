#include <std.h>
inherit OBJECT;
create() {
::create();
set_id(({ "orb" }));
set_name("orb");
set_short("a magical aging orb");
set_long("This orb has a magical power to age things.  I'd use it carefully, cuz it can age absolutely ANYTHING!.");
set_weight(0);
}
void init()
{
  ::init();
add_action("age","age");
}
int age(string str)
{
object target;
if(!str){return 0;}
target=present(str,environment(TP));
if(!target)
{
    notify_fail("What?\n");
    return 0;
}
this_player()->add_sp(-25);
write("You use the powers of the orb to age your opponent.\n");
write("Your opponent slumps closer to the ground.\n");
target->add_hp(-(random(50)));
return 1;
}
