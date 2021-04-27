#include <std.h>
inherit "/d/common/obj/jewelry/necklace";

void create(){
	::create();
	set_name("prism of forethought");
	set_id(({ "prism", "crystal", "crystal prism", "pendant" }));
	set_short("%^BOLD%^%^MAGENTA%^P%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^s%^BOLD%^%^MAGENTA%^m %^CYAN%^of %^MAGENTA%^F%^RESET%^%^CYAN%^o%^BOLD%^r%^RESET%^%^MAGENTA%^e%^BOLD%^t%^CYAN%^h%^MAGENTA%^o%^RESET%^%^MAGENTA%^u%^BOLD%^%^CYAN%^g%^RESET%^%^CYAN%^h%^BOLD%^%^MAGENTA%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^a r%^RESET%^%^MAGENTA%^e%^CYAN%^f%^BOLD%^r%^RESET%^%^MAGENTA%^a%^BOLD%^c%^CYAN%^t%^RESET%^%^CYAN%^i%^MAGENTA%^v%^BOLD%^e c%^RESET%^%^CYAN%^r%^BOLD%^y%^MAGENTA%^s%^CYAN%^t%^RESET%^%^CYAN%^a%^BOLD%^%^MAGENTA%^l p%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^s%^BOLD%^%^MAGENTA%^m%^RESET%^");
	set_long("%^MAGENTA%^This s%^BOLD%^m%^RESET%^oo%^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^h, trapezoidal %^BOLD%^p%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^s%^BOLD%^%^MAGENTA%^m %^RESET%^%^MAGENTA%^is %^WHITE%^c"
	"lear %^MAGENTA%^and %^WHITE%^c%^BOLD%^o%^RESET%^l%^BOLD%^o%^RESET%^r%^BOLD%^l%^RESET%^e%^BOLD%^s%^RESET%^s%^MAGENTA%^, and what light passes through the crystal emerges again in a %^BOLD%^%^GREEN%^cri"
	"sp%^RESET%^%^MAGENTA%^, %^BOLD%^%^RED%^r%^ORANGE%^a%^GREEN%^i%^CYAN%^n%^MAGENTA%^b%^RED%^o%^ORANGE%^w%^CYAN%^-%^MAGENTA%^h%^RED%^u%^GREEN%^e%^ORANGE%^d %^RED%^s%^ORANGE%^p%^GREEN%^e%^CYAN%^c%^MAGENTA%"
	"^t%^GREEN%^r%^ORANGE%^u%^RED%^m%^RESET%^%^MAGENTA%^. The trinket seems to hold some other value, however, even beyond mere coin. Drawing one's gaze ever deeper into its depths, you can't help but feel"
      " that some manner of %^CYAN%^guidance %^MAGENTA%^is to be found hidden within.%^WHITE%^");
    set_lore("%^MAGENTA%^The practice of %^BOLD%^attuning%^RESET%^%^MAGENTA%^"
", the embedding of thought within a crystalline pattern,"
" dates back almost to the advent of psionics itself, and is"
" so common to the psionically-gifted as to be considered a"
" triviality. It's drawback is also well understood:"
" extracting the thought again nearly always compromises"
" the crystal's integrity, rendering it dull and worthless."
" Still, it is said that the city of Syenit is home to"
" masters possessed of such granular control as to attune"
" crystal with flawless precision, so that it might be read"
" at will without ever degrading in quality. These crystals"
" are most often instilled with the insights of their"
" creators, and gifted to aspiring psionicists as a focus"
" and teaching tool.%^WHITE%^\n \n%^MAGENTA%^Within this"
" prism dwells the wisdom of a great %^YELLOW%^seer"
"%^RESET%^%^MAGENTA%^. A wealth of experiences and discovery"
" can be found within, overlayed into a simple message:"
   " %^BOLD%^%^CYAN%^To grasp eternity, first capture the"
   " present.%^MAGENTA%^%^RESET%^");
set_property("lore difficulty",20);
	set_value(20000);
	set_item_bonus("perception",2);
	set_item_bonus("reflex",1);
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}

int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" somehow affixes the %^BOLD%^%^CYAN%^b%^WHITE%^ri%^MAGENTA%^l%^WHITE%^l%^MAGENTA%^i%^WHITE%^an%^CYAN%^t %^RESET%^%^CYAN%^p%^BOLD%^r%^GREEN%^i%^CYAN%^s%^RESET%^%^CYAN%^m %^MAGENTA%^to their person.%^WHITE%^",ETO);
	tell_object(ETO,"%^MAGENTA%^You catch a nigh-imperceptible %^CYAN%^gl%^BOLD%^i%^RESET%^%^CYAN%^mm%^BOLD%^e%^RESET%^%^CYAN%^r %^MAGENTA%^from the prism as you secure it to your person. Your awareness seems to %^CYAN%^s%^BOLD%^ha%^WHITE%^r%^CYAN%^pe%^RESET%^%^CYAN%^n%^MAGENTA%^.%^WHITE%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" removes the brilliant prism.",ETO);
	tell_object(ETO,"%^MAGENTA%^Your sharpened senses %^CYAN%^fade %^MAGENTA%^to normal, leaving you to reflect on what you've learned from the prism's teachings.%^WHITE%^");
	return 1;
}

