object *users() 
{
  string who;
  object *userList, List;
  int i,j;
  if(objectp(this_player()))
  {
    if(member_group(this_player()->query_name(), "superuser")) return efun::users();
  }
  if(objectp(previous_object()))
  {
    if(sscanf(getuid(previous_object()),"%sobj",who) > 0)
    {
        if(member_group(who,"superuser")) 
            return efun::users();      
        List = ({});
        userList = efun::users();
        j = sizeof(userList);
        for(i=0;i<j;i++)
        {
            if(!objectp(this_player()))
            {
                List += ({userList[i]});
                continue;
            }
            if(userList[i]->query_level() < this_player()->query_level()) 
                List += ({userList[i]});
                continue;
        }
        return List;
    }
  }
  return efun::users();
}
