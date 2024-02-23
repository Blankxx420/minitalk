/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:00:32 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/15 11:14:10 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

// First Part

int				ft_isalnum(int character);
int				ft_isalpha(int character);
int				ft_isascii(int character);
int				ft_isdigit(int character);
int				ft_atoi(const char *str);
int				ft_isprint(int character);
int				ft_tolower(int character);
int				ft_toupper(int character);
int				ft_strncmp( const char *first,
					const char *second, size_t length);
int				ft_memcmp(const void *pointer1,
					const void *pointer2, size_t size);
void			*ft_memchr( const void *memoryblock,
					int searchedchar, size_t size);
void			*ft_calloc(size_t elementcount, size_t elementcize);
int				ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
void			ft_bzero(void *dest, unsigned int size);
void			*ft_memcpy(void *destination, const void *source, size_t size);
void			*ft_memset(void *dest, int value, unsigned int size);
void			*ft_memmove(void *dest, const void *src, size_t size);
char			*ft_strchr( const char *string, int searchedchar);
char			*ft_strrchr(const char *string, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strstr(const char *str, const char *to_find);
void			ft_free_tab(char **tab);

// Second part

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
long long int	ft_atol(const char *str);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

// Bonus part

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));

// printf

int				ft_printf(const char *format, ...);
int				ft_putstrlen(char *str);
int				ft_putnbr_basel(unsigned long int nbr, char *base);
int				ft_putcharl(char c);
int				ft_putnbrl(int n);
int				ft_putunbrl(unsigned int n);

// gext_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

void			ft_read_and_extract(int fd, char **stock);
int				ft_check_newline(char *stash);
char			*get_next_line(int fd);
char			*ft_strjoinf(char *s1, char *s2);
char			*ft_get_line(char *buffer, char *line);
char			*ft_clean_stock(char *stock);

#endif