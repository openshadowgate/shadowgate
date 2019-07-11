//Temple of Kreysneothosies - created by Nienne 2/18
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("kreysneothosies");
   set_name("Temple of Kreysneothosies");
   set_short("%^YELLOW%^Temple of Kreysneothosies%^RESET%^");
   set_long("%^YELLOW%^Temple of Kreysneothosies%^RESET%^\n"
"%^BOLD%^%^WHITE%^This structure of %^RESET%^%^ORANGE%^earthy stone %^BOLD%^%^WHITE%^bears the distinctive architecture of the Tsarven empire, notable even before setting foot within the "
"building itself.  The vast iwan serves as a dramatic facade, which curves in and down to meet the main temple doorway.  Behind it rise %^RESET%^%^MAGENTA%^slender %^BOLD%^%^WHITE%^twin "
"minarets, standing to either side of the main temple dome, which is tiled entirely in %^BOLD%^%^CYAN%^sky-blue %^BOLD%^%^WHITE%^in distinct contrast to the rest of the building.  Stepping "
"through the vaulted doorway, you are first met with a line of wudhu taps, before the building itself leads deeper into a rectangular hallway lined with decorative pillars.  Archways to the "
"left and right each open onto %^RESET%^%^GREEN%^sh%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^ded cou%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^tya%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ds%^BOLD%^%^WHITE%^, "
"which are set about with stone walkways, elegant fountains, and immaculately tended gardens.  At the far end, the circular prayer hall opens out beneath the onion-shaped dome, where numerous "
"%^RESET%^%^ORANGE%^pa%^RED%^tt%^MAGENTA%^e%^CYAN%^rn%^GREEN%^ed %^BOLD%^%^WHITE%^mats are set for the use of visitors.  The minbar stands before them, and above it upon the wall has been "
"lettered the charge of Kreysneothosies.  Almost every other surface is patterned with artful calligraphy and motifs in the traditional Tsarven style, decorated with hints of glittering "
"%^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d %^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^ma%^CYAN%^la%^GREEN%^ch%^CYAN%^i%^GREEN%^te%^BOLD%^%^WHITE%^.\n%^RESET%^");
   set_smell("default","Incense carries a gentle, earthy scent throughout the temple.");
   set_listen("default","The low murmur of prayers and chanting is almost constant here.");
   set_exits(([
      "out": "/d/tharis/road/wroad30",
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
   add_action("spear_convert","purge");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Kreysneothosies charges his followers with this message:%^RESET%^%^CYAN%^
In all matters, uphold what is just and fair, and never betray your trust. Seek the truth, and use it to right wrongs and punish transgressors. Protect your home, your homeland, and your temple, and defend your brothers and sisters in arms. Heed and obey the wisdom of the law and your leaders, for it is only with respect given to righteous authority that civilization can be upheld. Be vigilant in your observations and anticipations, to detect corruption and chaos before they can threaten the order of society. Deliver vengeance to the guilty for those who cannot do it themselves.
CHARGE
   );
   return 1;
}

void purge_sequence(int step){
    object ob;
    if(!objectp(TO)) return;

    switch(step) {		
      case 1:
        tell_room(TO,"%^BOLD%^%^BLACK%^A priest steps forward, coming to pause behind the altar.  He extends his hands to hover only an inch above the spear, and closing his eyes, he begins "
"to pray fervently.\n%^RESET%^");
      break;
      case 2:
        tell_room(TO,"%^BOLD%^%^BLACK%^As his voice picks up, two more step forward to add their own to the chant, and gusts of wind pick up around the altar.  A sic%^GREEN%^k%^BLACK%^ly g"
"%^RED%^l%^BLACK%^ow becomes apparent around the spear, as though the fiendish taint itself were trying to fight back the cleansing prayer.\n%^RESET%^");
      break;
      case 3:
        tell_room(TO,"%^BOLD%^%^BLACK%^Hairline cra%^CYAN%^c%^BLACK%^ks snake their way across the f%^CYAN%^r%^WHITE%^o%^BLACK%^s%^BLUE%^t%^BLACK%^y r%^CYAN%^i%^BLUE%^m%^BLACK%^e as the spear "
"trembles and shakes, intense concentration growing upon the faces of all three priests as their tone intensifies.  A st%^YELLOW%^a%^BLACK%^tic charge crack%^WHITE%^l%^BLACK%^es in the air, "
"making your skin itch, and arcs up the length of the weapon.\n%^RESET%^");
      break;
      case 4:
        tell_room(TO,"%^BOLD%^%^BLACK%^With an exultant shout from the priests, the growing wh%^WHITE%^i%^CYAN%^r%^BLACK%^lwi%^WHITE%^n%^BLACK%^d around you issues a sudden thun%^YELLOW%^d"
"%^BLACK%^erclap!  The i%^BLUE%^c%^BLACK%^e shatters across the spear as the baleful glow of hellfire takes on a brilliant %^RESET%^%^ORANGE%^g%^YELLOW%^o%^BLACK%^l%^YELLOW%^d%^BLACK%^en l"
"%^YELLOW%^i%^BLACK%^ght, and you realize the once devilish visage has been transformed into the image of a screaming h%^RED%^a%^BLACK%^wk!\n%^RESET%^");
      break;
      case 5:
        tell_room(TO,"%^BOLD%^%^BLACK%^The three priests take a step back, exhausted but satisfied, leaving the results of their efforts gl%^YELLOW%^e%^BLACK%^ami%^CYAN%^n%^BLACK%^g upon the "
"altar.\n%^RESET%^");
        ob = new("/d/magic/temples/misc/stormspear");
        ob->move(TO);
        return;
        break;
	}
      step++;
      call_out("purge_sequence",10,step);
}

int spear_convert(string arg) {
    object thespear;

    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;

    if(!objectp(thespear = present(arg, TP))) {
      tell_object(TP, "You have no "+arg+" to sacrifice.");
      return 1;
    }
    tell_object(TP,"%^RESET%^%^ORANGE%^You step forward and place the "+arg+" upon the altar.%^RESET%^");
    tell_room(TO,"%^RESET%^%^ORANGE%^"+TP->QCN+" steps forward and places the "+arg+" upon the altar.%^RESET%^",TP);

    if(base_name(thespear) != "/d/islands/tonerra/obj/mephistar") {
      tell_room(TO,"%^ORANGE%^A nearby priest steps forward, saying: %^RESET%^'I'm afraid we cannot properly cleanse such an item. But you are welcome to donate it if you wish.'");
      return 1;
    }
    thespear->remove();
    call_out("purge_sequence",10,1);
    return 1;
}