#include <std.h>

string *races_allowed()
{
    return ({"human", "ratkin"});
}

/*
  Bostly homebrew, some things are based on rules in Lords of the wild
  Wererat plague lycanthropy powers are in wererat shapes
*/

int apply_template(object ob)
{
    ob->set("wererat",1);
    return 1;
}

int remove_template(object ob)
{
    ob->delete("wererat");
    return 1;
}
