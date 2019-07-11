/*
// File: exclude_array.c
// A simul_efun module.
// Thanks to the folks at Portals for this one.
// Author: either Huthar or Wayfarer, I presume.
// Now a part of the TMI distribution mudlib.
// Purpose: to remove a range from an array
*/
varargs mixed *exclude_array(mixed *array,int from, int to)
{
   mixed *bottom,*top;
   
   bottom = ({ });
   top = ({ });
   
   if(!to) to = from;
   if(from > 0)
      bottom = array[0 .. from - 1];
   if(to < sizeof(array) - 1)
      top = array[to + 1 .. sizeof(array) - 1];
   return bottom + top;
}
