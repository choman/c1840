/* display what's in a file of master recs. */
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

main(int argc, char *argv[])
{
  MASTER_REC  mr;
  int fd;
	
  assert(argc > 1);  /* ie at least one command line parameter. */
  fd = open(argv[1], O_RDONLY);  assert(fd > 0);
  while (sizeof(MASTER_REC) == read(fd, &mr, sizeof(MASTER_REC))) {
    print_mr(&mr);
  }/* while */
  close(fd);
  return 0;
}/* main */

print_mr(MASTER_REC *mr)
{
    printf("%d %s %f\n", mr->accnum, mr->firstname, mr->balance);
}
  
