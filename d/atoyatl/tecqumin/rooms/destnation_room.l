#include <std.h>

inherit ROOM;

mapping waystations;

void add_waystation(string roomname, int val){
  waystations +=([roomname:val]);
}

void remove_waystation(string roomname){
  waystations = m_delete(waystations, roomname);
}

int query_waystation(string roomname){
  return waystations[roomname];
}

mapping query_waystations(){
  return waystations;
}

void add_next_rooms( object * rooms, int prevcount){
  int i, j;
  object temproom;
  string * exits, roomname;
  if (!objectp(room)){
    return;
  }
  if (prevcount>=sizeof(rooms)){
    return;
  }
  for (i=prevcount;i<sizeof(rooms);i++){
    exits = rooms[i]->query_exits();
    if (sizeof(exits)<1){
      return;
    }
    for (j=0;j<sizeof(exits);j++){
      roomname = room->query_exit(exits[j]);
      if (file_exists(roomname)){
        temproom = find_object_or_load(roomname);
      }
      if (objectp(temproom) && !member_array(temproom, rooms, 1)){
        newrooms += ({temproom});
      }
    }
  }
}


void add_waystations_to_room(object room, object* checkedRooms, int stage){
  object * newrooms, temproom, scanner;
  int i, j, prevcount, runningcount;
  
  if (objectp(room)){
    return;
  }

  prevcount = 0;
  newrooms = ({});
  scanner = new("/realms/lujke/far_scanner3.c")
  
  // add the next set of rooms, 5 times in a row
  for (i = 0;i<5;i++){
    if (prevcount>=runningcount){ // this means no new rooms were found
      break;                      // on the last iteration
    }
    add_next_rooms(checkedRooms, prevcount);
    prevcount = runningcount;
    runningcount = sizeof(rooms);
  }
  
  // ignore the first 4 sets of rooms, but cycle through the last
  // set to be added, and add a waystation mapping for each one, if it is 
  // not within 5 steps of any other waystation
  
  for (i=prevcount;i<runningcount;i++){
    temproom =  scanner->find_waystation(newrooms[i], "/realms/lujke/tecqumin/rooms/zigzenith",5)
    // if no nearby waystation is found, add one in, with the stage number 
    // that was passed to the function
    if (!objectp(temproom) || temproom = newrooms[i]){
      add_waystation(file_name(newrooms[i], stage);
    }
  }
}  

void generate_waystations(int num_stages){
  object* checked_rooms;
  int i, j, prevcount, runningcount;

  checked_rooms = ({TO});
  prevcount = 0;
  runningcount = 1;
  for (i=0;i<num_stages;i++){
    for (j=prevcount;j<runningcount;j++){
      add_waystations_to_room(checked_rooms[j], checked_rooms, i);
    }
  }
}
