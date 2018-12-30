typedef struct cell * cell;
struct cell
{
  unsigned char B;
  int           freq;
  cell          next;
};

cell create_cell(int B, cell next);

cell insert_cell(cell head, int B);

cell delete_list(cell list);
