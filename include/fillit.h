/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arezouk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:45:58 by arezouk           #+#    #+#             */
/*   Updated: 2018/12/01 19:02:53 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}				t_list;

typedef struct	s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct	s_map
{
	int				size;
	char			**tab;
}				t_map;

typedef struct	s_tetri
{
	char			**posi;
	int				width;
	int				height;
	char			alpha;
}				t_tetri;

size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_list			*read_tetri(int	fd);
int				check_block(char *ch, int block);
int				check_tetri(char *ch);
int				small_sqrt(int i);
int				back_solving(t_map *map, t_list *list);
t_map			*solve(t_list *list);
t_tetri			*get_shape(char *ch, char alpha);
void			coordinate(char *ch, t_point *min, t_point *max);
t_point			*tetri_coord(int x, int y);
t_tetri			*tetri_struct(char **posi, int width, int height, char alpha);
void			free_tetri_struct(t_tetri *tetri);
t_list			*free_list(t_list *list);
void			free_map(t_map *map);
void			print_map(t_map *map);
t_map			*create_map(int size);
void			place_tetri(t_tetri *tetri, t_map *map, t_point *point,
				char alpha);
int				check_and_place(t_tetri *tetri, t_map *map, int x, int y);
size_t			count_list(t_list *list);
void			list_reverse(t_list **list);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			mapperino(t_map *map);
t_list			*ft_lstnew(void const *content, size_t content_size);
char			*ft_strdup(char *src);
void			ft_putchar(char c);

#endif
