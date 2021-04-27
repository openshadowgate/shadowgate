/*
Sat Aug 10 05:38:27 2002 from Girruuth
To: Styx 
Cc: Girruuth 
Subject: RE: your request

a small ornately designed wooden box with a lid, but no apparent means to
open the lid.  The top is decorated with a scene of a horizon and dawn just
arriving complete with yellows and oranges upon the landscape.  On the
bottom is an inscription which reads (in the color purple) "Those who set
their hearts free, often have no need of a key"

The coding part of the small box is some sort of wind up mechanism or small
button which is pressed to activate the illusionary display box.  The
images that are displaced should be random and accompanied with simple and
light background music all done with emotes.  The length of time it lasts
should be random but roughly the same each time, 1 to 3 mins real time.

The random images should be of the following and if not indicated
specifically in random colors as well....
1.  (in purple) A panther running through a lightly densed forest, stopping
and going apparently on the hunt.
2.  An unknown hand feeding grapes(in magenta) to an unknown mouth.
3.  A similar scene of the dawn and the landscape with the sun rising in
the background.
4.  A panther(in magenta) yawning and cleaning itself peacefully.
5.  an unknown set of hands juggling grapes(in magenta)
6.  a scene over a lake with the sun rising and the dual reflections of the
real and the projected of the sun rising happening
7.  One scene with all three aspects in them, a panther lying in the grass,
a grapevine growing on a wall next to the panther and the sun rising in the
background.

This is the idea that I had.  any questions?
*/
#include <std.h>
#define COLORS ({"%^BOLD%^%^MAGENTA%^", "%^RED%^", "%^BOLD%^%^RED%^", "%^YELLOW%^", "%^GREEN%^", "%^BOLD%^%^GREEN%^", "%^CYAN%^", "%^BOLD%^%^CYAN%^", "%^BLUE%^", "%^BOLD%^%^BLUE%^"})



inherit OBJECT;

int used, cycles;

void init(){
   ::init();
   add_action("start_it","press");
}

void create() {
  ::create();
    set_name("ornate box");
    set_id( ({"box","ornate box"}) );
    set_short("An ornate box setting atop a small pedestal");
    set_long("This is a small ornately designed wooden box with a lid, but no apparent means to open it.  The top is decorated with a scene of a horizon and dawn just arriving complete with yellows and oranges upon the landscape.  It sets upon a small, hand carved mohogany pedestal and if lifted, there is a small indentation on the bottom of the box as well as an inscription.");
    set_weight(400);
    set_value(500);
    set_cointype("gold");
   set("read", "%^MAGENTA%^Those who set their hearts free, often have "
       "no need of a key.\n%^RESET%^");
    set_lore("This box was designed and commissioned by the famous warrior "
       "known as Girruuth.  The magic to project the images came at "
       "great expense, though the purpose, as things generally are "
       "with him, was not known or disclosed at the time.");
}

int start_it(string str) {
   if(!str && str != "button" && str != "indentation") 
       return notify_fail("Press what?\n");
   if(used > 2)
       return notify_fail("You press the button but nothing happens.\n");
   if(cycles)
       return notify_fail("The box is already activated.\n");
   tell_object(TP,"You press the button on the bottom of the box and "
      "sounds and light begin to emanate from it.\n");
   tell_room(ETO,TPQCN+" presses the button on the bottom of the box and "
      "sounds and light begin to emanate from it.\n",TP);
   call_out("do_illusions",2);      
   used++;
   return 1;
}

void reset() {
   ::reset();
   used = 0;
   if(cycles > 8)  
      cycles = 0;
}

void do_illusions() {
   int i,j;
   i = random(10);
   j = random(10);
   if(!objectp(TO))   return;
   if(cycles > 8) {
      tell_room(EETO,"The music and scene fades slowly.\n\n");
      cycles = 0;
      return;
   }
   switch(random(3)) {
      case 0:
	tell_room(ETO,COLORS[i]+"Soft music drifts forth from the box.\n");
	break;
      case 1:
        tell_room(ETO,COLORS[i]+"You hear what sounds like a soft "
            "breeze blowing through trees.\n");
        break;
      case 2:
        tell_room(ETO,COLORS[i]+"Enchanting music fills the air.\n");
        break;
   }
   switch(random(3)) {
      case 0:
	tell_room(ETO,COLORS[j]+"Small dots of light flash around you.\n");
	break;
      case 1:
        tell_room(ETO,COLORS[j]+"Soft rays of light shimmer all around.\n");
        break;
      case 2:
        tell_room(ETO,COLORS[j]+"Light emanates from the box in small bursts.\n");
        break;
   }
   switch(random(7)) {
      case 0:
        tell_room(ETO,"You see a %^MAGENTA%^panther %^RESET%^running "
           "through a %^GREEN%^light forest%^RESET%^, apparently stopping "
           "and going on the hunt.\n");
        break;
      case 1:
        tell_room(ETO,"Among the lights, an unknown hand feeds %^MAGENTA%^"
           "grapes%^RESET%^ to an unknown mouth.\n");
        break;
      case 2: 
        tell_room(ETO,"The lights fade to show a scene of the dawn and a "
           "landscape with the sun rising in the background.\n");
        break;
      case 3:
	tell_room(ETO,"A scene of a %^MAGENTA%^panther%^RESET%^, yawning "
	   "and cleaning itself peacefully flashes before you.\n");
	break;
      case 4:
	tell_room(ETO,"A scene unfolds of an unknown set of hands "
	   "juggling %^MAGENTA%^grapes%^RESET%^.\n");
	break;
      case 5:
        tell_room(ETO,"You see a scene over a lake with the %^YELLOW%^sun "
           "rising %^RESET%^and the dual reflections of the lights and the "
           "sun rising.\n");
        break;
      case 6:
	tell_room(ETO,"A series of scenes blends together.\nThe first "
	   "is of a panther lying in the %^GREEN%^grass%^RESET%^.\n"
	   "The second shows a grapevine growing on a wall next to "
	   "the panther.\nLastly, the %^YELLOW%^sun %^RESET%^"
	   "rises in the background.\n");
	break;
   }
   cycles++;
   if(cycles < 10) {
     tell_room(ETO,"%^BOLD%^         ~         %^CYAN%^*         "
         "%^RED%^*         %^YELLOW%^~\n");
     call_out("do_illusions",9);
   }
}