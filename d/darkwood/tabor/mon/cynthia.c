#include <std.h>

inherit NPC;


void create(){
   ::create();
   set_name("Cynthia");
   set_id(({"Cynthia", "cynthia","old woman","old lady","woman","lady","storyteller","aged woman", "grandma"}));
   set_short("%^MAGENTA%^%^BOLD%^Cynthia, a g%^WHITE%^r%^MAGENTA%^i%^WHITE%^z%^MAGENTA%^z%^WHITE%^l%^MAGENTA%^e%^WHITE%^d%^MAGENTA%^%^BOLD%^ old woman%^RESET%^");
   set_long(
      "This old woman has grizzled gray hair and wrinkled "+
      "skin. She wears an old-fashioned dress and a large shawl. "+
      "Her eyes are clear and piercing when she looks "+
      "at people passing through the hall, but most of the time "+
      "she is occupied with her knitting. She rocks back and forth "+
      "in her chair while her knitting needles clank rapidly and "+
      "rythmically. "
      );
   set_gender("female");
   set_race("human");
   set_body_type("human");
   set_hd(2,1);
   set_stats("strength",6);
   set_stats("charisma",12);
   set_stats("dexterity",6);
   set_stats("constitution",12);
   set_stats("wisdom",22);
   set_stats("intelligence",18);
   set_exp(1);
   force_me("speech say lightly");

}

