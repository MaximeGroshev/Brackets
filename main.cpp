#include "differentiator.h"

int main ()
{
    log_init ("./logs/log_file.html");

    struct tree_t pine = {};
    struct tree_t dif_pine = {};
    constructor  (&pine);
    constructor  (&dif_pine);

    // FILE* br_read = fopen ("./test_files/read_br_seq.txt.txt", "r");
    // read_brackets (br_read, &pine);
    //fclose (br_read);
    // double res = tree_eval (&pine, pine.root);
    // printf ("%lg", res);

    tree_new_op_node (&pine, OP_ADD, tree_new_var_node (&pine, TYPE_VAR), tree_new_num_node (&pine, 4));
    dif (&dif_pine, pine.root);

    FILE* br_write = fopen ("./test_files/write_br_seq.txt", "w");
    write_brackets (br_write, pine.root);
    fclose (br_write);
    graph_dump  (&dif_pine);
    graph_dump  (&pine);

    tree_delete (&pine, pine.root);
    tree_delete (&dif_pine, dif_pine.root);

    log_distr ();
}
