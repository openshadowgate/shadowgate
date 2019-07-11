object find_living(string str){
	string whom;
    object who;
	int i,j;
	if(sscanf(geteuid(previous_object()),"%sobj",whom) > 0){
             if(member_group(whom,"superuser")) return efun::find_living(str);
      who = efun::find_living(str);
	if(objectp(who) && ((int)who->query_level() > (int)this_player()->query_level()))
		return 0;
	}
  return efun::find_living(str);
}
