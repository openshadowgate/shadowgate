#include <std.h>
#include "../amberly.h"
inherit ROOM;

int taffies, grapes, berries, apricots;

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("A chaotic butterfly garden");
   set_short("A chaotic butterfly garden");
   set_long("%^RESET%^%^GREEN%^Hundreds of %^MAGENTA%^b%^BOLD%^u%^RESET%^"
"%^MAGENTA%^t%^BOLD%^t%^RESET%^%^MAGENTA%^erf%^BOLD%^l%^RESET%^%^MAGENTA%^i"
"%^BOLD%^e%^RESET%^%^MAGENTA%^s %^GREEN%^dance throughout this "
"%^BOLD%^u%^RESET%^%^GREEN%^n%^BOLD%^r%^RESET%^%^GREEN%^es%^RESET%^%^GREEN%^t"
"%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^"
"%^GREEN%^d garden. There seems to be no rhyme or reason to the way it grows, "
"and yet it flows together in a %^BOLD%^%^GREEN%^k%^MAGENTA%^a"
"%^GREEN%^l%^MAGENTA%^e%^GREEN%^i%^MAGENTA%^d%^GREEN%^o%^MAGENTA%^s%^GREEN%^c"
"%^MAGENTA%^o%^GREEN%^p%^MAGENTA%^e %^RESET%^%^GREEN%^of "
"%^BOLD%^%^MAGENTA%^p%^WHITE%^i%^MAGENTA%^nk%^MAGENTA%^s, "
"%^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^rples %^GREEN%^and "
"%^WHITE%^whites %^GREEN%^against the natural, %^BOLD%^deep green "
"%^RESET%^%^GREEN%^surroundings. Many %^BOLD%^%^WHITE%^f%^CYAN%^l%^WHITE%^"
"owering %^RESET%^%^GREEN%^vines are %^CYAN%^scattered %^GREEN%^around the "
"area, most of which eventually lead to an %^YELLOW%^eye-catching "
"%^RESET%^%^MAGENTA%^c%^ORANGE%^a%^MAGENTA%^r%^ORANGE%^a%^MAGENTA%^v%^ORANGE%^"
"a%^MAGENTA%^n %^RESET%^%^GREEN%^that seems to center the garden itself. The "
"vines and trees around it make it hard to see what is beyond the caravan, as "
"they get thicker and more lush around it. Breath-taking %^YELLOW%^sun-"
"catchers %^RESET%^%^GREEN%^draw attention to several "
"%^BOLD%^%^WHITE%^i%^RESET%^v%^BOLD%^o%^RESET%^r%^BOLD%^y "
"%^RESET%^b%^BOLD%^enches %^RESET%^%^GREEN%^that just barely %^BOLD%^peek "
"%^RESET%^%^GREEN%^out of the %^YELLOW%^f%^GREEN%^o%^RESET%^%^GREEN%^l"
"%^BOLD%^i%^YELLOW%^a%^WHITE%^g%^RESET%^%^GREEN%^e.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^MAGENTA%^The sweet scent of "
"%^WHITE%^honeysuckle %^MAGENTA%^mingles heavily with the rest of the "
"garden.%^RESET%^");
   set_listen("default","%^RESET%^%^MAGENTA%^The sounds of %^CYAN%^windchimes "
"%^MAGENTA%^and %^WHITE%^birdsong %^MAGENTA%^fill the air.%^RESET%^");
   set_items(([
     "butterflies":"%^BOLD%^%^WHITE%^There are many %^CYAN%^c%^MAGENTA%^o"
"%^GREEN%^l%^RESET%^%^MAGENTA%^o%^YELLOW%^r%^WHITE%^f%^CYAN%^u%^GREEN%^l "
"%^MAGENTA%^butterflies %^RESET%^%^BOLD%^of all shapes and sizes within the "
"%^BOLD%^%^GREEN%^garden%^RESET%^%^BOLD%^. Some of them feed on the "
"%^YELLOW%^n%^GREEN%^e%^YELLOW%^c%^MAGENTA%^t%^YELLOW%^aring shrubs "
"%^RESET%^%^BOLD%^and %^RESET%^%^MAGENTA%^f%^BOLD%^l%^WHITE%^o"
"%^RESET%^%^MAGENTA%^wers %^RESET%^%^BOLD%^while others are content to flit "
"around.%^RESET%^",
     "caravan":"%^GREEN%^Centered among the %^BOLD%^w%^MAGENTA%^i"
"%^RESET%^l%^GREEN%^d %^BOLD%^vines %^RESET%^%^GREEN%^of the %^BOLD%^garden, "
"%^RESET%^%^GREEN%^is a %^MAGENTA%^c%^ORANGE%^a%^MAGENTA%^ravan "
"%^GREEN%^similar to what a %^CYAN%^gypsy %^GREEN%^might roam in. This "
"particular one is much %^CYAN%^f%^WHITE%^a%^ORANGE%^n%^MAGENTA%^"
"c%^WHITE%^i%^CYAN%^er %^GREEN%^than most. The wood working is "
"%^BOLD%^exquisite %^RESET%^%^GREEN%^and it has been painted a "
"%^MAGENTA%^d%^WHITE%^usty %^MAGENTA%^r%^WHITE%^ose %^GREEN%^color. The edges "
"and wheels are %^YELLOW%^gilded with g%^RESET%^%^ORANGE%^o%^BOLD%^l"
"%^RESET%^%^ORANGE%^d %^GREEN%^and lined with %^MAGENTA%^p%^BOLD%^ur"
"%^RESET%^%^MAGENTA%^ple s%^BOLD%^ap%^RESET%^%^MAGENTA%^phires%^GREEN%^. A "
"%^BOLD%^%^MAGENTA%^wooden un%^WHITE%^i%^MAGENTA%^corn%^RESET%^%^GREEN%^ "
"prances around the caravan, leading a group of %^WHITE%^children %^GREEN%^to "
"a replica %^BOLD%^%^WHITE%^waterwheel%^RESET%^%^GREEN%^.%^RESET%^",
     "vines":"%^GREEN%^Scattered all over the %^BOLD%^gardens "
"%^RESET%^%^GREEN%^are %^MAGENTA%^flowering vines %^GREEN%^full of "
"%^RED%^r%^WHITE%^o%^MAGENTA%^s%^BOLD%^e%^WHITE%^s%^RESET%^%^GREEN%^, "
"%^YELLOW%^h%^WHITE%^o%^MAGENTA%^n%^YELLOW%^e%^WHITE%^y%^MAGENTA%^suckle "
"%^RESET%^%^GREEN%^and %^YELLOW%^various fruits%^RESET%^%^GREEN%^.%^RESET%^",
     "foliage":"%^GREEN%^The foliage gets thicker the further into the garden "
"you look.%^RESET%^",
     "benches":"%^WHITE%^Painted a %^BOLD%^ivory color %^RESET%^and "
"%^CYAN%^glossed %^WHITE%^over with some kind of %^BOLD%^s%^RESET%^h%^BOLD%^"
"i%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^d%^RESET%^u"
"%^BOLD%^st, %^RESET%^these benches hold a %^YELLOW%^w%^GREEN%^h%^WHITE%^"
"i%^YELLOW%^msical %^RESET%^appeal and look about as comfortable as a outdoor "
"bench could. On the back are carefully detailed %^MAGENTA%^floral designs "
"%^WHITE%^and the occasional %^BOLD%^%^CYAN%^fairy%^RESET%^.",
     ({"sun-catchers","sun catchers"}):"%^BOLD%^%^CYAN%^Breath-taking "
"%^YELLOW%^s%^WHITE%^u%^YELLOW%^n catchers %^CYAN%^add to the "
"%^GREEN%^a%^CYAN%^m%^GREEN%^b%^CYAN%^i%^GREEN%^a%^CYAN%^n%^GREEN%^c%^CYAN%^e "
"%^CYAN%^of the%^WHITE%^ garden %^CYAN%^and during the %^RESET%^%^ORANGE%^day"
", %^BOLD%^%^CYAN%^draw attention to partially %^WHITE%^h%^RESET%^i%^BOLD%^"
"d%^RESET%^d%^BOLD%^en benches%^CYAN%^.%^RESET%^",
     "seeds":"%^MAGENTA%^A small packet of %^YELLOW%^seeds%^RESET%^ "
"%^MAGENTA%^has been discarded. Perhaps you could%^WHITE%^ feed the birds " 
"%^MAGENTA%^if you wanted.%^RESET%^",
     "roses":"%^BOLD%^%^MAGENTA%^Hundreds of %^WHITE%^r%^CYAN%^o%^RED%^s"
"%^GREEN%^e%^WHITE%^s %^MAGENTA%^scatter and climb throughout the "
"%^GREEN%^garden%^MAGENTA%^.%^RESET%^",
     "honeysuckle":"%^YELLOW%^H%^WHITE%^o%^MAGENTA%^n%^YELLOW%^e%^%^WHITE%^y"
"%^MAGENTA%^s%^YELLOW%^u%^WHITE%^c%^MAGENTA%^k%^YELLOW%^l%^WHITE%^e "
"%^GREEN%^vines literally surround the entire garden.%^RESET%^",
     "fruits":"%^GREEN%^There are %^BOLD%^vines %^RESET%^%^GREEN%^abundant "
"with %^MAGENTA%^g%^BOLD%^r%^RESET%^%^MAGENTA%^apes%^GREEN%^, bushes full of "
"%^RED%^r%^MAGENTA%^a%^BOLD%^s%^RED%^p%^RESET%^%^RED%^b%^MAGENTA%^e%^BOLD%^r"
"%^RED%^r%^RESET%^%^RED%^i%^MAGENTA%^e%^RED%^s %^GREEN%^and "
"%^BOLD%^%^BLUE%^blueberries%^RESET%^%^GREEN%^, as well as trees heavy with "
"%^YELLOW%^apricots%^RESET%^%^GREEN%^.%^RESET%^",
     "grapes":"%^MAGENTA%^They look d%^BOLD%^el%^RESET%^%^MAGENTA%^icious, it "
"would not be hard to %^BOLD%^pluck %^RESET%^%^MAGENTA%^a few from the vines.",
     "berries":"%^MAGENTA%^The %^BOLD%^ripe %^RED%^b%^MAGENTA%^e%^RESET%^"
"%^MAGENTA%^r%^RED%^r%^BOLD%^i%^MAGENTA%^e%^RESET%^%^MAGENTA%^s look plump "
"for the taking. Perhaps you would like to %^BOLD%^%^WHITE%^gather "
"%^RESET%^%^MAGENTA%^a few?%^RESET%^",
     "apricots":"%^ORANGE%^Some of the %^GREEN%^trees %^ORANGE%^are full of "
"%^YELLOW%^apricots %^RESET%^%^ORANGE%^just begging to be%^BOLD%^%^WHITE%^ "
"picked%^RESET%^%^ORANGE%^.%^RESET%^",
     "unicorn":"%^MAGENTA%^A %^BOLD%^bright p%^RESET%^%^MAGENTA%^i%^BOLD%^nk "
"%^WHITE%^wooden unicorn %^RESET%^%^MAGENTA%^trots back and forth around the "
"%^GREEN%^garden%^MAGENTA%^, gathering children to take to the%^WHITE%^ "
"waterwheel%^MAGENTA%^.%^RESET%^",
     "waterwheel":"%^BOLD%^%^WHITE%^The %^CYAN%^waterwheel %^WHITE%^is "
"actually just a %^GREEN%^miniature replica %^WHITE%^of the real thing and "
"obviously just for looks..or is it. There seems to be carefully placed "
"%^YELLOW%^compartments %^WHITE%^full of %^CYAN%^c%^MAGENTA%^o%^RED%^l"
"%^GREEN%^o%^BLUE%^r%^WHITE%^f%^CYAN%^u%^MAGENTA%^l%^CYAN%^l%^YELLOW%^y "
"wrapped %^WHITE%^candies in them that are just out of reach. Maybe if you "
"%^RESET%^s%^BOLD%^p%^RESET%^i%^BOLD%^n it, you might manage to shake one "
"loose.",
   ]));
   set_exits(([
     "out" : "/d/darkwood/room/road5",
	 "northeast" : ROOMS"pond"
   ]));
  taffies = random(3)+3;
  grapes = random(3)+1;
  berries = random(3)+1;
  apricots = random(2)+1;
  set_search("default","%^GREEN%^Various %^YELLOW%^seeds%^RESET%^%^GREEN%^ "
"are on the ground, scattered near the %^WHITE%^%^BOLD%^benches"
"%^RESET%^%^GREEN%^.%^RESET%^");
  set_search("garden","%^GREEN%^Various %^YELLOW%^seeds%^RESET%^%^GREEN%^ "
"are on the ground, scattered near the %^WHITE%^%^BOLD%^benches"
"%^RESET%^%^GREEN%^.%^RESET%^");
} 

