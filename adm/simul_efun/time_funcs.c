string parse_time(int t)
{
   string str;
   if(!intp(t)) return "";
   
   str=(t%60)+" s";
   t /= 60;
   if(t%60>0)
      str=t%60+" m "+str;
   t /= 60;
   if(t%24>0)
      str=t%24+" h "+str;
   t /= 24;
   if(t>0)
      str = t +" d "+str;
   return str;   
}

string last_reboot() { return ctime(time() - uptime()); }
