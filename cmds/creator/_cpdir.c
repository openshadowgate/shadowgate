varargs int cmd_cpdir(string str) {
  string * files, * headers, path, dest, temp;
  int i, count, num; 
  if (!stringp(str))
  {
    help();
    return 1;
  }
  num = sscanf(str, "%s %s", path, dest);
  tell_object(TP, "Original dest: " + dest);

  if (num<2)
  {
    dest = TP->query_path();
  }
  tell_object(TP, "Path: " + path);
/*  if (path[sizeof(path)-1..sizeof(path)-1] != "/")
  {
    path = path + "/";
  } 
  if (path[0..0] != "/")
  {
    path = "/" + path;
  }
*/ 
  tell_object(TP, "Dest: " + dest);
/*  if (dest[sizeof(dest)-1..sizeof(dest)-1] != "/")
  {
    dest = dest + "/";
  } 
  if (dest[0..0] != "/")
  {
    dest = "/" + dest;
  } 
*/
  files = get_dir(path + "*.c");
  headers = get_dir(path + "*.h");
  count = sizeof(files);
  if (count<1 && sizeof(headers)<1)
  {
    tell_object(TP, "No files found in origin directory: " + path);
    return 1;
  }
  for (i=0;i<count;i++)
  {
     tell_object(TP, "Copying " + path + files[i] + " to " + dest);
     temp = read_file(path + files[i] );
     report("file read. " + strlen(temp) + " characters long");
     report ("Writing to file: " + dest + files[i]);
     write_file(dest + files[i] , temp);
  }
  count = sizeof(headers);
  if (count<1)
  {
    return 1;
  }
  for (i=0;i<count;i++)
  {
     tell_object(TP, "Copying " + path + headers[i] + " to " + dest);
     temp = read_file(path + headers[i] + ".h ");
     write_file(dest + headers[i] + ".h", temp);
  }
  return 1;
}

void report(string str){
  "/daemon/reporter_d"->report("lujke", str);
}

void help() 
{
   write(
    "Syntax: <cpdir [origin path] [destination path]"
    "Copies all files in the directory specified by the origin path into the directory specified by the destination path."
    "Paths should be strings beginning and ending with '/' e.g. '/cmds/mortal/'"
    "Origin path is required. Destination path optional - if not entered, it defaults to the currently selected path." 
  );

}