void catch_say(string msg){

    if(!userp(TP)){
        return;
    }


    if (TP->query_invis()) {
        force_me("emote stirs.");
        force_me("say Who's there?");
        return;
    }


//    if (query_bad_race(TP)) {
//       force_me("say What are you doing in Tabor? Get out of here! Shoo!");
//        return;
//    }


   ::catch_say(msg);
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   object current;
   object obj;
   string name;
   set_spoken("wizish");
   name = who->query_name();

   if(!msg || !objectp(who)) return;

   if(strsrch(msg,"Hi") != -1 || strsrch(msg,"hail") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ello") != -1 ||
      strsrch(msg,"Hail") != -1)  {
      force_me("emote glances up from her knitting to look at you.");

        if(TP->query_level() > 10) {
            force_me("say Hello dear. I don't think I know anything an accomplished person like you don't already know.");
            force_me("emote smiles affably.");
            return;
        }
      
        force_me("say Hello dear. My name is Cynthia, but everybody calls me grandma. " +
        "You may not believe me, but I once was an adventurer like you!");
        force_me("say Ask me for tips, perhaps these old bones has some wisdom in them still.");
      return;
   }
   if(strsrch(msg,"tip") != -1 || strsrch(msg,"advice") != -1 ||
      strsrch(msg,"Tip") != -1 || strsrch(msg,"Advice") != -1 || strsrch(msg,"knowledge") != -1 ||
      strsrch(msg,"Knowledge") != -1 || strsrch(msg,"wisdom") != -1 || strsrch(msg,"Wisdom") != -1) {

      force_me("emote nods as she rocks her chair.");
      force_me("say There are two places a new adventurer could try their luck. " +
      "The first is the goblin keep, just southeast of Tabor."+
      "The second are the Ekibi caverns to the north, past the Meadowlands. ");
      force_me("say But before heading out of town, I would recommend you get a map of the surrounding area. " +
     "The scribe is a darling, I'm sure you'll get one for free if you ask nicely.");
      return;
   }

   if(strsrch(msg,"knitting") != -1 ){
      force_me("say I'm knitting a pair of nice, warm woolen socks. I can't find my old pair - "+
      "The goblins must have stolen them, that's what I'm thinking!");
      return;
   }


   if(strsrch(msg,"question") != -1 ){
      force_me("say You can ask me for tips, dear. Or I can tell you about Tabor and the surrounding areas.");
      return;
   }

   if(strsrch(msg,"scribe") != -1 || strsrch(msg,"Scribe") != -1 ){
      force_me("say The scribe's shop is in the center of Tabor, just opposite the general store, south of the bank.");
      return;
   }

   if(strsrch(msg,"map") != -1 || strsrch(msg,"Map") != -1 ){
      force_me("say Every adventurer should study maps before they head out! The scribe can give you one, or you can "+
      "take a look at the map in the tavern.");
      return;
   }

   if(strsrch(msg,"tavern") != -1 || strsrch(msg,"Tavern") != -1 ){
      force_me("say There's a nice tavern south of here, just past the stables. There's a map in the common hall, "+
      "and they serve the most delicious deer eyes!");
      force_me("emote giggles to herself.");
      return;
   }

   if(strsrch(msg,"abor") != -1 ){
      force_me("say This is such a lovely town, don't you think? It's a quiet place, except for those blasted goblins! "+
      "When you get tired of this this lazy old town, you might want to go to Shadow next.");
      return;
   }

   if(strsrch(msg,"randma") != -1 || strsrch(msg,"Cynthia") != -1 ){
      force_me("say I had such adventures when I was your age! " +
      "Yes, I lived fully, even though I never had any children of my own. " +
      "And now in my old age I find it a true pleasure helping young adventurers like yourself.");
      return;
   }


   if(strsrch(msg,"help") != -1 || strsrch(msg,"Help") != -1 ){
      force_me("say Do you need help, dear? Perhaps I can help. " +
      "It's many years since my adventuring days, but I might have some tips for you. ");
      return;
   }



   if(strsrch(msg,"city") != -1 || strsrch(msg,"country") != -1
        || strsrch(msg,"cities") != -1 || strsrch(msg,"area") != -1
        || strsrch(msg,"world") != -1 ){
      force_me("say There are many cities in the world you can visit. "+
      "Go ask the scribe for a map if you haven't done so already. "+
      "There is also a map in the tavern just east of the stables to the south.");
      force_me("say When you get tired of this this lazy old town, you might want to go to Shadow next.");
      return;
   }


   if(strsrch(msg,"hadow") != -1  ){
      force_me("say Shadow is a magnificent city if ever I saw one!");
      force_me("say But what makes it so special is that it is very well connected indeed. " + 
      "You can walk there on the road of course, or take the river ferry. "+
      "And Shadow has a portal service that quickly lets you travel all over the world!");
      force_me("say When I was young, I often met adventurers like you in the town square in Shadow. " +
      "It's a good place to go to make new friends and perhaps get yourself a travel companion. "+
      "Or you could just try the tavern of course.");
   }

   if(strsrch(msg,"adventure") != -1 || strsrch(msg,"Adventure") != -1){
      force_me("say Oh yes, I was an adventurer!");
      force_me("emote nods to herself.");
      force_me("say Come back some day, we can have some tea and share stories.");
      return;
   }

   if(strsrch(msg,"quest") != -1 || strsrch(msg,"Quests") != -1){
      force_me("say There is a gnome who owns a farm north of Tabor. I hear he's in trouble.");
      force_me("say There are also rumors of a beatuiful nereid in a cave. "+
      "They say she gives rewards to those who answers her riddles... "+
      "But who knows how many didn't live to warn about the danger?");
       force_me("say Oh, and I almost forgot, there's a collector searching for lost items. "+
       "You'll find the collector in the tavern.");
      
      return;
   }


   if(strsrch(msg,"goblin") != -1 ){
      force_me("say The goblins are a nuisince to the town! And the guards aren't doing a good "+
      "job keeping them in check, bless their hearts. The keep is just south of Tabor.");
      return;
   }

   if(strsrch(msg,"Ekibi") != -1 ){
      force_me("say The Ekibi caves are far from here, but Rosinden might make it worth "+
      "your trouble if you need bit of gold.");
      force_me("say To find the caves, go out the northwestern gate, then follow the road "+
      "northwest to the plains. Continue north. The caves are northeast of the "+
      "Meadowlands. Bring a map in case you get lost.");

      return;
   }

   if(strsrch(msg,"osinden") != -1 ){
      force_me("say Rosinden needs... minerals... or something... Go talk to her. " +
      "You'll find her near the Ekibi caverns.");

      return;
   }


   if(strsrch(msg,"question") != -1 ){
      force_me("say You can ask me for tips, dear. Or I can tell you about Tabor and the surrounding areas.");
      return;
   }



   if(strsrch(msg,"gnome") != -1 || strsrch(msg,"Gnome") != -1
    || strsrch(msg,"farm") != -1 || strsrch(msg,"Farm") != -1){
      force_me("say North of Tabor is an abandoned village. Southwest of that village "+
      "you will find the gnome's farm.");
      return;
   }


   if(strsrch(msg,"collector") != -1 || strsrch(msg,"Collector") != -1){
      force_me("say The collectors are searching for lost items. There's always one in the tavern. "+
      "The items are spread all over the place. ");
      force_me("emote frowns.");
      force_me("say It might be a trick to get you killed, so be careful!");
      return;
   }

   if(strsrch(msg,"village") != -1 || strsrch(msg,"Village") != -1
    || strsrch(msg,"Koenig") != -1 ){
        force_me("emote frowns grimly.");
        force_me("say A terrible thing, what happened to Koenig... All the dead people...");
        force_me("emote sighs heavily and continues to knit.");     
      return;
   }



    force_me("say Sorry dear, what was that? Speak up please.");
    
   return;
}



void init()
{
    ::init();

   setup();

   if(TP->query_level() > 7) {
       return;
    }

    if(!userp(TP)){
        return;
    }

    if (TP->query_invis()) {
        return;
    }

//   if (query_bad_race(TP)) {
//        return;
//   }
 
    call_out("notify_newcomers", 1);
}

void notify_newcomers()
{
    command("emote looks up with a friendly smile.");
    command("say Hello there, dear.");
}


void setup()
{
   // I encountered a problem with set_emotes. They didn't trigger  if I left the room
   // and returned. This was a problem whether the code was in create or init.
   // For some reason this works, putting the code in a setup function
   // and calling it from init. - Vanadis
  

   set_emotes(10,({"Cynthia rocks in her chair.",
      "Cynthia coughs and takes a deep breath.",
      "Cynthia knits intently.",
      "Cynthia closes her eyes and slumbers for a few moments."}),0);


}
