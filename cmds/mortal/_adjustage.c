#include <std.h>

inherit DAEMON;

int cmd_adjustage(string str){
   int num;
   
   if(!str) return 0;
   if(TP->query("age cat reset")) return notify_fail("You've already done that.\n");
   switch(str){
      case "child":
         num = -10 - random(11);
         break;
      case "normal":
         num = random(30);
         break;
      case "middle":
         num = 60+random(50);
         break;
      case "old":
         num = 100+random(140);
         break;
      case "venerable":
         num = 250+random(250);
         break;
      default:
         return notify_fail("Please use one of the following: child, normal, middle, old, venerable\n");
   }
   TP->setPlayerAgeCat(num);
   return 1;
}
