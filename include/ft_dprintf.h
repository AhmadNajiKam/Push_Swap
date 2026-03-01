/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamamji <akamamji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:04:54 by akamamji          #+#    #+#             */
/*   Updated: 2026/02/28 18:18:45 by akamamji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int		ft_dputchar(int fd, char c);
int		ft_dputnbr(int fd, int n);
int		ft_dputstr(int fd, char *s);
size_t	ft_strlen(const char *s);
int		ft_dputdouble(int fd, double number);
int		ft_dprintf(int fd, const char *format, ...);
#endif
