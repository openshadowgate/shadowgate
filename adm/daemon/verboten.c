#include <security.h>

#define VERBOTEN_WORDS ({ " icq",\
    " email",\
   " msn",\
    " hotmail",\
    " irc",\
    "@",\
})

void found_word(object tp, string type);


void test_verboten(string str, object tp, string type){
    int i;
    string hold;


    seteuid(geteuid());

    if(!stringp(str) || !objectp(tp))
      return;

   hold = str;
    str = lower_case(str);

    //This part makes sure we log the next couple things that come out of this person.
    if( i = tp->query_property("LogStuff")){
      tp->remove_property("LogStuff");
      tp->set_property("LogStuff", (i-1));
      write_file("/log/adm/ICQ/"+tp->query_name()+".log", "* "+query_verb()+" "+hold+"\n");
      return;
    }

    for(i=0;i<sizeof(VERBOTEN_WORDS);i++){
      if(strsrch(str, lower_case(VERBOTEN_WORDS[i])) != -1){
        found_word(tp, type);
        write_file("/log/adm/ICQ/"+tp->query_name()+".log", "* "+query_verb()+" "+hold+"\n");
        return;
      }
    }
    return;
}

void found_word(object tp, string type){
    string *lines;
    object *pe;
    int i;

    write_file("/log/adm/ICQ/"+tp->query_name()+".log", "<<<< BEGIN Time: "+ctime(time())+" >>>>\n");

    write_file("/log/adm/ICQ/"+tp->query_name()+".log", "Present: ");
    pe = all_living(environment(tp));
    for(i=0;i<sizeof(pe);i++){
      if(!interactive(pe[i])) continue;
      write_file("/log/adm/ICQ/"+tp->query_name()+".log", " "+pe[i]->query_name());
    }
    write_file("/log/adm/ICQ/"+tp->query_name()+".log", "\n\n");

    lines = tp->query_messages(type);
    for(i=0;i<sizeof(lines);i++){
      write_file("/log/adm/ICQ/"+tp->query_name()+".log", "# "+lines[i]);
    }
    tp->set_property("LogStuff", 30);

    return;
}
