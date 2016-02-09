
#include "arkanoid.h"
#include <GLFW/glfw3.h>

void		menu_background(t_ark *a)
{
	if (a->menu->is_open)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(-2.f, -2.f);
		glVertex2f(2.f, -2.f);
		glVertex2f(2.f, 2.f);
		glVertex2f(-2.f, 2.f);
		glEnd();
	}
}

void		menu_buttons(t_ark *a)
{
	if (a->menu->is_open)
	{
		if (a->menu->current == MENU_RESUME)
			menu_button_resume_hover();
		else
			menu_button_resume();
		if (a->menu->current == MENU_OPTION)
			menu_button_options_hover();
		else
			menu_button_options();
		if (a->menu->current == MENU_QUIT)
			menu_button_quit_hover();
		else
			menu_button_quit();
	}
}

void	menu_button_quit(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, -0.2f);
	glVertex2f(-0.5f, -0.2f);
	glEnd();
	text_display_black(-0.07f, -0.4f, "QUIT");
}

void	menu_button_options(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2f(-0.5f, -0.15f);
	glVertex2f(0.5f, -0.15f);
	glVertex2f(0.5f, 0.15f);
	glVertex2f(-0.5f, 0.15f);
	glEnd();
	text_display_black(-0.1f, -0.02f, "OPTIONS");
}

void	menu_button_resume(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, 0.2f);
	glVertex2f(-0.5f, 0.2f);
	glEnd();
	text_display_black(-0.1f, 0.33f, "RESUME");
}

void	menu_button_quit_hover(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.6f, 0.2f);
	glVertex2f(-0.52f, -0.52f);
	glVertex2f(0.52f, -0.5f);
	glVertex2f(0.52f, -0.2f);
	glVertex2f(-0.52f, -0.18f);
	glEnd();
	text_display_white(-0.07f, -0.4f, "QUIT");
}

void	menu_button_options_hover(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.6f, 0.2f);
	glVertex2f(-0.52f, -0.14f);
	glVertex2f(0.52f, -0.17f);
	glVertex2f(0.52f, 0.17f);
	glVertex2f(-0.52f, 0.14f);
	glEnd();
	text_display_white(-0.1f, -0.02f, "OPTIONS");
}

void	menu_button_resume_hover(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.6f, 0.2f);
	glVertex2f(-0.52f, 0.52f);
	glVertex2f(0.52f, 0.5f);
	glVertex2f(0.52f, 0.2f);
	glVertex2f(-0.52f, 0.18f);
	glEnd();
	text_display_white(-0.1f, 0.33f, "RESUME");
}
