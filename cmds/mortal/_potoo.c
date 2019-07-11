//      /cmds/mortal/_potoo.c
//      Coded by Lujke to inform the populate about Potoos
//      And to amuse Eris

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_potoo(string text);
void help();


int cmd_potoo(string text)
{
   tell_object(TP, "You cannot potoo.");
        return 1;
}

void help() {
        write(
      "Potoos (family Nyctibiidae) are a group of near passerine"
      +" birds related to the nightjars and frogmouths. They are"
      +" sometimes called poor-me-ones, after their haunting calls."
      +" There are seven species in one genus, Nyctibius, in Atoyatl"
      +" Tepexitl.\n\n"

      +"These are nocturnal insectivores which lack the bristles"
      +" around the mouth found in the true nightjars. They hunt"
      +" from a perch like a shrike or flycatcher or stirge. During"
      +" the day they perch upright on tree stumps, camouflaged to"
      +" look like part of the stump. The single spotted egg is laid"
      +" directly on the top of a stump. "
    );
}