void init(){
   ::init();
   add_action("feed_birds","feed");
   add_action("spin_wheel","spin");
   add_action("apricot_fun","pick");
   add_action("grapes_fun","pluck");
   add_action("berries_fun","gather");
}

void reset() {
  taffies = random(3)+3;
  grapes = random(3)+1;
  berries = random(3)+1;
  apricots = random(2)+1;
  switch(random(10)){
     case 0..1:
       tell_room(TO,"%^BOLD%^%^WHITE%^A small group of %^GREEN%^children "
"%^YELLOW%^laugh %^MAGENTA%^merrily %^WHITE%^as they dip in and out of "
"%^CYAN%^hiding places%^WHITE%^.%^RESET%^");
     break;
     case 2..3:
       tell_room(TO,"%^BOLD%^%^CYAN%^T%^RESET%^%^CYAN%^i%^BOLD%^ny "
"gi%^RESET%^%^CYAN%^gg%^BOLD%^les %^WHITE%^erupt throughout the "
"%^GREEN%^garden %^WHITE%^and for just a moment, your skin is covered in a "
"%^GREEN%^r%^RED%^a%^BLUE%^i%^CYAN%^n%^MAGENTA%^b%^WHITE%^o%^RESET%^%^GREEN%^"
"w %^BOLD%^%^WHITE%^of polka dots.%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^CYAN%^A %^BOLD%^%^WHITE%^soft melody "
"%^RESET%^%^CYAN%^pours through the %^MAGENTA%^garden %^CYAN%^as several "
"%^BOLD%^w%^RESET%^i%^BOLD%^n%^CYAN%^d-c%^WHITE%^h%^RESET%^i%^BOLD%^m%^CYAN%^"
"es %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^s%^RESET%^p%^BOLD%^e%^RESET%^r "
"%^CYAN%^to the %^WHITE%^winds %^CYAN%^delicately.%^RESET%^");
     break;
     case 5:
       tell_room(TO,"%^ORANGE%^A %^WHITE%^fat mouse %^ORANGE%^peeks its head "
"from under a %^GREEN%^leaf, %^ORANGE%^nibbles on some %^YELLOW%^crumbs "
"%^RESET%^%^ORANGE%^then scurries back into its %^BOLD%^%^GREEN%^hiding "
"place%^RESET%^%^ORANGE%^.%^RESET%^");
     break;
     case 6..7:
       tell_room(TO,"%^GREEN%^The fragrant scent of %^WHITE%^honeysuckle "
"%^GREEN%^mingled with other %^BOLD%^%^MAGENTA%^flowery%^RESET%^%^GREEN%^ "
"enticements is carried on a %^CYAN%^invigorating breeze%^GREEN%^.%^RESET%^");
     break;
     case 8..10:
       tell_room(TO,"%^BOLD%^%^WHITE%^A lost %^CYAN%^silk ribbon "
"%^WHITE%^floats across the %^GREEN%^garden %^WHITE%^lifted from one plant "
"to another by the %^RESET%^%^CYAN%^wind%^BOLD%^%^WHITE%^.%^RESET%^");
     break;
   }
}

