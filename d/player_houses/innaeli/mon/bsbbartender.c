#include <std.h>
inherit BARKEEP;

// The Bloody Scourage Inn (Innaeli & Anson's HM 'home')
// Design Work Written by Innaeli 
// Put into game December 2008 :: Nienne 
// Wizard assisted by Lurue 

void create() {
  ::create();
  set_property("no bump", 1);
  set_name("bartender");
  set_alignment(5);
  set("race","human");
  set_level(15);
  set("aggressive", 0);
  set_hd(12,2);   
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_mp(random(400));
  set_max_mp(query_mp());
  add_money("copper", random(20));
  set_exp(20);
  set_body_type("human");
  set_currency("silver");
  set_spoken("wizish");

  if(random(2)) {
    set_id( ({"bartender","barkeep","farah","Farah","Farah Laneigh","farah laneigh"}) );
    set_short("%^BOLD%^%^WHITE%^Farah Laneigh the Barkeep%^RESET%^");
    set_long("%^RESET%^Farah is a %^BOLD%^q%^RESET%^ui%^BOLD%^et "+
  "y%^RESET%^ou%^BOLD%^n%^RESET%^g wo%^BOLD%^%^WHITE%^m%^RESET%^a"+
  "%^BOLD%^%^WHITE%^n%^RESET%^ with a %^RESET%^%^MAGENTA%^shy%^RESET%^ "+
  "smile and %^BOLD%^%^WHITE%^sparkling %^BOLD%^%^CYAN%^a%^RESET%^"+
  "%^CYAN%^z%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^e "+
  "e%^RESET%^%^CYAN%^ye%^BOLD%^%^CYAN%^s%^RESET%^. Her l%^BOLD%^"+
  "%^WHITE%^o%^RESET%^ng %^BOLD%^%^BLACK%^black hair%^RESET%^ is "+
  "pulled into a knot atop her head, but a few loose tendrils frame "+
  "the delicate features of her pretty face. She is dressed in a "+
  "%^BOLD%^%^BLACK%^bla%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^k an%^RESET%^"+
  "%^RED%^d re%^BOLD%^%^BLACK%^d le%^RESET%^%^RED%^at%^BOLD%^%^BLACK%^"+
  "h%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r bo%^RESET%^%^RED%^d%^BOLD%^"+
  "%^BLACK%^ice%^RESET%^ that barely covers her chest, a s%^BOLD%^"+
  "%^BLACK%^h%^RESET%^ort %^BOLD%^%^BLACK%^black leather skirt"+
  "%^RESET%^ that leaves little to the imagination, and %^BOLD%^"+
  "%^BLACK%^thi%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^h-hi%^RESET%^%^RED%^"+
  "g%^BOLD%^%^BLACK%^h %^RESET%^%^RED%^s%^BOLD%^%^BLACK%^tocki"+
  "%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^gs%^RESET%^ coupled with "+
  "%^BOLD%^%^BLACK%^black heels%^RESET%^. Her left hip bares a small "+
  "%^BOLD%^%^BLACK%^tattoo%^RESET%^ of a %^BOLD%^%^BLACK%^coiled "+
  "%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^co%^RESET%^%^RED%^u%^BOLD%^"+
  "%^BLACK%^rg%^RESET%^%^RED%^e%^RESET%^.");
    set_gender("female");
    command("say sweetly");
    set_emotes(1,({"%^BOLD%^%^WHITE%^Farah struts over to an unruly "+
		"soldier and %^RESET%^cracks%^BOLD%^%^WHITE%^ a %^BOLD%^"+
		"%^BLACK%^w%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^ip%^BOLD%^"+
		"%^WHITE%^ on the table, sending him flopping over into his "+
		"chair.%^RESET%^\n%^BOLD%^%^WHITE%^His friends laugh and "+
		"cheer as Farah returns to her work with a %^RESET%^"+
		"%^RED%^wry%^BOLD%^%^WHITE%^ smile.%^RESET%^",
    "%^BOLD%^%^WHITE%^Jumping onto the bar, Farah sways her hips in "+
		"a %^RESET%^%^RED%^s%^BOLD%^%^RED%^u%^RESET%^%^RED%^ltry "+
		"%^BOLD%^%^RED%^d%^RESET%^%^RED%^an%^BOLD%^%^RED%^c%^RESET%^"+
		"%^RED%^e%^BOLD%^%^WHITE%^, much to the delight of the men "+
		"in the room!%^RESET%^\n%^BOLD%^%^WHITE%^Jeers fill the "+
		"room as she steps down from the bar, laughing.%^RESET%^",
    "%^BOLD%^%^WHITE%^Farah sits on the lap of a young man, %^BOLD%^"+
		"%^MAGENTA%^gi%^RESET%^%^MAGENTA%^g%^BOLD%^%^MAGENTA%^gl"+
		"%^RESET%^%^MAGENTA%^in%^BOLD%^%^MAGENTA%^g%^BOLD%^%^WHITE%^ "+
		"as he %^RESET%^whispers%^BOLD%^%^WHITE%^ in her ear."+
		"%^RESET%^ "}),0); 
  }
  else {
    set_id( ({"bartender","barkeep","amfilios","Amfilios","Amfilios DeVaughn","amfilios devaughn"}) );
    set_short("%^BOLD%^%^WHITE%^Amfilios DeVaughn the Barkeep%^RESET%^");
    set_long("%^RESET%^Amfilios is a dapper young man clad in a "+
  "suit of %^BOLD%^%^BLACK%^black leather%^RESET%^. He wears a "+
  "%^BOLD%^%^WHITE%^r%^RESET%^uf%^BOLD%^fl%^RESET%^e%^BOLD%^d"+
  "%^RESET%^ %^RESET%^%^RED%^red shirt%^RESET%^ beneath his "+
  "%^BOLD%^%^BLACK%^black blazer%^RESET%^, %^BOLD%^%^BLACK%^black "+
  "leather pants%^RESET%^, and %^BOLD%^sh%^RESET%^in%^BOLD%^in"+
  "%^RESET%^g %^BOLD%^%^BLACK%^black boots%^RESET%^. His %^BOLD%^"+
  "%^BLACK%^d%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^rk hair%^RESET%^ "+
  "just reaches his shoulders, and he sports a bit of %^BOLD%^"+
  "%^BLACK%^s%^RESET%^tu%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^b"+
  "%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET%^ on his pleasantly "+
  "chiseled face. His %^RESET%^%^ORANGE%^de%^BOLD%^%^BLACK%^e"+
  "%^RESET%^%^ORANGE%^p brown e%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^"+
  "es%^RESET%^ are quick to give a %^RESET%^%^MAGENTA%^c%^BOLD%^ha"+
  "%^RESET%^%^MAGENTA%^rmi%^BOLD%^n%^RESET%^%^MAGENTA%^g wi%^BOLD%^"+
  "n%^RESET%^%^MAGENTA%^k%^RESET%^ to the women in his vicinity. "+
  "He is quite skilled at his job, and he certainly doesnt mind "+
  "showing off.%^RESET%^");
    set_gender("male");
    command("grins as he speaks");
    set_emotes(1,({"%^BOLD%^%^WHITE%^Amfilios tosses a glass high in "+
		"the air and catches it behind his back before filling it to the "+
		"brim and sliding it down the bar toward a drunk, old man."+
		"%^RESET%^\n%^BOLD%^%^WHITE%^There is a roar of %^BOLD%^"+
		"%^CYAN%^d%^RESET%^%^CYAN%^ru%^BOLD%^%^CYAN%^nk%^RESET%^%^CYAN%^"+
		"e%^BOLD%^%^CYAN%^n %^RESET%^%^CYAN%^c%^BOLD%^%^CYAN%^he%^RESET%^"+
		"%^CYAN%^er%^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^ and %^BOLD%^"+
		"%^CYAN%^ap%^RESET%^%^CYAN%^pl%^BOLD%^%^CYAN%^au%^RESET%^%^CYAN%^"+
		"s%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^ at the spectacle!%^RESET%^",
    "%^BOLD%^%^WHITE%^Amfilios hands a %^RESET%^%^MAGENTA%^pretty"+
		"%^BOLD%^%^WHITE%^ young woman a drink and a %^RESET%^%^GREEN%^"+
		"l%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^ng-s%^BOLD%^%^GREEN%^te"+
		"%^RESET%^%^GREEN%^mm%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^d "+
		"%^BOLD%^%^RED%^c%^RESET%^%^RED%^rim%^BOLD%^%^RED%^so%^RESET%^"+
		"%^RED%^n r%^BOLD%^%^RED%^o%^RESET%^%^RED%^se%^BOLD%^%^WHITE%^."+
		"%^RESET%^\n%^BOLD%^%^WHITE%^She giggles and blushes before "+
		"returning to her table of friends.%^RESET%^",
    "%^BOLD%^%^WHITE%^Amfilios' gaze passes over the bar and lands on a "+
                "%^RESET%^%^CYAN%^drunken%^BOLD%^%^WHITE%^ patron. Stepping "+
                "over to the man, Amfilios takes a moment to discuss something "+
                "with the man before helping him stagger out the door.\n"+
                "%^BOLD%^%^WHITE%^A few minutes later, Amfilios comes back "+
                "inside, wiping a bit of %^BLACK%^something%^WHITE%^ from his "+
                "hands.%^RESET%^",
    "%^BOLD%^%^WHITE%^A patron begins to argue with Amfilios about which "+
                "drink he wanted.\n %^BOLD%^%^WHITE%^With a %^CYAN%^s"+
                "%^WHITE%^l%^RESET%^%^CYAN%^y%^BOLD%^%^WHITE%^ grin, Amfilios "+
                "apologizes and offers the man a glass of the %^RESET%^ "+
                "%^MAGENTA%^house special%^BOLD%^%^WHITE%^. \n %^BOLD%^%^WHITE%^"+
                "As the man drinks the tall %^MAGENTA%^f%^WHITE%^o%^RESET%^"+
                "a%^MAGENTA%^m%^BOLD%^i%^RESET%^%^MAGENTA%^n%^BOLD%^g"+
                "%^WHITE%^ drink he quickly becomes calm and placid.\n "+
                "%^BOLD%^%^WHITE%^A bit later, the patron is no where to be "+
                "found.%^RESET%^",
    "%^BOLD%^%^WHITE%^Grabbing a young woman by the waist, "+
		"Amifilios %^RESET%^%^CYAN%^twirls%^BOLD%^%^WHITE%^ her in "+
		"a %^RESET%^%^CYAN%^graceful dan%^BOLD%^%^CYAN%^c%^RESET%^"+
		"%^CYAN%^e%^BOLD%^%^WHITE%^ before returning to his work."+
               "%^RESET%^",}),0);
  }
  
  set_menu(
      ({"tyrs tears","water","bloody virgin","black widow",
	  "death by fire","dragons blood","bloody scourge","tequila",
	  "whiskey","dark rum","vodka","talassan black",
	  "amber lager","noblemans special","feywine","blood wine",
	  "moon wine","fried cheese","soft pretzel",
	  "spicy chicken wings","bloody steak","flaming chicken",
	  "braised ribs","chefs stew","vanilla ice cream",
	  "chocolate chip cake","chocolate strawberries"}),
      ({"soft drink","soft drink","soft drink","alcoholic",
	  "alcoholic","alcoholic","alcoholic","alcoholic","alcoholic",
	  "alcoholic","alcoholic","alcoholic","alcoholic","alcoholic",
	  "alcoholic","alcoholic","alcoholic","food","food","food",
	  "food","food","food","food","food","food","food"}),
      ({20,5,25,35,40,30,45,35,30,25,30,35,25,15,220,20,35,
	    10,10,10,50,40,40,45,15,15,15}),
	);
  
    set_menu_short(({
	"a glass of fruit juice",
	"a glass of water",
	"a thick orange drink",
	"a black martini drink",
	"a scorched shot glass",
	"a black champagne glass",
	"a crimson-hued drink",
	"a shot glass rimmed with salt",
	"a shot of golden liquid",
	"a shot of amber liquid",
	"a shot of clear liquid",
	"a mug of dark beer",
	"a mug of amber beer",
	"a bottle of pale beer",
	"a glass of feywine",
	"a glass of blood wine",
	"a glass of white wine",
	"a plate of fried cheese",
	"a soft pretzel",
	"a plate of chicken wings",
	"a slab of bloody steak",
        "a grilled chicken sandwich",
	"a rack of messy ribs",
	"a bowl of thick stew",
	"a dish of vanilla ice cream",
	"a thin slice of chocolate chip cake",
	"a plate of chocolate dipped strawberries",
	}));
  
  set_my_mess(({
	"%^BOLD%^%^MAGENTA%^Wow...Fruity!%^RESET%^",
	"The water is cool and refreshing.",
	"The Bloody Virgin feels warm and thick on the way down.",
	"The dark drink is smooth with a bit of a kick.",
	"You slam the drink down!  Hopefully you remember to douse it first!",
	"The frozen, chunky drink slides down your throat.",
	"Your eyes begin to water as your mouth burns.",
	"You slam down the shot of tequila!",
	"You slam down the shot of whiskey!",
	"You slam down the shot of dark rum!",
	"You slam down the shot of vodka!",
	"You take the last swig, finishing the dark brew.",
	"You take the last swig, finishing the lager.",
	"The beer tastes like an ogre's sweaty balls.",
	"%^BOLD%^%^MAGENTA%^You drink the feywine and feel an almost "+
		"magical, blissful peace wash over you as your skin starts "+
		"to tingle all over.  The glass almost slips from your "+
		"hands as you hear a faerie giggling in your ear.  You set "+
		"the glass down, letting the wine take full effect.%^RESET%^",
	"You drink the warm thick red wine, savoring the flavor.",
	"The wine goes down smoothly.",
	"The perfect combination of cheese and grease!",
	"This pretzel is making you thirsty.",
	"You suck the last of the meat from the bones.  Messy!",
	"The steak is bloody and stringy, and the potatoes are chunky "+
		"and filling.",
	"It looked harmless enough, but damn that was spicy!",
        "As you finish off the meat, you begin to wonder what "+
		"unfortunate creature is short a set of ribs.",
	"The mystery stew is quite filling.",
	"The perfect combination of vanilla, chocolate and strawberries.",
	"The cake is sweet, rich and absolutely heavenly.",
	"The strawberries are sweet and delicious!"
	}));
  
  set_your_mess(({
	"sips down a Tyr's Tears.",
	"gulps down a glass of water.",
	"swallows down a thick Bloody Virgin.",
	"sips down a Black Widow.",
	"slams down the Death by Fire!",
	"enjoys a Dragon's Blood.",
	"slams down the drink.. painfully!",
	"slams down the tequila!",
	"slams down the whiskey!",
	"slams down the dark rum!",
	"slams down the vodka!",
	"finishes off the dark beer.",
	"finishes off the Amber Lager.",
	"tips back the bottle and finishes off the beer.",
	"is overcome with an expression of peace and smiles softly.",
	"savors a glass of blood wine.",
	"finishes off a glass of Moon Wine.",
	"looks disappointed after finishing the last of the fried cheese.",
	"eats the whole pretzel and doesn't even share.",
	"finishes the wings, leaving behind a pile of chicken bones.",
	"finishes the steak, leaving behind a puddle of blood on the "+
		"plate.",
	"eats the chicken sandwich and nibbles on a couple fried "+
		"potatoes.",
	"hungrily polishes off the rack of ribs, leaving a clean plate.",
	"finishes off whole bowl of stew.",
	"finishes the ice cream, leaving none for you.",
	"devours the chocolate cake.",
	"eats the last of the chocolate-covered strawberries."
	}));
    
  set_menu_long(({
	"%^RESET%^This is a %^RESET%^%^RED%^f%^MAGENTA%^r%^RED%^u"+
		"%^MAGENTA%^i%^RED%^t%^MAGENTA%^y%^RESET%^ concoction for "+
		"the weak of heart. It is a mixture of fresh %^RESET%^"+
		"%^ORANGE%^apple juice%^RESET%^ with just a twist of "+
		"%^BOLD%^%^MAGENTA%^grape%^RESET%^. It comes served in a "+
		"tall glass with a little %^RESET%^paper umbrella%^RESET%^.",
	
	"%^RESET%^This tall glass of %^BOLD%^%^BLUE%^water%^RESET%^ is "+
		"served with a twist of %^YELLOW%^lemon%^RESET%^.",
	
	"%^BOLD%^%^RED%^This %^RESET%^%^RED%^thick%^BOLD%^%^RED%^ drink "+
		"is made from %^RESET%^%^RED%^tomato juice%^BOLD%^%^RED%^ "+
		"and %^RESET%^%^GREEN%^lime%^BOLD%^%^RED%^, and comes "+
		"served with a %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^e%^BOLD%^"+
		"%^GREEN%^le%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^y s%^RESET%^"+
		"%^GREEN%^t%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^c%^BOLD%^"+
		"%^GREEN%^k%^BOLD%^%^RED%^.%^RESET%^",
	
	"%^BOLD%^%^BLACK%^This drink is a favorite of the ladies. "+
		"%^BOLD%^%^WHITE%^V%^RESET%^o%^BOLD%^%^WHITE%^d%^RESET%^k"+
		"%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^ is mixed with just a "+
		"splash of %^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^sp%^RESET%^"+
		"re%^BOLD%^%^BLACK%^ss%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ "+
		"to give it an extra kick and its dark hue. It comes served "+
		"in a black %^RESET%^%^MAGENTA%^martini glass%^BOLD%^"+
		"%^BLACK%^, garnished with three %^RESET%^%^ORANGE%^c"+
		"%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ff%^BOLD%^%^BLACK%^"+
		"e%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ beans.%^RESET%^",
	
	"%^YELLOW%^This is a potent mixture of %^BOLD%^%^BLACK%^dark "+
		"rum%^YELLOW%^, %^RESET%^%^ORANGE%^amaretto%^YELLOW%^ and "+
		"%^BOLD%^%^BLACK%^whiskey%^YELLOW%^ with a splash of "+
		"something b%^RESET%^%^ORANGE%^u%^YELLOW%^bbl%^RESET%^"+
		"%^ORANGE%^y%^YELLOW%^. It is served in a %^BOLD%^%^BLACK%^"+
		"black glass%^YELLOW%^ with %^BOLD%^%^RED%^f%^RESET%^"+
		"%^RED%^l%^MAGENTA%^a%^ORANGE%^m%^RESET%^%^RED%^e%^BOLD%^"+
		"%^RED%^s%^YELLOW%^ licking at its surface.%^RESET%^",
	
	"%^BOLD%^%^WHITE%^Frozen %^BOLD%^%^BLACK%^bl%^RESET%^%^MAGENTA%^"+
		"a%^BOLD%^%^MAGENTA%^c%^BOLD%^%^BLACK%^kbe%^RESET%^"+
		"%^MAGENTA%^r%^BOLD%^%^BLACK%^rie%^BOLD%^%^MAGENTA%^s"+
		"%^RESET%^ combined with %^RESET%^%^ORANGE%^brandy%^RESET%^ "+
		"and %^BOLD%^vodka%^RESET%^ lends this drink a %^BOLD%^"+
		"%^BLACK%^chunky%^RESET%^ texture and %^BOLD%^%^BLACK%^"+
		"bittersweet%^RESET%^ taste. It comes served in a %^BOLD%^"+
		"%^BLACK%^black champagne glass%^RESET%^, garnished with a "+
		"%^BOLD%^%^MAGENTA%^blac%^RESET%^%^MAGENTA%^k%^BOLD%^"+
		"%^MAGENTA%^b%^BOLD%^%^BLACK%^err%^RESET%^%^MAGENTA%^y"+
		"%^RESET%^.",
	
	"%^RESET%^%^RED%^This thick, %^BOLD%^%^RED%^c%^RESET%^%^RED%^ri"+
		"%^BOLD%^%^RED%^ms%^RESET%^%^RED%^o%^BOLD%^%^RED%^n%^RESET%^"+
		"%^RED%^ drink consists of %^BOLD%^%^RED%^tomato juice"+
		"%^RESET%^%^RED%^, %^RESET%^vodka%^RESET%^%^RED%^, plenty "+
		"of %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t sauce"+
		"%^RESET%^%^RED%^ and %^BOLD%^%^RED%^ca%^RESET%^%^RED%^y"+
		"%^BOLD%^%^RED%^enn%^RESET%^%^RED%^e p%^BOLD%^%^RED%^ep"+
		"%^RESET%^%^RED%^pe%^BOLD%^%^RED%^r%^RESET%^%^RED%^, and a "+
		"secret ingredient. It is served in a %^BOLD%^%^BLACK%^"+
		"black glass%^RESET%^%^RED%^ and garnished with a slice of "+
		"%^BOLD%^%^RED%^chili pepper%^RESET%^%^RED%^.",
	
	"%^BOLD%^%^WHITE%^This crystal clear %^RESET%^tequila%^BOLD%^"+
		"%^WHITE%^ is served in a %^RESET%^%^RED%^red shot glass"+
		"%^RESET%^ rimmed with %^RESET%^salt%^BOLD%^%^WHITE%^, and "+
		"served with a slice of %^YELLOW%^lemon%^BOLD%^%^WHITE%^.",
	
	"%^BOLD%^%^WHITE%^Served in a %^RESET%^%^RED%^red shot glass"+
		"%^BOLD%^%^WHITE%^, the 18-year whiskey is a deep, "+
		"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^"
		"%^ORANGE%^e%^YELLOW%^n%^BOLD%^%^WHITE%^ hue, and it smells "+
		"quite strong.%^RESET%^",
	
	"%^BOLD%^%^WHITE%^This shot of rum is a deep, dark %^YELLOW%^a"+
		"%^RESET%^%^ORANGE%^mb%^YELLOW%^e%^RESET%^%^ORANGE%^r"+
		"%^BOLD%^%^WHITE%^ hue and it smells slightly %^ORANGE%^"+
		"nutty%^BOLD%^%^WHITE%^ with an underlying hint of wood and "+
		"toffee. It is served in a %^RESET%^%^RED%^red shot glass"+
		"%^BOLD%^%^WHITE%^.%^RESET%^",
	
	"%^BOLD%^%^WHITE%^The %^RESET%^clear liquor%^BOLD%^%^WHITE%^ is "+
		"served in a %^RESET%^%^RED%^red shot glass%^BOLD%^"+
		"%^WHITE%^ with a twist of %^YELLOW%^lemon%^BOLD%^"+
		"%^WHITE%^.%^RESET%^",
	
	"%^BOLD%^%^BLACK%^Masterfully brewed, this bitter beer is so "+
		"dark it is practically black, with a %^RESET%^f%^BOLD%^"+
		"%^WHITE%^o%^RESET%^ami%^BOLD%^%^BLACK%^n%^RESET%^g%^BOLD%^"+
		"%^WHITE%^, %^BOLD%^%^WHITE%^c%^RESET%^re%^BOLD%^%^WHITE%^"+
		"am%^RESET%^y he%^BOLD%^%^WHITE%^a%^RESET%^d%^BOLD%^"+
		"%^BLACK%^. It is served in a tall, 20-ounce mug.%^RESET%^",
	
	"%^RESET%^%^ORANGE%^Served in a tall 20-ounce mug, the lager "+
		"is a rich %^YELLOW%^c%^RESET%^%^ORANGE%^o%^YELLOW%^p"+
		"%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^e%^YELLOW%^r%^RESET%^"+
		"%^ORANGE%^ hue with a %^RESET%^foamy %^BOLD%^%^WHITE%^"+
		"white%^RESET%^ head%^RESET%^%^ORANGE%^. It smells sweet "+
		"and delicious.%^RESET%^ ",
	
	"%^RESET%^Favored by many for its %^BOLD%^%^WHITE%^cheap price"+
		"%^RESET%^ and %^BOLD%^%^WHITE%^potency%^RESET%^, this "+
		"beer comes served in a %^RESET%^%^ORANGE%^bottle%^RESET%^ "+
		"and is generally referred to as %^CYAN%^swill%^RESET%^. "+
		"You get what you pay for.",
	
	"%^RESET%^The feywine comes up to the halfway mark in this tall "+
		"wine glass.",
	
	"%^RESET%^This is a glass of blood wine.  It is very thick and "+
		"red and is served warm.  The aroma of this drink makes "+
		"your mouth water.",
	
	"%^BOLD%^%^WHITE%^There are many rumors surrounding the "+
		"creation of %^MAGENTA%^moon wine%^BOLD%^%^WHITE%^. Some "+
		"say it is made from tears gathered from the %^CYAN%^"+
		"weeping moon%^BOLD%^%^WHITE%^ when the days fall into "+
		"darkness. Others say it is a powerful %^RED%^aphrodisiac"+
		"%^BOLD%^%^WHITE%^ drawn from Sunites at the height of "+
		"their lovemaking. Still others say it is simply %^RESET%^"+
		"white wine%^BOLD%^%^WHITE%^, and it comes served in a c"+
		"%^RESET%^ry%^BOLD%^%^WHITE%^st%^RESET%^a%^BOLD%^%^WHITE%^l "+
		"wine glass with tiny shavings of %^RESET%^%^RED%^r%^BOLD%^"+
		"%^RED%^u%^RESET%^%^RED%^b%^BOLD%^%^RED%^i%^RESET%^%^RED%^e"+
		"%^BOLD%^%^RED%^s%^BOLD%^%^WHITE%^ sprinkled on top."+
		"%^RESET%^ ",
	
	"%^BOLD%^%^WHITE%^Mozzarella cheese%^RESET%^ is cut into cubes "+
		"and tossed into a fryer, resulting in this delicious dish. "+
		"It is served on a small %^BOLD%^%^BLACK%^black plate"+
		"%^RESET%^ with %^RESET%^%^RED%^t%^BOLD%^%^RED%^o%^RESET%^"+
		"%^RED%^mat%^BOLD%^%^RED%^o s%^RESET%^%^RED%^a%^BOLD%^"+
		"%^RED%^uc%^RESET%^%^RED%^e%^RESET%^ for dipping.",
	
	"%^RESET%^%^ORANGE%^This thick, %^RESET%^salty%^RESET%^"+
		"%^ORANGE%^ and doughy %^YELLOW%^pretzel%^RESET%^%^ORANGE%^ "+
		"is served warm and with a side of %^YELLOW%^m%^RESET%^"+
		"%^ORANGE%^elte%^YELLOW%^d c%^RESET%^%^ORANGE%^hees"+
		"%^YELLOW%^e%^RESET%^%^ORANGE%^.%^RESET%^ ",
	
	"%^RESET%^The wings are dipped in %^RESET%^%^RED%^spicy %^BOLD%^"+
		"%^BLACK%^c%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^yen%^RESET%^"+
		"%^RED%^n%^BOLD%^%^BLACK%^e pe%^RESET%^%^RED%^p%^BOLD%^"+
		"%^BLACK%^per%^RESET%^%^RED%^ sauce%^RESET%^ and %^BOLD%^"+
		"butter%^RESET%^, and then fried to perfection. Theyre "+
		"served with a side of %^RESET%^ch%^CYAN%^u%^BOLD%^%^WHITE%^"+
		"nk%^BOLD%^%^BLUE%^y b%^BOLD%^%^WHITE%^le%^BOLD%^%^CYAN%^u "+
		"%^BOLD%^%^BLUE%^c%^BOLD%^%^WHITE%^he%^RESET%^%^CYAN%^e"+
		"%^BLUE%^s%^BOLD%^%^WHITE%^e dressing%^RESET%^ and %^BOLD%^"+
		"%^GREEN%^c%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^le%^RESET%^"+
		"%^GREEN%^r%^BOLD%^%^GREEN%^y s%^RESET%^%^GREEN%^tick"+
		"%^BOLD%^%^GREEN%^s%^RESET%^.",
	
	"%^RESET%^%^RED%^The steak comes served one way: %^BOLD%^%^RED%^"+
		"blo%^RESET%^%^RED%^o%^BOLD%^%^RED%^dy%^RESET%^%^RED%^. It "+
		"almost looks alive. Served on a %^BOLD%^%^BLACK%^black plate"+
		"%^RESET%^%^RED%^, the %^BOLD%^%^RED%^bl%^RESET%^%^RED%^o"+
		"%^BOLD%^%^RED%^od%^RESET%^%^RED%^y s%^BOLD%^%^RED%^t"+
                "%^RESET%^%^RED%^ea%^BOLD%^%^RED%^k%^RESET%^%^RED%^ comes "+
		"with a side of %^BOLD%^%^WHITE%^m%^RESET%^as%^BOLD%^h"+
		"%^RESET%^e%^BOLD%^%^WHITE%^d p%^RESET%^ot%^BOLD%^%^WHITE%^"+
		"at%^RESET%^o%^BOLD%^%^WHITE%^es%^RESET%^%^RED%^ topped "+
		"with %^RESET%^butter%^RESET%^%^RED%^ and %^BOLD%^%^WHITE%^"+
		"sour cream%^RESET%^%^RED%^.%^RESET%^",
	
	"%^RESET%^A slender slice of %^BOLD%^%^BLACK%^g%^RESET%^"+
		"%^ORANGE%^ri%^BOLD%^%^BLACK%^ll%^RESET%^%^ORANGE%^e%^BOLD%^"+
		"%^BLACK%^d%^RESET%^%^ORANGE%^ chicken%^RESET%^ is stuck on "+
		"a %^RESET%^%^ORANGE%^bun%^RESET%^ and topped with %^BOLD%^"+
		"%^GREEN%^l%^RESET%^%^GREEN%^et%^BOLD%^%^GREEN%^t%^RESET%^"+
		"%^GREEN%^uc%^BOLD%^%^GREEN%^e%^RESET%^ and a slice of "+
		"%^BOLD%^%^RED%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^m"+
		"%^RESET%^%^ORANGE%^at%^BOLD%^%^RED%^o%^RESET%^. It is "+
		"served with a side of %^RESET%^%^ORANGE%^crunchy fried "+
		"potatoes%^RESET%^.",
	
	"%^RESET%^The rack of %^RESET%^%^ORANGE%^short ribs%^RESET%^ "+
		"comes garnished with a sprig of something %^BOLD%^%^GREEN%^"+
		"g%^RESET%^%^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e"+
		"%^BOLD%^%^GREEN%^n%^RESET%^. The %^RED%^mes%^RESET%^"+
		"%^MAGENTA%^s%^RED%^y %^RESET%^%^ORANGE%^ribs%^RESET%^ are "+
		"served on a large, full plate.",
	
	"%^RESET%^%^ORANGE%^A few pieces of %^BOLD%^%^BLACK%^meat"+
		"%^RESET%^%^ORANGE%^ and %^BOLD%^%^GREEN%^v%^RESET%^"+
		"%^GREEN%^e%^BOLD%^%^RED%^g%^RESET%^%^RED%^e%^BOLD%^"+
		"%^YELLOW%^t%^RESET%^%^YELLOW%^a%^BOLD%^%^RED%^b%^RESET%^"+
		"%^RED%^l%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s%^RESET%^"+
		"%^ORANGE%^ float around in this thick, %^BOLD%^%^BLACK%^"+
		"dark%^RESET%^%^ORANGE%^ stew. It is considered the "+
		"specialty of the cook, but nobody is sure exactly what it "+
		"consists of. Its served in a bowl with a slice of "+
		"%^RESET%^br%^RESET%^%^ORANGE%^e%^RESET%^ad%^RESET%^"+
		"%^ORANGE%^.%^RESET%^",
	
	"%^BOLD%^%^WHITE%^The small dish of %^RESET%^v%^BOLD%^%^WHITE%^"+
		"a%^RESET%^nil%^BOLD%^%^WHITE%^la i%^RESET%^c%^BOLD%^"+
		"%^WHITE%^e c%^RESET%^re%^BOLD%^%^WHITE%^a%^RESET%^m%^BOLD%^"+
		"%^WHITE%^ is drenched in %^BOLD%^%^BLACK%^chocolate sauce"+
		"%^BOLD%^%^WHITE%^ and topped with %^RESET%^%^GREEN%^f"+
		"%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s"+
		"%^RESET%^%^GREEN%^h %^BOLD%^%^RED%^st%^RESET%^%^RED%^ra"+
		"%^BOLD%^%^RED%^wbe%^RESET%^%^RED%^r%^BOLD%^%^RED%^ries"+
		"%^BOLD%^%^WHITE%^. It comes with two spoons for sharing."+
		"%^RESET%^",
	
	"%^BOLD%^%^BLACK%^This thin slice of %^RESET%^%^ORANGE%^ch"+
		"%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^ol"+
		"%^RESET%^%^ORANGE%^ate c%^BOLD%^%^BLACK%^a%^RESET%^"+
		"%^ORANGE%^ke%^BOLD%^%^BLACK%^ is dri%^RESET%^%^ORANGE%^z"+
		"%^BOLD%^%^BLACK%^zl%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d "+
		"in c%^RESET%^%^ORANGE%^ho%^BOLD%^%^BLACK%^col%^RESET%^"+
		"%^ORANGE%^a%^BOLD%^%^BLACK%^te %^RESET%^%^ORANGE%^s%^BOLD%^"+
		"%^BLACK%^au%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^e. Small "+
		"%^RESET%^%^ORANGE%^chips%^BOLD%^%^BLACK%^ of chocolate are "+
		"mixed into the spongy cake, and the whole thing is topped "+
		"with %^RESET%^%^ORANGE%^sweet %^BOLD%^%^BLACK%^chocolate"+
		"%^RESET%^%^ORANGE%^ icing%^BOLD%^%^BLACK%^. A small scoop "+
		"of %^BOLD%^%^WHITE%^va%^RESET%^n%^BOLD%^%^WHITE%^ill"+
		"%^RESET%^a i%^BOLD%^%^WHITE%^c%^RESET%^e %^BOLD%^%^WHITE%^"+
		"cr%^RESET%^ea%^BOLD%^%^WHITE%^m%^BOLD%^%^BLACK%^ is served "+
		"on the side.%^RESET%^",
	
	"%^RESET%^This small plate holds four %^BOLD%^%^WHITE%^massive "+
		"%^RESET%^%^RED%^str%^BOLD%^%^RED%^aw%^RESET%^%^RED%^be"+
		"%^BOLD%^%^RED%^rr%^RESET%^%^RED%^ies%^RESET%^ that have "+
		"been dipped in %^BOLD%^%^BLACK%^ch%^RESET%^%^ORANGE%^o"+
		"%^BOLD%^%^BLACK%^col%^RESET%^%^ORANGE%^at%^BOLD%^%^BLACK%^e"+
		"%^RESET%^ - two in %^BOLD%^%^WHITE%^white chocolate"+
		"%^RESET%^, and two in %^BOLD%^%^BLACK%^dark chocolate"+
		"%^RESET%^. The %^BOLD%^%^RED%^s%^RESET%^%^RED%^tr%^BOLD%^"+
		"%^RED%^aw%^RESET%^%^RED%^b%^BOLD%^%^RED%^errie%^RESET%^"+
		"%^RED%^s%^RESET%^ look freshly picked and still have their "+
		"%^RESET%^%^GREEN%^st%^BOLD%^%^GREEN%^em%^RESET%^%^GREEN%^s"+
		"%^RESET%^.",
	}));
}

