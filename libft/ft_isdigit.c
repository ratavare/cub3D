/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:17:29 by ratavare          #+#    #+#             */
/*   Updated: 2024/02/14 17:09:06 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int value)
{
	if (value >= 48 && value <= 57)
		return (1);
	else
		return (0);
}
