
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/param.h>
# include <readline/history.h>
# include <readline/readline.h>

//variable global para señales
int g_sig;

//estructura general de datos de la shell
typedef struct s_cmd {
    char	**argum;
}			t_cmd;

typedef struct s_pipe {
    int		flag;// si hay uno, sino cero
}			t_pipe;

typedef struct s_redir {
    int		f_red_input;
    int		f_red_output;
    int		f_red_delimit;
    int		f_red_heredoc;
    char	*fdin; //nombre de archivo de entrada
    char	*fdout;//nombre de archivo de salida
}			t_redir;

typedef struct s_token
{
    struct s_cmd	*cmd;
    struct s_pipe	*pipe;
    struct s_redir	*redir;
    struct s_token	*head;
    struct s_token	*next;
    struct s_token	*prev;// lo necesito si es doblemente enlazada
}					t_token;


// void    init_struct(char *readline)
// {
//     t_token	*node;

//     while (/* condition */)
//     {
//         /* code */
//     }
    

// 	node = malloc(sizeof(t_token));
// 	node->cmd = malloc(sizeof(t_cmd));
// 	token->next = NULL;
// }


// void    init_argum(void)
// {
//     t_cmd   *node;
//     //numero de palabras que contiene. Cuando haya parseo se calculara ahí
//     int     nw = 5;
//     int     cnt = 0;

//     node->argum = malloc(nw)(sizeof(char **));
//     while(cnt < (nw - 1))
//     {
//         argum[cnt] = malloc (sizeof(char *));
//         cnt++;
//     }
// }

// //añadir un nodo al final de la lista token que ya existe.
// void    *add_token (t_token *tail, char *value)
// {
//     t_token *node;

//     node = malloc(sizeof(t_token));
//     node->cmd = malloc(sizeof(t_cmd));
//     node->cmd->argum = malloc(sizeof(char *));
//     tail->next = node;
//     node->next = NULL;
//     node->cmd->argum = value;
// }

// void	execute_multi_cmd(char *path, t_token *token, char **env)
// {
// 	int		cnt;
// 	int		fd1;
// 	int		fd2;

// 	//si existe f_red_output, entonces abro el archivo de salida y le asigno un fd.
// 	if (token->redir->f_red_output)
// 	{
// 		fd2 = open(token->redir->fdout, O_CREAT | O_TRUNC | O_WRONLY, 0664);
// 	}
// 	if (token->redir->fd_red_input)
// 	{
// 		fd1 = open(token->redir->fdin, O_RDONLY);
// 	}
// 	dup2(fd1, STDIN_FILENO);
// 	dup2(fd2, STDOUT_FILENO);
// 	envario(fd1, env, argv[2]);
// 	while (argv[cnt] && cnt < argc - 2)
// 	{
// 		envario(STDOUT_FILENO, env, argv[cnt]);
// 		cnt++;
// 	}                      
// 	arg = ft_split(argv[cnt], ' ');
// 	path = ft_path(arg[0], env);
// 	if (execve(path, arg, env) < 0)
// 		exit(1);
// }

int	ft_nword(char *s, char p, char o, char i)
{
	int	cnt;
	int	wd;

	wd = 0;
	cnt = 0;
	while (*s)
	{
		if (*s != ' ' && *s != p && *s != o && *s != i && cnt == 0)
		{
			wd++;
			cnt = 1;
		}
		else if (*s == ' ' || *s == p || *s == o || *s == i)
			cnt = 0;
		s++;
	}
	return (wd);
}

int main(int argc, char **argv, char **env)
{
    char    *read_line;
	t_token *token;
    int     nw;

	(void)argv;
	(void)argc;
	g_sig = 0;
    while (1)
	{
		read_line = readline("🌝 Minishell$> ");
		if (!read_line)
		{
			printf("[Error]: readline_Fail");
			exit(1);
		}
		add_history(read_line);
        nw = ft_nword(read_line, '|', '>', '<');
        printf("El número de palabras es %d\n", nw);
    }
}