void init(){
	::init();
	add_action("buy_em","buy");
}

void receive_given_item(object ob){
	if((string)ob->query_short() == "an empty bottle" ||
	(string)ob->query_name() == "bottle"){
		force_me("emote puts away the empty bottle.");
		ob->remove();
		}
	}

int buy_em(string str){
	if(str == "tyrs tears"){
		if(!random(4)){
		tell_object(TP,"%^BOLD%^%^WHITE%^People roar with laughter as you order "+
					"Tyr's Tears!");
		tell_room(ETO,"%^BOLD%^%^WHITE%^People roar with laughter as "+TPQCN+" orders "+
					"Tyr's Tears!",TP);
		}
	return 0;
	}
	
	if(str == "bloody scourge"){
		if(!random(4)){
		tell_object(TP,"%^BOLD%^%^WHITE%^Rowdy patrons start chanting "+
					"%^RED%^Bloody! %^WHITE%^and soon the shouts "+
					"turn into an uproar! Theres a loud %^BOLD%^"+
					"%^BLACK%^CRACK%^BOLD%^%^WHITE%^ of a whip "+
					"followed by laughter.");
		tell_room(ETO,"%^BOLD%^%^WHITE%^Rowdy patrons start chanting "+
					"%^RED%^Bloody! %^WHITE%^and soon the shouts "+
					"turn into an uproar! Theres a loud %^BOLD%^"+
					"%^BLACK%^CRACK%^BOLD%^%^WHITE%^ of a whip "+
					"followed by laughter as "+TPQCN+" is served"+
					"a Bloody Scourge!",TP);
			}
	return 0;
	}

	if(str == "death by fire"){
		if(!random(4)){
		tell_object(TP,"%^BOLD%^%^WHITE%^Applause and cheers erupt "+
					"around the bar as your %^BOLD%^%^RED%^D"+
					"%^RESET%^%^RED%^eat%^BOLD%^%^RED%^h%^BOLD%^"+
					"%^WHITE%^ by %^BOLD%^%^RED%^F%^RESET%^%^RED%^ir"+
					"%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^ is served "+
					"still %^BOLD%^%^RED%^f%^RESET%^%^RED%^la"+
					"%^MAGENTA%^m%^ORANGE%^i%^RED%^n%^BOLD%^%^RED%^"+
					"g%^BOLD%^%^WHITE%^!%^RESET%^");
		tell_room(ETO,"%^BOLD%^%^WHITE%^Applause and cheers erupt "+
					"around the bar as "+TPQCN+" %^BOLD%^%^RED%^D"+
					"%^RESET%^%^RED%^eat%^BOLD%^%^RED%^h%^BOLD%^"+
					"%^WHITE%^ by %^BOLD%^%^RED%^F%^RESET%^%^RED%^ir"+
					"%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^ is served "+
					"still %^BOLD%^%^RED%^f%^RESET%^%^RED%^la"+
					"%^MAGENTA%^m%^ORANGE%^i%^RED%^n%^BOLD%^%^RED%^"+
					"g%^BOLD%^%^WHITE%^!%^RESET%^",TP);
		}
	return 0;
	}
return 0;
}
