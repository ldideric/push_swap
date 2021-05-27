/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sudocode.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 14:44:03 by ldideric      #+#    #+#                 */
/*   Updated: 2021/05/27 14:50:29 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


int	partition(int *a, int low, int high)
{
	int	i;
	int	pivot;
	int	leftwall;

	i = low + 1;
	pivot = a[low];
	leftwall = low;
	while (i < high)
	{
		if (a[i] < pivot)
		{
			swap(a[i], a[leftwall]);
			leftwall = leftwall + 1;
		}
		i++;
	}
	swap(pivot, a[leftwall]);
	return (leftwall);
}

void	quicksort(int *a, int low, int high)
{
	if (low < high)
	{
		pivot_location = partition(a, low, high);
		quicksort(a, low, pivot_location);
		quicksort(a, pivot_location + 1, high);
	}
}
