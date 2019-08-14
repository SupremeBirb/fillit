/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_r_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:05:53 by lelee             #+#    #+#             */
/*   Updated: 2019/08/13 00:02:59 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"

int main(int ac, char **av)
{
	open("Test", O_RDWR);
	return (0);
}

/*
** Open:
** 		int open (const char* Path, int flags [,int mode ]);
** 
**	Flags -
**	O_RDONLY: read only, O_WRONLY: write only, O_RDWR: read and write,
**	O_CREAT: create file if it doesn't exist, O_EXCL: prevent creation if it
**	already exists.
**
**	Path - 
**	(#) use absolute path begin with "/", when you are not work in same 
**	directory as the file. 
**	(#) Use relative path which is only file name with extension, when you are 
**	working in the same directory of file.
**
**
** Close:
**		int close(int fd);
**
**	Parameter: fd - File Descriptor
**	Return: 0 on success || -1 on error
**  
**  How it works in the OS -
**	(#) Destroy file table entry referenced by element fd of file descriptor
**  table.
**  	(*) As long as no other process is pointing to it.
**  (#) Set element fd of file descriptor table to NULL.
**
**
** Read:
** 		size_t read (int fd, void *buf, size_t cnt);
** 
**	Parameters: fd - File descriptor
** 				buf - buffer to read data from
** 				cnt - length of buffer
** 
** 	Returns: (Number of bytes actually read)
**		(#) return number of bytes read on success
**		(#) return 0 on reaching end of file
**		(#) return -1 on error
**
**	Important Points:
**		(#) buf needs to point to a valid memory location with length not 
**			smaller than the specified size because of overflow.
**		(#) fd should be a valid file descriptor returned from open() to 
**			perform read operation because if fd is NULL then read should g
**			enerate error.
**		(#) cnt is the requested number of bytes read, while the return value 
**			is the actual number of bytes read. Also, some times read system
**		 	call should read less bytes than cnt.
*/