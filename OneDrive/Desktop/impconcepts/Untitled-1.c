#include<stdio.h>
#include<limits.h>

static int __cmp_uid(char *uid1, char *uid2)
{
  int i;

  for (i = 0; i < 10; i++) {
    if (uid1[i] > uid2[i]) {
      return 1;
    }
    else if (uid1[i] < uid2[i]) {
      return -1;
    }
  }
  return 0;
}
int main()
{
  printf("%d",__cmp_uid("bure",NULL));
}