int feed_birds(string str){
  if(!str) {
    notify_fail("What do you want to feed?\n");
    return 0;
  }
  if(str != "the birds" && str != "birds") {
    notify_fail("You can't feed that.\n");
    return 0;
  }
  tell_room(TO,"%^ORANGE%^Several %^CYAN%^c%^WHITE%^o%^ORANGE%^lo%^MAGENTA%^" 
"r%^WHITE%^f%^CYAN%^ul %^ORANGE%^birds swoop down around "+TP->QCN+"'s feet "
"as "+TP->QS+" scatters some %^YELLOW%^seeds "
"%^RESET%^%^ORANGE%^about.%^RESET%^",TP);
  tell_object(TP,"%^ORANGE%^Several %^CYAN%^c%^WHITE%^o%^ORANGE%^lo%^MAGENTA%^" 
"r%^WHITE%^f%^CYAN%^ul %^ORANGE%^birds swoop down around your feet, eagerly "
"partaking in the scattered %^YELLOW%^seeds%^RESET%^%^ORANGE%^.%^RESET%^");
  return 1;
}

int spin_wheel(string str){
  object ob;
  if(!str) {
    notify_fail("What do you want to spin?\n");
    return 0;
  }
  if(str != "wheel" && str != "waterwheel" && str != "the wheel" && str != "the waterwheel") {
    notify_fail("You can't spin that.\n");
    return 0;
  }
  if(!taffies) {
    tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" spins the waterwheel, but "
"nothing comes out.%^RESET%^",TP);
    tell_object(TP,"%^BOLD%^%^WHITE%^You spin the waterwheel, but nothing "
"comes out. It must be empty.%^RESET%^");
    return 1;
  }  
  tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" spins the waterwheel, and a "
