
#include "arkanoid.h"

void		text_display_white(float x, float y, const char *str)
{
	int	j;
	int	i;

	j = ft_strlen(str);
	glColor3f(1.f, 1.f, 1.f);
	glRasterPos2f(x, y);
	i = 0;
	while (i < j)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
		i++;
	}
}

void		text_display_black(float x, float y, const char *str)
{
	int	j;
	int	i;

	j = ft_strlen(str);
	glColor3f(0.f, 0.f, 0.f);
	glRasterPos2f(x, y);
	i = 0;
	while (i < j)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
		//		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
		i++;
	}
}

float		text_draw_menu_string(const char *str, t_vector position, float height)
{
	float		base_position;

	base_position = position.x;
	while (*str)
	{
		position.x += text_draw_char(*str, position, height, 'x');
		str++;
	}
	return (position.x - base_position);
}

float		text_draw_menu_string_hover(const char *str, t_vector position, float height)
{
	float		base_position;

	base_position = position.x;
	while (*str)
	{
		position.x += text_draw_char(*str, position, height, 'h');
		str++;
	}
	return (position.x - base_position);
}

float		text_draw_char(char c, t_vector position, float height, char hover)
{
	float		width;
	t_vector	offset;
	GLuint	texture;

	texture = text_get_texture(hover);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_TEXTURE_2D);
	width = height * 0.5f;
	c -= 32;
	offset.x = c % 10;
	offset.y = c / 10;
	offset.x /= 10;
	offset.y /= 10;
	offset.y = 1.0 - offset.y - 0.1;
	glBegin(GL_QUADS);
	glTexCoord2d(offset.x, offset.y);
	glVertex2f(position.x, position.y);
	glTexCoord2d(offset.x + 0.1, offset.y);
	glVertex2f(position.x + width, position.y);
	glTexCoord2d(offset.x + 0.1, offset.y + 0.1);
	glVertex2f(position.x + width, position.y + height);
	glTexCoord2d(offset.x, offset.y + 0.1);
	glVertex2f(position.x, position.y + height), glEnd();
	glDisable(GL_TEXTURE_2D);
	return (width);
}

GLuint		text_get_texture(char hover)
{
	static GLuint	texture;

	if (texture != 0)
		return (texture);
	glGenTextures(1, &texture);
	if (hover == 'h')
		texture = SOIL_load_OGL_texture("files/text_hover.png", SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	else
		texture = SOIL_load_OGL_texture("files/text.png", SOIL_LOAD_AUTO,
				SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	if (texture == 0)
		ft_error("Could not load the text texture.");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return (texture);
}
