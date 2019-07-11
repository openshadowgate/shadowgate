#include <std.h>

inherit OBJECT;

int painted;
int descd;
int ident;

void create(){
  ::create();
  
  set_short("a clean canvas");
  set_long(
      "%^RESET%^%^WHITE%^" +
      "This is a pristine white canvas.  The weave is tight and smooth, with" +
      " no major imprefections.  The cotton appears ready to hold paint " +
      "well. \n\n" +
      "%^BOLD%^%^YELLOW%^<%^BOLD%^%^WHITE%^" +
      "shortdesc (obvious short)" +
      "%^BOLD%^%^YELLOW%^>%^RESET%^%^WHITE%^ " +
      "\n\t - Set what is seen in inventory!\n" +
      "%^BOLD%^%^YELLOW%^<%^BOLD%^%^WHITE%^" +
      "ident (ID)" +
      "%^BOLD%^%^YELLOW%^>%^RESET%^%^WHITE%^ " +
      "\n\t - Pick one unique ID for the painting!\n" +
      "%^BOLD%^%^YELLOW%^<%^BOLD%^%^WHITE%^" +
      "paint (painting description)" +
      "%^BOLD%^%^YELLOW%^>%^RESET%^%^WHITE%^ " +
      "\n\t - Will allow you to paint your picture!" +
      "\n\t   (canvas, painting, and picture are automatic)\n" +
      "%^BOLD%^%^RED%^All changes are Final!%^RESET%^%^WHITE%^"
      
  );
  set_id(({"canvas","canvasxxx"}));
  set_weight(1);
  set_value(200);
}

void init(){
  ::init();
  if(!painted) add_action("paint_canvas","paint");
  if(!painted) add_action("desc_canvas","shortdesc");
  if(!painted) add_action("ident_canvas","ident");
}

int paint_canvas(string str){
  string temp;
  temp = "/daemon/filters_d"->filter_colors(str);
  if(strsrch(temp,"painting") == -1 && strsrch(temp,"Painting") == -1 && 
     strsrch(temp,"picture") == -1  && strsrch(temp,"Picture") == -1 &&
     strsrch(temp,"sketch") == -1  && strsrch(temp,"Sketch") == -1 &&
     strsrch(temp,"drawing") == -1  && strsrch(temp,"Drawing") == -1){
    tell_object(TP,
    "You must include \"sketch\", \"drawing\", \"picture\" or \"painting\"!\n");
    return 1;
  }
  if(!objectp(TO)) return 0;
  if(!str || painted){
    tell_object(TP,"That won't work!\n");
    return 1;
  }
  TO->set_long(str + "%^RESET%^\n");
  tell_object(TP,"The canvas now appears as:\n" + str+"\n" );
  painted = 1;
  return 1;
}

int desc_canvas(string str){
  string temp;
  temp = "/daemon/filters_d"->filter_colors(str);
  if(strsrch(temp,"painting") == -1 && strsrch(temp,"Painting") == -1 && 
     strsrch(temp,"picture") == -1  && strsrch(temp,"Picture") == -1 &&
     strsrch(temp,"sketch") == -1  && strsrch(temp,"Sketch") == -1 &&
     strsrch(temp,"drawing") == -1  && strsrch(temp,"Drawing") == -1){
    tell_object(TP,
    "You must include \"sketch\", \"drawing\", \"picture\" or \"painting\"!\n");
    return 1;
  }
  if(!objectp(TO)) return 0;
  if(!str || descd){
    tell_object(TP,"That won't work!\n");
    return 1;
  }
  TO->set_short(str + "%^RESET%^");
  tell_object(TP,"The canvas now appears as:\n" + str+"\n" );
  descd = 1;
  return 1;
}

int ident_canvas(string str){
  if(!objectp(TO)) return 0;
  if(!str || ident) return 0;
  add_id(str + "");
  add_id("painting");
  add_id("picture");
  ident = 1;
  return 1;
}