"piece of %^GREEN%^w%^CYAN%^r%^RESET%^%^GREEN%^a%^BOLD%^ppe%^CYAN%^d "
"candy%^WHITE%^ slides down a secret chute to land on the ground at "+TP->QP+
" feet.%^RESET%^",TP);
  tell_object(TP,"%^BOLD%^%^WHITE%^You spin the waterwheel, and a piece of "
"%^GREEN%^w%^CYAN%^r%^RESET%^%^GREEN%^a%^BOLD%^ppe%^CYAN%^d candy%^WHITE%^ "
"slides down a secret chute to land on the ground at your feet.%^RESET%^");
  ob = new(OBJ"food");
  ob->move(TO);
  ob->set_name("taffy");
  ob->set_id(({"food","taffy","wrapped taffy","lolly","candy"}));
  ob->set_short("%^BOLD%^%^WHITE%^a piece of %^GREEN%^w%^CYAN%^r%^RESET%^"
"%^GREEN%^a%^BOLD%^ppe%^CYAN%^d %^WHITE%^taffy%^RESET%^");
  switch(random(4)) {
    case 0:
    ob->set_long("%^BOLD%^%^WHITE%^The candy is wrapped in a%^GREEN%^ "
"r%^YELLOW%^a%^MAGENTA%^i%^RESET%^%^GREEN%^nb%^RED%^o%^GREEN%^w "
"%^BOLD%^%^WHITE%^hue of colors. Through a %^CYAN%^clear %^WHITE%^portion of "
"the paper, you can see ripples of %^MAGENTA%^pink %^WHITE%^and white. The "
"scents of %^YELLOW%^vanilla %^WHITE%^and%^MAGENTA%^ r%^RED%^a%^MAGENTA%^"
"s%^RESET%^%^MAGENTA%^p%^RED%^b%^BOLD%^e%^MAGENTA%^rr%^RED%^i%^RESET%^"
"%^MAGENTA%^e%^RED%^s %^BOLD%^%^WHITE%^roll off the taffy.%^RESET%^");
    ob->set_my_mess("%^BOLD%^%^GREEN%^An extra creamy mix of%^MAGENTA%^ "
"raspberries %^GREEN%^and %^WHITE%^vanilla %^GREEN%^teases your mouth as "
"the %^YELLOW%^soft taffy %^GREEN%^is chewed.%^RESET%^");
    ob->set_your_mess("%^RESET%^%^MAGENTA%^unwraps the %^WHITE%^candy "
"%^MAGENTA%^and pops it into their mouth, chewing eagerly. The delicate scent "
"of %^BOLD%^raspberries %^RESET%^MAGENTA%^fills the air.%^RESET%^");
    break;

    case 1:
    ob->set_long("%^BOLD%^%^WHITE%^The candy is wrapped in a%^GREEN%^ "
"r%^YELLOW%^a%^MAGENTA%^i%^RESET%^%^GREEN%^nb%^RED%^o%^GREEN%^w "
"%^BOLD%^%^WHITE%^hue of colors. Through a %^CYAN%^clear %^WHITE%^portion of "
"the paper, you can see ripples of %^ORANGE%^orange %^WHITE%^and white. A "
"creamy %^RESET%^%^ORANGE%^orange %^BOLD%^%^WHITE%^scent rolls off the "
"taffy.%^RESET%^");
    ob->set_my_mess("%^BOLD%^%^GREEN%^An extra creamy mix of %^YELLOW%^citrus "
"%^GREEN%^and %^WHITE%^vanilla %^GREEN%^teases your mouth as the%^YELLOW%^ "
"soft taffy %^GREEN%^is chewed.%^RESET%^");
    ob->set_your_mess("%^RESET%^%^ORANGE%^unwraps the %^WHITE%^candy "
"%^ORANGE%^and pops it into their mouth, chewing eagerly. The delicate scent "
"of %^YELLOW%^citrus %^RESET%^ORANGE%^fills the air.%^RESET%^");
    break;

    case 2:
    ob->set_long("%^BOLD%^%^WHITE%^The candy is wrapped in a%^GREEN%^ "
"r%^YELLOW%^a%^MAGENTA%^i%^RESET%^%^GREEN%^nb%^RED%^o%^GREEN%^w "
"%^BOLD%^%^WHITE%^hue of colors. Through a %^CYAN%^clear %^WHITE%^portion of "
"the paper, you can see ripples of %^BLUE%^blue %^WHITE%^and white. A creamy "
"%^RESET%^%^CYAN%^blueberry %^BOLD%^%^WHITE%^scent rolls off the "
"taffy.%^RESET%^");
    ob->set_my_mess("%^BOLD%^%^GREEN%^An extra creamy mix of%^CYAN%^ "
"blueberries %^GREEN%^and %^WHITE%^vanilla %^GREEN%^teases your mouth as the "
"%^YELLOW%^soft taffy %^GREEN%^is chewed.%^RESET%^");
    ob->set_your_mess("%^BOLD%^%^BLUE%^unwraps the %^WHITE%^candy %^BLUE%^and "
"pops it into their mouth, chewing eagerly. The delicate scent of "
"%^RESET%^CYAN%^blueberries %^BOLD%^%^BLUE%^fills the air.%^RESET%^");
    break;

    case 3:
    ob->set_long("%^BOLD%^%^WHITE%^The candy is wrapped in a%^GREEN%^ "
"r%^YELLOW%^a%^MAGENTA%^i%^RESET%^%^GREEN%^nb%^RED%^o%^GREEN%^w "
"%^BOLD%^%^WHITE%^hue of colors. Through a %^CYAN%^clear %^WHITE%^portion of "
"the paper, you can see ripples of %^RESET%^%^MAGENTA%^purple "
"%^BOLD%^%^WHITE%^and white. A creamy%^RESET%^%^MAGENTA%^ "
"g%^BOLD%^ra%^RESET%^%^MAGENTA%^p%^BOLD%^e %^WHITE%^scent rolls off the "
"taffy.%^RESET%^");
    ob->set_my_mess("%^BOLD%^%^GREEN%^An extra creamy mix of%^MAGENTA%^ "
"grapes %^GREEN%^and %^WHITE%^vanilla %^GREEN%^teases your mouth as the "
"%^YELLOW%^soft taffy %^GREEN%^is chewed.%^RESET%^");
    ob->set_your_mess("%^RESET%^%^MAGENTA%^unwraps the %^WHITE%^candy "
"%^MAGENTA%^and pops it into their mouth, chewing eagerly. The delicate scent "
"of %^BOLD%^MAGENTA%^grapes %^RESET%^%^MAGENTA%^fills the air.%^RESET%^");
    break;
  }
  taffies--;
  return 1;
}

