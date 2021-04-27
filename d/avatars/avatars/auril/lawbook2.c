#include <std.h>
inherit OBJECT;
void create(){
	::create();
	set_name("book");
	set_id(({"book","journal"}));
        set_short("%^RED%^The Tyrian Book of Misdeeds%^RESET%^");
        set_obvious_short("a red leather book");
	set_long("%^RED%^This short book is a traveller's version of the great Tyrian Book of Misdeeds. Each temple of Tyr has a greater version where all the faithful's observations of crimes are recorded by the priests.  This book as a bronze clasp, that can lock the contents of the pages away.  There does not appear to be a lock on it, just the silver emblem of a pair of scales balanced on a warhammer's head.");
	set_value(1);
	}

	string query_long(string str){
	string hold = ::query_long(str);
	if (stringp(query("read"))) {
	hold += " It has writing on it.";
	}
	 return hold;
	}
