//save_d.c

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_FILE "/daemon/save/arrays"

mapping __SaveArrays;

void SAVE();

void create(){
	::create();
	__SaveArrays = ([]);
	seteuid(UID_DAEMONSAVE);
	restore_object(SAVE_FILE);
	seteuid(getuid());
	}

void set_value(string array,string name){
        if (pointerp(array) || pointerp(name)) return;
	if(!__SaveArrays) __SaveArrays = ([]);
	if(!__SaveArrays[array]) __SaveArrays[array] = ({});
	
	__SaveArrays[array] += ({name});
	SAVE();
}

string *query_array(string array){
	if(!__SaveArrays) __SaveArrays = ([]);
	if(!__SaveArrays[array]) __SaveArrays[array] = ({});
	
	return __SaveArrays[array];
}

void remove_name_from_array(string array, string name){
	if(!__SaveArrays) __SaveArrays = ([]);
	if(!__SaveArrays[array]) __SaveArrays[array] = ({});
	
	__SaveArrays[array] -= ({name});
	SAVE();
}

void remove_name(string name){
	string *arrays;
	int i;
	
	arrays = keys(__SaveArrays);
	
	for(i = 0; i < sizeof(arrays);i++)
		__SaveArrays[arrays[i]] -= ({name});
		
	SAVE();
}

void remove_array(string nme){
    map_delete(__SaveArrays, nme);
    SAVE();
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
}

int is_member(string array, string name){
	if(!__SaveArrays) __SaveArrays = ([]);
	if(!__SaveArrays[array]) __SaveArrays[array] = ({});
	
	return member_array(name, __SaveArrays[array]);
}

string * show_list_arrays() {
  string * str;
  str = keys(__SaveArrays);
  return str;
}
