#include <std.h>
inherit "/std/armour";
int sing;

void create()
{
   ::create();
      set_name("%^BOLD%^%^CYAN%^A w%^RESET%^%^CYAN%^a%^BLUE%^t%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^r%^CYAN%^y-%^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^l%^BLUE%^u%^BOLD%^%^BLUE%^e %^CYAN%^fish hat%^RESET%^");
      set_short("%^BOLD%^%^CYAN%^A w%^RESET%^%^CYAN%^a%^BLUE%^t%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^r%^CYAN%^y-%^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^l%^BLUE%^u%^BOLD%^%^BLUE%^e %^CYAN%^fish hat%^RESET%^");
      set_id(({"hat","fish hat"}));
      set_long("%^BOLD%^%^CYAN%^This hat has been crafted from the %^RESET%^s%^BOLD%^%^WHITE%^c%^RESET%^a"
"%^BOLD%^%^WHITE%^l%^RESET%^y %^BOLD%^%^CYAN%^skin of a small blue fish.  It has been made to keep much of the"
" natural shape of the fish, its body elongated and somewhat narrow.  The head of the fish is still intact, and"
" its constant grin and %^BLACK%^big buggy eyes %^CYAN%^would sit above the wearers face.  Light reflects off of the"
" smooth scales in %^WHITE%^sh%^CYAN%^i%^WHITE%^mme%^CYAN%^r%^WHITE%^ing %^CYAN%^colors, and it looks like"
" something perhaps a merman would wear.  The exception is the %^RESET%^%^ORANGE%^smell %^BOLD%^%^CYAN%^emitting"
" from the hat.\n%^RESET%^%^ORANGE%^...It still smells like fish.%^RESET%^\n\nHigh quality\n");
   set_weight(2);
   set_value(200);
   set_ac(0);
   set_type("clothing");
   set_limbs(({"head"}));
   set_size(2);
   set_wear((:this_object(),"wearme":));
   set_remove((:this_object(),"unwearme":));
   set_heart_beat(1);
   sing = 0;
}
int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The fish seems to grin as "+ETOQCN+" puts on the hat.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^ORANGE%^Wow, the smell of the hat is almost overwhelming.%^RESET%^");
   return 1;
}
int unwearme(string str){
   tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" slowly removes the hat with a frown.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^%^CYAN%^Taking the hat off makes you miss the sea.%^RESET%^");
   return 1;
}
void heart_beat(){
   object temp;
   if(EETO->is_player()){
    temp = ETO;
      switch(random(100)){
      case 0..96:
      break;
      case 97..99:
         tell_room(environment(EETO),"%^RESET%^%^CYAN%^A faint mumbling sound can be heard coming from "+EETO->query_cap_name()+"'s "+temp->query_name()+".",EETO);
         tell_object(EETO,"%^RESET%^%^CYAN%^A faint mumbling sound can be heard coming from your "+temp->query_name()+".%^RESET%^",environment(EETO));
      break;
      }
      return ;
   }
   if(sing==0){
      switch(random(100)){
        case 0..95:
        break;
        case 96:
         tell_room(EETO,"%^RESET%^%^MAGENTA%^The fish hat "+ETO->query_cap_name()+" has says through its big fish lips: %^RESET%^%^CYAN%^I looooove Aramel.%^RESET%^",ETO);
         tell_object(ETO,"%^RESET%^%^MAGENTA%^Your fish hat says through its big fish lips: %^RESET%^%^CYAN%^I looooove Aramel.%^RESET%^",EETO);
       break ;
       case 97:
 
         tell_room(EETO,"%^RESET%^%^MAGENTA%^The fish hat "+ETO->query_cap_name()+" has says mockingly as it winks its f%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^shy eye: %^RESET%^%^CYAN%^Aramel is the best, yes he is.%^RESET%^",ETO);
         tell_object(ETO,"%^RESET%^%^MAGENTA%^The hat you have says mockingly as it winks its f%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^shy eye: %^RESET%^%^CYAN%^Aramel is the best, yes he is.%^RESET%^",EETO);

       break;
       case 98:
         tell_room(EETO,"%^RESET%^%^CYAN%^"+ETO->query_cap_name()+"'s fish hat winks at you.%^RESET%^", ETO);
       break;
       case 99:
       sing = 1;
       call_out("say_what",1,ETO);
       break;
      }
   }
}
void say_what(){
   string speach;
        speach = "%^RESET%^%^MAGENTA%^The fish hat begins to sing: %^CYAN%^There once was a ranger, Aramel was he...%^RESET%^";
        call_out("start_speaking",2, speach);
        speach = "%^RESET%^%^MAGENTA%^The fish hat continues to sing: %^CYAN%^He lived on the land but smelled like the sea.%^RESET%^";
        call_out("start_speaking",4, speach);
        speach = "%^RESET%^%^MAGENTA%^The fish hat winks.";
        call_out("start_speaking",8, speach);
        speach = "%^RESET%^%^MAGENTA%^The fish hat continues on some more: %^CYAN%^A female elf liked him but he really loved me!";
        call_out("start_speaking",10, speach);
        speach = "%^RESET%^%^MAGENTA%^The fish hat flaps its fins quickly and then continues on again: %^CYAN%^I'm the fish hat whee!  I'm the fish hat whee! I'm the fish hat, yes thats me!%^RESET%^";
        call_out("start_speaking",12, speach);
        speach = "%^RESET%^%^MAGENTA%^The fish hat winks again before saying with gusto: %^CYAN%^...The greatest fish hat in the sea!%^RESET%^";
        call_out("start_speaking",14,speach);
        speach = "%^RESET%^%^MAGENTA%^The fish hat goes quiet for a moment before looking around and whispering to you: %^CYAN%^And I'll always be more lovely than that priestess Shrydelheeeee!%^RESET%^";
        call_out("start_speaking",20, speach);
        call_out("end_song",22);
}

void start_speaking(string speach){
    tell_room(EETO,""+speach+"",TO);
    return;
}
void end_song(){
    sing = 0;
    return;
}



