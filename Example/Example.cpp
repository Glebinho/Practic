// Example.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale>
#include <iostream>

using namespace std;

const int SIZE = 6;
void Vstavka(){
	// 25,    44, 69, 31, 11, 21
	// 25, 44,    69, 31, 11, 21
	// 25, 44, 69,    31, 11, 21
	// 25, 31, 44, 69,    11, 21
	// 11, 25, 31, 44, 69     21
	// 11, 21, 25, 31, 44, 69
	
	int arr[SIZE] = {25, 44, 69, 31, 11, 21};
	
	cout<<"Исходный массив:"<<endl;

	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"Отсортированный массив:"<<endl;

	for (int i = 1; i < SIZE; i++){
		int key = arr[i];
		int j = i - 1; 

		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			arr[j] = key;
			j--;
		}
	}
	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;

}

void Vubor(){
	// 66, 22, 17,  7,  100, 51
	//  7,  22, 17, 66, 100, 51
	//  7,  17, 22, 66, 100, 51
	//  7,  17, 22, 51, 100, 66
	//  7,  17, 22, 51, 66, 100 

	int arr[SIZE] = {67, 22, 17, 7, 100, 51};
	
	cout<<"Исходный массив:"<<endl;

	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"Отсортированный массив:"<<endl;

	for (int i = 0; i < SIZE-1; i++){
		int min_id = i;
		for (int j = i; j < SIZE; j++){
			if(arr[j] < arr[min_id]){
				min_id = j;
			}

		}
		if(i != min_id){
			int buff = arr[i];
			arr[i] = arr[min_id];
			arr[min_id] = buff;
		}
	}
	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;

}

void Buble(){
	// 55, 68, 43, 15, 78, 22
	// 55, 43, 15, 68, 22, 78
	// 43, 15, 22, 55, 68, 78
	// 15, 22, 43, 55, 68, 78
	int arr[SIZE] = {55, 68, 43, 15, 78, 22};

	cout<<"Исходный массив:"<<endl;

	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"Отсортированный массив:"<<endl;

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE-1; j++){
			if(arr[j]>arr[j+1]){
				int buff = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = buff;
			}
		}
	}

	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
}

void Sheiker(){
	// 90,  8, 11, 23, 44, 50
	//  8, 11, 23, 44, 50, 90
	int arr[SIZE] = {90, 8, 11, 23, 44, 50};

	cout<<"Исходный массив:"<<endl;

	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"Отсортированный массив:"<<endl;

	int left = 0, right = 6-1;
	int last;
	while(left < right){
		last = -1;
		for (int i = left; i < right; i++){
			if(arr[i]>arr[i+1]){
				int buff = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = buff;
				last = i;
			}
		}
		right = last;
		}
	last = SIZE;
	while(left < right){
		last = -1;
		for (int i = right-1; i >= left; i--){
			if(arr[i]>arr[i+1]){
				int buff = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = buff;
				last = i;
			}
		}
		left = last + 1;
	}
	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
}

void Shell(){
	// 54, 37, 13, 98, 23, 71 в 3 шага
	// 54, 23, 13, 98, 37, 71 в 1 шаг тк 3/2= 1.5 = 1
	// 13, 23, 37, 54, 71, 98
	
	int arr[SIZE] = {54, 37, 13, 98, 23, 71};
	
	cout<<"Исходный массив:"<<endl;

	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"Отсортированный массив:"<<endl;
	
	for (int step = 6/2; step > 0; step/=2){
		for (int i = step; i < 6; i++){
			for (int j = i - step; j >= 0 && arr[j] > arr[j+step]; j-=step){
				int buff = arr[j];
				arr[j] = arr[j+step];
				arr[j+step] = buff;

			}

		}

	}
	for (int i = 0; i < SIZE; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE,"Russian_Russia.1251");
	cout<<"Сортировка методом вставки:"<<endl;
	Vstavka();
	cout<<"Сортировка методом прямого выбора:"<<endl;
	Vubor();
	cout<<"Сортировка методом пузырька:"<<endl;
	Buble();
	cout<<"Сортировка шейкер методом:"<<endl;
	Sheiker();
	cout<<"Сортировка методом Шелла:"<<endl;
	Shell();
	system("pause");
	return 0;
}

