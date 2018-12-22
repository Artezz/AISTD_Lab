#pragma once
#include "stdafx.h"

struct Array {

	int row =-1, col = -1, firstN = 0;
	int **arr;

	void createArr() {
		arr = (int**)malloc(sizeof(int*) * row);
		for (size_t i = 0; i < row; i++)
			arr[i] = (int*)malloc(sizeof(int) * col);
	}

	void input() {
		std::cout << "Enter row: ";
		std::cin >> row;
		std::cout << "Enter column: ";
		std::cin >> col;
		std::cout << "Enter first num (default 0): ";
		std::cin >> firstN;
	}

	void fillArr() {
		if (row - col <= 0) {
			for (size_t i = 0; i < row - i; i++) {
				for (size_t k = 0 + i; k < col - i; k++) {

					if (k < col) {
						arr[i][k] = firstN; //горизонт
						arr[row - 1 - i][k] = firstN;
					}

					if (k < row && k < col - i - std::abs(row - col)) {
						arr[k][i] = firstN;  //верт
						arr[k][col - 1 - i] = firstN;
					}


				}
				firstN++;
			}
		}
		else {
			for (size_t i = 0; i < col - i; i++) {
				for (size_t k = 0 + i; k < row - i; k++) {
					if (k < col && k < row - i - std::abs(row - col)) {
						arr[i][k] = firstN; //горизонт
						arr[row - 1 - i][k] = firstN;
					}

					if (k < row) {
						arr[k][i] = firstN;  //верт
						arr[k][col - 1 - i] = firstN;
					}


				}
				firstN++;
			}
		}
	}

	void printArr() {
		for (size_t i = 0; i < row; i++) {
			for (size_t k = 0; k < col; k++) {
				std::cout <<std::setw(2)<< arr[i][k] << " ";
				}
			std::cout << std::endl;
		}
	}
	~Array(){
		for (size_t i = 0; i < row - i; i++) {
			free(arr[i]);
		}
		free(arr);
		std::cout << "OK";
	}
};