int apricot_fun(string str){
  object ob;
  if(!str) {
    notify_fail("What do you want to pick?\n");
    return 0;
  }
  if(str != "apricots" && str != "apricot") {
    notify_fail("You can't pick that.\n");
    return 0;
  }
  if(!apricots) {
    tell_object(TP,"There don't seem to be any left to pick.");
    return 1;
  }
  tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" reaches out to pick an "
"%^YELLOW%^apricot%^WHITE%^.%^RESET%^",TP);
  tell_object(TP,"%^BOLD%^%^WHITE%^You reach out and pick an "
"%^YELLOW%^apricot%^WHITE%^.%^RESET%^");
  ob = new(OBJ"food");
  ob->move(TP);
  ob->set_id(({"fruit","food","apricot"}));
  ob->set_short("%^YELLOW%^A plump %^RESET%^%^ORANGE%^a%^BOLD%^p%^RESET%^"
"%^ORANGE%^r%^BOLD%^i%^RESET%^%^ORANGE%^c%^BOLD%^ot %^RESET%^");
  ob->set_long("%^YELLOW%^The %^ORANGE%^a%^BOLD%^p%^RESET%^%^ORANGE%^r%^BOLD%^"
"i%^RESET%^%^ORANGE%^c%^BOLD%^ot has a slight %^RED%^red hue %^YELLOW%^on its "
"otherwise yellow flesh and smells %^WHITE%^deliciously sweet.%^RESET%^");
  ob->set_my_mess("%^ORANGE%^The fruit is a delightful addition to your "
"tongue.%^RESET%^");
  ob->set_your_mess("%^RESET%^%^ORANGE%^sighs with contentment as they "
"enjoy the apricot.%^RESET%^");
  apricots--;
  return 1;
}

