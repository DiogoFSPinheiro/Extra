/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:37:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:09:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include <unistd.h>

int		printf_ft_putchar_fd(char c, int fd);
int		printf_ft_putnbr_fd(int n, int fd, int c);
int		printf_ft_putnbr_hexa(unsigned int nb, char *base, int fd, int c);
int		printf_ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *format, ...);
int		printf_ft_putnbr_fd_u(unsigned int n, int fd, int c);
size_t	printf_ft_strlen(const char *str);
int		printf_ft_putnbr_ptr(unsigned long long ptr, int fd);
int		ft_println(const char *format, ...);

#endif
