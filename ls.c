#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;
  if (argc != 2)
  {
    fprintf(stderr, "usage ls: directory name\n");
    exit(1);
  }

  if ((dp = opendir(argv[1])) == NULL)
  {
    fprintf(stderr, "can  not open %s", argv[1]);
    exit(1);
  }
  while ((dirp = readdir(dp)) != NULL)
    printf("%s\n", dirp->d_name);
  closedir(dp);
  exit(0);
}