int grapes_fun(string str){
  object ob;
  if(!str) {
    notify_fail("What do you want to pluck?\n");
    return 0;
  }
  if(str != "grapes") {
    notify_fail("You can't pluck that.\n");
    return 0;
  }
  if(!grapes) {
    tell_object(TP,"There don't seem to be any left to pluck.");
    return 1;
  }
  tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" reaches out to pluck some "
"%^MAGENTA%^grapes%^WHITE%^.%^RESET%^",TP);
  tell_object(TP,"%^BOLD%^%^WHITE%^You reach out and pluck some "
"%^MAGENTA%^grapes%^WHITE%^.%^RESET%^");
  ob = new(OBJ"food");
  ob->move(TP);
  ob->set_id(({"fruit","food","grapes"}));
  ob->set_short("%^RESET%^%^MAGENTA%^a %^BOLD%^plump%^RESET%^%^MAGENTA%^ "
"cluster of g%^BOLD%^r%^RESET%^%^MAGENTA%^ap%^MAGENTA%^es%^RESET%^");
  ob->set_long("%^MAGENTA%^The grapes are fat with %^BOLD%^%^WHITE%^ripeness "
"%^RESET%^%^MAGENTA%^and vary from %^WHITE%^pale %^MAGENTA%^to "
"%^BOLD%^%^BLACK%^dark %^RESET%^%^MAGENTA%^purple. They have a strong, "
"%^BOLD%^sweet smell %^RESET%^%^MAGENTA%^that is popular in many dessert "
"wines.%^RESET%^");
  ob->set_my_mess("%^MAGENTA%^The %^BOLD%^grapes %^RESET%^%^MAGENTA%^are "
"ripe in your mouth, leaving a %^WHITE%^dessert-like %^MAGENTA%^sweetness on "
"your tongue.%^RESET%^");
  ob->set_your_mess("%^RESET%^%^MAGENTA%^pops a %^BOLD%^grape "
"%^RESET%^%^MAGENTA%^into their mouth.%^RESET%^");
  grapes--;
  return 1;
}

