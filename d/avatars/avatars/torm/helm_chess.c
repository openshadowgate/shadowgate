//Coded by Lujke
#include <std.h>
inherit "/d/common/obj/misc/chessboard";

#define BLACK 1
#define WHITE 2
#define ERROR 666

#define EMPTY 0
#define B_PAWN 1
#define W_PAWN 2
#define B_ROOK 3
#define W_ROOK 4
#define B_KNIGHT 5
#define W_KNIGHT 6
#define B_BISHOP 7
#define W_BISHOP 8
#define B_QUEEN 9
#define W_QUEEN 10
#define B_KING 11
#define W_KING 12


string show_square(int square);
string get_piece_name(int piecetype);

void create() 
{
  ::create();
  set_obvious_short("an %^CYAN%^exquisite%^BOLD%^%^YELLOW%^ chess"
                   +" set%^BOLD%^%^MAGENTA%^");
  set_short("%^BOLD%^%^BLUE%^Chess set of the %^YELLOW%^W%^BLUE%^a"
           +"%^YELLOW%^tchful E%^BLUE%^y%^YELLOW%^e%^BOLD%^%^MAGENTA%^");
  set_long("%^BOLD%^%^BLUE%^A traveller's chess board, decorated with"
          +" %^BOLD%^%^YELLOW%^y%^BLUE%^ello%^YELLOW%^w t%^BLUE%^ri"
          +"%^YELLOW%^m %^BLUE%^. It is designed to fold into a box to"
          +" make it easier to carry.\n%^BOLD%^%^BLUE%^The centre of the"
          +" board is decorated with a blue %^YELLOW%^W%^BLUE%^a"
          +"%^YELLOW%^tchful E%^BLUE%^y%^YELLOW%^e%^BOLD%^%^BLUE%^. The"
          +" pieces are intricately fashioned from stones of"
          +" %^YELLOW%^yellow b%^RESET%^%^ORANGE%^e%^YELLOW%^ryl%^BLUE%^"
          +" and %^BOLD%^%^BLUE%^blue q%^RESET%^%^BLUE%^u%^BOLD%^"
          +"%^BLUE%^ar%^CYAN%^t%^BLUE%^z stand attentively at guard,"
          +" %^RESET%^%^ORANGE%^watching %^BOLD%^%^BLUE%^and %^RESET%^"
          +"%^ORANGE%^waiting%^BOLD%^%^BLUE%^ for the next move.");
   set_id( ({"board", "chessboard", "chess board", "game", "table", 
                            "helm board", "chess table", "game board"}) );
   set_lore("The game of chess is considered significant within the"
           +" faith of Helm, as it teaches the importance of forethought,"
           +" vigilance, planning and strategy. Some say that the game"
           +" was invented by Helm to teach just those virtues.\nThe"
           +" Chess sets of the Watchful Eye were crafted and enchanted"
           +" in honour of Helm and are played to His glory.");
   set_weight(2);
   set_value(20000);
}

string show_square(int square)
{
  string str;
  if ((square/8)%2==0)
  {
    if (square%2==0)
    {
      str = "%^B_BLUE%^";
    }
    else
    {
      str = "%^B_YELLOW%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_YELLOW%^";
    }
    else
    {
      str = "%^B_BLUE%^";
    }
  }

  switch(squares[square])
  {
  case EMPTY:
    str += "   ";
    break;
  case B_PAWN:
    str += "%^BOLD%^%^BLUE%^ p %^RESET%^";
    break;
  case W_PAWN:
    str += "%^BOLD%^%^YELLOW%^ p %^RESET%^";
    break;
  case B_ROOK:
    str +="%^BOLD%^%^BLUE%^ C %^RESET%^";
    break;
  case W_ROOK:
    str +="%^BOLD%^%^YELLOW%^ C %^RESET%^";
    break;
  case B_KNIGHT:
    str +="%^BOLD%^%^BLUE%^ Kn%^RESET%^";
    break;
  case W_KNIGHT:
    str +="%^BOLD%^%^YELLOW%^ Kn%^RESET%^";
    break;
  case B_BISHOP:
    str +="%^BOLD%^%^BLUE%^ B %^RESET%^";
    break;
  case W_BISHOP: 
    str +="%^BOLD%^%^YELLOW%^ B %^RESET%^";
    break;
  case B_QUEEN:
    str +="%^BOLD%^%^BLUE%^ Q %^RESET%^";
    break;
  case W_QUEEN:
    str +="%^BOLD%^%^YELLOW%^ Q %^RESET%^";
    break;
  case B_KING:
    str +="%^BOLD%^%^BLUE%^ Ki%^RESET%^";
    break;
  case W_KING:
    str +="%^BOLD%^%^YELLOW%^ Ki%^RESET%^";
    break;   
  };
  return str;
}

string show_empty_square(int square)
{
  string str;
  if ((square/8)%2==0)
  {
    if (square%2==0)
    {
      str = "%^B_BLUE%^";
    }
    else
    {
      str = "%^B_YELLOW%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_YELLOW%^";
    }
    else
    {
      str = "%^B_BLUE%^";
    }
  }
  str +="   ";
  return str;
}

