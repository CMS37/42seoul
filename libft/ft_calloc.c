/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:47:55 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/12 15:47:55 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*arr;

	arr = malloc(elsize * nelem);
	if (!arr)
		return (NULL);
	ft_bzero(arr, (nelem * elsize));
	return (arr);
}

/*
int main() 
{ 
	int arr_1[5]; // 배열 선언 
	int *arr_2; // 포인터 변수 선언 
	int i; 
	for(i = 0; i < 5; i++) 
	{ 
		arr_1[i] = i+1; // 배열에 값 대입 
	} 	
	//arr_2 = (int*) malloc(sizeof(int)*5); // 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함 
	arr_2 = (int*) ft_calloc(5, sizeof(int)); // sizoe(int)크기의 변수를 5개 저장할 수 있는 공간할당 
	for(i = 0; i < 5; i++) 
	{ 
		arr_2[i] = arr_1[i]; 
		printf("%d ", arr_2[i]); 
	} 
	
	free(arr_2); // free함수를 이용하여 메모리 해제 
	
	return 0; 
}
*/