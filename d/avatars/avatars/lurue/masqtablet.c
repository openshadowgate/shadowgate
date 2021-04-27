#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("tablet");
	set_id(({ "tablet" }));
	set_short("%^BOLD%^%^WHITE%^an important looking tablet%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^an important looking tablet%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^WHITE%^Important information about your Masquerade Character:%^RESET%^ This character is a temporary log in and will be rid shortly after the masquerade is over.  %^RED%^Do not %^RESET%^attempt to take it out of the party area and into the main mud.  You will needed to use $R in your adjective (such as $Roid for humanoid) and all NPCs are designed as humans with common language and perfect sight, regardless of your original form.  This is to help cut down on issues.  We know its not perfect, but its what we have.  Your NPC has brown eyes/hair, but you can describe and adjective them as anything you like, just remember you have to use $R in your adjective.  Also, you should have a costume of some sort so that you can enter the contest.  %^RED%^Finally:%^RESET%^ NPCs are Level 30 with 10s in their stats. We have declared the contest area as a %^RED%^no pk zone%^RESET%^ so feel free to stir trouble, just no weapons/spells/attacks.%^RESET%^

AVATAR
	);
	set_weight(0);
	set_value(0);
}
