
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cmd {
    char    **argum;
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



int main()
{
    t_token *head;
    t_token *second;

    head = malloc(sizeof(t_token));
    second = malloc(sizeof(t_token));
    head->cmd = malloc(sizeof(t_cmd));
    head->cmd->argum = malloc(sizeof(char *));
    second->cmd = malloc(sizeof(t_cmd));
    second->cmd->argum = malloc(sizeof(char *));
    head->next = second;
    head->cmd->argum = "1";
    second->cmd->argum = "2";
    second->next = NULL;
    
    printf("El primer nodo:%s\n", head->cmd->argum);
    printf("El segundo nodo:%s\n", second->cmd->argum);
    printf("El segundo nodo:%s\n", head->next->cmd->argum);
    printf("El primer nodo:%s\n", head->cmd->argum);
}