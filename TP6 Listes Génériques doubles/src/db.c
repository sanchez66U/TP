#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "lst_elm_t.h"
#include "lst.h"
#include "db.h"

void write_list(struct list *L, enum mode_t mode, void (*ptrf)())
{
  FILE *fd;

  char fname[20];

  if (mode == TEXT)
  {
    printf("\t\tWrite list to text file (.txt)\n\tfile name :");
    scanf("%s", fname);
    fd = fopen(fname, "wt");
  }
  else
  {
    printf("\t\tWrite list to binary file (.bin)\n\tfile name :");
    scanf("%s", fname);
    fd = fopen(fname, "wb");
  }

  assert(fd != NULL);

  for (struct elmlist *iter = get_head(L); iter; iter = get_suc(iter))
  {
    (*ptrf)(get_data(iter), mode, fd);
  }

  fclose(fd);
}

struct list *read_list(enum mode_t mode, void *(*ptr_data)(), void(ptr_del)())
{ // on peut ajouter en argument un pointeur sur la fonction de comparaison des formulaires gt_form si l'on souhaite faire une insertion ordonnée
  FILE *fd;
  char fname[20];

  if (mode == TEXT)
  {
    printf("\t\tRead list from text file (.txt)\n\tfile name :");
    scanf("%s", fname);
    fd = fopen(fname, "rt");
  }
  else
  {
    printf("\t\tRead list from binary file (.bin)\n\tfile name :");
    scanf("%s", fname);
    fd = fopen(fname, "rb");
  }

  struct list *L = new_list();
  while (!feof(fd))
  {
    void *data = (*ptr_data))(fd, mode);
    if (!data)
      continue;
    ordered_insert(L, data, ptr_del));
    E = get_tail(L);
    struct elmlist *T = getPred(E);
    set_suc(T, NULL);
    L->tail = T;
    del_elmlist(E, ptr_del);
  }

  fclose(fd);
  return L;
}
