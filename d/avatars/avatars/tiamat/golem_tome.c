#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("book of golem creation");
	set_id(({ "book", "tome", "manual" }));
	set_short("%^RESET%^%^ORANGE%^Tome of Golem Creation%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^Tome of Golem Creation%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^ORANGE%^This is a thick tome, bound in leather and filled with aging paper.  The leather is dry and cracking slightly, and reinforced with %^BOLD%^brass fittings%^RESET%^%^ORANGE%^.  The cover is blazoned with arcane runes which are difficult to decipher.  With a snap, the brass hinge opens, allowing you to read the material.  The pages are yellowing with age and covered with rust colored foxing.  Despite the minor deterioration, the pages are highly detailed with grafts and illustrations.%^RESET%^

AVATAR
	);
	set("read",
@AVATAR
The material in the book is long and complex.  Consuming all of its information might take a week or more, even for a brilliant mage.  Of particular interest is the component list for creating a golem.  The requirements are summarized below.

%^BOLD%^%^GREEN%^^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^

%^RESET%^%^RED%^ The golems require a body to be crafted by a master smith, preferably the wizard herself, although many choose to enlist the help of master artisans.  The shell of the body must be crafted from the metal of the designers choosing.  The stronger the metal, the more protected the finished golem.%^RESET%^

%^RESET%^%^BLUE%^The enchanted must read and know the material found within the %^BOLD%^Book of Golem Creation%^RESET%^%^BLUE%^.  If the directions are not properly followed, there is the danger of the golem either malfunctioning or exploding.%^RESET%^

%^RESET%^%^GREEN%^The construction requires appropriate laboratory or workroom space.  The process of enchanting will require that various potions be boiled, so fire is necessary.  There must be room to accommodate the entire body length of the golem.  Access to other magical reagents are preferred.%^RESET%^

%^RESET%^%^MAGENTA%^A special power source must be developed for the golem.  This step is highly dependant on the specialty of the wizard.  For a necromancer, the easiest way to store this power is by stealing the life energy from a very powerful creature.  The energy is to be stored is a special cell that is built within to the golem.%^RESET%^

%^RESET%^%^ORANGE%^After all of the components are assembled, the enchanting process requires a great deal of attention from the wizard and/or her assistants.  The enchanting ritual is expected to require at least a week's time.%^RESET%^ 

%^BOLD%^%^GREEN%^^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^


AVATAR
	);
     set("langage","common");	set_weight(2);
	set_value(900);
	set_lore(
@AVATAR
The Book of Golem creation, also called the Tome of Golem Creation is a minor artifact dating back far into the Realm's magical past.  Unlike many of these objects, the power is not housed in its material essence, but rather its knowledge.  Few mages are capable of copying a Book in its entirety, which has led to a tradition of lending the few existing copies among certain magical communities.  The object is priceless.


AVATAR
	);
	set_property("lore difficulty",15);
}