int berries_fun(string str){
  object ob;
  if(!str) {
    notify_fail("What do you want to gather?\n");
    return 0;
  }
  if(str != "berries") {
    notify_fail("You can't gather that.\n");
    return 0;
  }
  if(!berries) {
    tell_object(TP,"There don't seem to be any left to gather.");
    return 1;
  }
  tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" gathers up a few "
"%^BLUE%^berries%^WHITE%^.%^RESET%^",TP);
  tell_object(TP,"%^BOLD%^%^WHITE%^You gather up a few "
"%^BLUE%^berries%^WHITE%^.%^RESET%^");
  ob = new(OBJ"food");
  ob->move(TP);
  ob->set_id(({"fruit","food","berries"}));
  ob->set_short("%^RESET%^%^GREEN%^a %^BOLD%^handful %^RESET%^%^GREEN%^of "
"%^MAGENTA%^b%^BOLD%^e%^BLUE%^rr%^BOLD%^%^WHITE%^i%^MAGENTA%^e%^RESET%^"
"%^MAGENTA%^s%^RESET%^");
  ob->set_long("%^GREEN%^The %^BOLD%^tiny fruits %^RESET%^%^GREEN%^are a "
"mixture of %^BOLD%^%^BLUE%^blueberries %^RESET%^%^GREEN%^and%^BOLD%^%^RED%^ "
"raspberries, %^RESET%^%^GREEN%^all %^MAGENTA%^ripe %^GREEN%^for "
"eating.%^RESET%^");
  ob->set_my_mess("%^CYAN%^The %^BOLD%^b%^MAGENTA%^e%^CYAN%^rries "
"%^RESET%^%^CYAN%^are ripe in your mouth, leaving a tart %^RED%^sweetness "
"%^CYAN%^on your tongue.%^RESET%^");
  ob->set_your_mess("%^RESET%^%^CYAN%^pops a few %^RED%^b%^BLUE%^e"
"%^MAGENTA%^r%^BOLD%^r%^RED%^i%^RESET%^%^RED%^e%^BOLD%^%^BLUE%^s "
"%^RESET%^%^CYAN%^into their mouth, eating them with a smile.%^RESET%^");
  berries--;
  return 1;
}
