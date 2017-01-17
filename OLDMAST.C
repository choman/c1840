#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct clientdata {
  int accnum;
  char firstname[100];
/*  char lastname[15]; */
  float balance;
} MASTER_REC;

main()
{
  MASTER_REC  mr[]={   {100, "Alan Jones", 348.17},
		       {300,"Mary Smith", 27.19},
		       {500,"Sam Sharp",  0.00},
		       {700, "Suzy Green", -14.22}};
  int fd;

  fd = open("oldmast.dat", O_WRONLY | O_CREAT, 0777);  assert(fd > 0);
  printf("About to write %d bytes!\n", sizeof(mr));
  write(fd, mr, sizeof(mr));  /* warning!  Sizeof used in a nonportable way 
			       * be careful!
			       */
  close(fd);
  return 0;
}/* main */

  
  
