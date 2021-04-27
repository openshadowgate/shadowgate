#include <std.h>
inherit "/d/common/obj/jewelry/ring";

void create(){
	::create();
	set_name("Lion's Sigil");
	set_id(({ "ring of protection", "band", "ring", "white-gold band", "sigil", "lion's sigil" }));
	set_short("%^RESET%^%^BOLD%^L%^CYAN%^i%^ORANGE%^o%^WHITE%^n's S%^CYAN%^i%^WHITE%^g%^ORANGE%^i%^WHITE%^l%^RESET%^");
	set_obvious_short("%^RESET%^%^BOLD%^a %^ORANGE%^g%^WHITE%^l%^ORANGE%^e%^WHITE%^a%^ORANGE%^m%^WHITE%^in%^ORANGE%^g %^WHITE%^w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e-g%^RESET%^o%^BOLD%^ld band%^RESET%^");
	set_long("%^BOLD%^This %^RESET%^delicate%^BOLD%^, white-gold band is quite light, yet it carries an odd weight all its own, seeming to emanate a %^RESET%^%^RED%^warm %^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^resol"
	"ute %^BOLD%^%^WHITE%^aura. Set into the shimmering metal is the engraving of a %^ORANGE%^mighty lion%^WHITE%^, head held high and fangs bared in a great %^RED%^r%^RESET%^%^ORANGE%^o%^BOLD%^a%^RED%^r %"
	"^WHITE%^that seems to leave the band %^RESET%^%^ORANGE%^thrumming %^BOLD%^%^WHITE%^with a faint v%^RESET%^i%^BOLD%^b%^RESET%^r%^BOLD%^a%^RESET%^t%^BOLD%^i%^RESET%^o%^BOLD%^n in its wake. At the lion's"
	" feet, a message is inscribed in a f%^BLACK%^l%^RESET%^o%^BOLD%^w%^RESET%^i%^BOLD%^%^BLACK%^n%^WHITE%^g, %^BLACK%^darkened script%^WHITE%^.%^RESET%^
"	);
	set_value(20000);
	set_lore("%^YELLOW%^One Roar in the Dark%^RESET%^

%^BOLD%^%^BLACK%^The war was all but lost, and the jungle had fallen into eternal shadow. The forces of darkness plunged deep into the heart of the land, turni"
	"ng aside each would-be defender with merciless efficiency. The hawks lost sight of the darkened land and circled aimlessly in the sky, their keen sight turned useless. The snakes slithered away in fea"
	"r, hoping to remain underfoot and unnoticed by the invading enemy. The rats succumbed to their basest instincts, gorging themselves upon the dead even as the jungle was ravaged. The prideful gorillas "
	"threw themselves blindly upon the enemy, yet found themselves outflanked and cut down. And the scheming jackals set fruitless traps and lay in wait, certain that they would soon catch the shadows in a"
	" clever ambush that would never come.%^RESET%^

%^ORANGE%^A sole lion stood upon the last patch of unspoilt grass, the shadows teeming around him and hissing mockeries. His right flank torn open in ba"
	"ttle, he could make no attempt to strike against his foes, but he did not cower or concede, his head held high and resolute as he took in the breath for one last, defiant roar.%^WHITE%^

%^BOLD%^%^BLA"
	"CK%^The shadows laughed, and goaded him. '%^RESET%^Scream as you like, lion! Your land is lost! Have you not seen your allies scattered before us, victims to their own shortcomings? Even your great st"
	"rength is sapped, and you stand alone! What then is your aim, cat? What is one roar in the dark?%^BOLD%^%^BLACK%^'%^RESET%^

%^CYAN%^Never again will a sound be made that shook the land so mightily, n"
	"or cast the shadows back with such force as the roar the lion let out in this moment. It tore through the air with such ferocity that the sky itself was set aflame, calling down a pillar of brilliant "
	"blue flame about the great cat, washing the jungle in clear and resounding light.%^WHITE%^

%^BOLD%^%^CYAN%^The shadows had scarcely recovered before they felt the hawks' razor-sharp talons upon them,"
	" their sight restored the flame's light. The shadows scrambled to reform their ranks, yet found themselves entangled underfoot by the snakes, their keen instincts tempered with the lion's bravery. Ins"
	"pired with newfound discipline, the gorillas struck once more upon the enemy, the roar resounding through the air like a steady war drum. The shadows fled in a panic, only to find themselves routed by"
	" the jackals, now able to read their enemy to much greater effect. The shadows burrowed into the ground in one last, desperate attempt to escape, yet even there the rats hunted them down in the darkne"
	"ss, the drive of a righteous cause firm in their hearts. Until at last, the shadows had all perished.%^RESET%^

%^BOLD%^One roar began in the dark, but it ended in the light.%^RESET%^
"	);
	set_property("lore difficulty",20);
	set_item_bonus("will",1);
	set_item_bonus("negative energy resistance",10);
      set("read","%^BOLD%^%^BLACK%^What then is your aim, cat? %^YELLOW%^What is one roar in the dark?%^RESET%^");
      set("language","common");
	set_size(2);
	set_property("enchantment",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
   object *stuff;
   int i,j, flag;

   stuff = ETO->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++) {
     if(!objectp(stuff[i])) continue;
     if((string)stuff[i]->query_type() == "ring") {
       if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         flag = 1;
         break;
       }
     }
   }
   if(flag) {
     write("The magic of the ring already worn prevents you from wearing this one!");
     return 0;
   }

	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips on the white-gold band. %^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^You slip on the white-gold band, and hear the echoing of a %^CYAN%^lion's roar %^WHITE%^in the distance.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" slips off the white-gold band.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^Slipping off the band, you hear the content yawn of a %^CYAN%^lion %^WHITE%^in the distance, its duty fulfilled.%^RESET%^");
	return 1;
}

