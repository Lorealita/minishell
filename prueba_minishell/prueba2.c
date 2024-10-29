
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cmd {
    char    *argum;
} t_cmd;

typedef struct s_pipe {
    int     flag;// si hay uno, sino cero
} t_pipe;

typedef struct s_redir {
    int     f_red_input;
    int     f_red_output;
    int     f_red_delimit;
    int     f_red_heredoc;
} t_redir;

typedef struct s_token { // puede que sea una lista doblemente enlazada
    struct s_cmd    *cmd;
    struct s_pipe   *pipe;
    struct s_redir  *redir;
    int              fdin; //puede ser struct o int
    int              fdout;//puede ser struct o int
    struct s_token  *next;
    struct s_token  *prev;// lo necesito si es doblemente enlazada
} t_token;

//añadir un nodo al final de la lista token que ya existe.
t_token *add_token (t_token *tail)
{
    t_token *node;

    node = malloc(sizeof(t_token));
    node->cmd = malloc(sizeof(t_cmd));
    node->cmd->argum = malloc(sizeof(char *));
    tail->next = node;
    node->next = NULL;
    return(node);
}

int main()
{
    t_token *head;
    t_token *second;
    t_token *tail;

    head = malloc(sizeof(t_token));
    head->cmd = malloc(sizeof(t_cmd));
    head->cmd->argum = malloc(sizeof(char *));
    second = add_token(head);
    tail = add_token(second);
    head->cmd->argum = "1";
    second->cmd->argum = "2";
    tail->cmd->argum = "3";
    
    printf("El primer nodo:%s\n", head->cmd->argum);
    printf("El segundo nodo:%s\n", second->cmd->argum);
    printf("Este es el nodo final:%s\n", tail->cmd->argum);

}