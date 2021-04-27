#include <std.h>
#include <daemons.h>
inherit OBJECT;

int tracker;

void create(){
	::create();
	set_name("conch shell");
	set_id(({ "shell", "conch", "conch shell", "horn", "horn of the deep" }));
	set_short("%^RESET%^%^BOLD%^%^RED%^H%^YELLOW%^o%^RED%^rn %^RESET%^of the %^BOLD%^%^BLUE%^D%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^ep%^RESET%^");
	set_obvious_short("%^ORANGE%^a large %^RED%^c%^ORANGE%^o%^WHITE%^n%^ORANGE%^c%^RED%^h s%^ORANGE%^h%^WHITE%^e%^ORANGE%^l%^RED%^l%^RESET%^");
        set_long("%^ORANGE%^This large shell is easily the size of a human's fist.  The exterior is coarse to the touch and fades from a %^RED%^d%^ORANGE%^e%^RED%^ep r%^ORANGE%^e%^RED%^ddi%^ORANGE%^s%^RED%^h br%^ORANGE%^o%^RED%^wn %^ORANGE%^color to a %^RESET%^p%^ORANGE%^a%^WHITE%^le cr%^ORANGE%^e%^WHITE%^am %^ORANGE%^at the edges, while the interior is a %^BOLD%^%^WHITE%^p%^MAGENTA%^e%^WHITE%^arlesc%^MAGENTA%^e%^WHITE%^nt "
"wh%^MAGENTA%^i%^WHITE%^te%^RESET%^%^ORANGE%^.  The coil of the shell is quite tight, preventing anyone from pushing their fingers into its core, though a small %^BOLD%^%^BLACK%^h%^RESET%^o%^BOLD%^%^BLACK%^le %^RESET%^%^ORANGE%^has been drilled into the very top as though one could %^YELLOW%^blow %^RESET%^%^ORANGE%^through the shell and cause it to make a sound.");
	set("read",
@AVATAR
%^CYAN%^The %^BLUE%^sound %^CYAN%^it makes is sweet %^WHITE%^above%^RESET%^
%^CYAN%^But %^MAGENTA%^sweeter %^CYAN%^still when passed through %^BLUE%^water's glove%^RESET%^
%^CYAN%^For %^ORANGE%^those %^CYAN%^that %^BOLD%^play%^RESET%^%^CYAN%^ the %^GREEN%^siren's song%^RESET%^
%^CYAN%^A %^RED%^gift %^CYAN%^you hold the whole %^YELLOW%^day %^RESET%^%^CYAN%^long%^RESET%^

AVATAR
	);
   set("langage","elven");
   set_weight(2);
   set_value(0);
   set_lore("%^RESET%^Said to be crafted by the skilled hands of mermaids and given only to those whom the mermaids trust, only a few of these Horns of the Deep are thought to exist.  Prized by seafarers of all kinds, it is believed that by blowing upon one of these horns, it will "
"summon aid of the mermaids themselves or their guardian creatures.  Darker rumors persist that for one who knows how to play the horn's true song, the melody will bespell a sea dweller.  Perhaps if one could %^YELLOW%^read%^RESET%^ the odd bumps upon shell's surface, they could learn the song needed.");
   set_property("lore difficulty",25);
   tracker = 0;
}

void init() {
   ::init();
   add_action("blow_fun","blow");
   add_action("play_fun","blast");
}

