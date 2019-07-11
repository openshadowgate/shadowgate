//     /adm/simul_efun/arrange_string.c
//     from the Nightmare mudlib
//     makes a string a certain length
//     created by Descartes of Borg 23 december 1992
//     modified to take into account ansi colour :) codes
//       by Blodgett 10 september 1993 (europosis!)

string strip_colors(string str)
{
    string ret;
    mapping Uncolor = ([ "RESET": "\b", "BOLD": "","ULINE":"", "FLASH":"", "BLACK":"", "RED":"",
            "BLUE":"", "CYAN":"", "MAGENTA":"", "ORANGE":"", "YELLOW":"",
            "GREEN":"", "WHITE":"", "BLACK":"", "B_RED":"", "B_ORANGE":"",
            "B_YELLOW":"", "B_BLACK":"", "B_CYAN":"","B_WHITE":"", "B_GREEN":"",
            "B_MAGENTA":"", "STATUS":"", "WINDOW":"", "INITTERM": "", "B_BLUE":"",
            "ENDTERM":""]);
    ret = terminal_colour(str, Uncolor);
    return replace_string(ret, "\b", "");
}


varargs string arrange_string (string str, int x)
{
    string *letters;
    int NewLen, z, bare, tmp1 = -1, tmp2 = -1, real_letters;
    if(!x) x = 79;
    if(!stringp(str)) { if(intp(str)) { str = ""+str; } else { return ""; } }
    bare = strlen(strip_colors(str));
    if(x == bare) return str;    
    if(x < strlen(str))
    {
        NewLen = x;
        NewLen += (strlen(str) - bare);
        letters = explode(str, "");
        for(z = 0;z < sizeof(letters);z++)
        {      
            if(real_letters >= x) 
            {
                if(tmp2 != -1) 
                {
                    if(tmp2 < z) NewLen = z;
                    else NewLen = tmp2;
                    break;
                }
                if(tmp1 != -1) 
                {                 
                    NewLen = tmp1-1;
                    break;
                }
                if(letters[z] == "%" && letters[z+1] == "^") NewLen = z-1;
                else NewLen = z;
                break;
            }
            if((z+1) < sizeof(letters))
            {
                if(letters[z] == "%" && letters[z+1] == "^")
                {
                    if(tmp1 != -1)
                    {
                        if(tmp2 == -1) 
                        {          
                            z++;
                            tmp2 = z;
                            tmp1 = -1;
                            continue;
                        }
                    }
                    if(tmp1 == -1)
                    {
                        tmp1 = z;
                        tmp2 = -1;
                        continue;
                    }
                    continue;
                }
            }            
            if(tmp2 == -1 && tmp1 == -1) real_letters++;
            if(tmp2 != -1 && tmp1 == -1) real_letters++;
            continue;
        }
        str = str[0..(NewLen-1)];
    }    
    bare = strlen(strip_colors(str));
    if(x == bare) return str; 
    if(x >= bare)
    {        
        z = x - bare;
        while(z > 0) 
        {
            z--;
            str += " ";
            continue;
        }
        return str;
    }
    return str;
}

