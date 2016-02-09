
#ifndef ARKANOID_H
# define ARKANOID_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <GLFW/glfw3.h>
# include <SOIL.h>
# include <GLUT/glut.h>
# include <fcntl.h>
# include <time.h>
# include "libft.h"
	
# define WKW_WINW 1600
# define WKW_WINH 900
# define ARCANOID_TITLE "Arkanoid rush"

# define MENU_RESUME 1
# define MENU_OPTION 2
# define MENU_QUIT 3

typedef struct			s_chrono
{
	time_t			start;
	time_t			end;

}				t_chrono;

typedef struct			s_vector
{
	float			x;
	float			y;
}				t_vector;

typedef struct			s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct			s_ball
{
	double				x;
	double				y;
	double				dx;
	double				dy;
    double				speed;
    int					balls_of_steel;
    struct s_ball		*next;
}						t_ball;

typedef struct		s_block
{
	int				life;
	t_pos			pos;
	struct s_block	*next;
	struct s_block	*prev;
}					t_block;

typedef struct			s_player
{
	int			life;
	int			speed;
	int			score;
	char			*name;
	double		x;
	double		y;
}				t_player;

typedef struct			s_menu
{
	int			is_open;
	int			current;
}				t_menu;

typedef struct			s_ark
{
	GLFWwindow		*window;
	t_block			*map;
	t_player		*j1;
	t_player		*j2;
	t_menu			*menu;
	t_chrono		*chrono;
	t_ball			*ball;
	float			ratio;

	int				w;
	int				h;
}				t_ark;

void				callback_error(int error, const char* description);
void				callback_key(GLFWwindow *window, int key, int scancode, int action, int mods);

void				key_exit(GLFWwindow *window, int key, int action);
void				key_pause(t_ark *a);
void				key_menu_nav_up(t_ark *a);
void				key_menu_nav_down(t_ark *a);

void				menu_background(t_ark *a);
void				menu_buttons(t_ark *a);
void				menu_button_resume(void);
void				menu_button_options(void);
void				menu_button_quit(void);
void				menu_button_resume_hover(void);
void				menu_button_options_hover(void);
void				menu_button_quit_hover(void);


void				tools_gl_exit(t_ark *a);
GLFWwindow			*tools_gl_init(t_ark *a);
void				tools_gl_loop(t_ark *a);
void				tools_create_triangle(void);
void				tools_create_rectangle(void);
void                            tools_gl_setortho(t_ark *a);
void                            tools_gl_antialiasing(void);
void				tools_menu_init(t_ark *a);

void				get_level(t_ark *a, const char *file);
void				draw_game(t_ark *a);
void				draw_ball(t_ark *a, t_ball *ball);
t_ball				*ball_create(void);
void				game_update(t_ark *a);

void				ft_error(const char *message);
void				ft_error_num(int error, const char *message);

float				text_draw_menu_string(const char *str, t_vector position, float height);
float				text_draw_menu_string_hover(const char *str, t_vector position, float height);
float				text_draw_char(char c, t_vector position, float height, char hover);
GLuint				text_get_texture(char hover);

t_vector			vector_init(float x, float y);


void				text_display_black(float x, float y, const char *str);
void				text_display_white(float x, float y, const char *str);
int			time_spent(t_chrono *c);
void				chrono_string(t_ark *ark, int hrs, int min, int sec);
void				chrono_display(t_ark *a);

void				highscore_save(t_ark *a, char *player, char *score);
void				highscore_j1(t_ark *a);
void				highscore_j2(t_ark *a);
void				highscore_j1_display(t_ark *a);
void				highscore_j2_display(t_ark *a);

#endif