int blow_fun(string str) {
   object myav;
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 0;
   }
   if (TP->query_gagged()) {
     return notify_fail(TP->query_gagged_message());
     return 0;
   }
   if (!str) {
     notify_fail("What do you want to blow?");
     return 0;
   }
   if (str != "horn" && str != "shell") {
     notify_fail("You can't blow that.");
     return 0;
   }
   if (sizeof(TP->query_attackers()) > 0) {
     tell_object(TP,"You can't do that in the middle of a fight!");
     return 1;
   }
   tell_object(TP,"%^CYAN%^As you blow upon the %^RED%^sh%^ORANGE%^e"
"%^RED%^ll%^CYAN%^, it makes a %^BOLD%^%^BLACK%^deep%^RESET%^%^CYAN%^, "
"%^RESET%^hollow %^CYAN%^sound that can be heard for %^ORANGE%^miles"
"%^CYAN%^, even under %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^.%^RESET%^");
   tell_room(ETP,"%^CYAN%^As "+TP->QCN+"%^RESET%^%^CYAN%^ blows upon the "
"%^RED%^sh%^ORANGE%^e%^RED%^ll%^CYAN%^, it makes a %^BOLD%^%^BLACK%^deep"
"%^RESET%^%^CYAN%^, %^RESET%^hollow %^CYAN%^sound that can be heard for "
"%^ORANGE%^miles%^CYAN%^, even under %^BOLD%^%^BLUE%^water%^RESET%^"
"%^CYAN%^.%^RESET%^",TP);
   message("info","%^CYAN%^A %^BOLD%^%^BLACK%^deep%^RESET%^%^CYAN%^, "
"%^RESET%^hollow %^CYAN%^sound fills the air for %^ORANGE%^miles "
"%^CYAN%^around.%^RESET%^",nearbyRoom(ETP,3));
   myav = find_player("lurue");
   if(userp(myav)) tell_object(myav,"%^ORANGE%^The Horn of the Deep has "
"been played by "+TP->query_true_name()+"!%^RESET%^");
   return 1;
}

int play_fun(string str){
   object targ;
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 0;
   }
   if (TP->query_gagged()) {
     return notify_fail(TP->query_gagged_message());
     return 0;
   }
   if (!str) {
     notify_fail("What do you want to blast?");
     return 0;
   }
   if ((string)TP->query_diety() != "istishia" && !avatarp(TP)) {
     notify_fail("You can't do that.");
     return 0;
   }
   if(!targ = present(str,ETP)) {
     notify_fail("You can't see that here.\n");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"You've already used the power of the horn today.");
     return 1;
   }
   tracker = time() + 28800;
   tell_object(TP,"%^BLUE%^A %^CYAN%^d%^GREEN%^i%^CYAN%^scor%^GREEN%^d%^CYAN%^ant h%^GREEN%^a%^CYAN%^rmo"
"%^GREEN%^n%^CYAN%^y %^BLUE%^of %^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^ep %^RESET%^h%^BOLD%^%^BLACK%^o"
"%^RESET%^llow %^BLUE%^sounds issues from your %^RED%^c%^ORANGE%^o%^RED%^nch sh%^ORANGE%^e%^RED%^ll "
"%^BLUE%^causing "+targ->QCN+" to reel %^BOLD%^%^WHITE%^b%^BLUE%^a%^WHITE%^ckw%^BLUE%^a%^WHITE%^rds"
"%^RESET%^%^BLUE%^!%^RESET%^");
   tell_room(ETP,"%^BLUE%^A %^CYAN%^d%^GREEN%^i%^CYAN%^scor%^GREEN%^d%^CYAN%^ant h%^GREEN%^a%^CYAN%^rmo"
"%^GREEN%^n%^CYAN%^y %^BLUE%^of %^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^ep %^RESET%^h%^BOLD%^%^BLACK%^o"
"%^RESET%^llow %^BLUE%^sounds issues from "+TP->QCN+"'s %^RED%^c%^ORANGE%^o%^RED%^nch sh%^ORANGE%^e%^RED%^ll "
"%^BLUE%^causing "+targ->QCN+" to reel %^BOLD%^%^WHITE%^b%^BLUE%^a%^WHITE%^ckw%^BLUE%^a%^WHITE%^rds%^RESET%^"
"%^BLUE%^!%^RESET%^%^RESET%^",({TP,targ}));
   tell_object(targ,"%^BLUE%^You are stunned by the %^CYAN%^d%^GREEN%^i%^CYAN%^scor%^GREEN%^d%^CYAN%^ant "
"h%^GREEN%^a%^CYAN%^rmo%^GREEN%^n%^CYAN%^y %^BLUE%^of %^BOLD%^%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^ep "
"%^RESET%^h%^BOLD%^%^BLACK%^o%^RESET%^llow %^BLUE%^sounds that issues from "+TP->QCN+"'s %^RED%^c%^ORANGE%^o"
"%^RED%^nch sh%^ORANGE%^e%^RED%^ll%^BLUE%^!%^RESET%^");
   targ->set_paralyzed((10+random(4)),"%^BLUE%^The discordant notes are still echoing in your head!%^RESET%^");
   return 1;
}