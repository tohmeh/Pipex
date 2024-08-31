/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIBFT.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:36:53 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/12 11:03:50 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct t_voidlst
{
	void				*content;
	struct t_voidlst	*next;
}	t_voidlst;

typedef struct t_char_list
{
	char				content;
	struct t_char_list	*next;
}	t_char_list;

char		*get_next_line(int fd);
char		*ft_substr(char const *str, size_t start, size_t len);
char		*ft_strchr(const char *str, int character);
char		*ft_strrchr(const char *str, int character);
char		*ft_strnstr(const char *str, const char *to_found, size_t len);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *str1, const char *str2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, const char delimiters);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		ft_toupper(char c);
char		ft_tolower(char c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_strlen(const char *str);
int			ft_isprint(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int			ft_atoi(const char *str);
int			ft_lstsize(t_voidlst *lst);
int			ft_print_adress_lower(unsigned int m);
int			ft_print_adress_upper(unsigned int m);
int			ft_print_address(void *p);
int			ft_printf(const char *str, ...);
int			ft_putchar_fd(char c, int fd);
int			ft_putlnbr(unsigned int nb);
int			ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *str);
int			lstsize(t_char_list *lst);
int			exists(t_char_list *head);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *ptr, int value, size_t num);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putendl_fd(char *s, int fd);
void		ft_lstadd_front(t_voidlst **lst, t_voidlst *new_t_stack);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		ft_lstadd_back(t_voidlst **lst, t_voidlst *new_t_stack);
void		ft_lstdelone(t_voidlst *lst, void (*del)(void*));
void		ft_lstclear(t_voidlst **lst, void (*del)(void*));
void		ft_lstiter(t_voidlst *lst, void (*f)(void *));
void		lstadd_back(t_char_list **lst, t_char_list *new_t_stack);
size_t		ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
t_voidlst	*ft_lstnew(void *content);
t_voidlst	*ft_lstmap(t_voidlst *lst, void *(*f)(void *), void (*del)(void *));
t_char_list	*lstnew(char content);
t_voidlst	*ft_lstlast(t_voidlst *lst);

#endif
