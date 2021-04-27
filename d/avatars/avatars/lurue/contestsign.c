#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("wood sign");
	set_id(({ "sign" }));
	set_short("%^BOLD%^%^MAGENTA%^A sign hung on the side of the stage%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^A sign hung on the side of the stage%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^MAGENTA%^Let it be known and understood that during the Story Telling Contest the following rules apply to all: %^BOLD%^%^WHITE%^The %^CYAN%^Law of Sanctuary %^WHITE%^applies to the Inn today.  Individuals who cause a ruckus, make threats, cause injury or in general disturb the enjoyment of others will be asked to leave.  Failure to do so, will result in the eviction of the offender from the Inn and possibly jail time at the Shadow Jail.  Please refrain from practicing of your smithing and creation crafts, or any other activity which potentially can be distracting to others, including pipe smoking (they're too spammy).  Keep any pets under control.  Magic/psionics, drawn weapons and the like are strictly prohibited within the inn during the contest, except for on stage as props.  If you would like to enter the contest, please use %^CYAN%^<thought>%^WHITE%^ to alert the judges.  Enjoy the show!%^RESET%^

AVATAR
	);
	set("read",
@AVATAR

%^BOLD%^%^MAGENTA%^Let it be known and understood that during the Story Telling Contest the following rules apply to all: %^BOLD%^%^WHITE%^The %^CYAN%^Law of Sanctuary %^WHITE%^applies to the Inn today.  Individuals who cause a ruckus, make threats, cause injury or in general disturb the enjoyment of others will be asked to leave.  Failure to do so, will result in the eviction of the offender from the Inn and possibly jail time at the Shadow Jail.  Please refrain from practicing of your smithing and creation crafts, or any other activity which potentially can be distracting to others, including pipe smoking (they're too spammy).  Keep any pets under control.  Magic/psionics, drawn weapons and the like are strictly prohibited within the inn during the contest, except for on stage as props.  If you would like to enter the contest, please use %^CYAN%^<thought>%^WHITE%^ to alert the judges.  Enjoy the show!%^RESET%^


AVATAR
	);
     set("langage","common");	set_weight(150);
	set_value(0);
}
