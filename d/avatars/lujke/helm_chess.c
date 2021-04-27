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
  set_obvious_short("an %^CYAN%^e%^RED%^x%^CYAN%^qu%^RED%^i%^CYAN%^site"
                   +"%^BOLD%^%^BLUE%^ ch%^CYAN%^e%^BLUE%^ss set"
                   +"%^RESET%^");
  set_short("%^BOLD%^%^BLUE%^Chess set of the %^CYAN%^W%^BLUE%^a"
           +"%^CYAN%^tchful E%^BLUE%^y%^CYAN%^e%^BOLD%^%^RESET%^");
  set_long("%^BOLD%^%^CYAN%^A traveller's chess board, decorated with"
          +" %^BOLD%^%^RED%^red trim%^CYAN%^. It is designed to fold into"
          +" a box to make it easier to carry.\n%^BOLD%^%^CYAN%^The"
          +" centre of the board is decorated with a blue %^BLUE%^W"
          +"%^CYAN%^a%^BLUE%^tchful E%^CYAN%^y%^BLUE%^e%^BOLD%^%^CYAN%^."
          +" The pieces are intricately fashioned from br%^WHITE%^i"
          +"%^CYAN%^ght st%^WHITE%^ee%^CYAN%^l %^CYAN%^"
          +" and %^RESET%^%^RED%^gl%^BOLD%^%^RED%^i%^RESET%^%^RED%^tter"
          +"%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng %^BOLD%^%^RED%^r%^RESET%"
          +"^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^i%^BOLD%^%^RED%^es"
          +"%^BOLD%^%^CYAN%^ stand attentively at guard,"
          +" %^RESET%^%^CYAN%^w%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^tching"
          +" %^BOLD%^%^CYAN%^and %^RESET%^%^CYAN%^wa%^BOLD%^%^CYAN%^i"
          +"%^RESET%^%^CYAN%^ting%^BOLD%^%^CYAN%^ for the next move.");
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
      str = "%^B_CYAN%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_CYAN%^";
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
    str += "%^BOLD%^%^RED%^ p %^RESET%^";
    break;
  case W_PAWN:
    str += "%^BOLD%^%^CYAN%^ p %^RESET%^";
    break;
  case B_ROOK:
    str +="%^BOLD%^%^RED%^ C %^RESET%^";
    break;
  case W_ROOK:
    str +="%^BOLD%^%^CYAN%^ C %^RESET%^";
    break;
  case B_KNIGHT:
    str +="%^BOLD%^%^RED%^ Kn%^RESET%^";
    break;
  case W_KNIGHT:
    str +="%^BOLD%^%^CYAN%^ Kn%^RESET%^";
    break;
  case B_BISHOP:
    str +="%^BOLD%^%^RED%^ B %^RESET%^";
    break;
  case W_BISHOP: 
    str +="%^BOLD%^%^CYAN%^ B %^RESET%^";
    break;
  case B_QUEEN:
    str +="%^BOLD%^%^RED%^ Q %^RESET%^";
    break;
  case W_QUEEN:
    str +="%^BOLD%^%^CYAN%^ Q %^RESET%^";
    break;
  case B_KING:
    str +="%^BOLD%^%^RED%^ Ki%^RESET%^";
    break;
  case W_KING:
    str +="%^BOLD%^%^CYAN%^ Ki%^RESET%^";
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
      str = "%^B_CYAN%^";
    }
  }
  else
  {
    if (square%2==0)
    {
      str = "%^B_CYAN%^";
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
    return "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by pawn"
          +"%^RESET%^";
  case B_ROOK:
    return "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by castle"
          +"%^RESET%^";
  case B_KNIGHT:
    return "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by knight"
          +"%^RESET%^";
  case B_BISHOP:
    return "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by bishop"
          +"%^RESET%^";
  case B_QUEEN:
    return "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by queen"
          +"%^RESET%^";
  case B_KING:
    return "%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by king"
          +"%^RESET%^";
  case W_PAWN:
    return "%^BOLD%^%^CYAN%^st%^WHITE%^ee%^CYAN%^l pawn%^RESET%^";
  case W_ROOK:
    return "%^BOLD%^%^CYAN%^st%^WHITE%^ee%^CYAN%^l castle%^RESET%^";
  case W_KNIGHT:
    return "%^BOLD%^%^CYAN%^st%^WHITE%^ee%^CYAN%^l knight%^RESET%^";
  case W_BISHOP:
    return "%^BOLD%^%^CYAN%^st%^WHITE%^ee%^CYAN%^l bishop%^RESET%^";
  case W_QUEEN:
    return "%^BOLD%^%^CYAN%^st%^WHITE%^ee%^CYAN%^l queen%^RESET%^";
  case W_KING:
    return "%^BOLD%^%^CYAN%^st%^WHITE%^ee%^CYAN%^l king%^RESET%^";
  }
}

string show_next_move()
{
  string next_move;
  next_move= "  %^ORANGE%^Next move%^BOLD%^%^BLACK%^:";
  if (nextmove==WHITE)
  {
    next_move+="%^BOLD%^%^CYAN%^\tst%^WHITE%^ee%^CYAN%^l%^RESET%^";
  }
  else
  {
    next_move+="%^BOLD%^%^RED%^\tr%^RESET%^%^RED%^u%^BOLD%^%^RED%^by"
              +"%^RESET%^";
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
                  + " carefully! Praise %^BOLD%^%^BLUE%^Helm!");
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
                  + "%^BOLD%^%^BLUE%^Helm%^RESET%^ and brings the full" 
                  + " power of His gaze upon your opponent's " 
                  + get_piece_name (squares[endpos]) + ", which is"
                  + " unable to bear the onslaught.");
    tell_room(ETO, TPQCN + "'s " + get_piece_name(squares[startpos]) 
                  + " steps forth from " + str + " in the name of "
                  + "%^BOLD%^%^BLUE%^Helm%^RESET%^ and brings the full" 
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
