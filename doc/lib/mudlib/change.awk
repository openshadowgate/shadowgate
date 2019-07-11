# AWK script for changing for changing all the file in the current directory
# and all those below it to reflect the changes in set_race and query_race
# and in set_aggressive and query_aggressive if anyone calls that

# There are several versions of awk.  If you have the old version, it will
# crash with errors on "awk 1" if you have the new version it will hang or
# exit normally.
# if you have an old version try "nawk" or "gawk"
# either way, to run this type "awk -f race.awk" and it will hum for a bit and
# give you back your prompt
# -Valodin@Nightmare  June 15, 1993
# This file looks at only .c files and should leave compressed ".Z" and
# tarred ".tar" files alone

BEGIN { 
  dir = 0;
  cdir = 0;
  file = 0;
  cfile = 0;
  expanddir("");
  while (cdir < dir) {
    expanddir(dirs[cdir++]);
  }
  while (cfile < file) {
    filed = files[cfile] ".tmp";
    while (getline < files[cfile] > 0) {
       gsub(/set_hit_func\(this_object\(\)/, "set_hit((:this_object(), \"weapon_hit\"");
       gsub(/set_wield_string/, "set_wield");
       print > filed;
    }
    close(filed);
    close(files[cfile]);
    system("mv -f " filed " " files[cfile]);
    cfile++;
  }
} 

function expanddir(dirname) {
while ("ls -l " dirname | getline > 0) 
  if (NF >= 8) 
     if ($1 !~ /^d/) {
        # don't look at compressed files
        if ($NF !~ /\.Z/)
           # don't look at tarred files
           if ($NF !~ /\.tar/)
              # only look at .c files
              if ($NF ~ /\.c/)
                 if (dirname == "") 
                    files[file++] = $NF
                 else
                    files[file++] = dirname "/" $NF
     }
     else
        if (dirname == "") 
           dirs[dir++] = $NF
        else
           dirs[dir++] = dirname "/" $NF
close("ls -l " dirname)
}