string get_piece_name(int piecetype)
{
  switch(piecetype)
  {
  case B_PAWN:
    return "%^BOLD%^%^BLUE%^blue pawn%^RESET%^";
  case B_ROOK:
    return "%^BOLD%^%^BLUE%^blue castle%^RESET%^";
  case B_KNIGHT:
    return "%^BOLD%^%^BLUE%^blue knight%^RESET%^";
  case B_BISHOP:
    return "%^BOLD%^%^BLUE%^blue bishop%^RESET%^";
  case B_QUEEN:
    return "%^BOLD%^%^BLUE%^blue queen%^RESET%^";
  case B_KING:
    return "%^BOLD%^%^BLUE%^blue king%^RESET%^";
  case W_PAWN:
    return "%^BOLD%^%^YELLOW%^yellow pawn%^RESET%^";
  case W_ROOK:
    return "%^BOLD%^%^YELLOW%^yellow castle%^RESET%^";
  case W_KNIGHT:
    return "%^BOLD%^%^YELLOW%^yellow knight%^RESET%^";
  case W_BISHOP:
    return "%^BOLD%^%^YELLOW%^yellow bishop%^RESET%^";
  case W_QUEEN:
    return "%^BOLD%^%^YELLOW%^yellow queen%^RESET%^";
  case W_KING:
    return "%^BOLD%^%^YELLOW%^yellow king%^RESET%^";
  }
}

string show_next_move()
{
  string next_move;
  next_move= "  %^ORANGE%^Next move%^BOLD%^%^BLACK%^:";
  if (nextmove==WHITE)
  {
    next_move+="%^BOLD%^%^YELLOW%^\tyellow%^RESET%^";
  }
  else
  {
    next_move+="%^BOLD%^%^BLUE%^\tblue%^RESET%^";
  }
  return next_move;

}
void send_capture_message(int startpos, int endpos, object ob, string str)
{
  if ((string)ob->query_diety() != "helm" )
  {
    ::send_capture_message(startpos, endpos, ob, str);
    return;
  }
  switch(((squares[startpos]+1)/2)*2)
  {
  case W_PAWN:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " steps up smartly from " + str + " and denounces"
                  + " the misdeeds of your opponent's "
                  + get_piece_name (squares[endpos])+ ", shaming it into"
                  + " withdrawing. He must have been watching very"
                  + " carefully! Praise %^BOLD%^%^YELLOW%^Helm!");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " steps up smartly from " + str + " and denounces"
                  + " the misdeeds of the " 
                  + get_piece_name (squares[endpos])+ ", shaming it into"
                  + " withdrawing.", TP);  
    break;
  case W_ROOK:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " slides smoothly from " + str + " and takes"
                  + " your opponent's " + get_piece_name (squares[endpos])
                  + " prisoner, placing it under close guard.");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " slides smoothly from " + str + " and takes"
                  + " the " + get_piece_name (squares[endpos])
                  + " prisoner, placing it under close guard.", TP);  
    break;
  case W_KNIGHT:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " gallops accross the field of battle from " + str 
                  + ", jumping over every obstacle in its way and charges"
                  + " down your opponent's " 
                  + get_piece_name (squares[endpos]) + ".");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " gallops accross the field of battle from " + str 
                  + ", jumping over every obstacle in its way and charges"
                  + " down the " + get_piece_name(squares[endpos]) 
                  + ".", TP); 
    break;
  case W_BISHOP:
    tell_object(TP, "Your " + get_piece_name(squares[startpos]) 
                  + " steps forth from " + str + " in the name of "
                  + "%^BOLD%^%^YELLOW%^Helm%^RESET%^ and brings the full" 
                  + " power of His gaze upon your opponent's " 
                  + get_piece_name (squares[endpos]) + ", which is"
                  + " unable to bear the onslaught.");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " steps forth from " + str + " in the name of "
                  + "%^BOLD%^%^YELLOW%^Helm%^RESET%^ and brings the full" 
                  + " power of His gaze upon the " 
                  + get_piece_name (squares[endpos]) + ", which is"
                  + " unable to bear the onslaught.", TP); 
    break;
  case W_QUEEN:
    tell_object(TP, "The " + get_piece_name(squares[startpos]) 
                  + " sweeps with regal majesty from " + str + " and"
                  + " brings an end to the wickedness of the " 
                  + get_piece_name (squares[endpos]) + ".");
    tell_room(ETO,  TPQCN + " sweeps the " 
                  + get_piece_name(squares[startpos]) 
                  + " forward with regal majesty from " + str + " and"
                  + " brings an end to the wickedness of the " 
                  + get_piece_name (squares[endpos]) + ".", TP); 

    break;
  case W_KING:
    tell_object(TP, "The " + get_piece_name(squares[startpos]) 
                  + " moves bravely from " + str + " and"
                  + " personally captures the " 
                  + get_piece_name (squares[endpos]) + ".");
    tell_room(ETO, TPQCN + " moves the " 
                  + get_piece_name(squares[startpos]) 
                  + " bravely from " + str + ", where it "
                  + " personally captures the " 
                  + get_piece_name (squares[endpos]) + ".", TP); 
    break;
  }


}
