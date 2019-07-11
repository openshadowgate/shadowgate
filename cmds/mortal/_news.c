#include <std.h>

inherit DAEMON;
#define ALLOWED_NEWS ({ "assassin", "hm" , "newbie", "newname" ,"general" }) 
int cmd_news(string str){
   if(!str){
      if(file_exists("/news/news")){
         TP->more("/news/news");
         return 1;
      }
   }
   if(str == "assassin" && !TP->query("is_assassin"))
      return notify_fail("No way!\n");
   if(!avatarp(TP) && (member_array(str,TP->query_classes()) == -1)
      && (member_array(str, ALLOWED_NEWS) == -1 ) )
      return notify_fail("No way!\n");
   if(str == "general"){
      if(file_exists("/news/general")){
         TP->more("/news/general");
         return 1;
      }
   }
   if(str == "newname"){
      if(file_exists("/news/newname")){
         TP->more("/news/newname");
         return 1;
      }
   }
   if( high_mortalp(TP) && str == "hm"){
      if(file_exists("/news/hm")){
         TP->more("/news/hm");
         return 1;
      }
   }
   if(avatarp(TP) || member_array(str,TP->query_classes()) != -1){
      if(file_exists("/news/"+str)){
         TP->more("/news/"+str);
         return 1;
      }
      return notify_fail("No news for "+str+"\n");
   }
   if(TP->query("is_assassin") && str == "assassin"){
      if(file_exists("/news/assassin")){
         TP->more("/news/assassin");
         return 1;
      }
      return notify_fail("No news for assassin\n");
   }
   return notify_fail("No news\n");
}

int help(){
   write(
@OBS
Syntax:   news [class || general || assassin || hm || newname ]

The news command will give you the most up-to-date MUD news,
general news, class news, hm news and assassin news if you are one.

The name policy that new players are expected to follow is also available.

PS: If you are not of a particular class, there is no way
    for you to access the relavent news file.
OBS
   );
}
